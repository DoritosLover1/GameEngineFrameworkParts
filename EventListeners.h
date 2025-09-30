#pragma once
class EventListeners
{
public :
	
	// Pure virtual functions of EventListeners
	virtual void onEvent(bool isActive) = 0;

	// Virtual destructor
	virtual ~EventListeners() {}
};

