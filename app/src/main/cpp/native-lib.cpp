#include <jni.h>
#include <string>

extern "C"
{
JNIEXPORT jstring JNICALL
Java_com_kxl_atu_ndkdemo_MainActivity_stringFromJNI2(JNIEnv *env, jobject instance) {
    // TODO
    return env->NewStringUTF("Hello from C++ TOO");
}

jstring
Java_com_kxl_atu_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
}