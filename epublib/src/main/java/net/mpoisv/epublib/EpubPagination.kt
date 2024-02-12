package net.mpoisv.epublib

import net.mpoisv.epublib.utils.ByteBuf

class EpubPagination internal constructor(val page: Int, byteArray: ByteArray) {
    val key: Int
    private val data: ByteArray
    val value get() = run {
        val buf = ByteBuf(data)
        val size = buf.readVarInt()
        val list = ArrayList<EpubElement>(size)
        for(i in 0 until size) {
            list.add(loadEpubElement(buf, buf.readVarInt()))
        }
        list.toTypedArray()
    }
    init {
        val buf = ByteBuf(byteArray)
        key = buf.readVarInt()
        data = buf.read(buf.readLength)
    }

    override fun toString(): String {
        return value.contentToString()
    }
}