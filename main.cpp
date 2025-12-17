// main.cpp
// this file will be the entry point for the combat simulation. 
// it will asks the user for basic setup, creates both teams, and then it will start the simulation

#include <iostream>
#include <limits>

#include "CombatSimulation.h"
#include "Warrior.h"
#include "Defender.h"
#include "Healer.h"

int main()
{
    std::cout << "=== combat simulation ===" << std::endl;

    int teamSize = 0;

	// first we ask the user how many characters they want per team, - it is only limited to 1 to 5 for simplicity, an invalid input handling is included as well.
    while (teamSize < 1 || teamSize > 5)
    {
        std::cout << "enter number of characters per team (1 to 5): ";
        std::cin >> teamSize;

        //  so this part will handle invalid input such as letters or numbers outside the range. 
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            teamSize = 0;
            std::cout << "invalid input. please enter a number." << std::endl;
        }
        else if (teamSize < 1 || teamSize > 5)
        {
            std::cout << "please enter a value between 1 and 5." << std::endl;
        }
    }

    std::cout << "\ncreating two teams of size " << teamSize << "...\n" << std::endl;

    // now we create the simulation engine
    CombatSimulation simulation;

    // first we have to create team one with a repeating pattern of roles. 
    for (int i = 0; i < teamSize; i++)
    {
        std::string name = "team1_unit_" + std::to_string(i + 1);

        if (i % 3 == 0)
        {
            simulation.addCharacter(new Warrior(name, 1));
        }
        else if (i % 3 == 1)
        {
            simulation.addCharacter(new Defender(name, 1));
        }
        else
        {
            simulation.addCharacter(new Healer(name, 1));
        }
    }

    // and then we create team two with a repeating pattern of roles. 
    for (int i = 0; i < teamSize; i++)
    {
        std::string name = "team2_unit_" + std::to_string(i + 1);

        if (i % 3 == 0)
        {
            simulation.addCharacter(new Warrior(name, 2));
        }
        else if (i % 3 == 1)
        {
            simulation.addCharacter(new Defender(name, 2));
        }
        else
        {
            simulation.addCharacter(new Healer(name, 2));
        }
    }

    // once both teams are made, we then run the full simulation until one team wins. 
    simulation.runSimulation();

    std::cout << "\npress enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}
