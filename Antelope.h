#pragma once
#include "animal.h"
class Antelope :
    public Animal
{
protected:
	Organism* createNew(int x, int y);
public:
	Antelope();
	Antelope(int x, int y, int age, int initiative, int strength);
	Antelope(int x, int y);
	void action(int key);
	void collision(Organism* organism);
	void print();
	char getSign();
};

