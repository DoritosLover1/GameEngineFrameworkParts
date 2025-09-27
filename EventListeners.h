#pragma once

class EventListeners
{
public :
	
	// Pure virtual functions of EventListeners
	virtual void onEvent(int eventID) = 0;
	virtual void offEvent(int eventID) = 0;
	virtual void triggerEvent(int eventID) = 0;

	// Virtual destructor
	virtual ~EventListeners() {}
};

