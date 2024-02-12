package net.mpoisv.epublib

import net.mpoisv.epublib.utils.ByteBuf

class EpubPage internal constructor(val epub: Epub, private val ptr: Long) {
    val name get() = if(epub.isAlive) getEpubPageName(ptr) else null

    val rawDocument get() = run { if(epub.isAlive) getEpubPageDocument(ptr) else null }
    val document get() = run {
        if(!epub.isAlive) return@run null
        val doc = getEpubPageDocument(ptr) ?: return@run null
        val buf = ByteBuf(doc)
        val size = buf.readVarInt()
        val list = ArrayList<EpubElement>(size)
        for(i in 0 until size)
            list.add(loadEpubElement(buf, buf.readVarInt()))
        list.toTypedArray()
    }

    override fun toString(): String {
        val doc = document ?: return "null"
        return doc.contentToString()
    }

    companion object {
        @JvmStatic
        private external fun getEpubPageName(ptr: Long): String?
        @JvmStatic
        private external fun getEpubPageDocument(ptr: Long): ByteArray?
    }
}