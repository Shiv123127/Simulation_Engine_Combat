// this file implements the shared behaviour for all combat characters

#include "Character.h"
#include <iostream>

Character::Character(const std::string& characterName, int startingHealth, int attack, int team)
{
    name = characterName;
    maxHealth = startingHealth;
    currentHealth = startingHealth;
    attackPower = attack;
    teamId = team;
}

Character::~Character()
{
    // no dynamic memory allocated inside this class
}

std::string Character::getName() const
{
    return name;
}

int Character::getTeamId() const
{
    return teamId;
}

int Character::getHealth() const
{
    return currentHealth;
}

bool Character::isAlive() const
{
    return currentHealth > 0;
}

void Character::takeDamage(int damage)
{
    if (damage <= 0)
    {
        return;
    }

    currentHealth -= damage;

    if (currentHealth < 0)
    {
        currentHealth = 0;
    }

    // this will print the remaining health after the damage is applied
	std::cout << name << " health is now " << currentHealth << std::endl;
}

void Character::heal(int amount)
{
    if (amount <= 0)
    {
        return;
    }

    currentHealth += amount;

    if (currentHealth > maxHealth)
    {
        currentHealth = maxHealth;
    }
}

void Character::performAttack(Character& target)
{
    target.takeDamage(attackPower);
}
