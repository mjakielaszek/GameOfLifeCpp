#pragma once

#include "desi.h"
#include "organism.h"

using namespace std;

class World {
private:
	World();
	void initAll();
	void drawWorld();
	void savingTheGame();
	void loadingTheGame();
	int xSize, ySize;
	vector<Organism*> organisms;
public:
	int getX();
	int getY();
	World(int x, int y);
	void sort_all(vector<Organism*>& all);
	void makeTurn(int key, bool* isActive);
};