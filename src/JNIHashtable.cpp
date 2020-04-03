#include <jni.h>
#include <stdio.h>
#include "JNIHashtable.h"

JNIEXPORT jobject JNICALL Java_JNIHashtable_getHashtable (JNIEnv *env, jobject obj) {
	jclass hashtableClass = env->FindClass("java/util/Hashtable");
    jmethodID init = env->GetMethodID(hashtableClass, "<init>", "()V");
    jobject hashtable = env->NewObject(hashtableClass, init );
    jmethodID put = env->GetMethodID(hashtableClass, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");

	jstring key = env->NewStringUTF("star");
	jstring val = env->NewStringUTF("wars");
    env -> CallObjectMethod(hashtable,put, key, val);
	
	env->DeleteLocalRef(key);
	env->DeleteLocalRef(val);
	env->DeleteLocalRef(hashtableClass);

	return hashtable;
}
