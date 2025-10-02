#include "Mainframe.h"
#include "KeyboardListener.h"
#include "MouseListener.h"

int Mainframe::generateEventID()
{
	static int currentID = 0;
	return ++currentID;
}

void Mainframe::addDamageListeners(const EventTypeEnum type, float& amount, DamageTypeEnum& damageType)
{
	if (type == EventTypeEnum::DAMAGE) {
		std::shared_ptr<DamageListener> newDamageListener = std::make_shared<DamageListener>(generateEventID(), amount, damageType);
		eventListeners[type].push_back(newDamageListener);
		std::cout << "Added DamageListener with ID: " << newDamageListener->getEventID() << ", Amount: " << newDamageListener->getDamageAmount() << ", Type: " << static_cast<int>(damageType) << std::endl;
	}
	else
	{
		std::cerr << "Error: Invalid event type for DamageListener. Expected DAMAGE." << std::endl;
	}
}

void Mainframe::addKeyboardListeners(const EventTypeEnum type)
{
	if (type == EventTypeEnum::KEYBOARD) {
		std::shared_ptr<KeyboardListener> newKeyboardListener = std::make_shared<KeyboardListener>(generateEventID());
		eventListeners[type].push_back(newKeyboardListener);
		std::cout << "Added KeyboardListener with ID: "<< newKeyboardListener->getEventID() << std::endl;
	}
	else
	{
		std::cerr << "Error: Invalid event type for KeyboardListener. Expected KEYBOARD." << std::endl;
	}
}

void Mainframe::addMouseListeners(const EventTypeEnum type)
{
	if (type == EventTypeEnum::MOUSE) {
		std::shared_ptr<MouseListener> newMouseListener = std::make_shared<MouseListener>(generateEventID());
		eventListeners[type].push_back(newMouseListener);
		std::cout << "Added MouseListener with ID: "<< newMouseListener->getEventID() << std::endl;
	}
	else
	{
		std::cerr << "Error: Invalid event type for MouseListener. Expected MOUSE." << std::endl;
	}
}
