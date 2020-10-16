#ifndef __SHARED_DATA__
#define __SHARED_DATA__

#include <jni.h>

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <android/log.h>

#include <poll.h>
#include <pthread.h>
#include <sched.h>

#include <android/configuration.h>
#include <android/looper.h>
#include <android/native_activity.h>

#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <GLES/gl.h>

#include <android/sensor.h>
#include <android/log.h>

    struct AndroidApp;
    struct AndroidPollSource {
        int32_t id;
        struct AndroidApp* app;
        void (*process)(struct AndroidApp* app, struct AndroidPollSource* source);
    };

    struct AndroidApp {
        void* userData;
        void (*onAppCmd)(struct AndroidApp* app, int32_t cmd);
        int32_t (*onInputEvent)(struct AndroidApp* app, AInputEvent* event);

        ANativeActivity* activity;
        AConfiguration* config;

        void* savedState;
        size_t savedStateSize;

        ALooper* looper;
        AInputQueue* inputQueue;
        ANativeWindow* window;
        ARect contentRect;
        int activityState;
        int destroyRequested;

        pthread_mutex_t mutex;
        pthread_cond_t cond;

        int msgread;
        int msgwrite;

        pthread_t thread;

        struct AndroidPollSource cmdPollSource;
        struct AndroidPollSource inputPollSource;

        int running;
        int stateSaved;
        int destroyed;
        int redrawNeeded;
        AInputQueue* pendingInputQueue;
        ANativeWindow* pendingWindow;
        ARect pendingContentRect;
    };

    // Struct ini juga ada di CORE nanti aku refactor
    struct GDEngine {
        struct AndroidApp* app;

        int animating;
        EGLDisplay display;
        EGLSurface surface;
        EGLContext context;
        int32_t width;
        int32_t height;
    };

     extern struct GDEngine gdEngine;
    
#endif // __SHARED_DATA__

