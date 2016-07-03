//
// Created by Lionel on 2016/7/3.
//
#include <jni.h>
#include <stdio.h>
#include <cassert>
#include "egame_proxy.h"

static jstring getIpAddress(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF("192.168.100000");
}


#define JNIREG_CLASS "android/example/com/jnidemo1/EgameProxyManager"

static JNINativeMethod gMethods[] = {
/* name, signature, funcPtr */
        { "getProxyIp", "()Ljava/lang/String;", (void*) getIpAddress } };

/*
 * Register several native methods for one class.
 */
static int registerNativeMethods(JNIEnv* env, const char* className,
                                 JNINativeMethod* gMethods, int numMethods) {
    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }

    return JNI_TRUE;
}

/*
 * Register native methods for all classes we know about.
 */
static int registerNatives(JNIEnv* env) {
    if (!registerNativeMethods(env, JNIREG_CLASS, gMethods,
                               sizeof(gMethods) / sizeof(gMethods[0])))
        return JNI_FALSE;

    return JNI_TRUE;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env = NULL;
    jint result = -1;

    if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    assert(env != NULL);

    if (!registerNatives(env)) { //注册
        return -1;
    }
    /* success -- return valid version number */
    result = JNI_VERSION_1_4;

    return result;
}

