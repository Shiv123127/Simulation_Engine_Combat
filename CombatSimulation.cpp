// this file implements the combat simulation logic that controls turns,team interactions, and the overall battle flow. 

#include "CombatSimulation.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// si the constructor sets the starting turn number and seeds the random number generator. 
CombatSimulation::CombatSimulation()
{
    turnCounter = 1;

    // here we seed random once so that combat outcomes vary between runs
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

// now the destructor cleans up all dynamically allocated characters, this ensures there are no memory leaks when the simulation ends
CombatSimulation::~CombatSimulation()
{
    for (Character* c : teamOne)
    {
        delete c;
    }

    for (Character* c : teamTwo)
    {
        delete c;
    }
}

// so now we can add a character to the correct team based on its team id
void CombatSimulation::addCharacter(Character* character)
{
    if (character->getTeamId() == 1)
    {
        teamOne.push_back(character);
    }
    else
    {
        teamTwo.push_back(character);
    }
}

//so now we run the full combat simulation until one team is defeated.
void CombatSimulation::runSimulation()
{
    std::cout << "combat simulation started" << std::endl;

    // it will continue running turns while both teams still have living members
    while (teamAlive(teamOne) && teamAlive(teamTwo))
    {
        std::cout << "\nturn " << turnCounter << std::endl;
        runTurn();
        turnCounter++;
    }

    //  finally it will determine and display the winning team
    if (teamAlive(teamOne))
    {
        std::cout << "\nteam one wins the battle" << std::endl;
    }
    else
    {
        std::cout << "\nteam two wins the battle" << std::endl;
    }
}

// it will execute a single turn where each team acts once
void CombatSimulation::runTurn()
{
    // team one takes actions first
    for (Character* c : teamOne)
    {
        if (c->isAlive() && teamAlive(teamTwo))
        {
            // thne select random ally and enemy to demonstrate polymorphic behaviour. 
            Character* ally = selectTarget(teamOne);
            Character* enemy = selectTarget(teamTwo);

            // the character decides what action to take on its turn
            c->takeTurn(*ally, *enemy);
        }
    }

    // this will remove defeated characters from team two after attacks
    removeDead(teamTwo);

    // team two takes actions next. 
    for (Character* c : teamTwo)
    {
        if (c->isAlive() && teamAlive(teamOne))
        {
            Character* ally = selectTarget(teamTwo);
            Character* enemy = selectTarget(teamOne);
            c->takeTurn(*ally, *enemy);
        }
    }

    // now remove defeated characters from team one after attacks
    removeDead(teamOne);
}

// then we check whether a team still has at least one living character
bool CombatSimulation::teamAlive(const std::vector<Character*>& team) const
{
    for (Character* c : team)
    {
        if (c->isAlive())
        {
            return true;
        }
    }
    return false;
}

// we have to remove dead characters from a team and frees their memory
void CombatSimulation::removeDead(std::vector<Character*>& team)
{
    for (auto it = team.begin(); it != team.end(); )
    {
        if (!(*it)->isAlive())
        {
			// so we have to delete the object before removing it from the container and avoid memory leaks
            delete* it;
            it = team.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

// selects a random character from a team to act as a target
Character* CombatSimulation::selectTarget(std::vector<Character*>& team)
{
    int index = std::rand() % team.size();
    return team[index];
}
