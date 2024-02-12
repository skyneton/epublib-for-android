package net.mpoisv.epublib

import android.os.Bundle
import android.util.Log
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import net.mpoisv.epublib.ui.theme.EpubLibTheme
import java.io.File
import kotlin.math.max
import kotlin.math.min

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            EpubLibTheme {
                // A surface container using the 'background' color from the theme
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background
                ) {
                    Greeting("Android")
                }
            }
        }

        val file = File(applicationContext.cacheDir, "beyond_good_and_evil.epub")
        file.createNewFile()
        file.writeBytes(resources.assets.open("beyond_good_and_evil.epub").readBytes())
        val epub = Epub(file, applicationContext.cacheDir.absolutePath)


        Log.i("EPUB_TOTAL_PAGES", "${epub.totalPages}")

        var avg = 0.0
        var min = Long.MAX_VALUE
        var max = 0L
        for(i in 0 until 100) {
            val A = System.nanoTime()
            Epub(file, applicationContext.cacheDir.absolutePath).close()
            val B = System.nanoTime()
            val D = B - A
            min = min(min, D)
            max = max(max, D)
            avg += (D.toDouble() - avg) / (i + 1)
        }
        val pages = arrayListOf<String?>().apply {
            for(i in 0 until epub.totalPages) add(epub.getPage(i)!!.name)
        }
        Log.w("PERFORMANCE", """
            Book: ${epub.name}
            TotalPages: ${epub.totalPages}
            CoverImage: ${epub.getCoverImage()?.run { "$width * $height".apply { recycle() } }}
            Pages: $pages
            Cache Size: ${epub.toCacheArray()?.size}
            
            Min: ${min}ns(${min * 1e-6}ms)
            Max: ${max}ns(${max * 1e-6}ms)
            Avg: ${avg}ns(${avg * 1e-6}ms)
            
            Iter: 100
        """.trimIndent())

        epub.close()
    }
}

@Composable
fun Greeting(name: String, modifier: Modifier = Modifier) {
    Text(
        text = "Hello $name!",
        modifier = modifier
    )
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    EpubLibTheme {
        Greeting("Android")
    }
}