/*
    Compile unit: C:\Skate_Wii\main\packages\sk8\scaffold\1.00.00\scaffold\core\appman\wiimain.cpp
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x8020C1F8 -> 0x8020D9D4
*/
// Range: 0x8020C1F8 -> 0x8020C264
// this: r31
WiiExecutionMan::WiiExecutionMan() {
    // References
    // -> struct [anonymous] __vt__15WiiExecutionMan;
}

// Range: 0x8020C264 -> 0x8020C344
// this: r30
void WiiExecutionMan::Init(int timerHz /* r31 */) {
    // Local variables
    struct ThreadParameters loadThreadParms; // r1+0x8

    // References
    // -> int TimerTargetHz;
}

// Range: 0x8020C344 -> 0x8020C348
void WiiExecutionMan::InitRenderThread() {}

// Range: 0x8020C348 -> 0x8020C34C
void WiiExecutionMan::PurgeRenderThread() {}

// Range: 0x8020C34C -> 0x8020C3B0
long long _CalcPeriod() {
    // Local variables
    int tmp; // r4
}

// Range: 0x8020C3B0 -> 0x8020C46C
// this: r26
void WiiExecutionMan::InitTimerThread(int FrequencyInHz /* r27 */) {
    // Local variables
    long long now; // r30
    long long Period; // r28

    // References
    // -> struct OSAlarm TimerAlarm;
    // -> void * TimerThreadMsgData[32];
    // -> struct OSMessageQueue TimerThreadMsgQ;
    // -> struct OSThread TimerThread;
    // -> unsigned char TimerThreadStack[4096];
    // -> int TimerCurrentHz;
}

// Range: 0x8020C46C -> 0x8020C478
void WiiExecutionMan::PurgeTimerThread() {}

// Range: 0x8020C478 -> 0x8020C4D8
// this: r31
void WiiExecutionMan::Purge() {}

// Range: 0x8020C4D8 -> 0x8020C4E4
void WiiExecutionMan::Wait() {}

// Range: 0x8020C4E4 -> 0x8020C4F0
void WiiExecutionMan::Wakeup() {}

// Range: 0x8020C4F0 -> 0x8020C4F4
void WiiExecutionMan::Exit() {}

// Range: 0x8020C4F4 -> 0x8020C4FC
void WiiExecutionMan::SetTimerHz() {
    // References
    // -> int TimerTargetHz;
}

// Range: 0x8020C4FC -> 0x8020C504
int WiiExecutionMan::GetTimerHz() {
    // References
    // -> int TimerCurrentHz;
}

// Range: 0x8020C504 -> 0x8020C5A4
void WiiExecutionMan::TimerAlarmHandler() {
    // Local variables
    long long now; // r30
    long long NewPeriod; // r28

    // References
    // -> struct OSMessageQueue TimerThreadMsgQ;
    // -> struct OSAlarm TimerAlarm;
    // -> int TimerCurrentHz;
    // -> int TimerTargetHz;
}

// Range: 0x8020C5A4 -> 0x8020C5E0
void WiiExecutionMan::StopTimerThread() {
    // References
    // -> struct OSMessageQueue TimerThreadMsgQ;
    // -> struct OSAlarm TimerAlarm;
}

// Range: 0x8020C5E0 -> 0x8020C648
void * WiiExecutionMan::TimerThreadFunc() {
    // Local variables
    void * msg; // r1+0x8

    // References
    // -> class AppMan * sTheAppMan;
    // -> struct OSMessageQueue TimerThreadMsgQ;
}

// Range: 0x8020C648 -> 0x8020C6EC
long WiiExecutionMan::loadThread() {
    // Local variables
    class WiiExecutionMan * thisPtr; // r30
}

// Range: 0x8020C6EC -> 0x8020C700
void WiiExecutionMan::Load() {}

// Range: 0x8020C700 -> 0x8020C710
unsigned char WiiExecutionMan::IsLoadDone() {}

// Range: 0x8020C710 -> 0x8020C714
void WiiExecutionMan::Update() {}

// Range: 0x8020C714 -> 0x8020C7F0
static void systemInit() {
    // Local variables
    struct Options ops; // r1+0x10
    class Manager * pManager; // r31
    struct ThreadParameters fileSysThreadParams; // r1+0x1C
    long entrynum; // r0

    // References
    // -> static unsigned char isEUBuild;
    // -> class XAllocator * sInstance;
    // -> class MemCategoryID kMemCategory_System;
}

// Range: 0x8020C824 -> 0x8020C92C
static void initGXMemory() {
    // References
    // -> void * xfb_p[2];
    // -> static void * gx_fifo_p;
    // -> unsigned long fbSize;
    // -> class XAllocator * sInstance;
    // -> class MemCategoryID kMemCategory_System;
    // -> static struct _GXRenderModeObj Rmodeobj;
}

// Range: 0x8020C92C -> 0x8020C988
static void * alloc32(unsigned long size /* r31 */) {
    // References
    // -> class XAllocator * sInstance;
    // -> class MemCategoryID kMemCategory_SystemMEM2;
}

