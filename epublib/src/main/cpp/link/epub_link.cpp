#include <jni.h>

//
// Created by skyne on 2024-01-01.
//
#include "../epub/Epub.h"
#include "../epub/EpubPagination.h"

extern "C"
JNIEXPORT jlong JNICALL
Java_net_mpoisv_epublib_Epub_fromRootText(JNIEnv *env, jclass clazz, jstring container,
                                                         jobject file_to_string_handler,
                                                         jobject image_handler,
                                                         jboolean parse_now) {
    const jchar* text = env->GetStringCritical(container, nullptr);
    JString containerText = JString(text, env->GetStringLength(container));
    env->ReleaseStringCritical(container, text);

    jclass fileToStringHandlerClazz = env->GetObjectClass(file_to_string_handler);
    jmethodID fileApplyMethodID = env->GetMethodID(fileToStringHandlerClazz, "apply", "(Ljava/lang/Object;)Ljava/lang/Object;");

    jclass imageHandlerClazz = env->GetObjectClass(image_handler);
    jmethodID imageApplyMethodID = env->GetMethodID(imageHandlerClazz, "apply", "(Ljava/lang/Object;)Ljava/lang/Object;");
    long result = reinterpret_cast<long>(new Epub(containerText, [&env, &file_to_string_handler, &fileApplyMethodID](const JString& path) -> JString {
        jstring str = env->NewString(path.begin(), path.size());
        jstring result = static_cast<jstring>(env->CallObjectMethod(file_to_string_handler, fileApplyMethodID, str));
        env->DeleteLocalRef(str);
        if(result == NULL) {
            env->DeleteLocalRef(result);
            return {};
        }
        const jchar* text = env->GetStringCritical(result, nullptr);
        JString fileText = JString(text, env->GetStringLength(result));
        env->ReleaseStringCritical(result, text);
        env->DeleteLocalRef(result);
        return fileText;
    }, [&env, &image_handler, &imageApplyMethodID](const JString& path) -> Array<int> {
        jstring str = env->NewString(path.begin(), path.size());
        jintArray result = static_cast<jintArray>(env->CallObjectMethod(image_handler, imageApplyMethodID, str));
        env->DeleteLocalRef(str);
        jint* jWidthHeight = static_cast<jint*>(env->GetPrimitiveArrayCritical(result, nullptr));
        Array<int> widthHeight = Array<int>(jWidthHeight, env->GetArrayLength(result), true);
        env->ReleasePrimitiveArrayCritical(result, jWidthHeight, 0);
        env->DeleteLocalRef(result);
        return widthHeight;
    }, parse_now));
    env->DeleteLocalRef(fileToStringHandlerClazz);
    env->DeleteLocalRef(imageHandlerClazz);
    return result;
}
extern "C"
JNIEXPORT void JNICALL
Java_net_mpoisv_epublib_Epub_release(JNIEnv *env, jclass clazz, jlong ptr) {
    delete reinterpret_cast<Epub*>(ptr);
}
extern "C"
JNIEXPORT jint JNICALL
Java_net_mpoisv_epublib_Epub_getTotalPages(JNIEnv *env, jclass clazz, jlong ptr) {
    if(ptr == 0) return 0;
    return reinterpret_cast<Epub*>(ptr)->totalPages();
}

