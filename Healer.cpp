// this file implements healer behaviour during combat

#include "Healer.h"
#include <iostream>

Healer::Healer(const std::string& healerName, int team)
    : Character(healerName, 90, 10, team)
{
    healAmount = 20;
}

void Healer::takeTurn(Character& ally, Character& enemy)
{
    if (ally.getHealth() < 50)
    {
        std::cout << name << " heals " << ally.getName() << std::endl;
        ally.heal(healAmount);
    }
    else
    {
        std::cout << name << " attacks " << enemy.getName() << std::endl;
        performAttack(enemy);
    }
}
