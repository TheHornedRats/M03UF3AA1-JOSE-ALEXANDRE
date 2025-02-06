#include "Tablero.h"
#include "Victoria.h"


char checkWin() {

	for (int i = 0; i < TAMANO_TABLERO; i++)
	{
		if (tablero[i][0] != VACIO && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2])
			return tablero[i][0];
		if (tablero[0][i] != VACIO && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i])
			return tablero[0][i];

	}
	if (tablero[0][0] != VACIO && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
		return tablero[0][0];
	if (tablero[0][2] != VACIO && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
		return tablero[0][2];
	for (int i = 0; i < TAMANO_TABLERO; i++)
	{
		for (int j = 0; j < TAMANO_TABLERO; j++) {
			if (tablero[i][j] == VACIO)
				return VACIO;


			
		}
	}

	return 'E';
	
}