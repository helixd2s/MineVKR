// Generated by JavaCPP version 1.5.3: DO NOT EDIT THIS FILE

#define ENABLE_OPENGL_INTEROP
#define WIN32
#define OS_WIN
#define VK_ENABLE_BETA_EXTENSIONS
#define VK_USE_PLATFORM_WIN32_KHR

#ifdef _WIN32
    #define _JAVASOFT_JNI_MD_H_

    #define JNIEXPORT __declspec(dllexport)
    #define JNIIMPORT __declspec(dllimport)
    #define JNICALL __stdcall

    typedef int jint;
    typedef long long jlong;
    typedef signed char jbyte;
#elif defined(__GNUC__) && !defined(__ANDROID__)
    #define _JAVASOFT_JNI_MD_H_

    #define JNIEXPORT __attribute__((visibility("default")))
    #define JNIIMPORT
    #define JNICALL

    typedef int jint;
    typedef long long jlong;
    typedef signed char jbyte;
#endif

#include <jni.h>

#ifdef __ANDROID__
    #include <android/log.h>
#elif defined(__APPLE__) && defined(__OBJC__)
    #include <TargetConditionals.h>
    #include <Foundation/Foundation.h>
#endif

#ifdef __linux__
    #include <malloc.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/sysinfo.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <dlfcn.h>
    #include <link.h>
    #include <pthread.h>
#elif defined(__APPLE__)
    #include <sys/types.h>
    #include <sys/sysctl.h>
    #include <mach/mach_init.h>
    #include <mach/mach_host.h>
    #include <mach/task.h>
    #include <unistd.h>
    #include <dlfcn.h>
    #include <mach-o/dyld.h>
    #include <pthread.h>
#elif defined(_WIN32) && !defined(NO_WINDOWS_H)
    #define NOMINMAX
    #include <windows.h>
    #include <psapi.h>
#endif

#if defined(__ANDROID__) || TARGET_OS_IPHONE
    #define NewWeakGlobalRef(obj) NewGlobalRef(obj)
    #define DeleteWeakGlobalRef(obj) DeleteGlobalRef(obj)
#endif

#include <limits.h>
#include <stddef.h>
#ifndef _WIN32
    #include <stdint.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <exception>
#include <memory>
#include <new>

#define jlong_to_ptr(a) ((void*)(uintptr_t)(a))
#define ptr_to_jlong(a) ((jlong)(uintptr_t)(a))

#if defined(_MSC_VER)
    #define JavaCPP_noinline __declspec(noinline)
    #define JavaCPP_hidden /* hidden by default */
#elif defined(__GNUC__)
    #define JavaCPP_noinline __attribute__((noinline)) __attribute__ ((unused))
    #define JavaCPP_hidden   __attribute__((visibility("hidden"))) __attribute__ ((unused))
#else
    #define JavaCPP_noinline
    #define JavaCPP_hidden
#endif
#if __cplusplus >= 201103L || _MSC_VER >= 1900
    #define JavaCPP_override override
#else
    #define JavaCPP_override
#endif

#include "./include/vkt2/vector.hpp"

static JavaVM* JavaCPP_vm = NULL;
static bool JavaCPP_haveAllocObject = false;
static bool JavaCPP_haveNonvirtual = false;
static const char* JavaCPP_classNames[10] = {
        "org/bytedeco/javacpp/Pointer",
        "java/lang/String",
        "org/bytedeco/javacpp/Pointer$NativeDeallocator",
        "org/bytedeco/javacpp/Loader",
        "java/nio/Buffer",
        "java/lang/Object",
        "java/lang/NullPointerException",
        "org/bytedeco/javacpp/BytePointer",
        "java/lang/RuntimeException",
        "net/fabricmc/minertx/jivix/Vector$ByteVector" };
