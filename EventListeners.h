#pragma once
#include "EventTypeEnum.h"
class EventListeners
{
public :
	virtual EventTypeEnum getEventType() const = 0;
	// Pure virtual functions of EventListeners
	virtual void onEvent(bool isActive) = 0;

	// Virtual destructor
	virtual ~EventListeners() {}
};

