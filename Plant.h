#pragma once
#include "organism.h"
class Plant : public Organism
{
public:
    Plant();
    void collision(Organism* organism) {};
    void action(int move);
};

