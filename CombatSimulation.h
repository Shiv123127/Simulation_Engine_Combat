// this file defines the combat simulation engine
// it controls team management, turn order, and battle progression

#pragma once
#include <vector>
#include "Character.h"

class CombatSimulation
{
private:
    //i have put containers to hold the characters for each team
    std::vector<Character*> teamOne;
    std::vector<Character*> teamTwo;

    // we have to track the number of turns elapsed
    int turnCounter;

public:
    // first we have the constructor that initialises the simulation
    CombatSimulation();

    //the destructor will clean up the allocated memory
    ~CombatSimulation();

    // we add a character to the appropriate team
    void addCharacter(Character* character);

    // then we run the combat simulation until one team wins
    void runSimulation();

private:
    // e then execute one full combat turn
    void runTurn();

    // we have to check whether a team has any living characters
    bool teamAlive(const std::vector<Character*>& team) const;

    // now we remove defeated characters from a team
    void removeDead(std::vector<Character*>& team);

    // selects a random living character from a team
    Character* selectTarget(std::vector<Character*>& team);
};
