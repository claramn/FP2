#include "tablero.h"
#include "colors.h"

using namespace std;
const int HUECOS = 2;
const int N = 2;


int getNumFilas(const tTablero& tab) {
	return tab.nFils;
}

int getNumCols(const tTablero& tab) {
	return tab.nCols;
}

tCelda celdaEnPos(const tTablero& tablero, int x, int y) {
	return tablero.datos[x][y];
}

void ponCeldaEnPos(tTablero& tablero,const int x, const int y, const tCelda& c) {
	tablero.datos[x][y] = c;
}

void mostrarCoutSeparadorMat(tTablero tab) {
	cout << "\t -+";
	for (int col = 0; col < getNumCols(tab); ++col) {
		cout << setw(HUECOS + 2) << setfill('-') << '+' << setfill(' ');
	}
	cout << endl;
}

void iniciaTablero(tTablero& tablero) {
	tablero.nCols = 0;
	tablero.nFils = 0;
}

void destruyeTablero(tTablero& tablero) {
	for (int i = 0; i < tablero.nFils; i++) {
		for (int j = 0; j < tablero.nCols; j++) {
			tCelda celda = celdaEnPos(tablero, i, j);
			destruyeCelda(celda);
		}
	}
	tablero.nCols = 0;
	tablero.nFils = 0;
}


ostream& operator<<(ostream& out, const tTablero& tab) {

	cout << "\t  |";
	for (int col = 0; col < getNumCols(tab); ++col) {
		cout << LBLUE << setw(HUECOS) << col << " " << RESET << '|';
	}
	cout << endl;
	/* muestra la linea separadora */
	mostrarCoutSeparadorMat(tab);

	/* muestra una fila donde todas las celdas son bombillas */


	for (int c = 0; c < getNumFilas(tab); c++) {
		cout << "\t" << LBLUE << setw(HUECOS) << c << RESET << '|';
		for (int j = 0; j < getNumCols(tab); ++j) {
			if (esPared(tab.datos[c][j])) {
				cout << BG_BLACK << WHITE;
				cout << setw(HUECOS) << setfill(' ') << celdaToChar(tab.datos[c][j]) << " " << RESET << '|';
			}
			else if (esBombilla(tab.datos[c][j])) {
				cout << BG_YELLOW << BLACK;
				cout << setw(HUECOS) << setfill(' ') << celdaToChar(tab.datos[c][j]) << " " << RESET << '|';
			}
			else if (esParedRestringida(tab.datos[c][j])) {
				cout << BG_BLACK << WHITE;
				cout << setw(HUECOS) << setfill(' ') << celdaToChar(tab.datos[c][j]) << " " << RESET << '|';
			}
			else if (estaIluminada(tab.datos[c][j])) {
				cout << BG_YELLOW << BLACK;
				cout << setw(HUECOS) << setfill(' ') << celdaToChar(tab.datos[c][j]) << " " << RESET << '|';
			}
			else {
				cout << BG_WHITE << BLACK;
				cout << setw(HUECOS) << setfill(' ') << celdaToChar(tab.datos[c][j]) << " " << RESET << '|';
			}
		}
		/* muestra la linea separadora */
		cout << endl;
		mostrarCoutSeparadorMat(tab);
	}
	cout << endl;

	
	/* muestra una fila donde todas las celdas son bombillas */

	
	cout << endl;
	return out;
}

ifstream& operator>>(ifstream& archivo, tTablero& tab) {
	archivo >> tab.nFils >> tab.nCols;
	char cel = ' ';
	for (int i = 0; i < tab.nFils; i++) {
		for (int j = 0; j < tab.nCols; j++) {
			archivo >> cel;
			tab.datos[i][j] = charToCelda(cel);
		}
	}
	return archivo;
}
ofstream& operator<<(ofstream& archivo, const tTablero& tab) {
	tCelda cel;
	archivo << getNumFilas(tab) << " " << getNumCols(tab) << endl;
	for (int i = 0; i < getNumFilas(tab); i++) {
		for (int j = 0; j < getNumCols(tab); j++) {
		cel = celdaEnPos(tab, i, j);
		archivo << celdaToCharArchivo(cel);
		}
	archivo << endl;
	}
	return archivo;
}
