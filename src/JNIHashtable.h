#include <jni.h>
#ifndef _Included_JNIHashtable
#define _Included_JNIHashtable
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jobject JNICALL Java_JNIHashtable_getHashtable
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif