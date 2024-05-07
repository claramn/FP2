#pragma once
#include "partida.h"

const int MAX_PARTIDAS = 20;

typedef tPartida* tPtrPartida;
typedef struct {
	int nElem;
	tPtrPartida datos[MAX_PARTIDAS];

} tListaPartidas;

void iniciaListaPartidas(tListaPartidas& listaPartidas);
ifstream& operator>>(ifstream& archivo, tListaPartidas& listaPartidas);
void insertarOrd(tListaPartidas& listaPartidas, const tPartida& partida);
void destruyeListaPartidas(tListaPartidas& listaPartidas);
int buscaPos(const tListaPartidas& listaPartidas, int nivel);
tPtrPartida dameElem(const tListaPartidas& listaPartidas, int pos);
int dameNumElem(const tListaPartidas& listaPartidas);
ofstream& operator<<(ofstream& archivo, const tListaPartidas& listaPartidas);
void eliminarPartida(tListaPartidas& listaPartidas, const tPartida& partida);