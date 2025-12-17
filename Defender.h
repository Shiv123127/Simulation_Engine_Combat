// this file defines the defender class
// defenders reduce incoming damage and survive longer in combat
#pragma once
#include "Character.h"

class Defender : public Character
{
private:
    //this is the amount of damage blocked when attacked
    int defenceValue;

public:
    // and this will create a defender assigned to a specific team
    Defender(const std::string& defenderName, int team);

    // we have to override damage handling to apply defence
    void takeDamage(int damage) override;

    // finally defines defender behaviour during its turn
    void takeTurn(Character& ally, Character& enemy) override;
};
