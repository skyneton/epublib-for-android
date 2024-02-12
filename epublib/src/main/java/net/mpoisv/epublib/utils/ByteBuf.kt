package net.mpoisv.epublib.utils

import java.io.ByteArrayOutputStream
import java.io.IOException

class ByteBuf(private val readBuffer: ByteArray? = null): AutoCloseable {
    var position: Int = 0
    val readBufferLength: Int get() = readBuffer?.size ?: 0
    val readLength get() = readBufferLength - position
    private var _writeBuffer: ByteArrayOutputStream? = null

    private val writeBuffer get(): ByteArrayOutputStream {
        if(_writeBuffer == null)
            _writeBuffer = ByteArrayOutputStream()

        return _writeBuffer!!
    }

    val writeLength: Int get() = writeBuffer.size()

    fun read(count: Int) : ByteArray {
        val array = ByteArray(count)
        for (i in 0 until count)
            array[i] = readByte().toUByte().toByte()

        return array
    }

    fun peek(count: Int): ByteArray {
        val array = ByteArray(count)
        var tempPosition = position
        for (i in 0 until count)
            array[i] = readBuffer!![tempPosition++].toUByte().toByte()

        return array
    }

    fun readByte(): Int = readBuffer!![position++].toInt()

    fun readVarInt() : Int {
        var value = 0
        var byteLength = 0
        var byte: Int
        while(readByte().apply { byte = this }.and(0x80) == 0x80) {
            value = value.or(byte.and(0x7F).shl(byteLength++ * 7))
            if(byteLength > 5) throw IOException("VarInt too long.")
        }
        return value.or(byte.and(0x7F).shl(byteLength * 7))
    }

    fun readVarLong() : Long {
        var value = 0L
        var byteLength = 0
        var byte: Int
        while(readByte().apply { byte = this }.and(0x80) == 0x80) {
            value = value.or(byte.toLong().and(0x7F).shl(byteLength++ * 7))
            if(byteLength > 10) throw IOException("VarLong too long.")
        }
        return value.or(byte.toLong().and(0x7F).shl(byteLength * 7))
    }

    fun readString() : String = String(read(readVarInt()), Charsets.UTF_8)

    fun readByteArray(): ByteArray {
        return read(readVarInt())
    }

    fun readBool() = readByte() != 0

    fun readShort(): Short = ((readByte().toUByte().toInt() shl 8) or readByte().toUByte().toInt()).toShort()

    fun readInt(): Int = (readByte().toUByte().toInt() shl 24) or (readByte().toUByte().toInt() shl 16) or (readByte().toUByte().toInt() shl 8) or readByte().toUByte().toInt()

    fun writeByte(byte: Byte): ByteBuf {
        writeBuffer.write(byte.toUByte().toInt())
        return this
    }

    fun writeVarInt(integer: Int): ByteBuf {
        var int = integer.toUInt()
        var size = 0
        while(int.and((-128).toUInt()) != 0U) {
            writeBuffer.write(int.and(127U).or(128U).toUByte().toInt())
            int = int.shr(7)
            size++
        }

        writeBuffer.write(int.toUByte().toInt())
        return this
    }

    fun writeVarLong(integer: Long): ByteBuf {
        var long = integer.toULong()
        while(long.and((-128).toULong()) != 0UL) {
            writeBuffer.write(long.and(127U).or(128U).toUByte().toInt())
            long = long.shr(7)
        }

        writeBuffer.write(long.toUByte().toInt())
        return this
    }

    fun writeString(string: String) = writeByteArray(string.toByteArray(Charsets.UTF_8))

    fun writeByteArray(array: ByteArray): ByteBuf {
        writeVarInt(array.size)
        writeBuffer.write(array)
        return this
    }

    fun writeBool(bool: Boolean) = writeByte(if(bool) 1 else 0)

    fun write(array: ByteArray): ByteBuf {
        writeBuffer.write(array)
        return this
    }

    fun writeShort(short: Short): ByteBuf {
        writeBuffer.write((short.toUInt() shr 8).toUByte().toInt())
        writeBuffer.write(short.toUByte().toInt())
        return this
    }

    fun writeInt(int: Int): ByteBuf {
        writeBuffer.write((int shr 24).toUByte().toInt())
        writeBuffer.write((int shr 16).toUByte().toInt())
        writeBuffer.write((int shr 8).toUByte().toInt())
        writeBuffer.write(int.toUByte().toInt())
        return this
    }

    fun flush(): ByteArray {
        val out = writeBuffer.toByteArray()
        writeBuffer.close()
        return out
    }

    override fun close() {
        if(_writeBuffer != null) {
            _writeBuffer!!.close()
            _writeBuffer = null
        }
    }

    fun writeAllBytes() = writeBuffer.toByteArray()

    fun flushWithLength() : ByteArray {
        val bos = ByteArrayOutputStream()
        writeVarInt(bos, writeBuffer.size())
        bos.write(writeBuffer.toByteArray())
        val out = bos.toByteArray()
        bos.close()
        writeBuffer.close()
        return out
    }

    override fun toString() = writeBuffer.toByteArray().map { b -> b.toInt().toChar() }.joinToString("")

    companion object {
        @JvmStatic
        fun readVarInt(data: ByteArray): IntArray {
            var value = 0
            var byteLength = 0
            var byte: Int
            while(data[byteLength].toInt().apply { byte = this }.and(0x80) == 0x80) {
                value = value.or(byte.and(0x7F).shl(byteLength++ * 7))
                if(byteLength > 5) throw IOException("VarInt too long.")
            }
            return intArrayOf(value.or(byte.and(0x7F).shl(byteLength * 7)), byteLength + 1)
        }

        @JvmStatic
        fun writeVarInt(bos: ByteArrayOutputStream, integer: Int) {
            var int = integer.toUInt()
            while(int.and((-128).toUInt()) != 0U) {
                bos.write(int.and(127U).or(128U).toUByte().toInt())
                int = int.shr(7)
            }

            bos.write(int.toUByte().toInt())
        }

        @JvmStatic
        fun getVarInt(integer: Int): List<Byte> {
            val list = ArrayList<Byte>()
            var int = integer.toUInt()
            while(int.and((-128).toUInt()) != 0U) {
                list.add(int.and(127U).or(128U).toByte())
                int = int.shr(7)
            }

            list.add(int.toByte())
            return list
        }
    }
}