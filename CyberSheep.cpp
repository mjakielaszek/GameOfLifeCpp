#include "CyberSheep.h"
#include <algorithm>
#include <vector>
#include <math.h>
#include "Hogweed.h"
CyberSheep::CyberSheep()
{
}

CyberSheep::CyberSheep(int x, int y) {
	this->setX(x);
	this->setY(y);
	this->setAge(0);
	this->setStrength(CYBER_SHEEP_STRENGTH);
	this->setInitiative(CYBER_SHEEP_INITIATIVE);
}

void CyberSheep::print() {
	gotoxy(XSTART + this->getX(), YSTART + this->getY());
	cout << CYBER_SHEEP;
}
void CyberSheep::sort_all(vector<DISTANCE*>& all) {
	auto sortuj = [](DISTANCE* i, DISTANCE* j) { return i->distance < j->distance; };
	sort(all.begin(), all.end(), sortuj);
}

void CyberSheep::action(int key) {
	vector<DISTANCE*> hogweeds;
	for (int i = 0; i < this->organisms->size(); i++) {
		Organism* data = Organism::getItem(*this->organisms, i);
		if (typeid(*data) == typeid(Hogweed)) {
			DISTANCE* hogweed = new DISTANCE;
			hogweed->x = data->getX();
			hogweed->y = data->getY();
			int xDiff = pow(hogweed->x - this->getX(), 2);
			int yDiff = pow(hogweed->y - this->getY(), 2);
			int distance = sqrt(xDiff+yDiff);
			hogweed->distance = distance;
			hogweeds.push_back(hogweed);
		}
	}

	if (hogweeds.size() == 0) {
		Animal::action(key);
		return;
	}

	sort_all(hogweeds);
	if (abs(hogweeds[0]->x - this->getX()) >= abs(hogweeds[0]->y - this->getY())) {
		if (hogweeds[0]->x > this->getX()) {
			if (this->getX() < getXsize() - 1 && find_organism(*organisms, this->getX() - 1, this->getY()) == NULL) {
				this->changeX(1);
				return;
			}
			collisionCheck(*organisms, this->getX() - 1, this->getY());
		}
		if (hogweeds[0]->x < this->getX()) {
			if (this->getX() > 1 && find_organism(*organisms, this->getX() + 1, this->getY()) == NULL) {
				this->changeX(-1);
				return;
			}
			collisionCheck(*organisms, this->getX() + 1, this->getY());
		}
	}
	if (abs(hogweeds[0]->x - this->getX()) < abs(hogweeds[0]->y - this->getY())) {
		if (hogweeds[0]->y > this->getY()) {
			if (this->getY() < getYsize() - 1 && find_organism(*organisms, this->getX(), this->getY() + 1) == NULL) {
				this->changeY(1);
				return;
			}
			collisionCheck(*organisms, this->getX(), this->getY() + 1);
		}
		if (hogweeds[0]->y < this->getY()) {
			if (this->getY() > 1 && find_organism(*organisms, this->getX(), this->getY() - 1) == NULL) {
				this->changeY(-1);
				return;
			}
			collisionCheck(*organisms, this->getX(), this->getY() - 1);
		}
	}
};

Organism* CyberSheep::createNew(int x, int y) {
	return new CyberSheep(x, y);
}

char CyberSheep::getSign() { return CYBER_SHEEP; }

CyberSheep::CyberSheep(int x, int y, int age, int initiative, int strength) {
	this->setStrength(strength);
	this->setX(x);
	this->setY(y);
	this->setAge(age);
	this->setInitiative(initiative);
}