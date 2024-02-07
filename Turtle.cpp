#include "Turtle.h"
#include "Commentator.h"
Turtle::Turtle()
{
}

Turtle::Turtle(int x, int y) {
	this->setX(x);
	this->setY(y);
	this->setStrength(TURTLE_STRENGTH);
	this->setInitiative(TURTLE_INITIATIVE);
	this->setAge(0);
}

void Turtle::print() {
	gotoxy(XSTART + this->getX(), YSTART + this->getY());
	cout << TURTLE;
}

void Turtle::action(int key) {
	int act = rand() % 100;
	if (act > 70) {
		int dir = rand() % MOVE_OPTIONS;
		switch (dir) {
		case 0:
			if (this->getX() > 0 && find_organism(*organisms, this->getX() - 1, this->getY()) == NULL) {
				this->changeX(-1);
				break;
			}
			collisionCheck(*organisms, this->getX() - 1, this->getY());
			break;
		case 1:
			if (this->getX() < getXsize() - 1 && find_organism(*organisms, this->getX() + 1, this->getY()) == NULL) {
				this->changeX(1);
				break;
			}
			collisionCheck(*organisms, this->getX() + 1, this->getY());
			break;
		case 2:
			if (this->getY()>0 && find_organism(*organisms, this->getX(), this->getY()-1) == NULL) {
				this->changeY(-1);
				break;
			}
			collisionCheck(*organisms, this->getX(), this->getY()-1);
			break;
		case 3:
			if (this->getY() < getYsize() - 1 && find_organism(*organisms, this->getX(), this->getY() + 1) == NULL) {
				this->changeY(1);
				break;
			}
			collisionCheck(*organisms, this->getX(), this->getY()+1);
			break;
		}
	}
}

Organism* Turtle::createNew(int x, int y) {
	return new Turtle(x, y);
}

void Turtle::collision(Organism* organism) {
	if (organism->getStrength() < TURTLE_PROTECTION) {
		Commentator::turtleDeflected(Organism::getName(this), Organism::getName(organism), 3 * getXsize(), YSTART + Commentator::height);
		return;
	}
	if (organism->getStrength() >= TURTLE_PROTECTION) fightHandling(organism);
};

char Turtle::getSign() { return TURTLE; }

Turtle::Turtle(int x, int y, int age, int initiative, int strength) {
	this->setStrength(strength);
	this->setX(x);
	this->setY(y);
	this->setAge(age);
	this->setInitiative(initiative);
}
