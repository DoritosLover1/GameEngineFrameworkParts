#include "DamageListener.h"

DamageListener::DamageListener(const int id, const float amount, const DamageTypeEnum type)
	: damageAmount(amount), eventID(id), damageType(type), isActive(false)
{}

DamageListener::DamageListener(const int id, const float amount)
    : DamageListener(id, 0, DamageTypeEnum::NONE) 
{}

DamageListener::DamageListener(const int id)
	: DamageListener(id, 0, DamageTypeEnum::NONE)
{}

DamageListener::~DamageListener()
{}

int DamageListener::getEventID() const
{
	return eventID;
}

bool DamageListener::getIsActive() const
{
	return isActive;
}

float DamageListener::getDamageAmount() const
{
	return damageAmount;
}

void DamageListener::setDamageAmount(const float amount)
{
	//Specify your damage amount as negative or positive based on whether you want to take or give damage
	damageAmount = amount;
}