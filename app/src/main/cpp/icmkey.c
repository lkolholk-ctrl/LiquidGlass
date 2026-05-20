#include <jni.h>
#include <string.h>
#include <android/log.h>
#include <unistd.h>
#include <stdio.h>

#define LOG_TAG "IcmKey"
#define JNI_HIDDEN __attribute__((visibility("hidden")))

// Original release SHA-256 (colons removed, lowercase)
static const char *ORIGINAL_SIGNATURE = "950344288c8c1ef3f321c53744bf83437aa60431e3483c013c68c7e872bdf527";

// Deobfuscator using volatile math to prevent the compiler from creating static strings in the .so
JNI_HIDDEN void get_k(char *out) {
    volatile int v = 0x5;
    int i = 0;
    out[i++] = (char)('p' + v - 5); out[i++] = (char)('k' + v - 5); out[i++] = (char)('_' + v - 5);
    out[i++] = (char)('m' + v - 5); out[i++] = (char)('s' + v - 5); out[i++] = (char)('n' + v - 5);
    out[i++] = (char)('g' + v - 5); out[i++] = (char)('_' + v - 5); out[i++] = (char)('S' + v - 5);
    out[i++] = (char)('a' + v - 5); out[i++] = (char)('b' + v - 5); out[i++] = (char)('C' + v - 5);
    out[i++] = (char)('h' + v - 5); out[i++] = (char)('r' + v - 5); out[i++] = (char)('8' + v - 5);
    out[i++] = (char)('h' + v - 5); out[i++] = (char)('0' + v - 5); out[i++] = (char)('_' + v - 5);
    out[i++] = (char)('N' + v - 5); out[i++] = (char)('d' + v - 5); out[i++] = (char)('X' + v - 5);
    out[i++] = (char)('X' + v - 5); out[i++] = (char)('-' + v - 5); out[i++] = (char)('W' + v - 5);
    out[i++] = (char)('1' + v - 5); out[i++] = (char)('T' + v - 5); out[i++] = (char)('l' + v - 5);
    out[i++] = (char)('C' + v - 5); out[i++] = (char)('9' + v - 5); out[i++] = (char)('H' + v - 5);
    out[i++] = (char)('c' + v - 5); out[i++] = (char)('r' + v - 5); out[i++] = (char)('g' + v - 5);
    out[i++] = (char)('X' + v - 5); out[i++] = (char)('F' + v - 5); out[i++] = (char)('0' + v - 5);
    out[i++] = (char)('_' + v - 5); out[i++] = (char)('9' + v - 5); out[i++] = (char)('T' + v - 5);
    out[i++] = (char)('0' + v - 5); out[i++] = (char)('M' + v - 5); out[i++] = (char)('S' + v - 5);
    out[i++] = (char)('M' + v - 5); out[i++] = (char)('p' + v - 5); out[i++] = (char)('4' + v - 5);
    out[i++] = (char)('c' + v - 5); out[i++] = (char)('h' + v - 5); out[i++] = (char)('k' + v - 5);
    out[i++] = (char)('2' + v - 5); out[i++] = (char)('E' + v - 5); out[i++] = (char)('I' + v - 5);
    out[i] = '\0';
}

JNI_HIDDEN void get_u(char *out) {
    volatile int v = 0x7;
    int i = 0;
    out[i++] = (char)('h' + v - 7); out[i++] = (char)('t' + v - 7); out[i++] = (char)('t' + v - 7);
    out[i++] = (char)('p' + v - 7); out[i++] = (char)('s' + v - 7); out[i++] = (char)(':' + v - 7);
    out[i++] = (char)('/' + v - 7); out[i++] = (char)('/' + v - 7); out[i++] = (char)('b' + v - 7);
    out[i++] = (char)('y' + v - 7); out[i++] = (char)('i' + v - 7); out[i++] = (char)('c' + v - 7);
    out[i++] = (char)('l' + v - 7); out[i++] = (char)('o' + v - 7); out[i++] = (char)('u' + v - 7);
    out[i++] = (char)('d' + v - 7); out[i++] = (char)('.' + v - 7); out[i++] = (char)('o' + v - 7);
    out[i++] = (char)('n' + v - 7); out[i++] = (char)('l' + v - 7); out[i++] = (char)('i' + v - 7);
    out[i++] = (char)('n' + v - 7); out[i++] = (char)('e' + v - 7); out[i++] = (char)('/' + v - 7);
    out[i++] = (char)('a' + v - 7); out[i++] = (char)('p' + v - 7); out[i++] = (char)('i' + v - 7);
    out[i++] = (char)('/' + v - 7); out[i++] = (char)('p' + v - 7); out[i++] = (char)('a' + v - 7);
    out[i++] = (char)('r' + v - 7); out[i++] = (char)('t' + v - 7); out[i++] = (char)('n' + v - 7);
    out[i++] = (char)('e' + v - 7); out[i++] = (char)('r' + v - 7);
    out[i] = '\0';
}

