#pragma once
#include "Plant.h"
class SowThistle : public Plant
{
protected:
    Organism* createNew(int x, int y);
public:
    SowThistle();
    SowThistle(int x, int y);
    SowThistle(int x, int y, int age, int initiative, int strength);
    void action(int key);
    void collision() {};
    void print();
    char getSign();
};

