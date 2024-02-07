#pragma once
#include "animal.h"

class Fox :
    public Animal
{
protected:
    Organism* createNew(int x, int y);
public:
    Fox();
    Fox(int x, int y);
    Fox(int x, int y, int age, int initiative, int strength);
    void action(int key);
    void collision() {};
    void print();
    char getSign();
};