static jclass JavaCPP_classes[10] = { NULL };
static jfieldID JavaCPP_addressFID = NULL;
static jfieldID JavaCPP_positionFID = NULL;
static jfieldID JavaCPP_limitFID = NULL;
static jfieldID JavaCPP_capacityFID = NULL;
static jfieldID JavaCPP_deallocatorFID = NULL;
static jfieldID JavaCPP_ownerAddressFID = NULL;
static jmethodID JavaCPP_initMID = NULL;
static jmethodID JavaCPP_arrayMID = NULL;
static jmethodID JavaCPP_arrayOffsetMID = NULL;
static jfieldID JavaCPP_bufferPositionFID = NULL;
static jfieldID JavaCPP_bufferLimitFID = NULL;
static jfieldID JavaCPP_bufferCapacityFID = NULL;
static jmethodID JavaCPP_stringMID = NULL;
static jmethodID JavaCPP_getBytesMID = NULL;
static jmethodID JavaCPP_toStringMID = NULL;

static inline void JavaCPP_log(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
#ifdef __ANDROID__
    __android_log_vprint(ANDROID_LOG_ERROR, "javacpp", fmt, ap);
#elif defined(__APPLE__) && defined(__OBJC__)
    NSLogv([NSString stringWithUTF8String:fmt], ap);
#else
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
#endif
    va_end(ap);
}

#ifdef __ANDROID__
    static pthread_key_t JavaCPP_current_env;
    static JavaCPP_noinline void JavaCPP_detach_env(void *data)
    {
        if (JavaCPP_vm) {
            JavaCPP_vm->DetachCurrentThread();
        }
    }
    static JavaCPP_noinline void JavaCPP_create_pthread_key(void)
    {
        pthread_key_create(&JavaCPP_current_env, JavaCPP_detach_env);
    }
#endif

static JavaCPP_noinline jclass JavaCPP_getClass(JNIEnv* env, int i) {
    if (JavaCPP_classes[i] == NULL && env->PushLocalFrame(1) == 0) {
        jclass cls = env->FindClass(JavaCPP_classNames[i]);
        if (cls == NULL || env->ExceptionCheck()) {
            JavaCPP_log("Error loading class %s.", JavaCPP_classNames[i]);
            return NULL;
        }
        JavaCPP_classes[i] = (jclass)env->NewWeakGlobalRef(cls);
        if (JavaCPP_classes[i] == NULL || env->ExceptionCheck()) {
            JavaCPP_log("Error creating global reference of class %s.", JavaCPP_classNames[i]);
            return NULL;
        }
        env->PopLocalFrame(NULL);
    }
    return JavaCPP_classes[i];
}

static JavaCPP_noinline jfieldID JavaCPP_getFieldID(JNIEnv* env, int i, const char* name, const char* sig) {
    jclass cls = JavaCPP_getClass(env, i);
    if (cls == NULL) {
        return NULL;
    }
    jfieldID fid = env->GetFieldID(cls, name, sig);
    if (fid == NULL || env->ExceptionCheck()) {
        JavaCPP_log("Error getting field ID of %s/%s", JavaCPP_classNames[i], name);
        return NULL;
    }
    return fid;
}

static JavaCPP_noinline jmethodID JavaCPP_getMethodID(JNIEnv* env, int i, const char* name, const char* sig) {
    jclass cls = JavaCPP_getClass(env, i);
    if (cls == NULL) {
        return NULL;
    }
    jmethodID mid = env->GetMethodID(cls, name, sig);
    if (mid == NULL || env->ExceptionCheck()) {
        JavaCPP_log("Error getting method ID of %s/%s", JavaCPP_classNames[i], name);
        return NULL;
    }
    return mid;
}

static JavaCPP_noinline jmethodID JavaCPP_getStaticMethodID(JNIEnv* env, int i, const char* name, const char* sig) {
    jclass cls = JavaCPP_getClass(env, i);
    if (cls == NULL) {
        return NULL;
    }
    jmethodID mid = env->GetStaticMethodID(cls, name, sig);
    if (mid == NULL || env->ExceptionCheck()) {
        JavaCPP_log("Error getting static method ID of %s/%s", JavaCPP_classNames[i], name);
        return NULL;
    }
    return mid;
}

