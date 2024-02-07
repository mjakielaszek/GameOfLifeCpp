#include "Fox.h"
Fox :: Fox(){}
Fox::Fox(int x, int y) {
	this->setX(x);
	this->setY(y);
	this->setAge(0);
	this->setStrength(FOX_STRENGTH);
	this->setInitiative(FOX_INITIATIVE);
}

void Fox::print() {
	gotoxy(XSTART + this->getX(), YSTART + this->getY());
	cout << FOX;
}
void Fox::action(int key) {
	int availableCells = 0;
	vector<COORDS*> cells;
	if ((Organism::find_organism(*this->organisms, this->getX() + 1, this->getY()) == NULL ||
		Organism::find_organism(*this->organisms, this->getX() + 1, this->getY())->getStrength() < this->getStrength())
		&& this->getX()< getXsize() - 1) {
		availableCells++;
		COORDS* cell = new COORDS;
		cell->x = this->getX() + 1;
		cell->y = this->getY();
		cells.push_back(cell);
	}
	
	if ((Organism::find_organism(*this->organisms, this->getX() - 1, this->getY()) == NULL ||
		Organism::find_organism(*this->organisms, this->getX() - 1, this->getY())->getStrength() < this->getStrength())
		&& this->getX() > 0) {
		availableCells++;
		COORDS* cell = new COORDS;
		cell->x = this->getX() - 1;
		cell->y = this->getY();
		cells.push_back(cell);
	}

	if ((Organism::find_organism(*this->organisms, this->getX(), this->getY() + 1) == NULL ||
		Organism::find_organism(*this->organisms, this->getX(), this->getY() + 1)->getStrength() < this->getStrength())
		&& this->getY() < getYsize() - 1) {
		availableCells++;
		COORDS* cell = new COORDS;
		cell->x = this->getX();
		cell->y = this->getY()+1;
		cells.push_back(cell);
	}

	if ((Organism::find_organism(*this->organisms, this->getX(), this->getY() - 1) == NULL ||
		Organism::find_organism(*this->organisms, this->getX(), this->getY() - 1)->getStrength() < this->getStrength())
		&& this->getY() > 0) {
		availableCells++;
		COORDS* cell = new COORDS;
		cell->x = this->getX();
		cell->y = this->getY() - 1;
		cells.push_back(cell);
	}

	int dir = rand() % availableCells;
	this->setX(cells[dir]->x);
	this->setY(cells[dir]->y);
};

Organism* Fox::createNew(int x, int y) {
	return new Fox(x, y);
}

Fox::Fox(int x, int y, int age, int initiative, int strength) {
	this->setStrength(strength);
	this->setX(x);
	this->setY(y);
	this->setInitiative(initiative);
	this->setAge(age);
}

char Fox::getSign() { return FOX; }