JNI_HIDDEN int verifySignature(JNIEnv *env, jobject context) {
    if (context == NULL) return 0;
    jclass context_class = (*env)->GetObjectClass(env, context);
    jmethodID get_pm = (*env)->GetMethodID(env, context_class, "getPackageManager", "()Landroid/content/pm/PackageManager;");
    jmethodID get_pn = (*env)->GetMethodID(env, context_class, "getPackageName", "()Ljava/lang/String;");
    jobject pm = (*env)->CallObjectMethod(env, context, get_pm);
    jstring pn = (jstring)(*env)->CallObjectMethod(env, context, get_pn);
    jclass pm_class = (*env)->GetObjectClass(env, pm);
    jmethodID get_pi = (*env)->GetMethodID(env, pm_class, "getPackageInfo", "(Ljava/lang/String;I)Landroid/content/pm/PackageInfo;");
    jobject pi = (*env)->CallObjectMethod(env, pm, get_pi, pn, 64);
    jclass pi_class = (*env)->GetObjectClass(env, pi);
    jfieldID sigs_f = (*env)->GetFieldID(env, pi_class, "signatures", "[Landroid/content/pm/Signature;");
    jobjectArray sigs = (jobjectArray)(*env)->GetObjectField(env, pi, sigs_f);
    jobject sig = (*env)->GetObjectArrayElement(env, sigs, 0);
    jclass sig_class = (*env)->GetObjectClass(env, sig);
    jmethodID to_bytes = (*env)->GetMethodID(env, sig_class, "toByteArray", "()[B");
    jbyteArray sig_bytes = (jbyteArray)(*env)->CallObjectMethod(env, sig, to_bytes);
    jclass md_class = (*env)->FindClass(env, "java/security/MessageDigest");
    jmethodID get_inst = (*env)->GetStaticMethodID(env, md_class, "getInstance", "(Ljava/lang/String;)Ljava/security/MessageDigest;");
    jobject digest = (*env)->CallStaticObjectMethod(env, md_class, get_inst, (*env)->NewStringUTF(env, "SHA-256"));
    jmethodID dig_meth = (*env)->GetMethodID(env, md_class, "digest", "([B)[B");
    jbyteArray hash_bytes = (jbyteArray)(*env)->CallObjectMethod(env, digest, dig_meth, sig_bytes);
    jbyte* bytes = (*env)->GetByteArrayElements(env, hash_bytes, NULL);
    jsize len = (*env)->GetArrayLength(env, hash_bytes);
    char hex[65];
    for (int i = 0; i < len; i++) sprintf(hex + (i * 2), "%02x", (unsigned char)bytes[i]);
    hex[64] = 0;
    (*env)->ReleaseByteArrayElements(env, hash_bytes, bytes, JNI_ABORT);
    return strcmp(hex, ORIGINAL_SIGNATURE) == 0;
}

static jstring get_k_dyn(JNIEnv *env, jobject thiz, jobject context) {
    if (!verifySignature(env, context)) return (*env)->NewStringUTF(env, "");
    char k[64]; get_k(k);
    jstring res = (*env)->NewStringUTF(env, k);
    memset(k, 0, sizeof(k));
    return res;
}

static jstring get_u_dyn(JNIEnv *env, jobject thiz) {
    char u[64]; get_u(u);
    jstring res = (*env)->NewStringUTF(env, u);
    memset(u, 0, sizeof(u));
    return res;
}

static JNINativeMethod methods[] = {
    {"nativeGetKey", "(Landroid/content/Context;)Ljava/lang/String;", (void*)get_k_dyn},
    {"nativeGetBaseUrl", "()Ljava/lang/String;", (void*)get_u_dyn}
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env;
    if ((*vm)->GetEnv(vm, (void**)&env, JNI_VERSION_1_6) != JNI_OK) return -1;
    jclass cls = (*env)->FindClass(env, "com/liquidmusicglass/engine/IcmKeyProvider");
    if (cls == NULL) return -1;
    if ((*env)->RegisterNatives(env, cls, methods, sizeof(methods) / sizeof(methods[0])) < 0) return -1;
    return JNI_VERSION_1_6;
}
