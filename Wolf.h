#pragma once
#include "animal.h"
class Wolf : public Animal
{
protected:
	Organism* createNew(int x, int y);
public :
	Wolf();
	Wolf(int x, int y);
	Wolf(int x, int y, int age, int initiative, int strength);
	void collision() {};
	void print();
	char getSign();
};