extern "C"
JNIEXPORT void JNICALL
Java_net_mpoisv_epublib_Epub_nPagination(JNIEnv *env, jclass clazz, jlong ptr, jint page,
                                                        jint viewport_width, jint viewport_height,
                                                        jobject text_paint,
                                                        jfloat font_scale, jfloat density,
                                                        jfloat text_size, jfloat letter_spacing,
                                                        jfloat text_scale_x, jfloat text_skew_x,
                                                        jfloat default_line_height, jboolean word_break,
                                                        jobject file_to_string_handler,
                                                        jobject image_handler,
                                                        jobject font_handler,
                                                        jobject font_by_idx_handler,
                                                        jobject page_handler) {
    Epub* epub = reinterpret_cast<Epub*>(ptr);
    if(!epub || page < 0 || epub->totalPages() <= page) return;

    jclass fileToStringHandlerClazz = env->GetObjectClass(file_to_string_handler);
    jmethodID fileApplyMethodID = env->GetMethodID(fileToStringHandlerClazz, "apply", "(Ljava/lang/Object;)Ljava/lang/Object;");

    jclass imageHandlerClazz = env->GetObjectClass(image_handler);
    jmethodID imageApplyMethodID = env->GetMethodID(imageHandlerClazz, "apply", "(Ljava/lang/Object;)Ljava/lang/Object;");

    jclass pageHandlerClazz = env->GetObjectClass(page_handler);
    jmethodID pageHandlerMethodID = env->GetMethodID(pageHandlerClazz, "invoke", "(Ljava/lang/Object;)Ljava/lang/Object;");

    const EpubPage *epubPage = epub->getPage(page,
                                             [&env, &file_to_string_handler, &fileApplyMethodID](
                                                     const JString &path) -> JString {
                                                 jstring str = env->NewString(path.begin(),
                                                                              path.size());
                                                 jstring result = static_cast<jstring>(env->CallObjectMethod(
                                                         file_to_string_handler,
                                                         fileApplyMethodID, str));
                                                 env->DeleteLocalRef(str);
                                                 if (result == NULL) {
                                                     env->DeleteLocalRef(result);
                                                     return {};
                                                 }
                                                 const jchar *text = env->GetStringCritical(
                                                         result, nullptr);
                                                 JString fileText = JString(text,
                                                                            env->GetStringLength(
                                                                                    result));
                                                 env->ReleaseStringCritical(result, text);
                                                 env->DeleteLocalRef(result);
                                                 return fileText;
                                             }, [&env, &image_handler, &imageApplyMethodID](
                    const JString &path) -> Array<int> {
                jstring str = env->NewString(path.begin(), path.size());
                jintArray result = static_cast<jintArray>(env->CallObjectMethod(image_handler,
                                                                                imageApplyMethodID,
                                                                                str));
                env->DeleteLocalRef(str);
                jint *jWidthHeight = static_cast<jint *>(env->GetPrimitiveArrayCritical(result,
                                                                                        nullptr));
                Array<int> widthHeight = Array<int>(jWidthHeight, env->GetArrayLength(result),
                                                    true);
                env->ReleasePrimitiveArrayCritical(result, jWidthHeight, 0);
                env->DeleteLocalRef(result);
                return widthHeight;
            });

    if (!epubPage) {
        env->DeleteLocalRef(fileToStringHandlerClazz);
        env->DeleteLocalRef(imageHandlerClazz);
        env->DeleteLocalRef(pageHandlerClazz);
        return;
    }
    auto [remainData, lastKey] = EpubPagination::pagination(env, *epubPage, text_paint, density,
                                                            font_scale, viewport_width,
                                                            viewport_height,
                                                            text_size, letter_spacing,
                                                            text_scale_x, text_skew_x,
                                                            default_line_height, word_break,
                                                            font_handler, font_by_idx_handler,
                                                            [&env, &page_handler, &pageHandlerMethodID](
                                                                    const std::vector<std::shared_ptr<EpubElement>> &list,
                                                                    int key) {
                                                                ByteBuf buf = ByteBuf();
                                                                buf.writeVarInt(
                                                                        key).writeVarInt(
                                                                        list.size());
                                                                for (const std::shared_ptr<EpubElement> &element: list)
                                                                    element->save(buf);
                                                                jbyteArray pagination = env->NewByteArray(
                                                                        buf.getWriteBuffer().size());
                                                                env->SetByteArrayRegion(
                                                                        pagination, 0,
                                                                        buf.getWriteBuffer().size(),
                                                                        reinterpret_cast<const jbyte *>(buf.getWriteBuffer().data()));

                                                                env->DeleteLocalRef(
                                                                        env->CallObjectMethod(
                                                                                page_handler,
                                                                                pageHandlerMethodID,
                                                                                pagination));

                                                                env->DeleteLocalRef(pagination);
                                                            });

    if (!remainData.empty()) {
        ByteBuf buf = ByteBuf();
        buf.writeVarInt(lastKey).writeVarInt(remainData.size());
        for (const std::shared_ptr<EpubElement> &element: remainData)
            element->save(buf);
        jbyteArray pagination = env->NewByteArray(buf.getWriteBuffer().size());
        env->SetByteArrayRegion(pagination, 0, buf.getWriteBuffer().size(),
                                reinterpret_cast<const jbyte *>(buf.getWriteBuffer().data()));

        env->DeleteLocalRef(
                env->CallObjectMethod(page_handler, pageHandlerMethodID, pagination));

        env->DeleteLocalRef(pagination);
    }

    env->DeleteLocalRef(fileToStringHandlerClazz);
    env->DeleteLocalRef(imageHandlerClazz);
    env->DeleteLocalRef(pageHandlerClazz);
}
extern "C"
JNIEXPORT jlong JNICALL
Java_net_mpoisv_epublib_Epub_nGetPage(JNIEnv *env, jclass clazz, jlong ptr,
                                                     jint page, jobject file_to_string_handler,
                                                     jobject image_handler) {
    Epub* epub = reinterpret_cast<Epub*>(ptr);
    if(!epub || page < 0 || epub->totalPages() <= page) return 0;

    jclass fileToStringHandlerClazz = env->GetObjectClass(file_to_string_handler);
    jmethodID fileApplyMethodID = env->GetMethodID(fileToStringHandlerClazz, "apply", "(Ljava/lang/Object;)Ljava/lang/Object;");

    jclass imageHandlerClazz = env->GetObjectClass(image_handler);
    jmethodID imageApplyMethodID = env->GetMethodID(imageHandlerClazz, "apply", "(Ljava/lang/Object;)Ljava/lang/Object;");

    long result = 0;

    const EpubPage *epubPage = epub->getPage(page,
                                             [&env, &file_to_string_handler, &fileApplyMethodID](
                                                     const JString &path) -> JString {
                                                 jstring str = env->NewString(path.begin(),
                                                                              path.size());
                                                 jstring result = static_cast<jstring>(env->CallObjectMethod(
                                                         file_to_string_handler,
                                                         fileApplyMethodID, str));
                                                 env->DeleteLocalRef(str);
                                                 if (result == NULL) {
                                                     env->DeleteLocalRef(result);
                                                     return {};
                                                 }
                                                 const jchar *text = env->GetStringCritical(
                                                         result, nullptr);
                                                 JString fileText = JString(text,
                                                                            env->GetStringLength(
                                                                                    result));
                                                 env->ReleaseStringCritical(result, text);
                                                 env->DeleteLocalRef(result);
                                                 return fileText;
                                             }, [&env, &image_handler, &imageApplyMethodID](
                    const JString &path) -> Array<int> {
                jstring str = env->NewString(path.begin(), path.size());
                jintArray result = static_cast<jintArray>(env->CallObjectMethod(image_handler,
                                                                                imageApplyMethodID,
                                                                                str));
                env->DeleteLocalRef(str);
                jint *jWidthHeight = static_cast<jint *>(env->GetPrimitiveArrayCritical(result,
                                                                                        nullptr));
                Array<int> widthHeight = Array<int>(jWidthHeight, env->GetArrayLength(result),
                                                    true);
                env->ReleasePrimitiveArrayCritical(result, jWidthHeight, 0);
                env->DeleteLocalRef(result);
                return widthHeight;
            });
    result = reinterpret_cast<long>(epubPage);

    env->DeleteLocalRef(fileToStringHandlerClazz);
    env->DeleteLocalRef(imageHandlerClazz);

    return result;
}
extern "C"
JNIEXPORT jbyteArray JNICALL
Java_net_mpoisv_epublib_EpubPage_getEpubPageDocument(JNIEnv *env, jclass clazz,
                                                                    jlong ptr) {
    EpubPage* page = reinterpret_cast<EpubPage*>(ptr);
    if(!page) return NULL;
    ByteBuf buf = ByteBuf();
    buf.writeVarInt(page->getDocument().size());
    for(const std::shared_ptr<EpubElement> element : page->getDocument()) {
        element->save(buf);
    }

    jbyteArray data = env->NewByteArray(buf.getWriteBuffer().size());
    env->SetByteArrayRegion(data, 0, buf.getWriteBuffer().size(),
                            reinterpret_cast<const jbyte *>(buf.getWriteBuffer().data()));
    return data;
}
extern "C"
JNIEXPORT jstring JNICALL
Java_net_mpoisv_epublib_EpubPage_getEpubPageName(JNIEnv *env, jclass clazz,
                                                                jlong ptr) {
    EpubPage* page = reinterpret_cast<EpubPage*>(ptr);
    if(!page) return nullptr;
    return env->NewString(page->getName().begin(), page->getName().size());
}
extern "C"
JNIEXPORT jlong JNICALL
Java_net_mpoisv_epublib_Epub_00024Companion_nGetPageWithoutParse(JNIEnv *env,
                                                                                jobject thiz,
                                                                                jlong ptr,
                                                                                jint page) {
    Epub* epub = reinterpret_cast<Epub*>(ptr);
    if(!epub || page < 0 || epub->totalPages() <= page) return 0;

    long result = 0;

    const EpubPage *epubPage = epub->getPage(page);
    result = reinterpret_cast<long>(epubPage);

    return result;
}
extern "C"
JNIEXPORT jbyteArray JNICALL
Java_net_mpoisv_epublib_Epub_nToByteArray(JNIEnv *env, jclass clazz, jlong ptr) {
    Epub* epub = reinterpret_cast<Epub*>(ptr);
    if(!epub) return NULL;
    ByteBuf buf;
    buf.writeVarInt(0) // version
    .writeVarInt(epub->totalPages());
    Array<EpubPage> pages = epub->getPages();
    for(const EpubPage& page : pages) {
        if(!page.parse()) return NULL;
        buf.writeVarInt(page.getDocument().size());
        for(const std::shared_ptr<EpubElement> element : page.getDocument()) {
            element->save(buf);
        }
    }

    jbyteArray data = env->NewByteArray(buf.getWriteBuffer().size());
    env->SetByteArrayRegion(data, 0, buf.getWriteBuffer().size(),
                            reinterpret_cast<const jbyte *>(buf.getWriteBuffer().data()));
    return data;
}
extern "C"
JNIEXPORT jboolean JNICALL
Java_net_mpoisv_epublib_Epub_nFromByteArray(JNIEnv *env, jclass clazz, jlong ptr,
                                                           jbyteArray byte_array) {
    Epub* epub = reinterpret_cast<Epub*>(ptr);
    if(!epub) return false;

    int len = env->GetArrayLength(byte_array);
    if(len <= 0) return false;
    jbyte* data = static_cast<jbyte*>(env->GetPrimitiveArrayCritical(byte_array, nullptr));
    ByteBuf buf = ByteBuf(reinterpret_cast<const char *>(data), len);
    if(buf.readVarInt() != 0) {
        env->ReleasePrimitiveArrayCritical(byte_array, data, 0);
        return false;
    }
    if(buf.readVarInt() != epub->totalPages()) {
        env->ReleasePrimitiveArrayCritical(byte_array, data, 0);
        return false;
    }
    Array<EpubPage> pages = epub->getPages();
    for(EpubPage& page : pages) {
        int size = buf.readVarInt();
        if(size < 0) {
            env->ReleasePrimitiveArrayCritical(byte_array, data, 0);
            return false;
        }
        Array<std::shared_ptr<EpubElement>> document = Array<std::shared_ptr<EpubElement>>(size);
        for(int i = 0; i < size; i++) {
            *document[i] = loadEpubElement(buf, buf.readVarInt());
        }
        page.setDocument(document);
    }

    env->ReleasePrimitiveArrayCritical(byte_array, data, 0);
    return true;
}

