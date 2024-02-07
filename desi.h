#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <fstream>
using namespace std;

#define XSIZE 20
#define YSIZE 20
#define MOVE_OPTIONS 4
#define DEFAULT_SPAWNRATE 10
#define XSTART 2
#define YSTART 2
#define OTHER_ORGANISMS 11
#define TURTLE_ACTION 70
#define ANTELOPE_MOVEMENT 2
#define PLANT_SOW_RATE 5
#define STRENGTH_BOOSTED 10
#define ABILITY_COOLDOWN 5

#define HUMAN 'H'
#define HUMAN_STRENGTH 5
#define HUMAN_INITIATIVE 4

#define WOLF 'W'
#define WOLF_STRENGTH 9
#define WOLF_INITIATIVE 5

#define SHEEP 'S'
#define SHEEP_STRENGTH 4
#define SHEEP_INITIATIVE 4

#define FOX 'F'
#define FOX_STRENGTH 3
#define FOX_INITIATIVE 7

#define TURTLE 'T'
#define TURTLE_STRENGTH 2
#define TURTLE_INITIATIVE 1
#define TURTLE_PROTECTION 5

#define ANTELOPE 'A'
#define ANTELOPE_STRENGTH 4
#define ANTELOPE_INITIATIVE 4
#define ESCAPE_CHANCE 50

#define CYBER_SHEEP 'C'
#define CYBER_SHEEP_STRENGTH 11
#define CYBER_SHEEP_INITIATIVE 4

#define PLANT_INITIATIVE 0
#define GRASS ','
#define GRASS_STRENGTH 0
#define SOW_THISLTE '$'
#define SOW_THISLTE_STRENGTH 0
#define HOGWEED '%'
#define HOGWEED_STRENGTH 10
#define BELLADONNA '*'
#define BELLADONNA_STRENGTH 99
#define GUARANA '^'
#define GUARANA_BOOST 3
#define GUARANA_STRENGTH 0

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_RIGHT 77
#define ARROW_LEFT 75
#define SPECIAL_ABILITY 112
#define SAVE 115
#define LOAD 108

struct COORDS {
	int x;
	int y;
};

struct DISTANCE {
	int x;
	int y;
	int distance;
};

void gotoxy(int x, int y);