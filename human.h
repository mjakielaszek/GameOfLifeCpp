#pragma once
#include "animal.h"
#include "world.h"


class Human : public Animal {
protected:
	int abilityCooldown;
	Organism* createNew(int x, int y);
	bool onCooldown;
	bool abilityActive;
public:
	Human();
	Human(int x, int y, int age, int initiative, int strength);
	Human(int x, int y);
	void action(int key);
	void print();
	char getSign();

	int getAbilityCooldown();
	bool getOnCooldown();
	bool getAbilityActive();

	void setAbilityCooldown(int value);
	void setAbilityActive(bool value);
	void setOnCooldown(bool value);
	void resetAbilityCooldown();
};