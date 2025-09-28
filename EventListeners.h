#pragma once
class EventListeners
{
public :
	
	// Pure virtual functions of EventListeners
	virtual void onEvent(int eventID, bool isActive) = 0;

	// Virtual destructor
	virtual ~EventListeners() {}
};

