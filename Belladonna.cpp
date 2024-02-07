#include "Belladonna.h"
Belladonna::Belladonna() {}
Belladonna::Belladonna(int x, int y) {
	this->setX(x);
	this->setY(y);
	this->setStrength(BELLADONNA_STRENGTH);
	this->setAge(0);
	this->setInitiative(PLANT_INITIATIVE);
}
void Belladonna::print() {
	gotoxy(XSTART + this->getX(), YSTART + this->getY());
	cout << BELLADONNA;
}
Organism* Belladonna::createNew(int x, int y) {
	return new Belladonna(x, y);
};
char Belladonna::getSign() { return BELLADONNA; }

Belladonna::Belladonna(int x, int y, int age, int initiative, int strength) {
	this->setStrength(strength);
	this->setAge(age);
	this->setX(x);
	this->setY(y);
	this->setInitiative(initiative);
}