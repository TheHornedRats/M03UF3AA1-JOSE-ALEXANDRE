#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tablero.h"
#include "IA.h"


void iaMueve() {

	int fila, columna;
	bool movimientoValido = false;

	std::cout << "Turno de la IA... preparate para pillar" << std::endl;



	while (!movimientoValido)
	{
		fila = rand() % TAMANO_TABLERO;
		columna = rand() % TAMANO_TABLERO;

		if (tablero[fila][columna] == VACIO)
		{
			tablero[fila][columna] = IA;
			movimientoValido = true;

		}
	}
}
