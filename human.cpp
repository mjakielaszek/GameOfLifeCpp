#include "human.h"
#include "Commentator.h"
Human::Human()
{
}

Human::Human(int x, int y) {
	this->setX(x);
	this->setY(y);
	this->setInitiative(HUMAN_INITIATIVE);
	this->setStrength(HUMAN_STRENGTH);
	this->setAge(0);
	this->resetAbilityCooldown();
	this->setOnCooldown(false);
	this->setAbilityActive(false);
}

void Human::print() {
	gotoxy(this->getX() + XSTART, this->getY() + YSTART);
	cout << HUMAN;
}

void Human::action(int key) {
	gotoxy(XSTART + getXsize() + 15, YSTART);
	cout << Organism::getName(this);
	switch (key) {
	case ARROW_DOWN:
		if (this->getY() < getYsize() - 1 && find_organism(*organisms, this->getX(), this->getY() + 1) == NULL) {
			this->changeY(1);
			break;
		}
		collisionCheck(*organisms, this->getX(), this->getY() + 1);
		break;
	case ARROW_UP:
		if (this->getY() > 0 && find_organism(*organisms, this->getX(), this->getY() - 1) == NULL) {
			this->changeY(-1);
			break;
		}
		collisionCheck(*organisms, this->getX(), this->getY() - 1);
		break;
	case ARROW_RIGHT:
		if (this->getX() < getXsize() - 1 && find_organism(*organisms, this->getX() + 1, this->getY()) == NULL) {
			this->changeX(1);
			break;
		}
		collisionCheck(*organisms, this->getX() + 1, this->getY());
		break;
	case ARROW_LEFT:
		if (this->getX() > 0 && find_organism(*organisms, this->getX() - 1, this->getY()) == NULL) {
			this->changeX(-1);
			break;
		}
		collisionCheck(*organisms, this->getX() - 1, this->getY());
		break;
	}
	if (!this->getAbilityActive() && !this->getOnCooldown())	Commentator::texts("press P to use magic potion", XSTART + getXsize() + 5, YSTART);
	if (this->getOnCooldown()) {
		Commentator::texts("the magic potion is on cooldown", XSTART + getXsize() + 5, YSTART);
		setAbilityCooldown(1);
	}
	if (getAbilityCooldown() == 5) {
		this->setOnCooldown(false);
		this->resetAbilityCooldown();
	}
	if (this->getAbilityActive()) {
		Commentator::texts("magic potion is active!", XSTART + getXsize() + 5, YSTART);
		this->increaseStrength(-1);
		if (this->getStrength() == 5) {
			this->setOnCooldown(true);
			this->setAbilityActive(false);
		}
	}
	if (key == SPECIAL_ABILITY) {
		if (this->getAbilityActive()) Commentator::texts("magic potion is already active!", XSTART + getXsize() + 5, YSTART);
		if (this->getOnCooldown()) Commentator::texts("magic potion is currently on cooldown", XSTART + getXsize() + 5, YSTART);
		if (this->getOnCooldown() == false && this->getAbilityActive() == false) {
			this->increaseStrength(STRENGTH_BOOSTED);
			this->setAbilityActive(true);
			Commentator::texts("the magic potion is active!", XSTART + getXsize() + 5, YSTART);
		}
	}
}

Organism* Human::createNew(int x, int y) {
	return new Human(x, y);
}

char Human::getSign() { return HUMAN; }

bool Human::getOnCooldown() { return this->onCooldown; };
bool Human::getAbilityActive() { return this->abilityActive; };
void Human::setAbilityCooldown(int value) { this->abilityCooldown += value; };
void Human::setAbilityActive(bool value) { this->abilityActive = value; };
void Human::setOnCooldown(bool value) { this->onCooldown = value; };
int Human::getAbilityCooldown() { return this->abilityCooldown; };
void Human::resetAbilityCooldown() { this->abilityCooldown = 0; };

Human::Human(int x, int y, int age, int initiative, int strength) {
	this->strength = strength;
	this->position.x = x;
	this->position.y = y;
	this->age = age;
	this->initiative = initiative;
	this->abilityCooldown = 0;
	this->onCooldown = false;
	this->abilityActive = false;
}
