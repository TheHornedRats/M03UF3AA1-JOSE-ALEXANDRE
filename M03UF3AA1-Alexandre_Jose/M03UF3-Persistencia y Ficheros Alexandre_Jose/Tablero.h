#ifndef TABLERO_H
#define TABLERO_H

#include<iostream>
#include "Config.h"


//aqui estamos definiendo el tablero usando las constantes de Config.h
extern char tablero[TAMANO_TABLERO][TAMANO_TABLERO];

//declaro la funcion para mostrar el tablero
void mostrarTablero();
void inicializarTablero();

#endif // !TABLERO_H

