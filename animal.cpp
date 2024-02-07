#include "animal.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Guarana.h"
#include "Commentator.h"
using namespace std;

Animal::Animal() 
: Organism()
{
}


void Animal::action(int move){
	int dir = rand() % MOVE_OPTIONS;
	switch (dir) {
	case 0:
		if (getX() > 0 && find_organism(*organisms, getX() - 1, getY()) == NULL) {
			this->changeX(-1);
			break;
		}
		collisionCheck(*organisms, getX() - 1, getY());
		break;
	case 1:
		if (getX() < getXsize() - 1 && find_organism(*organisms, getX() + 1, getY()) == NULL) {
			this->changeX(1);
			break;
		}
		collisionCheck(*organisms, getX() + 1, getY());
		break;
	case 2:
		if (getY() > 0 && find_organism(*organisms,getX(), getY() - 1) == NULL) {
			this->changeY(-1);
			break;
		}
		collisionCheck(*organisms, this->getX(), this->getY() - 1);
		break;
	case 3:
		if (this->getY() < getYsize() - 1 && find_organism(*organisms, this->getX(), this->getY() + 1) == NULL) {
			this->changeY(1);
			break;
		}
		collisionCheck(*organisms, this->getX(), this->getY() + 1);
		break;
	}
}
void Animal::fightHandling(Organism* organism) {
	if (this->getStrength() >= organism->getStrength()) {
		Commentator::fights(Organism::getName(this), Organism::getName(organism), getXsize() * 3, YSTART + Commentator::height);
		COORDS pos = organism->getPosition();
		remove_item(*organisms, organism);
		this->setPosition(pos);
		return;
	}
	if (this->getStrength() < organism->getStrength()) { 
		Commentator::fights(Organism::getName(organism), Organism::getName(this), getXsize() * 3, YSTART + Commentator::height);
		COORDS pos = this->getPosition();
		remove_item(*organisms, this);
		organism->setPosition(pos);
		return;
	}
}

void Animal::collision(Organism* organism) {
	if (typeid(*this) == typeid(*organism)) {
		this->spawnNew(100);
		return;
	}
	else {
		if (typeid(*organism) == typeid(Guarana)) {
			this->increaseStrength(GUARANA_BOOST);
			Commentator::guaranaBoost(Organism::getName(this), 3 * getXsize(), YSTART + Commentator::height);
			COORDS pos = organism->getPosition();
			remove_item(*organisms, organism);
			this->setPosition(pos);
			return;
		}
		if (typeid(*organism) == typeid(Turtle) || typeid(*organism) == typeid(Antelope)) {
			organism->collision(this);
			return;
		}
		fightHandling(organism);
	}
}