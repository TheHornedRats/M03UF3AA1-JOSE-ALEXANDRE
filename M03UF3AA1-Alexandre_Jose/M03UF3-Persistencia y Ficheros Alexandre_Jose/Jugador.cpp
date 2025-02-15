#include <iostream>
#include "Tablero.h"
#include "Jugador.h"


void jugadorMueve() {
	int fila, columna;
	bool valid_position = false;
	while (!valid_position) {
		std::cout << "INTRODUCE FILA Y COLUMNA CORAZON (1-" << TAMANO_TABLERO  << "):";
		std::cin >> fila >> columna;

		fila -= 1;
		columna -= 1;

		if (fila>= 0 && fila< TAMANO_TABLERO && columna >= 0 && columna < TAMANO_TABLERO)
		{
			if (tablero[fila][columna] == VACIO) {
				tablero[fila][columna] = JUGADOR;
				valid_position = true;

			}
			else
			{
				std::cout << "Esa casilla ya esta ocupada. Donde hay uno no caben dos.";

			}

		}
		else
		{
			std::cout << "La casilla debe estar en el tablero, un poco de seriedad.";
		}
	}
}