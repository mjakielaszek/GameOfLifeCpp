#include "Plant.h"
Plant::Plant() {
	this->setInitiative(PLANT_INITIATIVE);
}

void Plant::action(int key) {
	Organism::spawnNew(PLANT_SOW_RATE);
};
