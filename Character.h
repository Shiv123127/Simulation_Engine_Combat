// this file defines the base character class used in the team combat simulation
// all combat characters inherit shared attributes and behaviour from this class
#pragma once
#include <string>

class Character
{
protected: // we will display name, current and maximum health, attack power, and team id
    std::string name;
    int currentHealth;
    int maxHealth;
    int attackPower;
    int teamId;

public: // here we will define the constructor, destructor, and shared methods, it will return the character name, team id, current health, check if alive, take damage, heal, perform attack, and take turn 
    Character(const std::string& characterName, int startingHealth, int attack, int team);
    virtual ~Character();
    std::string getName() const;
    int getTeamId() const;
    int getHealth() const;
    bool isAlive() const;
    virtual void takeDamage(int damage);
    void heal(int amount);
    void performAttack(Character& target);
    virtual void takeTurn(Character& ally, Character& enemy) = 0;
};
