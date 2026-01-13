
class AppMan {

    static class AppMan* sTheAppMan; // size: 0x4

//vtable
public:
    virtual ~AppMan();
    virtual void SystemEvent(unsigned long long u64_1, unsigned long long u64_2);
    virtual bool CanExit();
    virtual int (*GetExceptionCallback())();
    virtual Sk8::Input::InputManager* GetInputManager();
    virtual int GetModuleUpdateTick();
    virtual bool ConstructGameBootDependencies();
    virtual bool ConstructPreStubBootDependencies();
    virtual bool InBootControllerDisconnection();
    virtual bool IsInFE();
    virtual void Init(int argc, char ** argv);
    virtual void Purge();
    virtual int Flush();
    virtual bool PreUpdate();
    virtual bool PostPostUpdate();
    virtual void TimerCallback();
    virtual void PanicExit();
    virtual void PanicExitPrep();

    
    
// Members
protected:
    class ExecutionMan* mExecutionMan;

private:
    class AppModule* mActiveModule;
    class AppModule* mLoadingModule;
    class EA::Thread::Mutex mMutex;
    int mTimerHz;
    float mTimerPeriod;
    int mTimerTick;
    class AtomicInt<unsigned int> mUpdateTick;
    class AtomicInt<unsigned int> mRenderTick;
    void (* mpBackgroundLoadFunction)(void *);
    void (* mpBackgroundLoadCallback)(void *);
    void * mpBackgroundLoadContext;
    enum eLoadState mLoadState;
    class AtomicInt<unsigned int> mIsRenderEnding;
    class AtomicInt<unsigned int> mIsFileError;
    class AtomicInt<unsigned int> mRequestExitGame;


public:

    bool IsLoading() {
        return mLoadingModule || !mExecutionMan->IsLoadDone();
    }

    int Run(class ExecutionMan * ex, int ac, char * * av);

    void MainLoop();

    void TimerFunction();

    void LoadModuleFunction(LoadModule* pLoadModule);

};