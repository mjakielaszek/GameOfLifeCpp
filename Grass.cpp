#include "Grass.h"
Grass::Grass(){}
Grass::Grass(int x, int y) {
	this->setX(x);
	this->setY(y);
	this->setStrength(GRASS_STRENGTH);
	this->setAge(0);
	this->setInitiative(PLANT_INITIATIVE);
}
void Grass::print() {
	gotoxy(XSTART + this->getX(), YSTART + this->getY());
	cout << GRASS;
}

Organism* Grass::createNew(int x, int y) {
	return new Grass(x, y);
}

char Grass::getSign() { return GRASS; }

Grass::Grass(int x, int y, int age, int initiative, int strength) {
	this->setStrength(strength);
	this->setX(x);
	this->setY(y);
	this->setAge(age);
	this->setInitiative(initiative);
}