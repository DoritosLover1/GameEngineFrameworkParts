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

int KeyboardListener::getEventID() const
{
    return keyboardID;
}

KeyboardListener::KeyboardListener() : isActive(true), keyCode(0), listenerThread()
{
	listenerThread = std::thread(&KeyboardListener::listen, this);
}

KeyboardListener::KeyboardListener(const int id) : isActive(true), keyCode(0), keyboardID(id), listenerThread()
{
    listenerThread = std::thread(&KeyboardListener::listen, this); 
}

bool KeyboardListener::getIsActive() const
{
    return isActive;
}