#include "listaPosiciones.h"

void iniciaListaPosiciones(tListaPosiciones& lp) {
	lp.cont = 0;
	lp.size = DIM;
	lp.arrayPos = new tPosicion[DIM];
	
}


void destruyeListaPosiciones(tListaPosiciones& lp) {
	for (int i = 0; i < lp.cont; i++) {
		destruyePosicion(lp.arrayPos[i]);
	}
	lp.cont = 0;
	lp.size = 0;
	delete[] lp.arrayPos;
	lp.arrayPos = NULL;
}

void resize(tListaPosiciones& lp, tPosicion pos) { // funcion privada
	int cont = lp.cont;
	int newSize = lp.size * 2;
	tPosicion* aux = new tPosicion[newSize];
	// copiamos lp en aux
	for (int i = 0; i < lp.cont; i++) {
		aux[i] = lp.arrayPos[i];
	}
	destruyeListaPosiciones(lp);
	lp.cont = cont;
	lp.size = newSize;
	lp.arrayPos = aux;
	aux = NULL;
}


void insertar(tListaPosiciones& lp, const tPosicion& pos) {
	if (lp.cont == lp.size) {
		resize(lp, pos);
	}
	lp.arrayPos[lp.cont] = pos;
	lp.cont++;
}



int dameNumElem(const tListaPosiciones& lp) {
     return lp.cont;
}

tPosicion dameElem(const tListaPosiciones& lp, int i) {
	return lp.arrayPos[i];
}


ofstream& operator<<(ofstream& archivo, const tListaPosiciones& lp) {
	archivo << lp.cont << endl;
	for (int i = 0; i < lp.cont; i++) {
		archivo << lp.arrayPos[i] << endl;
	}
	return archivo;
}
