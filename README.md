# Performance.
[beyond_good_and_evil.epub](https://github.com/skyneton/epublib-for-android/blob/main/assets/beyond_good_and_evil.epub)

![performance](https://raw.githubusercontent.com/skyneton/epublib-for-android/main/assets/performance.png)

# Try It.
[PlayStore](https://play.google.com/store/apps/details?id=net.mpoisv.textreader)
# How to?
```kotlin
val epub = Epub(File(path), cacheDirectory, parseNow = true)
/* parseNow is optional. defult is true. */
```

```kotlin
epub.totalPages // Get total pages
epub.getCoverImage() // Nullable. Get Cover Image.
epub.loadImage(path: String) // Get epub image.
epub.loadTypeface(path: String) // Get epub typeface.

epub.getPage(page: Int) // Nullable. Get page
epub.getPageWithoutParse(page: Int)
/* Nullable. If you use parseNow false and don't want parse during get page, use this. */
epub.pagination(page: Int, viewportWidth: Int, viewportHeight: Int, textPaint: TextPaint, density: Float, fontScale: Float, defaultLineHeight: Float = -1F, wordBreak: Boolean = true, onPage: (EpubPagination) -> Unit)
/*
If you want pagination, use it.
And want calcuate pixel, try density and fontScalue to 1.
If you want like css word-break to break-all, wordBreak set false.
*/

epub.lineBreak(epubElementText: EpubElementText, textPaint: TextPaint, viewportWidth: Int, density: Float, fontScale: Float, defaultLineHeight: Float = -1F, wordBreak: Boolean = true)

epub.fromCacheArray(byteArray: ByteArray)
epub.toCacheArray()
/*
Nullable.
If you want faster next time, try it and use fromCacheArray(byteArray: ByteArray)
*/

epub.close()
```

### TextUnit
pixel = `value * density * fontScale`

### EpubElement
`EpubElementDivider()` divider(hr tag)

`EpubElementImage()` img tag. values src, width, height.
- Try epub.loadImage(src)

`EpubElementText()` text container.
Has AnnotatedString (Not Jetpack Compose AnnotatedString).
- `SpanStyle` has fontFamily, color, fontSize, fontWeight, letterSpacing, textDecoration, fontSize.
- `ParagraphStyle` has lineHeight.

`EpubElementBox()` display-block container. has margin, padding, border, borderRadius, value(EpubElement children)
- `RectTextUnit` has top, right, bottom, left.

