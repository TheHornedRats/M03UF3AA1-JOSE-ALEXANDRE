#ifndef TABLERO_H
#define TABLERO_H

#include<iostream>
#include "Config.h"


//Aqui estamos definiendo el tablero usando las constantes de Config.h
extern char tablero[TAMANO_TABLERO][TAMANO_TABLERO];

//Declaramos las funciones para mostrar el tablero e inicializarlo
void mostrarTablero();
void inicializarTablero();

#endif // !TABLERO_H

