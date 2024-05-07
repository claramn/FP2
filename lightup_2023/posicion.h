#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

typedef struct {
	int x;
	int y;
} tPosicion;


void iniciaPosicion(tPosicion& pos, int xx, int yy); 
void destruyePosicion(tPosicion& pos);
bool operator==(const tPosicion& p1, const tPosicion& p2);
ofstream& operator<<(ofstream& archivo, const tPosicion& p);
int dameX(const tPosicion& pos);
int dameY(const tPosicion& pos);
