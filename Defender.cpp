// this file implements the defender combat behaviour

#include "Defender.h"
#include <iostream>

Defender::Defender(const std::string& defenderName, int team)
    : Character(defenderName, 150, 15, team)
{
    defenceValue = 10;
}

void Defender::takeDamage(int damage)
{
    int reducedDamage = damage - defenceValue;

    if (reducedDamage < 0)
    {
        reducedDamage = 0;
    }

    std::cout << name << " blocks part of the attack and takes "
        << reducedDamage << " damage" << std::endl;

    Character::takeDamage(reducedDamage);
}

void Defender::takeTurn(Character& ally, Character& enemy)
{
    std::cout << name << " attacks cautiously " << enemy.getName() << std::endl;
    performAttack(enemy);
}
