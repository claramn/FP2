#include "listaPartidas.h"

void iniciaListaPartidas(tListaPartidas& listaPartidas) {
	listaPartidas.nElem = 0;
}

void destruyeListaPartidas(tListaPartidas& listaPartidas) {
	for (int i = 0; i < listaPartidas.nElem; i++) {
		destruyePartida(*listaPartidas.datos[i]);
		delete []listaPartidas.datos[i];
		listaPartidas.datos[i] = NULL;
		
	}
	iniciaListaPartidas(listaPartidas);
	
}



int buscaPos(const tListaPartidas& listaPartidas, int nivel) {
	int i = 0;
	while (i < listaPartidas.nElem && *listaPartidas.datos[i] < nivel) i++;
	return i;
}


void insertarOrd(tListaPartidas& listaPartidas, const tPartida& partida) {
	if (listaPartidas.nElem < MAX_PARTIDAS - 1) {	
		int i = 0;
		while (i < listaPartidas.nElem && *listaPartidas.datos[i] < partida) 
			i++;
		for (int x = listaPartidas.nElem; x > i; x--) {
			listaPartidas.datos[x] = listaPartidas.datos[x - 1];
		}
		listaPartidas.datos[i] = new tPartida(partida);
		*listaPartidas.datos[i] = partida;
		listaPartidas.nElem++;
	}
}



ifstream& operator>>(ifstream& archivo, tListaPartidas& lp) {
	int numPartidas;
	archivo >> numPartidas;
	for (int i = 0; i < numPartidas; i++) {
		tPartida partida;
		iniciaPartida(partida);
		archivo >> partida;
		insertarOrd(lp, partida);
	}
	return archivo;
}   


tPtrPartida dameElem(const tListaPartidas& listaPartidas, int pos) {
	tPartida *p;
	if (MAX_PARTIDAS < pos) {
		p = NULL;
	}
	else {
		p = listaPartidas.datos[pos];
	}
	return p;
}


int dameNumElem(const tListaPartidas& listaPartidas) {
	return listaPartidas.nElem;
}


ofstream& operator<<(ofstream& archivo, const tListaPartidas& lp) {
	archivo << lp.nElem << endl;
	for (int i = 0; i < lp.nElem; i++) {
		archivo << *lp.datos[i];
	}
	return archivo;
}


void eliminarPartida(tListaPartidas& lp, const tPartida& p) {
	int i = 0;
	while (i < lp.nElem && *lp.datos[i] < p) i++;
	if (i < lp.nElem) {
		destruyePartida(*lp.datos[i]);
		delete lp.datos[i];
		for (int j = i; j < lp.nElem - 1; j++) {
			lp.datos[j] = lp.datos[j + 1];
		}
		
		lp.datos[lp.nElem] = NULL;
		lp.nElem--;
	}
}
