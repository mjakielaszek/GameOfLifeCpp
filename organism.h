#pragma once
#include "desi.h"
using namespace std;

class Organism {
protected:
	void spawnNew(int chances);
	virtual Organism* createNew(int x, int y) = 0;
	static void add_new_item(vector<Organism*>& all, Organism* item) {
		all.push_back(item);
		item->organisms = &all;
		item->setXsize(all[0]->getXsize());
		item->setYsize(all[0]->getYsize());
	};
	void collisionCheck(vector<Organism*> organisms, int x, int y);
	static void remove_item(vector<Organism*>& all, Organism* item) {
		if (all.empty()) return;
		int x = item->position.x;
		int y = item->position.y;
		auto wspolrzedne = [x, y](Organism* data) { return data->position.x == x && data->position.y == y; };
		remove_if(all.begin(), all.end(), wspolrzedne);
	};
	static string getName(Organism* organism);
	COORDS position;
	int xSize, ySize;
	int age;
	int initiative;
	int strength;
	vector<Organism*>* organisms;
public:
	virtual char getSign() = 0;
	Organism();
	int getX();
	int getY();
	int getAge();
	int getStrength();
	int getInitiative();
	void increaseStrength(int modify);
	void modifyAge(int modify);
	void changeX(int change);
	void changeY(int change);
	void setX(int x);
	void setY(int y);
	void setStrength(int str);
	void setInitiative(int init);
	void setAge(int age);
	int getXsize();
	int getYsize();
	void setXsize(int x);
	void setYsize(int y);
	COORDS getPosition();
	void setPosition(COORDS pos);
	virtual void collision(Organism* organism) = 0;
	virtual void action(int move) = 0;
	virtual void print() = 0;
	void SetWorldData(vector<Organism*>* organisms,int x, int y);
	~Organism();
	static Organism* find_organism(vector<Organism*> all, int x, int y) {
		auto wspolrzedne = [x, y](Organism* data) { return data->position.x == x && data->position.y == y; };
		auto result = find_if(all.begin(), all.end(), wspolrzedne);
		if (result != all.end())
		{
			return *result;
		}
		else
		{
			return NULL;
		}
	};
	static Organism* getItem(vector<Organism*> all, int index) {
		return all[index];
	};
};