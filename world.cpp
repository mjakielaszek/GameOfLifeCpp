#include "world.h"
#include "desi.h"
#include "human.h"
#include "Wolf.h"
#include "Antelope.h"
#include "Belladonna.h"
#include "CyberSheep.h"
#include "Fox.h"
#include "Grass.h"
#include "Guarana.h"
#include "Hogweed.h"
#include "sheep.h"
#include "SowThistle.h"
#include "Turtle.h"
#include "Commentator.h"

using namespace std;

void World::sort_all(vector<Organism*>& all) {
	auto sortuj = [](Organism* i, Organism* j) {
		if (i->getInitiative() != j->getInitiative()) return i->getInitiative() > j->getInitiative();
		if (i->getInitiative() == j->getInitiative()) return i->getAge() > j->getAge();
	};
	sort(all.begin(), all.end(), sortuj);
}

int World::getX() {
	return this->xSize;
}

int World::getY() {
	return this->ySize;
}
World::World() {
	this->xSize = XSIZE;
	this->ySize = YSIZE;
	initAll();
	drawWorld();
};

World ::World(int x, int y) {
	this->xSize = x;
	this->ySize = y;
	initAll();
	drawWorld();
};

void World::drawWorld() {
	gotoxy(XSTART-1, YSTART-1);
	cout << "#";
	for (int i = 0; i < getX() + 1; i++) {
		gotoxy(XSTART + i, YSTART - 1);
		cout << "#";
		gotoxy(XSTART + i, YSTART + getY());
		cout << "#";
	}
	for (int i = 0; i < getX() + 1; i++) {
		gotoxy(XSTART - 1, YSTART + i);
		cout << "#";
		gotoxy(XSTART + getX(), YSTART + i);
		cout << "#";
	}
	for (int i = 0; i < this->organisms.size(); i++) {
		Organism* data = Organism::getItem(organisms, i);
		if (data == NULL) continue;
		gotoxy(XSTART + data->getX(), YSTART + data->getY());
		data->print();
	}
	Commentator::texts("use arrows to navigate the human (H)", XSTART + this->getX() + 5, YSTART - 1);
	Commentator::texts(" , - grass", XSTART + this->getX() + 5, YSTART + 1);
	Commentator::texts(" $ - sow thistle", XSTART + this->getX() + 5, YSTART + 2);
	Commentator::texts(" % - hogweed", XSTART + this->getX() + 5, YSTART + 3);
	Commentator::texts(" * - belladonna", XSTART + this->getX() + 5, YSTART + 4);
	Commentator::texts(" ^ - guarana", XSTART + this->getX() + 5, YSTART + 5);
	Commentator::texts("press s to save the game", XSTART , YSTART + this->getY() + 2);
	Commentator::texts("press l to load the game", XSTART , YSTART + this->getY() + 3);
}

void World::initAll() {
	srand(time(0));
	int humanX = rand() % this->getX();
	int humanY = rand() % this->getY();
	this->organisms.push_back(new Human(humanX, humanY));

	for (int i = 0; i < this->getX(); i++) {
		for (int j = 0; j < this->getX(); j++) {
			int q = rand() % 100;
			if (q < DEFAULT_SPAWNRATE && Organism::find_organism(this->organisms, i, j) == NULL) {
				int organismType = rand() % OTHER_ORGANISMS; 
				switch (organismType) {
				case 0:
					this->organisms.push_back(new Wolf(i, j));
					break;
				case 1:
					this->organisms.push_back(new Sheep(i, j));
					break;
				case 2:
					this->organisms.push_back(new Fox(i, j));
					break;
				case 3:
					this->organisms.push_back(new Turtle(i, j));
					break;
				case 4:
					this->organisms.push_back(new Antelope(i, j));
					break;
				case 5:
					this->organisms.push_back(new CyberSheep(i, j));
					break;
				case 6:
					this->organisms.push_back(new Grass(i, j));
					break;
				case 7:
					this->organisms.push_back(new SowThistle(i, j));
					break;
				case 8:
					this->organisms.push_back(new Guarana(i, j));
					break;
				case 9:
					this->organisms.push_back(new Belladonna(i, j));
					break;
				case 10:
					this->organisms.push_back(new Hogweed(i, j));
					break;
				}
			}
		}
	}
}