static JavaCPP_noinline jobject JavaCPP_createPointer(JNIEnv* env, int i, jclass cls = NULL) {
    if (cls == NULL && (cls = JavaCPP_getClass(env, i)) == NULL) {
        return NULL;
    }
    if (JavaCPP_haveAllocObject) {
        return env->AllocObject(cls);
    } else {
        jmethodID mid = env->GetMethodID(cls, "<init>", "(Lorg/bytedeco/javacpp/Pointer;)V");
        if (mid == NULL || env->ExceptionCheck()) {
            JavaCPP_log("Error getting Pointer constructor of %s, while VM does not support AllocObject()", JavaCPP_classNames[i]);
            return NULL;
        }
        return env->NewObject(cls, mid, NULL);
    }
}

static JavaCPP_noinline void JavaCPP_initPointer(JNIEnv* env, jobject obj, const void* ptr, jlong size, void* owner, void (*deallocator)(void*)) {
    if (owner != NULL && deallocator != NULL) {
        jvalue args[4];
        args[0].j = ptr_to_jlong(ptr);
        args[1].j = size;
        args[2].j = ptr_to_jlong(owner);
        args[3].j = ptr_to_jlong(deallocator);
        if (JavaCPP_haveNonvirtual) {
            env->CallNonvirtualVoidMethodA(obj, JavaCPP_getClass(env, 0), JavaCPP_initMID, args);
        } else {
            env->CallVoidMethodA(obj, JavaCPP_initMID, args);
        }
    } else {
        env->SetLongField(obj, JavaCPP_addressFID, ptr_to_jlong(ptr));
        env->SetLongField(obj, JavaCPP_limitFID, (jlong)size);
        env->SetLongField(obj, JavaCPP_capacityFID, (jlong)size);
    }
}

static JavaCPP_noinline jstring JavaCPP_createString(JNIEnv* env, const char* ptr) {
    if (ptr == NULL) {
        return NULL;
    }
#ifdef MODIFIED_UTF8_STRING
    return env->NewStringUTF(ptr);
#else
    size_t length = strlen(ptr);
    jbyteArray bytes = env->NewByteArray(length < INT_MAX ? length : INT_MAX);
    env->SetByteArrayRegion(bytes, 0, length < INT_MAX ? length : INT_MAX, (signed char*)ptr);
    return (jstring)env->NewObject(JavaCPP_getClass(env, 1), JavaCPP_stringMID, bytes);
#endif
}

class JavaCPP_hidden JavaCPP_exception : public std::exception {
public:
    JavaCPP_exception(const char* str) throw() {
        if (str == NULL) {
            strcpy(msg, "Unknown exception.");
        } else {
            strncpy(msg, str, sizeof(msg));
            msg[sizeof(msg) - 1] = 0;
        }
    }
    virtual const char* what() const throw() { return msg; }
    char msg[1024];
};

#ifndef GENERIC_EXCEPTION_CLASS
#define GENERIC_EXCEPTION_CLASS std::exception
#endif
#ifndef GENERIC_EXCEPTION_TOSTRING
#define GENERIC_EXCEPTION_TOSTRING what()
#endif
static JavaCPP_noinline jthrowable JavaCPP_handleException(JNIEnv* env, int i) {
    jstring str = NULL;
    try {
        throw;
    } catch (GENERIC_EXCEPTION_CLASS& e) {
        str = JavaCPP_createString(env, e.GENERIC_EXCEPTION_TOSTRING);
    } catch (...) {
        str = JavaCPP_createString(env, "Unknown exception.");
    }
    jmethodID mid = JavaCPP_getMethodID(env, i, "<init>", "(Ljava/lang/String;)V");
    if (mid == NULL) {
        return NULL;
    }
    return (jthrowable)env->NewObject(JavaCPP_getClass(env, i), mid, str);
}




