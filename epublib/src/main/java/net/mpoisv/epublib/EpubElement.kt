package net.mpoisv.epublib

import net.mpoisv.epublib.utils.AnnotatedString
import net.mpoisv.epublib.utils.ByteBuf
import net.mpoisv.epublib.utils.ParagraphStyle
import net.mpoisv.epublib.utils.SpanStyle
import net.mpoisv.epublib.utils.TextUnit
import net.mpoisv.epublib.utils.extension.readColor
import net.mpoisv.epublib.utils.extension.readFontStyle
import net.mpoisv.epublib.utils.extension.readFontWeight
import net.mpoisv.epublib.utils.extension.readTextDecoration
import net.mpoisv.epublib.utils.extension.readTextUnit
import net.mpoisv.epublib.utils.extension.writeColor
import net.mpoisv.epublib.utils.extension.writeFontStyle
import net.mpoisv.epublib.utils.extension.writeFontWeight
import net.mpoisv.epublib.utils.extension.writeTextDecoration
import net.mpoisv.epublib.utils.extension.writeTextUnit

private enum class EpubElementData {
    EpubElementDivider,
    EpubElementImage,
    EpubElementText,
    EpubElementBox
}

open class EpubElement {
    open fun save(buf: ByteBuf) {}
    open fun load(buf: ByteBuf) = this
}
class EpubElementDivider: EpubElement() {
    override fun save(buf: ByteBuf) {
        buf.writeVarInt(EpubElementData.EpubElementDivider.ordinal)
    }
    override fun load(buf: ByteBuf) = this

    override fun toString(): String {
        return "Divider()"
    }
}

class EpubElementImage(src: String = "", width: Int = 0, height: Int = 0): EpubElement() {
    private var _src: String = src
    private var _width: Int = width
    private var _height: Int = height
    val src get() = _src
    val width get() = _width
    val height get() = _height

    override fun save(buf: ByteBuf) {
        buf.writeVarInt(EpubElementData.EpubElementImage.ordinal)
            .writeString(_src).writeVarInt(_width).writeVarInt(_height)
    }

    override fun load(buf: ByteBuf): EpubElementImage {
        _src = buf.readString()
        _width = buf.readVarInt()
        _height = buf.readVarInt()
        return this
    }

    override fun toString(): String {
        return "Image(src=$_src, width=$_width, height=$_height)"
    }
}

class EpubElementText(value: AnnotatedString = AnnotatedString()): EpubElement() {
    private var _value: AnnotatedString = value
    val value get() = _value

    override fun save(buf: ByteBuf) {
        buf.writeVarInt(EpubElementData.EpubElementText.ordinal)
            .writeString(_value.text)
            .writeVarInt(_value.paragraphStyles.size)
        for(para in _value.paragraphStyles) {
            buf.writeVarInt(para.start).writeVarInt(para.end)
                .writeTextUnit(para.item.lineHeight)
        }
        buf.writeVarInt(_value.spanStyles.size)
        for(span in _value.spanStyles) {
            buf.writeVarInt(span.start).writeVarInt(span.end)
                .writeString(span.item.fontFamily)
                .writeColor(span.item.color)
                .writeTextUnit(span.item.fontSize)
                .writeFontWeight(span.item.fontWeight)
                .writeTextUnit(span.item.letterSpacing)
                .writeTextDecoration(span.item.textDecoration)
                .writeFontStyle(span.item.fontStyle)
        }
    }

    override fun load(buf: ByteBuf): EpubElementText {
        val text = buf.readString()
        var size = buf.readVarInt()
        val para = ArrayList<AnnotatedString.Range<ParagraphStyle>>(size)
        for(i in 0 until size) {
            val start = buf.readVarInt()
            val end = buf.readVarInt()
            para.add(AnnotatedString.Range(ParagraphStyle(lineHeight = buf.readTextUnit()), start, end))
        }
        size = buf.readVarInt()
        val span = ArrayList<AnnotatedString.Range<SpanStyle>>(size)
        for(i in 0 until size) {
            val start = buf.readVarInt()
            val end = buf.readVarInt()
            val fontFamily = buf.readString()
            val color = buf.readColor()
            val fontSize = buf.readTextUnit()
            val fontWeight = buf.readFontWeight()
            val letterSpacing = buf.readTextUnit()
            val textDecoration = buf.readTextDecoration()
            val fontStyle = buf.readFontStyle()
            span.add(
                AnnotatedString.Range(
                    SpanStyle(
                        fontFamily = fontFamily,
                        color = color,
                        fontSize = fontSize,
                        fontWeight = fontWeight,
                        letterSpacing = letterSpacing,
                        textDecoration = textDecoration,
                        fontStyle = fontStyle
                    ), start, end
                )
            )
        }
        _value = AnnotatedString(text, span.toList(), para.toList())
        return this
    }

