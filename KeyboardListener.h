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
    int keyboardID;
    std::thread listenerThread;

	// Listens for key presses in a separate thread
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
       
	EventTypeEnum getEventType() const override {
        return EventTypeEnum::KEYBOARD;
	}

    void onEvent(bool isActive_) override
    {
        isActive = isActive_;
    }

    bool getIsActive() const;
    int getKeyCode() const;
	int getEventID() const;

    ~KeyboardListener();
    KeyboardListener();
    KeyboardListener(const int id);
};

