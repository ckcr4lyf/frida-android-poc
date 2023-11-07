#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_fridapoc_MainActivity_stringFromJNI(JNIEnv* env, jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_fridapoc_MainActivity_intFromJNIViaClass(JNIEnv *env, jobject thiz,
                                                          jobject instance) {
    jclass cls = env->FindClass("com/example/fridapoc/ExampleAlpha");
    jfieldID intFieldId = env->GetFieldID(cls, "height", "I");
    return env->GetIntField(instance, intFieldId);
}