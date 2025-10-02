#include <vector>
#include <map>
#include <iostream>
#include <memory>
#include "EventListeners.h"
#include "DamageListener.h"
#pragma once

class Mainframe
{
private:
	std::map<EventTypeEnum, std::vector<std::shared_ptr<EventListeners>>>eventListeners;

	int generateEventID();

public:

	void addDamageListeners(const EventTypeEnum type, float& amount, DamageTypeEnum& damageType);
	void addKeyboardListeners(const EventTypeEnum type);
	void addMouseListeners(const EventTypeEnum type);

	Mainframe() = default;
	~Mainframe() = default;
};

