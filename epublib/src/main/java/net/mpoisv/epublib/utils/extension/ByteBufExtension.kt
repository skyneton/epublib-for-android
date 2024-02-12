package net.mpoisv.epublib.utils.extension

import net.mpoisv.epublib.utils.ByteBuf
import net.mpoisv.epublib.utils.Color
import net.mpoisv.epublib.utils.FontStyle
import net.mpoisv.epublib.utils.FontWeight
import net.mpoisv.epublib.utils.TextDecoration
import net.mpoisv.epublib.utils.TextUnit

fun ByteBuf.writeTextUnit(value: TextUnit) = apply {
    if(value.isSpecified) writeVarInt(value.isEm.toInt() + 1).writeVarInt(value.value.toBits())
    else writeByte(0)
}

fun ByteBuf.readTextUnit() = run {
    val flag = readByte()
    if(flag == 0)
        TextUnit.Unspecified
    else
        Float.fromBits(readVarInt()).run { TextUnit(this, flag == 2) }
}

fun ByteBuf.writeColor(value: Color) = apply {
    writeBool(value.isSpecified)
    if(value.isSpecified) writeVarInt(value.value.toInt())
}

fun ByteBuf.readColor() = if(readBool()) Color(readVarInt().toUInt()) else Color.Unspecified

fun ByteBuf.writeFontWeight(value: FontWeight?) = writeVarInt(value?.weight ?: 0)
fun ByteBuf.readFontWeight() = readVarInt().run { if(this <= 0) null else FontWeight(this) }

fun ByteBuf.writeTextDecoration(value: TextDecoration) = writeVarInt(value.mask)
fun ByteBuf.readTextDecoration() = run {
    val mask = readVarInt()
    var result = TextDecoration.None
    if((mask and TextDecoration.LineThrough.mask) != 0)
        result = result.plus(TextDecoration.LineThrough)
    if((mask and TextDecoration.Underline.mask) != 0)
        result = result.plus(TextDecoration.Underline)
    result
}

fun ByteBuf.writeFontStyle(value: FontStyle?) = writeBool(FontStyle.Italic == value)
fun ByteBuf.readFontStyle() = if(readBool()) FontStyle.Italic else FontStyle.Normal