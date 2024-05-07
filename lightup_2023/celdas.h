#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


typedef enum tTipo { PARED, BOMBILLA, LIBRE };


typedef struct {
	tTipo tipo;
	int numBombillas;
} tCelda;

void iniciaCelda(tCelda& celda);
void destruyeCelda(tCelda& celda);
char celdaToChar(const tCelda& celda);
tCelda charToCelda(char c);
char celdaToCharArchivo(const tCelda& celda);
bool esPared(const tCelda& c);
bool esParedRestringida(const tCelda& c);
int numParedRestringida(const tCelda& c);
bool esBombilla(const tCelda& c);
bool estaApagada(const tCelda& c);
bool estaIluminada(const tCelda& c);
void apagaCelda(tCelda& c);
void iluminaCelda(tCelda& c);
void ponBombilla(tCelda& c);
