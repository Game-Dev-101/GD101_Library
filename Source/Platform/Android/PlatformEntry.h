#ifndef __PLATFORM_ENTRY__
#define __PLATFORM_ENTRY__

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

// Macro untuk LOG
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "GD101_app", __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, "GD101_app", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "GD101_app", __VA_ARGS__))
/* For debug builds */
#ifndef NDEBUG
#  define LOGV(...)  ((void)__android_log_print(ANDROID_LOG_VERBOSE, "GD101_app", __VA_ARGS__))
#else
#  define LOGV(...)  ((void)0)
#endif


#ifdef __cplusplus
extern "C" {
#endif

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

    enum {
        LOOPER_ID_MAIN = 1,
        LOOPER_ID_INPUT = 2,
        LOOPER_ID_USER = 3,
    };

    enum {
        APP_CMD_INPUT_CHANGED,
        APP_CMD_INIT_WINDOW,
        APP_CMD_TERM_WINDOW,
        APP_CMD_WINDOW_RESIZED,
        APP_CMD_WINDOW_REDRAW_NEEDED,
        APP_CMD_CONTENT_RECT_CHANGED,
        APP_CMD_GAINED_FOCUS,
        APP_CMD_LOST_FOCUS,
        APP_CMD_CONFIG_CHANGED,
        APP_CMD_LOW_MEMORY,
        APP_CMD_START,
        APP_CMD_RESUME,
        APP_CMD_SAVE_STATE,
        APP_CMD_PAUSE,
        APP_CMD_STOP,
        APP_CMD_DESTROY,
    };
    int8_t AndroidApp_read_cmd(struct AndroidApp* AndroidApp);
    void AndroidApp_pre_exec_cmd(struct AndroidApp* AndroidApp, int8_t cmd);
    void AndroidApp_post_exec_cmd(struct AndroidApp* AndroidApp, int8_t cmd);
    int GD101_LIB_EntryPoint(struct AndroidApp* app);

#ifdef __cplusplus
}
#endif
////////////////////////////////////////////////////////////////////////////

// Read all pending events.
int ident;
int events;
struct AndroidPollSource* source;

#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <android/sensor.h>
#include <android/log.h>

// Struktur Data Engine Kita
struct GDEngine {
    struct AndroidApp* app;

    int animating;
    EGLDisplay display;
    EGLSurface surface;
    EGLContext context;
    int32_t width;
    int32_t height;
};

struct GDEngine gdEngine;
/////////////////////////////////////////////////////////////////////////////
// Method Umum Untuk Semua
bool EndLoop();
int ScreenFlip();
int ClearScreen();
bool GD101_InitWindow(const char * windowName, int height, int width);
extern int Main();


#endif //__PLATFORM_ENTRY__