    override fun toString(): String {
        return _value.toString()
    }
}

class EpubElementBox(value: Array<EpubElement> = emptyArray(),
                     margin: RectTextUnit = RectTextUnit(),
                     padding: RectTextUnit = RectTextUnit(),
                     border: RectTextUnit = RectTextUnit(),
                     borderRadius: RectTextUnit = RectTextUnit()
): EpubElement() {
    private var _value: Array<EpubElement> = value
    private var _margin: RectTextUnit = margin
    private var _padding: RectTextUnit = padding
    private var _border: RectTextUnit = border
    private var _borderRadius: RectTextUnit = borderRadius
    val value get() = _value
    val margin get() = _margin
    val padding get() = _padding
    val border get() = _border
    val borderRadius get() = _borderRadius
    override fun toString(): String {
        val builder = StringBuilder("Box(margin=$margin, padding=$padding, border=$border, border-radius=$borderRadius) {")
        for(item in value) {
            builder.appendLine().append(item)
        }
        builder.append('}')
        return builder.toString()
    }

    override fun save(buf: ByteBuf) {
        buf.writeVarInt(EpubElementData.EpubElementBox.ordinal)
        _margin.save(buf)
        _padding.save(buf)
        _border.save(buf)
        _borderRadius.save(buf)
        buf.writeVarInt(_value.size)
        for(item in _value) item.save(buf)
    }

    override fun load(buf: ByteBuf): EpubElementBox {
        _margin.load(buf)
        _padding.load(buf)
        _border.load(buf)
        _borderRadius.load(buf)
        val size = buf.readVarInt()
        val list = ArrayList<EpubElement>()
        for(i in 0 until size)
            list.add(loadEpubElement(buf, buf.readVarInt()))

        _value = list.toTypedArray()
        return this
    }
}

fun loadEpubElement(buf: ByteBuf, id: Int): EpubElement {
    return when(id) {
        EpubElementData.EpubElementDivider.ordinal -> EpubElementDivider().load(buf)
        EpubElementData.EpubElementImage.ordinal -> EpubElementImage().load(buf)
        EpubElementData.EpubElementText.ordinal -> EpubElementText().load(buf)
        EpubElementData.EpubElementBox.ordinal -> EpubElementBox().load(buf)
        else -> EpubElement()
    }
}

class RectTextUnit(top: TextUnit = TextUnit.Unspecified, right: TextUnit = TextUnit.Unspecified, bottom: TextUnit = TextUnit.Unspecified, left: TextUnit = TextUnit.Unspecified) {
    private var _top: TextUnit = top
    private var _right: TextUnit = right
    private var _bottom: TextUnit = bottom
    private var _left: TextUnit = left
    val top get() = _top
    val right get() = _right
    val bottom get() = _bottom
    val left get() = _left

    fun copy(top: TextUnit = _top, right: TextUnit = _right, bottom: TextUnit = _bottom, left: TextUnit = _left) = RectTextUnit(top, right, bottom, left)
    override fun toString(): String {
        return "RectTextUnit(top=$top, right=$right, bottom=$bottom, left=$left)"
    }

    fun horizontalPx(fontSize: Float, density: Float, fontScale: Float) = _left.toPx(fontSize, density, fontScale) + _right.toPx(fontSize, density, fontScale)

    fun save(buf: ByteBuf) {
        buf.writeTextUnit(_top).writeTextUnit(_right).writeTextUnit(_bottom).writeTextUnit(_left)
    }

    fun load(buf: ByteBuf): RectTextUnit {
        _top = buf.readTextUnit()
        _right = buf.readTextUnit()
        _bottom = buf.readTextUnit()
        _left = buf.readTextUnit()
        return this
    }
}