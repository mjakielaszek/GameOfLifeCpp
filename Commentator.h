#pragma once
#include "desi.h"
class Commentator
{
public:
	Commentator();
	static int height;
	static void reset();
	static void texts(string text, int x, int y);
	static void fights(string winner, string loser, int x, int y);
	static void sowing(string plant, int x, int y);
	static void breeding(string animal, int x, int y);
	static void bump();
	static void guaranaBoost(string organism, int x, int y);
	static void antelopeEscape(int x, int y);
	static void turtleDeflected(string turtle, string attacker, int x, int y);
	static void consumption(string animal, string plant, int x, int y);
	~Commentator();
};

