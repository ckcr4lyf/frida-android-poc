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
extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_example_fridapoc_MainActivity_someManipulation(JNIEnv *env, jobject thiz,
                                                        jobject instance) {
    int8_t data[] = {0x41, 0x42, 0x43, 0x44};

    jbyteArray myArray = env->NewByteArray(4);
    jbyte* myJybtes = new jbyte[4];
    for (int i = 0; i < 4; i++){
        myJybtes[i] = data[i]; // TODO: Here we could add the value of the class proeprty or such
    }

    env->SetByteArrayRegion(myArray, 0, 4, myJybtes);
    return myArray;
}