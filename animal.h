#pragma once
#include "organism.h"

class Animal : public Organism {
public:
	Animal();
	void action(int move);
	void collision(Organism* organism);
	void fightHandling(Organism* organism);
};