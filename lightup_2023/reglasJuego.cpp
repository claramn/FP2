#include "reglasJuego.h"
#include "tablero.h"
#include "colors.h"
#include <iomanip>

const int NUM_DIRECCIONES = 4;
const int DIR2D = 2;
const int DIRECCIONES[NUM_DIRECCIONES][DIR2D] = { 0,-1,0,1,1,0,-1,0 };


bool comprobarPos(const tTablero tab, int i, int j) {
	return(0 <= i && 0 <= j && i <= getNumFilas(tab) && j <= getNumCols(tab));
}

int BombParedRes(const tTablero tab, int i, int j, int incri, int incrj) {
	int isig = i + incri;
	int jsig = j + incrj;
	int cont = 0;
	if (esBombilla(celdaEnPos(tab, isig, jsig))) cont++;
	return cont;
}

bool contadorParedCorrecto(const tTablero tab, int i, int j) {
	bool si = false;
	int cont = 0;
	int bomb = numParedRestringida(celdaEnPos(tab, i, j));
	for (int d = 0; d < NUM_DIRECCIONES; d++) {
		cont = cont + BombParedRes(tab, i, j, DIRECCIONES[d][0], DIRECCIONES[d][1]);
	}
	if (cont == bomb) si = true;
	return si;
}

void ilumApagFilCol(tTablero& tab, int i, int j, int incri, int incrj, bool apagIlum) {
	tCelda cel;
	i = i + incri;
	j = j + incrj;
	cel = celdaEnPos(tab, i, j);
	while (!esPared(cel) && !esParedRestringida(cel) && comprobarPos(tab, i, j)) {
		if (apagIlum == false) {
			apagaCelda(cel);
			ponCeldaEnPos(tab, i, j, cel);
		}
		else {
			iluminaCelda(cel);
			ponCeldaEnPos(tab, i, j, cel);
		}
		i = i + incri;
		j = j + incrj;
		cel = celdaEnPos(tab, i, j);
	}
}



void ilumApagZona(tTablero& tab, int i, int j, bool apagIlum) {
	for (int d = 0; d < NUM_DIRECCIONES; d++) {
		ilumApagFilCol(tab, i, j, DIRECCIONES[d][0], DIRECCIONES[d][1], apagIlum);
	}
}


bool estaTerminado(const tTablero& juego) {
	tCelda cel;
	bool seguir = true;
	bool fin = false;
	int i = 0;
	while (seguir && i < getNumFilas(juego)) {
		int j = 0;
		while (j < getNumCols(juego)&& seguir) {
			bool iluminada = estaIluminada(celdaEnPos(juego, i, j));
			if (iluminada || esBombilla(celdaEnPos(juego, i, j))) {
				j++; 
				seguir = true;
			}
			else if (esPared(celdaEnPos(juego, i, j))) {
				if (esParedRestringida(celdaEnPos(juego, i, j))) {
					if (!contadorParedCorrecto(juego, i, j)) seguir = false;
				}
				j++;
			}
			else {
				seguir = false;
			}
		}
		i++;
	}
	if (seguir==false)  fin = false;
	else {
		fin = true;
		cout << BG_BLACK << ROSE << endl;
		cout << right << setw(35) << "--- TABLERO COMPLETADO CORRECTAMENTE ---" << RESET << endl << endl;
	}
	return fin;
}


bool esPosQuit(int x, int y) {
	return (x == -1 && y == 0);
}

bool esPosReset(int x, int y) {
	return (x == -1 && y == -1);
}



void ejecutarPos( tTablero& tab, int x, int y) {
	tCelda cel;
	cel = celdaEnPos(tab, x, y);
	if (esPosReset(x,y)) {
		cout << "La partida se ha reiniciado " << endl;
		for (int i = 0; i < getNumFilas(tab); i++) {
			for (int j = 0; j < getNumCols(tab); j++) {
				cel = celdaEnPos(tab, i, j);
				while ( (esBombilla(cel) || estaIluminada(cel)) ){
					apagaCelda(cel);
					ponCeldaEnPos(tab, i, j, cel);
				}
			}
		}
	}
	else if (!esPared(cel) && !esParedRestringida(cel) && comprobarPos(tab, x, y) && !esBombilla(cel) && !estaIluminada(cel)) {
		ponBombilla(cel);
		ponCeldaEnPos(tab, x, y, cel);
		ilumApagZona(tab, x, y, esBombilla(cel));

	}
	else if (esBombilla(cel)) {
		apagaCelda(cel);
		ponCeldaEnPos(tab, x, y, cel);
		ilumApagZona(tab, x, y, esBombilla(cel));
	}

	else {
		 if (!esPosQuit(x, y)) {
			cout << "No puedes poner una bombilla en esa posicion" << endl;
		 }
	}
}

