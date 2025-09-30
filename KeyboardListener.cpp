#include "KeyboardListener.h"

int KeyboardListener::getKeyCode() const
{
    return keyCode;
}

KeyboardListener::~KeyboardListener()
{
    isActive = false;
    if (listenerThread.joinable())
        listenerThread.join();
    keyCode = 0;
}

KeyboardListener::KeyboardListener() : isActive(true), keyCode(0)
{
    listenerThread = std::thread(&KeyboardListener::listen, this);
}

bool KeyboardListener::getIsActive() const
{
    return isActive;
}