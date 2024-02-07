#include "Commentator.h"


void Commentator::bump() {
	Commentator::height+=1;
}

Commentator::Commentator()
{
}

void Commentator::reset() {
	Commentator::height = 0;
}
void Commentator::texts(string text, int x, int y) {
	gotoxy(x, y);
	cout << text;
}

void Commentator::fights(string winner, string loser, int x, int y) {
	gotoxy(x, y);
	cout << winner << " eliminated " << loser;
	Commentator::bump();
}

void Commentator::sowing(string plant, int x, int y) {
	gotoxy(x, y);
	cout << plant << " has sowed";
	Commentator::bump();
}

void Commentator::breeding(string animal, int x, int y) {
	gotoxy(x, y);
	cout << animal << " breeded";
	Commentator::bump();
}

void Commentator::guaranaBoost(string animal, int x, int y) {
	gotoxy(x, y);
	cout << animal << " obtained guarana boost!";
	Commentator::bump();
}

void Commentator::antelopeEscape(int x, int y) {
	gotoxy(x, y);
	cout << "anetelope has escaped the fight!";
	Commentator::bump();
}

void Commentator::turtleDeflected(string turtle, string attacker, int x, int y) {
	gotoxy(x, y);
	cout << turtle << " has deflected " << attacker << "'s attack";
	Commentator::bump();
}

Commentator::~Commentator()
{
}

void Commentator::consumption(string animal, string plant, int x, int y) {
	gotoxy(x, y);
	cout << animal << " ate " << plant;
	Commentator::bump();
}