#include "Hogweed.h"
#include "CyberSheep.h"
Hogweed::Hogweed() {}
Hogweed::Hogweed(int x, int y) {
	this->setX(x);
	this->setY(y);
	this->setInitiative(PLANT_INITIATIVE);
	this->setStrength(HOGWEED_STRENGTH);
	this->setAge(0);
}
void Hogweed::print() {
	gotoxy(XSTART + this->getX(), YSTART + this->getY());
	cout << HOGWEED;
}
void Hogweed::action(int key) {
	if (this->getY() < getYsize() - 1) {
		if (Organism::find_organism(*this->organisms, this->getX(), this->getY() + 1) != NULL &&
			typeid(*Organism::find_organism(*this->organisms, this->getX(), this->getY() + 1)) != typeid(CyberSheep))
				remove_item(*this->organisms, Organism::find_organism(*this->organisms, this->getX(), this->getY() + 1));
	}
	if (this->getY() > 0) {
		if (Organism::find_organism(*this->organisms, this->getX(), this->getY() - 1) != NULL && 
			typeid(*Organism::find_organism(*this->organisms, this->getX(), this->getY() - 1)) != typeid(CyberSheep))
				remove_item(*this->organisms, Organism::find_organism(*this->organisms, this->getX(), this->getY() - 1));
	}
	if (this->getX() < getXsize() - 1) {
		if (Organism::find_organism(*this->organisms, this->getX() + 1, this->getY()) != NULL && 
			typeid(*Organism::find_organism(*this->organisms, this->getX() + 1, this->getY())) != typeid(CyberSheep))
				remove_item(*this->organisms, Organism::find_organism(*this->organisms, this->getX()+1, this->getY()));
	}
	if (this->getX() > 0) {
		if (Organism::find_organism(*this->organisms, this->getX() - 1, this->getY()) != NULL &&
			typeid(*Organism::find_organism(*this->organisms, this->getX() - 1, this->getY())) != typeid(CyberSheep))
				remove_item(*this->organisms, Organism::find_organism(*this->organisms, this->getX()-1, this->getY()));
	}
};

Organism* Hogweed::createNew(int x, int y) {
	return new Hogweed(x, y);
}

char Hogweed::getSign() { return HOGWEED; }

Hogweed::Hogweed(int x, int y, int age, int initiative, int strength) {
	this->setStrength(strength);
	this->setAge(age);
	this->setX(x);
	this->setY(y);
	this->setInitiative(initiative);
}