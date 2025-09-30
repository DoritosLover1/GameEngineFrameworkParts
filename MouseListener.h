#include "EventListeners.h"
#include <Windows.h>
#include <string>
#include <atomic>

#pragma once

class MouseListener : public EventListeners
{
private:
    std::atomic<bool> isActive;
    POINT position;

public:
    void onEvent(bool isActive_) override
    {
        if (isActive_)
        {
            isActive.store(true, std::memory_order_relaxed);
        }
        else
        {
            isActive.store(false, std::memory_order_relaxed);
        }
    }

    bool getIsActive() const;
    void watchPosition();
    void printerPosition() const;

    ~MouseListener();
    MouseListener();
};
