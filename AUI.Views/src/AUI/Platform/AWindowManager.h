#pragma once
#include <AUI/Thread/IEventLoop.h>
#include "ACustomWindow.h"


class AWindow;

class API_AUI_VIEWS AWindowManager: public IEventLoop {
friend class AWindow;
private:
    IEventLoop::Handle mHandle;
    ADeque<_<AWindow>> mWindows;
    bool mLoopRunning = false;
#ifdef __linux
    AMutex mXNotifyLock;
    AConditionVariable mXNotifyCV;
#endif

public:
    AWindowManager();
    ~AWindowManager() override;

    void notifyProcessMessages() override;
    void loop() override;

    const ADeque<_<AWindow>>& getWindows() const {
        return mWindows;
    }

    template<typename T>
    [[nodiscard]] ADeque<_<AWindow>> getWindowsOfType() const {
        ADeque<_<AWindow>> result;
        for (auto& w : mWindows) {
            if (auto c = _cast<T>(w)) {
                result << c;
            }
        }

        return std::move(result);
    }

};