// Range: 0x8020C988 -> 0x8020C9E0
static unsigned char free32(void * addr /* r31 */) {
    // References
    // -> class XAllocator * sInstance;
    // -> class MemCategoryID kMemCategory_SystemMEM2;
}

// Range: 0x8020C9E0 -> 0x8020CA50
static void initDisplay() {
    // Local variables
    unsigned char uWideScreen; // r0

    // References
    // -> static unsigned char isWideScreen;
    // -> void * xfb_p[2];
    // -> long disp_xfb_idx;
    // -> long draw_xfb_idx;
    // -> static struct _GXRenderModeObj Rmodeobj;
}

// Range: 0x8020CA50 -> 0x8020CBC8
static void initGx() {
    // Local variables
    struct _GXColor clear_clr; // r1+0xC
    float yscale; // f0

    // References
    // -> void * xfb_p[2];
    // -> static unsigned char vfilter[7];
    // -> static struct _GXRenderModeObj Rmodeobj;
    // -> static struct GXFifoObj * gx_fifo_obj;
    // -> static void * gx_fifo_p;
}

// Range: 0x8020CBC8 -> 0x8020CD1C
void setupViewport() {
    // Local variables
    float mProjection[4][4]; // r1+0x5C
    float mView[3][4]; // r1+0x2C
    struct Vec vCamPos; // r1+0x20
    struct Vec vCamUp; // r1+0x14
    struct Vec vCamTarget; // r1+0x8

    // References
    // -> static int SCREEN_HEIGHT;
    // -> static int SCREEN_WIDTH;
}

// Range: 0x8020CD1C -> 0x8020D244
void renderWarning() {
    // Local variables
    float elapse; // f3
    float safezone_width; // f31
    float safezone_height; // f30
    float scaledHbiWidth; // f29
    float scaledHbiHeight; // f28

    // References
    // -> long disp_xfb_idx;
    // -> void * xfb_p[2];
    // -> long draw_xfb_idx;
    // -> float gHbiHeight;
    // -> float gHbiWidth;
    // -> static int SCREEN_HEIGHT;
    // -> static unsigned char isWideScreen;
    // -> static unsigned char gHBIconAlpha;
    // -> static char gHBIconMode;
    // -> static long long gHBIconTime;
    // -> float gRectHalfHeight;
    // -> float gRectHalfWidth;
    // -> static unsigned char warningAdisplayed;
    // -> static struct _GXColor gColor;
    // -> static unsigned char gHomeButtonOn;
}

// Range: 0x8020D244 -> 0x8020D894
int main(int ac /* r21 */, char * * av /* r22 */) {
    // Local variables
    int wpad_state; // r0
    unsigned long deviceType; // r1+0x18
    unsigned char wasConnectedAtBoot[4]; // r1+0x14
    int i; // r19
    unsigned long startMilliseconds; // r0
    unsigned long currentMilliseconds; // r4
    unsigned long startSeconds; // r0
    unsigned long currentSeconds; // r0
    unsigned long reconnectTime[4]; // r1+0x1C
    unsigned char displayMessage; // r24
    struct KPADStatus kpad; // r1+0x2C
    unsigned char controllerHasConnected[4]; // r1+0x10
    int i; // r23
    unsigned long startMilliseconds; // r0
    unsigned long currentMilliseconds; // r4

    // References
    // -> static class WiiExecutionMan ex;
    // -> unsigned char isUsingDeviceBuffers;
    // -> static unsigned char gPowerPressed;
    // -> static unsigned char gResetPressed;
    // -> static unsigned char gHBIconAlpha;
    // -> static long long gHBIconTime;
    // -> static char gHBIconMode;
    // -> static unsigned char gHomeButtonOn;
    // -> static unsigned char warningAdisplayed;
    // -> static struct _GXColor gColor;
    // -> class AppMan * sTheAppMan;
    // -> class XAllocator * sInstance;
    // -> class MemCategoryID kMemCategory_SystemMEM2;
    // -> static struct _GXRenderModeObj Rmodeobj;
}

// Range: 0x8020D914 -> 0x8020D9B8
void cleanUpStub() {
    // References
    // -> void * xfb_p[2];
    // -> static void * gx_fifo_p;
    // -> class XAllocator * sInstance;
    // -> class MemCategoryID kMemCategory_System;
}

// Range: 0x8020D9B8 -> 0x8020D9BC
struct OSThread * WiiExecutionMan::GetCurrentThreadId() {}

// Range: 0x8020D9BC -> 0x8020D9C4
struct OSThread * WiiExecutionMan::GetMainThreadId() {}

// Range: 0x8020D9C4 -> 0x8020D9CC
struct OSThread * WiiExecutionMan::GetRenderThreadId() {}

// Range: 0x8020D9CC -> 0x8020D9D4
struct OSThread * WiiExecutionMan::GetLoadThreadId() {}


