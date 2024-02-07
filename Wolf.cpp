#include "Wolf.h"

Wolf::Wolf()
{
}

Wolf::Wolf(int x, int y) {
	this->setX(x);
	this->setY(y);
	this->setStrength(WOLF_STRENGTH);
	this->setInitiative(WOLF_INITIATIVE);
	this->setAge(0);
}

void Wolf::print() {
	gotoxy(XSTART + this->getX(), YSTART + this->getY());
	cout << WOLF;
}

Organism* Wolf::createNew(int x, int y) {
	return new Wolf(x, y);
}
char Wolf::getSign() { return WOLF; }

Wolf::Wolf(int x, int y, int age, int initiative, int strength) {
	this->setStrength(strength);
	this->setX(x);
	this->setY(y);
	this->setAge(age);
	this->setInitiative(initiative);
}
