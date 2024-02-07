#include "Guarana.h"
Guarana::Guarana() {}
Guarana::Guarana(int x, int y) {
	this->setX(x);
	this->setY(y);
	this->setStrength(GUARANA_STRENGTH);
	this->setAge(0);
	this->setInitiative(PLANT_INITIATIVE);
}
void Guarana::print() {
	gotoxy(XSTART + this->getX(), YSTART + this->getY());
	cout << GUARANA;
}

Organism* Guarana::createNew(int x, int y) {
	return new Guarana(x, y);
}

char Guarana::getSign() { return GUARANA; }

Guarana::Guarana(int x, int y, int age, int initiative, int strength) {
	this->setStrength(strength);
	this->setX(x);
	this->setY(y);
	this->setAge(age);
	this->setInitiative(initiative);
}