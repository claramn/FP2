#include "celdas.h"
using namespace std;

const char BOMB = '*';
const char BOMBI = '.';
const char PAREDSINRES = 'X';
const char ESPACIO = ' ';

void iniciaCelda(tCelda& celda) { }

void destruyeCelda(tCelda& celda) { }

char celdaToChar(const tCelda& celda) {
	char r;
	if (celda.tipo == BOMBILLA) {
		r = BOMB;
	}
	else if (esParedRestringida(celda)) {
		 r = numParedRestringida(celda) + '0';
	}
	else r = ESPACIO;
	
	return r;
}


tCelda charToCelda(char c) {
	tCelda cel ;
	
	 if (c == BOMBI) {
		cel.tipo = LIBRE;
		cel.numBombillas = 0;
	}
	else if (c == PAREDSINRES) {
		cel.tipo = PARED;
		cel.numBombillas = -1;
	}
	else if(c>='0' && c<='4'){
		cel.tipo = PARED;
		cel.numBombillas = c - '0';
	}
	return cel;
}

char celdaToCharArchivo(const tCelda& celda) {
	char r;
	if (celda.tipo == BOMBILLA) {
		r = BOMBI;
	}
	else if (esPared(celda)) {
		if (esParedRestringida(celda)) {
			r = numParedRestringida(celda) + '0';
		}
		else r = PAREDSINRES;
		
	}
	
	else r = BOMBI;

	return r;
}

bool esPared(const tCelda& c) {
	return (c.tipo == PARED);
}


bool esParedRestringida(const tCelda& c) {
	return (c.numBombillas != -1 && c.tipo == PARED);
}

int numParedRestringida(const tCelda& c) {
	return c.numBombillas;
}

bool esBombilla(const tCelda& c) {
	return (c.tipo == BOMBILLA);
}


bool estaApagada(const tCelda& c) {
	return (c.tipo == LIBRE && c.numBombillas == 0);
}


bool estaIluminada(const tCelda& c) {
	bool il = false;
	if (c.tipo == LIBRE && c.numBombillas > 0) il = true;
	return il;
}

void apagaCelda(tCelda& c) {
	if (esBombilla(c)) {
		c.tipo = LIBRE;
		c.numBombillas = 0;
	}
	else if (estaIluminada(c)) {
		c.numBombillas--;
	}
}


void iluminaCelda(tCelda& c) {
	c.tipo = LIBRE;
	c.numBombillas++;
}

void ponBombilla(tCelda& c) {
	c.tipo = BOMBILLA;
}



