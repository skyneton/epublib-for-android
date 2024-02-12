package net.mpoisv.epublib

import android.annotation.SuppressLint
import android.graphics.Bitmap
import android.graphics.BitmapFactory
import android.graphics.Typeface
import android.os.Build
import android.text.TextPaint
import net.mpoisv.epublib.utils.ByteBuf
import net.mpoisv.epublib.utils.ByteHelper
import java.io.File
import java.util.UUID
import java.util.function.Function
import java.util.zip.ZipFile

class Epub(file: File, private val cacheDirectory: String, private val parseNow: Boolean = true): AutoCloseable {
    val path = file.absolutePath
    val name = file.nameWithoutExtension
    val file = ZipFile(file)

    private val imageCache = HashMap<String, Bitmap>()
    private val fontCache = HashMap<String, Typeface>()

    private var ptr: Long
    val totalPages get() = getTotalPages(ptr)
    val isAlive get() = ptr != 0L
    private val cacheFiles = ArrayList<String>()

    private var closed: Boolean = false

    init {
        val container = fileToStringHandler("META-INF/container.xml")
        ptr = if(container != null) {
            fromRootText(container, ::fileToStringHandler, ::imageHandler, parseNow)
        }else 0
    }

    override fun close() {
        closed = true

        release(ptr)
        ptr = 0L

        fontCache.clear()
        for((_, image) in imageCache) image.recycle()
        file.close()
        for(cache in cacheFiles) File(cache).delete()
        cacheFiles.clear()
    }

    fun getCoverImage(): Bitmap? {
        if(ptr == 0L) return null
        val path = nGetCoverImage(ptr) ?: return null
        return loadImage(path)
    }

    private fun fileToStringHandler(path: String): String? {
        if(closed) return null
        val entry = file.getEntry(path) ?: return null
        val stream = file.getInputStream(entry)
        val data = stream.readBytes().toString(Charsets.UTF_8)
        stream.close()
        return data
    }

    fun loadImage(path: String): Bitmap? {
        if(closed) return null
        val cachedImage = imageCache[path]
        if(cachedImage != null) return cachedImage
        val entry = file.getEntry(path) ?: return null
        val stream = file.getInputStream(entry)
        val bitmap = BitmapFactory.decodeStream(stream)
        stream.close()
        if(bitmap == null) return null
        imageCache[path] = bitmap
        return bitmap
    }

    private fun imageHandler(path: String): IntArray {
        if(closed) return intArrayOf()

        val cachedImage = imageCache[path]
        if(cachedImage != null) return intArrayOf(cachedImage.width, cachedImage.height)

        val entry = file.getEntry(path) ?: return intArrayOf()
        val stream = file.getInputStream(entry)
        val bitmap = BitmapFactory.decodeStream(stream)
        stream.close()
        if(bitmap == null) return intArrayOf()
        imageCache[path] = bitmap

        return intArrayOf(bitmap.width, bitmap.height)
    }

    fun loadTypeface(path: String): Typeface? {
        if(closed) return null

        val cachedFont = fontCache[path]
        if(cachedFont != null) return cachedFont

        val entry = file.getEntry(path) ?: return null
        val stream = file.getInputStream(entry)
        val fontFile = File(cacheDirectory, UUID.randomUUID().toString())
        cacheFiles.add(fontFile.absolutePath)
        fontFile.deleteOnExit()

        fontFile.writeBytes(stream.readBytes())
        stream.close()

        return Typeface.createFromFile(fontFile).apply { fontCache[path] = this }
    }

    fun getPage(page: Int): EpubPage? {
        if(ptr == 0L) return null
        val epubPage = nGetPage(ptr, page, ::fileToStringHandler, ::imageHandler)
        if(epubPage == 0L) return null
        return EpubPage(this, epubPage)
    }

    fun getPageWithoutParse(page: Int): EpubPage? {
        if(ptr == 0L) return null
        val epubPage = nGetPageWithoutParse(ptr, page)
        if(epubPage == 0L) return null
        return EpubPage(this, epubPage)
    }

