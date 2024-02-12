package net.mpoisv.epublib.utils

data class FontStyle(val value: Int) {
    companion object {
        val Normal = FontStyle(0)
        val Italic = FontStyle(1)
    }
}