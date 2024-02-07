#pragma once
#include "Plant.h"
class Grass :
    public Plant
{
protected:
    Organism* createNew(int x, int y);
public:
    Grass();
    Grass(int x, int y);
    Grass(int x, int y, int age, int initiative, int strength);
    void collision() {};
    void print();
    char getSign();
};

