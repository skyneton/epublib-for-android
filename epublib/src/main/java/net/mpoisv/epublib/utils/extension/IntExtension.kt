package net.mpoisv.epublib.utils.extension

import kotlin.math.ceil
import kotlin.math.floor

fun Double.ceilToInt() = ceil(this).toInt()
fun Float.ceilToInt() = ceil(this).toInt()
fun Double.floorToInt() = floor(this).toInt()
fun Float.floorToInt() = floor(this).toInt()

fun Boolean.toInt() = if(this) 1 else 0