static void JavaCPP_net_fabricmc_minertx_jivix_Vector_00024ByteVector_deallocate(void *p) { delete (::vkt::Vector<int8_t>*)p; }

static const char* JavaCPP_members[10][2] = {
        { NULL },
        { NULL },
        { NULL },
        { NULL },
        { NULL },
        { NULL },
        { NULL },
        { NULL },
        { NULL },
        { "sizeof" } };
static int JavaCPP_offsets[10][2] = {
        { -1 },
        { -1 },
        { -1 },
        { -1 },
        { -1 },
        { -1 },
        { -1 },
        { -1 },
        { -1 },
        { sizeof(::vkt::Vector<int8_t>) } };
static int JavaCPP_memberOffsetSizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

extern "C" {

JNIEXPORT jint JNICALL JNI_OnLoad_jnijavacpp(JavaVM* vm, void* reserved);
JNIEXPORT void JNICALL JNI_OnUnload_jnijavacpp(JavaVM* vm, void* reserved);

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    if (JNI_OnLoad_jnijavacpp(vm, reserved) == JNI_ERR) {
        return JNI_ERR;
    }
    JNIEnv* env;
    if (vm->GetEnv((void**)&env, JNI_VERSION_1_6) != JNI_OK) {
        JavaCPP_log("Could not get JNIEnv for JNI_VERSION_1_6 inside JNI_OnLoad().");
        return JNI_ERR;
    }
    if (JavaCPP_vm == vm) {
        return env->GetVersion();
    }
    JavaCPP_vm = vm;
    JavaCPP_haveAllocObject = env->functions->AllocObject != NULL;
    JavaCPP_haveNonvirtual = env->functions->CallNonvirtualVoidMethodA != NULL;
    jmethodID putMemberOffsetMID = JavaCPP_getStaticMethodID(env, 3, "putMemberOffset", "(Ljava/lang/String;Ljava/lang/String;I)Ljava/lang/Class;");
    if (putMemberOffsetMID == NULL) {
        return JNI_ERR;
    }
    for (int i = 0; i < 10 && !env->ExceptionCheck(); i++) {
        for (int j = 0; j < JavaCPP_memberOffsetSizes[i] && !env->ExceptionCheck(); j++) {
            if (env->PushLocalFrame(3) == 0) {
                jvalue args[3];
                args[0].l = env->NewStringUTF(JavaCPP_classNames[i]);
                args[1].l = JavaCPP_members[i][j] == NULL ? NULL : env->NewStringUTF(JavaCPP_members[i][j]);
                args[2].i = JavaCPP_offsets[i][j];
                jclass cls = (jclass)env->CallStaticObjectMethodA(JavaCPP_getClass(env, 3), putMemberOffsetMID, args);
                if (env->ExceptionCheck()) {
                    JavaCPP_log("Error putting member offsets for class %s.", JavaCPP_classNames[i]);
                    return JNI_ERR;
                }
                JavaCPP_classes[i] = cls == NULL ? NULL : (jclass)env->NewWeakGlobalRef(cls);
                if (env->ExceptionCheck()) {
                    JavaCPP_log("Error creating global reference of class %s.", JavaCPP_classNames[i]);
                    return JNI_ERR;
                }
                env->PopLocalFrame(NULL);
            }
        }
    }
    JavaCPP_addressFID = JavaCPP_getFieldID(env, 0, "address", "J");
    if (JavaCPP_addressFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_positionFID = JavaCPP_getFieldID(env, 0, "position", "J");
    if (JavaCPP_positionFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_limitFID = JavaCPP_getFieldID(env, 0, "limit", "J");
    if (JavaCPP_limitFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_capacityFID = JavaCPP_getFieldID(env, 0, "capacity", "J");
    if (JavaCPP_capacityFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_deallocatorFID = JavaCPP_getFieldID(env, 0, "deallocator", "Lorg/bytedeco/javacpp/Pointer$Deallocator;");
    if (JavaCPP_deallocatorFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_ownerAddressFID = JavaCPP_getFieldID(env, 2, "ownerAddress", "J");
    if (JavaCPP_ownerAddressFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_initMID = JavaCPP_getMethodID(env, 0, "init", "(JJJJ)V");
    if (JavaCPP_initMID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_arrayMID = JavaCPP_getMethodID(env, 4, "array", "()Ljava/lang/Object;");
    if (JavaCPP_arrayMID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_arrayOffsetMID = JavaCPP_getMethodID(env, 4, "arrayOffset", "()I");
    if (JavaCPP_arrayOffsetMID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_bufferPositionFID = JavaCPP_getFieldID(env, 4, "position", "I");
    if (JavaCPP_bufferPositionFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_bufferLimitFID = JavaCPP_getFieldID(env, 4, "limit", "I");
    if (JavaCPP_bufferLimitFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_bufferCapacityFID = JavaCPP_getFieldID(env, 4, "capacity", "I");
    if (JavaCPP_bufferCapacityFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_stringMID = JavaCPP_getMethodID(env, 1, "<init>", "([B)V");
    if (JavaCPP_stringMID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_getBytesMID = JavaCPP_getMethodID(env, 1, "getBytes", "()[B");
    if (JavaCPP_getBytesMID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_toStringMID = JavaCPP_getMethodID(env, 5, "toString", "()Ljava/lang/String;");
    if (JavaCPP_toStringMID == NULL) {
        return JNI_ERR;
    }
    return env->GetVersion();
}


JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved) {
    JNIEnv* env;
    if (vm->GetEnv((void**)&env, JNI_VERSION_1_6) != JNI_OK) {
        JavaCPP_log("Could not get JNIEnv for JNI_VERSION_1_6 inside JNI_OnUnLoad().");
        return;
    }
    for (int i = 0; i < 10; i++) {
        env->DeleteWeakGlobalRef((jweak)JavaCPP_classes[i]);
        JavaCPP_classes[i] = NULL;
    }
    JNI_OnUnload_jnijavacpp(vm, reserved);
    JavaCPP_vm = NULL;
}

JNIEXPORT jobject JNICALL Java_net_fabricmc_minertx_jivix_Vector_00024ByteVector_get(JNIEnv* env, jobject obj, jlong arg0) {
    ::vkt::Vector<int8_t>* ptr = (::vkt::Vector<int8_t>*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return 0;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    jobject rarg = NULL;
    signed char* rptr;
    jthrowable exc = NULL;
    try {
        rptr = &ptr->operator[](arg0);
        if (rptr != NULL) {
            rarg = JavaCPP_createPointer(env, 7);
            if (rarg != NULL) {
                env->SetLongField(rarg, JavaCPP_addressFID, ptr_to_jlong(rptr));
            }
        }
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
    return rarg;
}
JNIEXPORT jobject JNICALL Java_net_fabricmc_minertx_jivix_Vector_00024ByteVector_put(JNIEnv* env, jobject obj, jobject arg0) {
    ::vkt::Vector<int8_t>* ptr = (::vkt::Vector<int8_t>*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return 0;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    ::vkt::Vector<int8_t>* ptr0 = arg0 == NULL ? NULL : (::vkt::Vector<int8_t>*)jlong_to_ptr(env->GetLongField(arg0, JavaCPP_addressFID));
    if (ptr0 == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "Pointer address of argument 0 is NULL.");
        return 0;
    }
    jlong position0 = arg0 == NULL ? 0 : env->GetLongField(arg0, JavaCPP_positionFID);
    ptr0 += position0;
    jobject rarg = NULL;
    ::vkt::Vector<int8_t>* rptr;
    jthrowable exc = NULL;
    try {
        rptr = &((*ptr)=(*ptr0));
        if (rptr == ptr) {
            rarg = obj;
        } else if (rptr != NULL) {
            rarg = JavaCPP_createPointer(env, 9);
            if (rarg != NULL) {
                env->SetLongField(rarg, JavaCPP_addressFID, ptr_to_jlong(rptr));
            }
        }
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
    return rarg;
}
JNIEXPORT jlong JNICALL Java_net_fabricmc_minertx_jivix_Vector_00024ByteVector_size(JNIEnv* env, jobject obj) {
    ::vkt::Vector<int8_t>* ptr = (::vkt::Vector<int8_t>*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return 0;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    jlong rarg = 0;
    jthrowable exc = NULL;
    try {
        jlong rval = ptr->size();
        rarg = (jlong)rval;
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
    return rarg;
}
JNIEXPORT jobject JNICALL Java_net_fabricmc_minertx_jivix_Vector_00024ByteVector_map(JNIEnv* env, jobject obj) {
    ::vkt::Vector<int8_t>* ptr = (::vkt::Vector<int8_t>*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return 0;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    jobject rarg = NULL;
    signed char* rptr;
    jthrowable exc = NULL;
    try {
        rptr = ptr->map();
        if (rptr != NULL) {
            rarg = JavaCPP_createPointer(env, 7);
            if (rarg != NULL) {
                env->SetLongField(rarg, JavaCPP_addressFID, ptr_to_jlong(rptr));
            }
        }
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
    return rarg;
}
JNIEXPORT jobject JNICALL Java_net_fabricmc_minertx_jivix_Vector_00024ByteVector_at(JNIEnv* env, jobject obj, jlong arg0) {
    ::vkt::Vector<int8_t>* ptr = (::vkt::Vector<int8_t>*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return 0;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    jobject rarg = NULL;
    signed char* rptr;
    jthrowable exc = NULL;
    try {
        rptr = &ptr->at(arg0);
        if (rptr != NULL) {
            rarg = JavaCPP_createPointer(env, 7);
            if (rarg != NULL) {
                env->SetLongField(rarg, JavaCPP_addressFID, ptr_to_jlong(rptr));
            }
        }
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
    return rarg;
}
JNIEXPORT void JNICALL Java_net_fabricmc_minertx_jivix_Vector_00024ByteVector_allocate(JNIEnv* env, jobject obj) {
    jthrowable exc = NULL;
    try {
        ::vkt::Vector<int8_t>* rptr = new ::vkt::Vector<int8_t>();
        jlong rcapacity = 1;
        JavaCPP_initPointer(env, obj, rptr, rcapacity, rptr, &JavaCPP_net_fabricmc_minertx_jivix_Vector_00024ByteVector_deallocate);
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
}
JNIEXPORT jlong JNICALL Java_net_fabricmc_minertx_jivix_Vector_00024ByteVector_range(JNIEnv* env, jobject obj) {
    ::vkt::Vector<int8_t>* ptr = (::vkt::Vector<int8_t>*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return 0;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    jlong rarg = 0;
    jthrowable exc = NULL;
    try {
        jlong rval = ptr->range();
        rarg = (jlong)rval;
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
    return rarg;
}
JNIEXPORT jobject JNICALL Java_net_fabricmc_minertx_jivix_Vector_00024ByteVector_mapped(JNIEnv* env, jobject obj) {
    ::vkt::Vector<int8_t>* ptr = (::vkt::Vector<int8_t>*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return 0;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    jobject rarg = NULL;
    signed char* rptr;
    jthrowable exc = NULL;
    try {
        rptr = ptr->mapped();
        if (rptr != NULL) {
            rarg = JavaCPP_createPointer(env, 7);
            if (rarg != NULL) {
                env->SetLongField(rarg, JavaCPP_addressFID, ptr_to_jlong(rptr));
            }
        }
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
    return rarg;
}


}

