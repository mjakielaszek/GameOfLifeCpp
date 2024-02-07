#pragma once
#include "Plant.h"
class Guarana :
    public Plant
{
protected:
    Organism* createNew(int x, int y);
public:
    Guarana();
    Guarana(int x, int y);
    Guarana(int x, int y, int age, int initiative, int strength);
    void collision() {};
    void print();
    char getSign();
};

