#include "Tablero.h"



char tablero[TAMANO_TABLERO][TAMANO_TABLERO];

//creamos la funcion para mostrar el tablero 

void inicializarTablero() {
	for (int i = 0; i < TAMANO_TABLERO; i++)
	{
		for (int j = 0; j < TAMANO_TABLERO; j++)
		{
		tablero[i][j] = VACIO;
		}
	}
}