    @SuppressLint("WrongConstant")
    fun pagination(page: Int, viewportWidth: Int, viewportHeight: Int, textPaint: TextPaint, density: Float, fontScale: Float, defaultLineHeight: Float = -1F, wordBreak: Boolean = true, onPage: (EpubPagination) -> Unit) {
        if(ptr == 0L) return
        val fontFamilyReverse = HashMap<TypefaceInfo, Int>()
        val typefaces = arrayListOf(textPaint.typeface)

        nPagination(ptr, page, viewportWidth, viewportHeight,
            textPaint, fontScale, density,
            textPaint.textSize, textPaint.letterSpacing, textPaint.textScaleX, textPaint.textSkewX,
            if(defaultLineHeight < 0) textPaint.textSize * 1.33F else defaultLineHeight, wordBreak,
            ::fileToStringHandler, ::imageHandler,
            {fontFamily, fontWeight, italic ->
                if(closed) return@nPagination -2
                var typeface = loadTypeface(fontFamily) ?: return@nPagination -1
                val info = TypefaceInfo(typeface, fontWeight, italic)
                val idx = fontFamilyReverse[info]
                if (idx != null) {
                    textPaint.typeface = typefaces[idx]
                    return@nPagination idx
                }

                if(fontWeight != 400 || italic) {
                    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
                        typeface = Typeface.create(typeface, fontWeight, italic)
                    } else {
                        var style = 0
                        if (fontWeight >= 700) style = style or Typeface.BOLD
                        if (italic) style = style or Typeface.ITALIC

                        typeface = Typeface.create(typeface, style)
                    }
                }

                textPaint.typeface = typeface
                typefaces.add(typeface)
                fontFamilyReverse[info] = typefaces.lastIndex
                return@nPagination typefaces.lastIndex
            }, {
                    idx ->
                textPaint.typeface = typefaces[idx]
            }) {
            onPage.invoke(EpubPagination(page, it))
        }
    }

    @SuppressLint("WrongConstant")
    fun lineBreak(epubElementText: EpubElementText, textPaint: TextPaint, viewportWidth: Int, density: Float, fontScale: Float, defaultLineHeight: Float = -1F, wordBreak: Boolean = true): IntArray {
        if(ptr == 0L) return intArrayOf()

        val fontFamilyReverse = HashMap<TypefaceInfo, Int>()
        val typefaces = arrayListOf(textPaint.typeface)

        return nLineBreak(
            ByteBuf().apply { epubElementText.save(this) }.flush(),
            viewportWidth, textPaint,
            fontScale, density,
            textPaint.textSize, textPaint.letterSpacing, textPaint.textScaleX, textPaint.textSkewX,
            if(defaultLineHeight < 0) textPaint.textSize * 1.33F else defaultLineHeight, wordBreak,
            { fontFamily, fontWeight, italic ->
                if(closed) return@nLineBreak -2
                var typeface = loadTypeface(fontFamily) ?: return@nLineBreak -1
                val info = TypefaceInfo(typeface, fontWeight, italic)
                val idx = fontFamilyReverse[info]
                if (idx != null) {
                    textPaint.typeface = typefaces[idx]
                    return@nLineBreak idx
                }

                if(fontWeight != 400 || italic) {
                    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
                        typeface = Typeface.create(typeface, fontWeight, italic)
                    } else {
                        var style = 0
                        if (fontWeight >= 700) style = style or Typeface.BOLD
                        if (italic) style = style or Typeface.ITALIC

                        typeface = Typeface.create(typeface, style)
                    }
                }

                textPaint.typeface = typeface
                typefaces.add(typeface)
                fontFamilyReverse[info] = typefaces.lastIndex
                return@nLineBreak typefaces.lastIndex
            }, { idx ->
                textPaint.typeface = typefaces[idx]
            }
        )
    }

    fun toCacheArray(): ByteArray? {
        val data = nToByteArray(ptr) ?: return null
        val buf = ByteBuf().writeVarInt(1)
        buf.write(ByteHelper.compress(data))
        return buf.flush()
    }

    fun fromCacheArray(byteArray: ByteArray): Boolean {
        if(byteArray.isEmpty()) return false
        val buf = ByteBuf(byteArray)
        val data = when(buf.readVarInt()) {
            1 -> ByteHelper.decompress(buf.read(buf.readLength))
            else -> buf.read(buf.readLength)
        }
        return nFromByteArray(ptr, data)
    }

    data class TypefaceInfo(val typeface: Typeface, val fontWeight: Int, val italic: Boolean)

    companion object {
        init {
            System.loadLibrary("epublib")
        }

        @JvmStatic
        private external fun fromRootText(container: String, fileToStringHandler: Function<String, String?>, imageHandler: Function<String, IntArray>, parseNow: Boolean): Long
        @JvmStatic
        private external fun release(ptr: Long)
        @JvmStatic
        private external fun getTotalPages(ptr: Long): Int
        @JvmStatic
        private external fun nGetPage(ptr: Long, page: Int, fileToStringHandler: Function<String, String?>, imageHandler: Function<String, IntArray>): Long
        private external fun nGetPageWithoutParse(ptr: Long, page: Int): Long
        @JvmStatic
        private external fun nPagination(ptr: Long, page: Int, viewportWidth: Int, viewportHeight: Int, textPaint: TextPaint, fontScale: Float, density: Float, textSize: Float, letterSpacing: Float, textScaleX: Float, textSkewX: Float, defaultLineHeight: Float, wordBreak: Boolean, fileToStringHandler: Function<String, String?>, imageHandler: Function<String, IntArray>, fontHandler: (String, Int, Boolean) -> Int, fontByIdxHandler: (Int) -> Unit, pageHandler: (ByteArray) -> Unit)
        @JvmStatic
        private external fun nToByteArray(ptr: Long): ByteArray?
        @JvmStatic
        private external fun nFromByteArray(ptr: Long, byteArray: ByteArray): Boolean
        @JvmStatic
        private external fun nLineBreak(epubTextData: ByteArray, viewportWidth: Int, textPaint: TextPaint, fontScale: Float, density: Float, textSize: Float, letterSpacing: Float, textScaleX: Float, textSkewX: Float, defaultLineHeight: Float, wordBreak: Boolean, fontHandler: (String, Int, Boolean) -> Int, fontByIdxHandler: (Int) -> Unit): IntArray
        @JvmStatic
        private external fun nGetCoverImage(ptr: Long): String?
    }
}