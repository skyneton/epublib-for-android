package net.mpoisv.epublib.utils

class TextUnit private constructor(val value: Float, val isEm: Boolean, val isSpecified: Boolean) {
    constructor(): this(-127F, false, false)
    constructor(value: Float, isEm: Boolean): this(value, isEm, true)

    val isSp get() = isSpecified && isEm
    val isUnspecified get() = !isSpecified

    fun toPx(defaultFontSize: Float, density: Float, fontScale: Float): Float {
        if(isUnspecified) return 0F
        if(isEm) return value * defaultFontSize
        return value * density * fontScale
    }

    override operator fun equals(other: Any?): Boolean {
        return other is TextUnit && other.isSpecified && isSpecified && other.isEm == isEm && other.value == value
    }

    override fun hashCode(): Int {
        var result = value.hashCode()
        result = 31 * result + isEm.hashCode()
        result = 31 * result + isSpecified.hashCode()
        return result
    }

    companion object {
        @JvmStatic
        val Unspecified = TextUnit()
    }
}