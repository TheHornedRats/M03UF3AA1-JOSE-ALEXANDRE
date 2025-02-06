#include <iostream>
#include "Tablero.h"
#include "Jugador.h"


void jugadorMueve() {
	int fila, columna;
	bool valid_position = false;
	while (!valid_position) {
		std::cout << "INTRODUCE FILA Y COLUMNA PEDAZO DE MIERDA (0-" << TAMANO_TABLERO - 1 << "):";
		std::cin >> fila >> columna;

		if (fila>= 0 && fila< TAMANO_TABLERO && columna >= 0 && columna < TAMANO_TABLERO)
		{
			if (tablero[fila][columna] == VACIO) {
				tablero[fila][columna] = JUGADOR;
				valid_position = true;

			}
			else
			{
				std::cout << "Esa casilla ya está ocupada. Intenta de nuevo.";

			}

		}
		else
		{
			std::cout << "La casilla debe estar en el tablero, porfavor.";
		}
	}
}