#include "SowThistle.h"
SowThistle::SowThistle() {

}
SowThistle::SowThistle(int x, int y) {
	this->setAge(0);
}
void SowThistle::print() {
	gotoxy(XSTART + this->getX(), YSTART + this->getY());
	cout << SOW_THISLTE;
}
void SowThistle::action(int key) {
	int sow = rand() % 100;
	if (sow < 3*PLANT_SOW_RATE) {
		int dir = rand() % MOVE_OPTIONS;
		switch (dir) {
		case 0:
			if (this->getX() > 0 && Organism::find_organism(*this->organisms, this->getX() - 1, this->getY()) == NULL)
				Plant::add_new_item(*this->organisms, this->createNew(this->getX() - 1, this->getY()));
			break;
		case 1:
			if (this->getX() < getXsize() - 1 && Organism::find_organism(*this->organisms, this->getX() + 1, this->getY()) == NULL)
				Plant::add_new_item(*this->organisms, this->createNew(this->getX() + 1, this->getY()));
			break;
		case 2:
			if (this->getY() > 0 && Organism::find_organism(*this->organisms, this->getX(), this->getY() - 1) == NULL)
				Plant::add_new_item(*this->organisms, this->createNew(this->getX(), this->getY() - 1));
			break;
		case 3:
			if (this->getY() < getYsize() - 1 && Organism::find_organism(*this->organisms, this->getX(), this->getY() + 1) == NULL)
				Plant::add_new_item(*this->organisms, this->createNew(this->getX(), this->getY() + 1));
			break;
		}
	}

};

Organism* SowThistle::createNew(int x, int y) {
	return new SowThistle(x, y);
}

char SowThistle::getSign() { return SOW_THISLTE; }

SowThistle::SowThistle(int x, int y, int age, int initiative, int strength) {
	this->setStrength(strength);
	this->setX(x);
	this->setY(y);
	this->setAge(age);
	this->setInitiative(initiative);
}