#pragma once
#include "tablero.h"
#include "celdas.h"
#include <iostream>
#include <iomanip>
#include <fstream>


bool estaTerminado(const tTablero& juego);
bool esPosQuit(int x, int y);
void ejecutarPos(tTablero& tab, int x, int y);

