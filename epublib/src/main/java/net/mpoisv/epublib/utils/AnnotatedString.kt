package net.mpoisv.epublib.utils

class AnnotatedString(val text: String = "", val spanStyles: List<Range<SpanStyle>> = emptyList(), val paragraphStyles: List<Range<ParagraphStyle>> = emptyList()) {
    data class Range<T>(val item: T, val start: Int, val end: Int)
}