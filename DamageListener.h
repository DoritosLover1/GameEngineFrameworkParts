#include "EventListeners.h"
#include "DamageTypeEnum.h"
#include <string>

#pragma once
class DamageListener : public EventListeners
{
	private:
		// Damage amount to be applied
		float damageAmount;

		// Event ID and isActive to listen for
		int eventID;
		bool isActive;

		// Type of damage (e.g.,"physical", "magical", "true damage")
		DamageTypeEnum damageType;

	public:
		// Implementing pure virtual functions from EventListeners
		void onEvent(int eventID) override 
		{
			isActive= true;
		}
		void offEvent(int eventID) override 
		{
			isActive = false;
		}
		void triggerEvent(int eventID) override 
		{
			// Based on game engine specifics, apply damage logic here
		}

		// Getters for private members
		float getDamageAmount() const;
		int getEventID() const;
		bool getIsActive() const;

		// Setters for private members
		// For setting damageAmount, pass by value to modify the static member
		void setDamageAmount(const float amount);

		~DamageListener() override {}
		DamageListener() = default;
		DamageListener(const int id);
		DamageListener(const int id, const float amount = 0);
		DamageListener(const int id, const float amount = 0, const DamageTypeEnum type = DamageTypeEnum::NONE);
};


