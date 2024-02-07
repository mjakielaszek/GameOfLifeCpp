#pragma once
#include "animal.h"
class CyberSheep :
    public Animal
{
protected:
	Organism* createNew(int x, int y);
public:
	CyberSheep();
	CyberSheep(int x, int y);
	CyberSheep(int x, int y, int age, int initiative, int strength);
	void action(int key) ;
	void print();
	void sort_all(vector<DISTANCE*>& all);
	char getSign();
};

