#include "listaPartidas.h"
#include <fstream>
#include <iomanip>
#include "checkML.h"
using namespace std;

int pideElNivel();
void cargaListaPartidas(tListaPartidas& lp);
bool guardaListaPartidas(const tListaPartidas& lp);

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	tListaPartidas listaPartidas;
	iniciaListaPartidas(listaPartidas);
	ifstream archivo;
	cargaListaPartidas(listaPartidas);

	int nivel = pideElNivel();
	int pos = buscaPos(listaPartidas, nivel);
	int n = dameNumElem(listaPartidas);
	if (pos == n) {
		pos = n - 1;
	}

	tPtrPartida partida = dameElem(listaPartidas, pos);
	cout << endl;
	int nIt = 0;
	bool quit = juega(*partida, nIt);
	if (quit) {
		cout << "Has realizado " << (nIt - 1) << " movimientos" << endl;
		cout << "Hasta pronto!" << endl;
	}
	else {
		cout << "Has realizado " << nIt << " movimientos" << endl;
		eliminarPartida(listaPartidas, *partida);
	}
	if (guardaListaPartidas(listaPartidas)) {
		cout << "Las partidas se han guardado correctamente" << endl;
	}
	else {
		cout << "No se han podido guardar las partidas /n";
	}

	destruyeListaPartidas(listaPartidas);

	return 0;
}

int pideElNivel() {
	int n;
	cout << "Dime el nivel al que quieres jugar: ";
	cin >> n;
	return n;
}

void cargaListaPartidas(tListaPartidas& lp) {
	ifstream archivo;
	archivo.open("partida.txt");
	if (archivo.is_open()) {
 		archivo >> lp;
		archivo.close();
	}
	else cout << "error";
}

bool guardaListaPartidas(const tListaPartidas& lp) {
	ofstream archivo;
	string nombre_archivo;
	bool abierto = false;
	cout << endl;
	cout << "Introduce un fichero de texto para guardar las partidas: ";
	cin >> nombre_archivo;

	archivo.open(nombre_archivo);
	if (archivo.is_open()) {
		abierto = true;
		archivo << lp;
		archivo.close();
	}
	return abierto;
}