void World::savingTheGame() {
	fstream file;
	system("cls");
	string name;
	cin >> name;
	file.open(name, fstream::out);
	if (file.good()) cout << "file is proper"<<endl;
	else cout << "file incorrect";
	file << getX() << " " << getY() << " " << organisms.size() << endl;
	for (Organism* temp : organisms) {
		file << temp->getSign() << " ";
		file << temp->getAge() << " ";
		file << temp->getInitiative() << " ";
		file << temp->getX() << " " << temp->getY() << " ";
		file << temp->getStrength() << " ";
		file << endl;
	}
	file.close();
	cout << "game saved to " << name << endl;
	cout << "click enter to continue";
	int control = _getch();
	if (control == 13) {
		system("cls");
		return;
	}
}

void World::loadingTheGame() {
	system("cls");
	cout << "file name:";
	string name;
	cin >> name;
	fstream file;
	file.open(name, fstream::in);
	if (!file.good()) {
		cout << "no file found";
		cout << "click enter to continue";
		int control = _getch();
		if (control == 13) {
			system("cls");
			return;
		}
	}
	else {
		organisms.clear();
		int ammOfOrganisms;
		char sign;
		int xSize, ySize;
		int age, initiative, strength;
		COORDS pos;
		file >> xSize >> ySize >> ammOfOrganisms;
		this->xSize = xSize;
		this->ySize = ySize;
		for (int i = 0; i < ammOfOrganisms; i++) {
			file >> sign >> age >> initiative >> pos.x >> pos.y >> strength;
			switch (sign) {
			case HUMAN:
				this->organisms.push_back(new Human(pos.x, pos.y, age, initiative, strength));
				break;
			case WOLF:
				this->organisms.push_back(new Wolf(pos.x, pos.y, age, initiative, strength));
				break;
			case SHEEP:
				this->organisms.push_back(new Sheep(pos.x, pos.y, age, initiative, strength));
				break;
			case FOX:
				this->organisms.push_back(new Fox(pos.x, pos.y, age, initiative, strength));
				break;
			case TURTLE:
				this->organisms.push_back(new Turtle(pos.x, pos.y, age, initiative, strength));
				break;
			case ANTELOPE:
				this->organisms.push_back(new Antelope(pos.x, pos.y, age, initiative, strength));
				break;
			case GRASS:
				this->organisms.push_back(new Grass(pos.x, pos.y, age, initiative, strength));
				break;
			case SOW_THISLTE:
				this->organisms.push_back(new SowThistle(pos.x, pos.y, age, initiative, strength));
				break;
			case GUARANA:
				this->organisms.push_back(new Guarana(pos.x, pos.y, age, initiative, strength));
				break;
			case HOGWEED:
				this->organisms.push_back(new Hogweed(pos.x, pos.y, age, initiative, strength));
				break;
			case BELLADONNA:
				this->organisms.push_back(new Belladonna(pos.x, pos.y, age, initiative, strength));
				break;
			case CYBER_SHEEP:
				this->organisms.push_back(new CyberSheep(pos.x, pos.y, age, initiative, strength));
				break;
			}
		}
		system("cls");
		drawWorld();
	}
}

void World::makeTurn(int key, bool* isActive) {
	Commentator::reset();
	system("cls");// for windows
//	system("clear"); for unix-like
	sort_all(organisms);
	if (key == SAVE) {
		savingTheGame();
		return;
	}
	if (key == LOAD) {
		loadingTheGame();
		return;
	}
	for (int i = 0; i < this->organisms.size(); i++)	this->organisms[i]->SetWorldData(&this->organisms, getX(), getY());
	for (int i = 0; i < this->organisms.size(); i++) {
		if (this->organisms[i] != NULL) {
			this->organisms[i]->modifyAge(1);
			this->organisms[i]->action(key);
		}
	}
	int human = 0;
	for (int i = 0; i < this->organisms.size(); i++) {
		if (typeid(*this->organisms[i]) == typeid(Human)) 
			human++;
	}
	if (human == 0) *isActive = false;
	drawWorld();
}