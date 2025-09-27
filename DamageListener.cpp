#include "DamageListener.h"

DamageListener::DamageListener(const int id, const float amount, const DamageTypeEnum type)
	: damageAmount(amount), damageType(type), isActive(false)
{
	eventID = id;
}

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
	damageAmount = amount;
}