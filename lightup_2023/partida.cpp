#include "partida.h"
#include "reglasJuego.h"
#include "colors.h"
#include <string>


void iniciaPartida(tPartida& partida) {
	partida.nivel = 0;
	iniciaTablero(partida.tablero);
	iniciaListaPosiciones(partida.listaBombillas);
}

void destruyePartida(tPartida& partida) {
	partida.nivel = 0;
	destruyeTablero(partida.tablero);
	destruyeListaPosiciones(partida.listaBombillas);
}

void leeBombillas(ifstream& archivo, tListaPosiciones& listaBombillas) { // funcion privada
	int nBomb;
	archivo >> nBomb;
	int f;
	int c;
	for (int i = 0; i < nBomb; i++) {
		archivo >> f >> c;
		tPosicion pos;
		iniciaPosicion(pos, f, c);
		insertar(listaBombillas, pos);
	}
}

ifstream& operator>>(ifstream& archivo, tPartida& partida) {
	string nivel;
	int n;
	archivo >> nivel;
	archivo >> n;
	partida.nivel = n;
	archivo >> partida.tablero;
	leeBombillas(archivo, partida.listaBombillas);
	return archivo;
}

bool operator<(const tPartida& partida, int nivel) {
	return (partida.nivel < nivel);
}

bool operator<(const tPartida& partida1, const tPartida& partida2) {
	return (partida1.nivel < partida2.nivel);
  }

void enciendeBombillas(tPartida& p) {	// funcion privada
	int cont = dameNumElem(p.listaBombillas);
	for (int i = 0; i < cont; i++) {
		
		int x = dameX(dameElem(p.listaBombillas, i));
		int y = dameY(dameElem(p.listaBombillas, i));
		ejecutarPos(p.tablero, x, y);
	}
}

void pedirPorConsola(int& x, int& y) {	// funcion privada
	cout << "Introduce la posicion: ";
	cin >> x >> y;
	cout << endl;
}

void actualizaListaBombillas(tPartida& p) {	// funcion privada
	tCelda cel; 
	iniciaListaPosiciones(p.listaBombillas);
	for (int i = 0; i < getNumFilas(p.tablero); i++) {
		for (int j = 0; j < getNumCols(p.tablero); j++) {
			cel = celdaEnPos(p.tablero, i, j);
			if (esBombilla(cel)) {
				tPosicion pos;
				iniciaPosicion(pos, i, j);
				insertar(p.listaBombillas, pos);
			}
		}
	}
}

bool juega(tPartida& partida, int& nIt) {
	enciendeBombillas(partida);
	destruyeListaPosiciones(partida.listaBombillas);
	bool quit = false;
	cout << partida.tablero;
	int x = 0;
	int y = 0;
	nIt = 0;
	while (!estaTerminado(partida.tablero) && !esPosQuit(x, y)) {
		pedirPorConsola(x, y);
		ejecutarPos(partida.tablero, x, y);
		nIt++;
		cout << partida.tablero;
	}
	cout << endl;
	if (esPosQuit(x, y)) {
		quit = true;
	}
	actualizaListaBombillas(partida);
	return quit;
}


ofstream& operator<<(ofstream& archivo, const tPartida& p) {
	archivo << "LEVEL " << p.nivel << endl;
	archivo << p.tablero;
	archivo << p.listaBombillas;
	return archivo;
}

