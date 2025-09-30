#pragma once
#include <Windows.h>
#include <thread>
#include <atomic>
#include <functional>
#include "EventListeners.h"

class KeyboardListener : public EventListeners
{
private:
    std::atomic<bool> isActive;
    int keyCode;
    std::thread listenerThread;

    void listen()
    {
        while (isActive)
        {
            for (int k = 8; k <= 255; ++k)
            {
                if (GetAsyncKeyState(k) & 0x8000)
                {
                    keyCode = k;
                    onEvent(true);
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

public:
    void onEvent(bool isActive_) override
    {
        isActive = isActive_;
    }
    bool getIsActive() const;
    int getKeyCode() const;

    ~KeyboardListener();
    KeyboardListener();
};

