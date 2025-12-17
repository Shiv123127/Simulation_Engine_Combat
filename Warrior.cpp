// this file implements the warrior behaviour during combat

#include "Warrior.h"
#include <iostream>

Warrior::Warrior(const std::string& warriorName, int team)
    : Character(warriorName, 120, 25, team)
{
    // warriors have high attack and balanced health
}

void Warrior::takeTurn(Character& ally, Character& enemy)
{
    std::cout << name << " attacks " << enemy.getName() << std::endl;
    performAttack(enemy);
}
