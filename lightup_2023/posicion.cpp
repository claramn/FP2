#include "posicion.h"


void iniciaPosicion(tPosicion& pos, int xx, int yy) {
	pos.x = xx;
	pos.y = yy;
}

void destruyePosicion(tPosicion& pos) {
	pos.x = -1;
	pos.y = -1;
}


bool operator==(const tPosicion& p1, const tPosicion& p2) {
	return (p1.x == p2.x && p1.y == p2.y);
}

ofstream& operator<<(ofstream& archivo, const tPosicion& p) {
	archivo << p.x << " " << p.y;
	return archivo;
}

int dameX(const tPosicion& pos) {
	return pos.x;
}

int dameY(const tPosicion& pos) {
	return pos.y;
}
