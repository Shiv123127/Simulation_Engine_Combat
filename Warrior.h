// this file defines the warrior class
// warriors focus on dealing high damage to enemies

#pragma once

#include "Character.h"

class Warrior : public Character
{
public:
    // creates a warrior assigned to a specific team
    Warrior(const std::string& warriorName, int team);

    // defines the warrior turn behaviour
    void takeTurn(Character& ally, Character& enemy) override;
};
