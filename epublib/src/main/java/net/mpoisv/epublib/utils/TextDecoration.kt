package net.mpoisv.epublib.utils

data class TextDecoration internal constructor(val mask: Int) {
    operator fun plus(decoration: TextDecoration) = TextDecoration(mask or decoration.mask)
    operator fun contains(other: TextDecoration) = mask and other.mask != 0

    companion object {
        @JvmStatic
        val None = TextDecoration(0x0)
        @JvmStatic
        val Underline = TextDecoration(0x1)
        @JvmStatic
        val LineThrough = TextDecoration(0x2)
    }
}