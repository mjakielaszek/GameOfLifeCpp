#pragma once
#include "Plant.h"
class Belladonna :
    public Plant
{
protected:
    Organism* createNew(int x, int y);
public:
    Belladonna();
    Belladonna(int x, int y);
    Belladonna(int x, int y, int age, int initiative, int strength);
    void collision() {};
    void print();
    char getSign();
};

