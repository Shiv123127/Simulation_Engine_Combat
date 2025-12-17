// healers support allies by restoring health when needed
#pragma once
#include "Character.h"

class Healer : public Character
{
private:
    // this is the amount of health restored per heal action
    int healAmount;

public:
    // this then creates a healer assigned to a specific team
    Healer(const std::string& healerName, int team);

    //now we define healer behaviour during its turn
    void takeTurn(Character& ally, Character& enemy) override;
};
