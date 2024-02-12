package net.mpoisv.epublib.utils

import java.io.ByteArrayOutputStream
import java.util.zip.Deflater
import java.util.zip.Inflater

object ByteHelper {
    @JvmStatic
    fun compress(byteArray: ByteArray): ByteArray {
        if(byteArray.isEmpty()) return byteArray
        val deflater = Deflater(Deflater.DEFAULT_COMPRESSION, true)
        deflater.setInput(byteArray)
        deflater.finish()

        val buf = ByteArray(1024)
        val bos = ByteArrayOutputStream()
        while(!deflater.finished())
            bos.write(buf, 0, deflater.deflate(buf))

        deflater.end()
        val result = bos.toByteArray()
        bos.close()
        return result
    }

    @JvmStatic
    fun decompress(byteArray: ByteArray): ByteArray {
        if(byteArray.isEmpty()) return byteArray
        val inflater = Inflater(true)
        inflater.setInput(byteArray)

        val buf = ByteArray(1024)
        val bos = ByteArrayOutputStream()
        while(!inflater.finished())
            bos.write(buf, 0, inflater.inflate(buf))

        inflater.end()
        val result = bos.toByteArray()
        bos.close()
        return result
    }
}