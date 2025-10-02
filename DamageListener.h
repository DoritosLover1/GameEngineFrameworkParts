#include "EventListeners.h"
#include "DamageTypeEnum.h"
#include <string>
#include <atomic>
#pragma once

// This class listens the object is able to take/give damage
class DamageListener : public EventListeners
{
private:
    // Damage amount to be applied
    float damageAmount;

    // Event ID and isActive to listen for
    int eventID;
    std::atomic<bool> isActive;

    // Type of damage (e.g.,"physical", "magical", "true damage")
    DamageTypeEnum damageType;

public:

    EventTypeEnum getEventType() const override {
		return EventTypeEnum::DAMAGE;
    }

    void onEvent(bool isActive_) override
    {
        if (isActive_ && damageType != DamageTypeEnum::NONE)
        {
            isActive.store(true, std::memory_order_relaxed);
        }
        else
        {
            isActive.store(false, std::memory_order_relaxed);
        }
    }

    // Getters for private members
    float getDamageAmount() const;
    int getEventID() const;
    bool getIsActive() const;

    // Setters for private members
    void setDamageAmount(const float amount);

    ~DamageListener();
    DamageListener() = default;
    DamageListener(const int id);
    DamageListener(const int id, const float amount = 0);
    DamageListener(const int id, const float amount = 0, const DamageTypeEnum type = DamageTypeEnum::NONE);
};
