#include "sheep.h"
Sheep::Sheep() {

}

Sheep::Sheep(int x, int y) {
	this->setX(x);
	this->setY(y);
	this->setStrength(SHEEP_STRENGTH);
	this->setInitiative(SHEEP_INITIATIVE);
	this->setAge(0);
}

void Sheep::print() {
	gotoxy(XSTART + this->getX(), YSTART + this->getY());
	cout << SHEEP;
}

Organism* Sheep::createNew(int x, int y) {
	return new Sheep(x, y);
}

char Sheep::getSign() { return SHEEP; }

Sheep::Sheep(int x, int y, int age, int initiative, int strength) {
	this->setStrength(strength);
	this->setX(x);
	this->setY(y);
	this->setAge(age);
	this->setInitiative(initiative);
}