#pragma once
#include "animal.h"
class Turtle :
    public Animal
{
protected:
    Organism* createNew(int x, int y);
public:
    Turtle();
    Turtle(int x, int y);
    Turtle(int x, int y, int age, int initiative, int strength);
    void action(int key);
    void print();
    void collision(Organism* organism);
    char getSign();
};

