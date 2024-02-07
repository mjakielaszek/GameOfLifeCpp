#include "Antelope.h"
#include "Commentator.h"
Antelope::Antelope()
{
}

Antelope::Antelope(int x, int y) {
	this->setX(x);
	this->setY(y);
	this->setAge(0);
	this->setInitiative(ANTELOPE_INITIATIVE);
	this->setStrength(ANTELOPE_STRENGTH);
}

void Antelope::print() {
	gotoxy(XSTART + this->getX(), YSTART + this->getY());
	cout << ANTELOPE;
}

void Antelope::action(int key) {
	int dir = rand() % MOVE_OPTIONS;
	switch (dir) {
	case 0:
		if (this->getX() > 1 && find_organism(*organisms, this->getX() - 2, this->getY()) == NULL) {
			this->changeX(-ANTELOPE_MOVEMENT);
			break;
		}
		collisionCheck(*organisms, this->getX() - 2, this->getY());
		break;
	case 1:
		if (this->getX() < getXsize() - 2 && find_organism(*organisms, this->getX() + 2, this->getY()) == NULL) {
			this->changeX(ANTELOPE_MOVEMENT);
			break;
		}
		collisionCheck(*organisms, this->getX() + 2, this->getY());
		break;
	case 2:
		if (this->getY() > 1 && find_organism(*organisms, this->getX(), this->getY() - 2) == NULL) {
			this->changeY(-ANTELOPE_MOVEMENT);
			break;
		}
		collisionCheck(*organisms, this->getX(), this->getY() - 2);
		break;
	case 3:
		if (this->getY() < getYsize() - 2 && find_organism(*organisms, this->getX(), this->getY() + 2) == NULL) {
			this->changeY(ANTELOPE_MOVEMENT);
			break;
		}
		collisionCheck(*organisms, this->getX(), this->getY() + 2);
		break;
	}
}

Organism* Antelope::createNew(int x, int y) {
	return new Antelope(x, y);
}

void Antelope::collision(Organism* organism) {
	if (typeid(*this) == typeid(*organism)) {
		spawnNew(100);
		return;
	}
	int survival = rand() % 100;
	if (survival > ESCAPE_CHANCE) {
		Commentator::antelopeEscape(3 * getXsize(), YSTART + Commentator::height);
		action(0);
	}
	else fightHandling(organism);
	return;
}

char Antelope::getSign() { return ANTELOPE; }

Antelope::Antelope(int x, int y, int age, int initiative, int strength) {
	this->setStrength(strength);
	this->setX(x);
	this->setY(y);
	this->setAge(age);
	this->setInitiative(initiative);
}