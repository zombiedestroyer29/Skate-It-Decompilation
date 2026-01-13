#include "appman.h"

namespace {
    void RwDebugMessageCallback(const char *channelname, const char *file, uint32_t line, const char *format, va_list args);
    void RwDebugMessageChannelCallback(rw::core::debug::Channel *channel, const char *file, uint32_t line, const char *format, va_list args);
    bool RwDebugPrintAssertCallback(const char *condition, const char *file, const char *function, unsigned int line, const char *format, va_list argList, unsigned int flags);
    bool EAAssertFailure(const char *expr, const char *filename, int line, const char *function, const char *msg, char *args);
}

AppMan::AppMan() :
mActiveModule(NULL), 
mLoadingModule(NULL), 
mMutex(NULL, true),
mTimerTick(0),
mUpdateTick(0),
mRenderTick(0),
mpBackgroundLoadFunction(NULL),
mpBackgroundLoadCallback(NULL),
mpBackgroundLoadContext(NULL),
mLoadState(kLoadIdle),
mIsRenderEnding(0),
mIsFileError(0),
mRequestExitGame(0)
{
    AppMan::sTheAppMan = this;
}

AppMan::~AppMan() {
    xVERIFY(AppMan::sTheAppMan);
    AppMan::sTheAppMan = NULL;
}

int AppMan::Run(class ExecutionMan * ex, int ac, char * * av) {
    mTimerPeriod = 0.016666668;
    mTimerHz = 60;

    #ifdef JuiceEnabled
    Juice::JuiceHook::Instance()->ThreadMonitor();
    Juice::JuiceHook::Instance()->SetHangTimeout(120000u);
    #endif

    
    rw::core::debug::SetDebugMessageFunction(RwDebugMessageCallback);
    rw::core::debug::SetDebugMessageChannelFunction(RwDebugMessageChannelCallback);
    rw::core::debug::SetDebugPrintAssertFunction(RwDebugPrintAssertCallback);
    EA::Assert::SetFailureCallback(EAAssertFailure);

    mExecutionMan = ex;
    ex->Init(mTimerHz);
    Init(ac, av);
    mExecutionMan->InitRenderThread();
    MainLoop();
    
    xConsolePrint("PurgeTimerThread\n");
    mExecutionMan->PurgeTimerThread();
    xConsolePrint("Done PurgeTimerThread\n");
        
    Purge();
    
    return 0;
}


void AppMan::MainLoop() {
    unsigned char threadSafe;
    unsigned char doUpdate;
}

void AppMan::TimerFunction() {
    mTimerTick++;
    TimerCallback();
    mExecutionMan->Update();
    mExecutionMan->Wakeup();
}

void AppMan::LoadModuleFunction(LoadModule* pLoadModule) {
    xVERIFY(pLoadModule);
    pLoadModule->Load();
}