//extern "C"
//JNIEXPORT jintArray JNICALL
//Java_net_mpoisv_epublib_EpubElementText_lineBreak(JNIEnv *env, jclass clazz,
//                                                                 jbyteArray epub_text_data) {
//    char* epubTextData = static_cast<char*>(env->GetPrimitiveArrayCritical(epub_text_data, nullptr));
//    ByteBuf buf = ByteBuf(epubTextData, env->GetArrayLength(epub_text_data));
//    EpubElementText epubElementText = EpubElementText();
//    epubElementText.load(buf);
//    env->ReleasePrimitiveArrayCritical(epub_text_data, epubTextData, 0);
//}
extern "C"
JNIEXPORT jintArray JNICALL
Java_net_mpoisv_epublib_Epub_nLineBreak(JNIEnv *env, jclass clazz,
                                                       jbyteArray epub_text_data,
                                                       jint viewport_width, jobject text_paint,
                                                       jfloat font_scale, jfloat density,
                                                       jfloat text_size, jfloat letter_spacing,
                                                       jfloat text_scale_x, jfloat text_skew_x,
                                                       jfloat default_line_height, jboolean world_break,
                                                       jobject font_handler,
                                                       jobject font_by_idx_handler) {
    jclass textPaintClazz = env->GetObjectClass(text_paint);
    jmethodID measureText = env->GetMethodID(textPaintClazz, "measureText", "([CII)F");

    jclass fontHandlerClazz = env->GetObjectClass(font_handler);
    jmethodID fontMethodID = env->GetMethodID(fontHandlerClazz, "invoke", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");

    jclass fontByIdxHandlerClazz = env->GetObjectClass(font_by_idx_handler);
    jmethodID fontByIdxMethodID = env->GetMethodID(fontByIdxHandlerClazz, "invoke", "(Ljava/lang/Object;)Ljava/lang/Object;");

    jclass integerClazz = env->FindClass("java/lang/Integer");
    jmethodID integerValueOf = env->GetStaticMethodID(integerClazz, "valueOf", "(I)Ljava/lang/Integer;");
    jmethodID integerIntValue = env->GetMethodID(integerClazz, "intValue", "()I");

    jclass booleanClazz = env->FindClass("java/lang/Boolean");
    jmethodID booleanValueOf = env->GetStaticMethodID(booleanClazz, "valueOf", "(Z)Ljava/lang/Boolean;");

    char* epubTextData = static_cast<char*>(env->GetPrimitiveArrayCritical(epub_text_data, nullptr));
    ByteBuf buf = ByteBuf(epubTextData, env->GetArrayLength(epub_text_data));
    buf.readVarInt();
    EpubElementText epubElementText = EpubElementText();
    epubElementText.load(buf);

    env->ReleasePrimitiveArrayCritical(epub_text_data, epubTextData, 0);

    const auto [measure, _] = EpubPagination::measureBreakAnnotatedText(env, density, font_scale, text_paint, measureText,
                                                                        epubElementText.text(),
                                                                        viewport_width, text_size, letter_spacing, text_scale_x, text_skew_x,
                                                                        default_line_height, world_break,
                                                                        nullptr, 0, font_handler, fontMethodID, font_by_idx_handler, fontByIdxMethodID,
                                                                        integerClazz, integerValueOf, integerIntValue, booleanClazz, booleanValueOf);

    Array<int> lineEnd(measure.size());
    auto ptr = lineEnd.begin();
    for(const auto &[end, height] : measure) {
        *(ptr++) = end;
    }

    env->DeleteLocalRef(textPaintClazz);

    env->DeleteLocalRef(fontHandlerClazz);
    env->DeleteLocalRef(fontByIdxHandlerClazz);
    env->DeleteLocalRef(integerClazz);
    env->DeleteLocalRef(booleanClazz);

    auto lineEndJArray = env->NewIntArray(lineEnd.size());
    env->SetIntArrayRegion(lineEndJArray, 0, lineEnd.size(), lineEnd.begin());

    return lineEndJArray;
}
extern "C"
JNIEXPORT jstring JNICALL
Java_net_mpoisv_epublib_Epub_nGetCoverImage(JNIEnv *env, jclass clazz, jlong ptr) {
    Epub* epub = reinterpret_cast<Epub*>(ptr);
    if(!epub) return NULL;
    JString cover = epub->getCover();
    return env->NewString(cover.begin(), cover.size());
}