#pragma once
#include "animal.h"
class Sheep :
    public Animal
{
protected:
    Organism* createNew(int x, int y);
public:
    Sheep();
    Sheep(int x, int y);
    Sheep(int x, int y, int age, int initiative, int strength);
    void collision() {};
    void print();
    char getSign();
};

