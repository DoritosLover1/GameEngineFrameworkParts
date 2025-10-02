#include "MouseListener.h"
#include <iostream>

bool MouseListener::getIsActive() const
{
    return isActive.load(std::memory_order_relaxed);
}

int MouseListener::getEventID() const
{
    return mouseID;
}

void MouseListener::watchPosition()
{
    while (true)
    {
        GetCursorPos(&position);
    }
}

void MouseListener::printerPosition() const
{
    if (isActive.load(std::memory_order_relaxed))
    {
        printf("Mouse Position - X: %ld, Y: %ld\n", position.x, position.y);
    }
    else
    {
        printf("MouseListener is inactive.\n");
    }
}

MouseListener::~MouseListener()
{
    std::cout << "MouseListener destroyed." << std::endl;
}

//Mouse position listener
MouseListener::MouseListener() {
    isActive.store(true, std::memory_order_relaxed);
    position = { 0, 0 };
}

MouseListener::MouseListener(const int id)
{
    isActive.store(true, std::memory_order_relaxed);
    mouseID = id;
	position = { 0, 0 };
}
