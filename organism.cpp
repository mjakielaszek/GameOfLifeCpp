#include "organism.h"
#include "Commentator.h"

Organism::Organism()
{
	this->setX(0);
	this->setY(0);
	this->setStrength(0);
	this->setInitiative(0);
	this->setAge(0);
}

Organism::~Organism()
{
}

void Organism::setXsize(int x) { this->xSize = x; };
void Organism::setYsize(int y) { this->ySize = y; };

void Organism::spawnNew(int chances) {
	int spawn = rand() % 100;
	if (spawn < chances) {
		Commentator::breeding(Organism::getName(this), 3*this->getXsize(), YSTART + Commentator::height);
		int dir = rand() % MOVE_OPTIONS;
		switch (dir) {
		case 0:
			if (this->getX() > 0 && Organism::find_organism(*this->organisms, this->getX() - 1, this->getY()) == NULL)
				add_new_item(*this->organisms, this->createNew(this->getX() - 1, this->getY()));
			break;
		case 1:
			if (this->getX() < getXsize() - 1 && Organism::find_organism(*this->organisms, this->getX() + 1, this->getY()) == NULL)
				add_new_item(*this->organisms, this->createNew(this->getX() + 1, this->getY()));
			break;
		case 2:
			if (this->getY() > 0 && Organism::find_organism(*this->organisms, this->getX(), this->getY() - 1) == NULL)
				add_new_item(*this->organisms, this->createNew(this->getX(), this->getY() - 1));
			break;
		case 3:
			if (this->getY() < getYsize() - 1 && Organism::find_organism(*this->organisms, this->getX(), this->getY() + 1) == NULL)
				add_new_item(*this->organisms, this->createNew(this->getX(), this->getY() + 1));
			break;
		}
	}
}

void Organism::collisionCheck(vector<Organism*> organisms, int x, int y) {
	if (find_organism(organisms, x, y) != NULL) {
		collision(find_organism(organisms, x, y));
		return;
	}
}

void Organism::SetWorldData(vector<Organism*>* organisms, int x, int y) {
	this->organisms = organisms;
	setXsize(x);
	setYsize(y);
}

string Organism::getName(Organism* organism) {
	string type = typeid(*organism).name();
	string name;
	size_t pos = type.find("class ");
	if (pos != string::npos) {
		pos += 6;
		name = type.substr(pos);
	}
	else {
		name = type;
	}
	return name;
}

int Organism::getX() { return this->position.x; }
int Organism::getY() { return this->position.y; }
int Organism::getAge() { return this->age; }
int Organism::getStrength() { return this->strength; }
int Organism::getInitiative() {	return this->initiative; }
void Organism::increaseStrength(int modify) { this->strength += modify; }
void Organism::modifyAge(int modify) { this->age += modify; }
void Organism::changeX(int change) { this->position.x += change; }
void Organism::changeY(int change) { this->position.y += change; }
void Organism::setX(int x) { this->position.x = x; };
void Organism::setY(int y) { this->position.y = y; };
void Organism::setStrength(int str) { this->strength = str; };
void Organism::setInitiative(int init) { this->initiative = init; };
void Organism::setAge(int age) { this->age = age; };
int Organism::getXsize() { return this->xSize; };
int Organism::getYsize() { return this->ySize; };
COORDS Organism::getPosition() { return this->position; };
void Organism::setPosition(COORDS pos) { this->position = pos; };