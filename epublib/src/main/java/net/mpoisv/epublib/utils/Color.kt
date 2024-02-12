package net.mpoisv.epublib.utils

class Color private constructor(val value: UInt, val isSpecified: Boolean) {

    /**
     * A | R | G | B
     */
    constructor(value: UInt): this(value, true)

    /**
     * r, g, b, a must be in 0 ~ 255
     */
    constructor(r: Int, g: Int, b: Int, a: Int): this((a.toUInt() shl 24) or (r.toUInt() shl 16) or (g.toUInt() shl 8) or (b.toUInt()), true)

    constructor(): this(0U, false)

    val isUnspecified get() = !isSpecified

    override operator fun equals(other: Any?): Boolean {
        return other is Color && other.isSpecified && isSpecified && other.value == value
    }

    override fun hashCode(): Int {
        var result = value.hashCode()
        result = 31 * result + isSpecified.hashCode()
        return result
    }

    companion object {
        val Unspecified = Color()
    }
}