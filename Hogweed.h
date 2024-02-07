#pragma once
#include "Plant.h"
class Hogweed :
    public Plant
{
protected:
    Organism* createNew(int x, int y);
public:
    Hogweed();
    Hogweed(int x, int y);
    Hogweed(int x, int y, int age, int initiative, int strength);
    void action(int key);
    void collision() {};
    void print();
    char getSign();
};

