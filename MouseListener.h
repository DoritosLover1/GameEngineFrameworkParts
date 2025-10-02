#include "EventListeners.h"
#include <Windows.h>
#include <string>
#include <atomic>

#pragma once

class MouseListener : public EventListeners
{
private:
    std::atomic<bool> isActive;
	int mouseID;
    POINT position;

public:

    EventTypeEnum getEventType() const override {
        return EventTypeEnum::MOUSE;
    }

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
    int getEventID() const;


    ~MouseListener();
    MouseListener();
	MouseListener(const int id);
};
