#include "Tablero.h"

void mostrarTablero() {
	std::cout <<  "--------------" << std::endl;
	for (int i = 0; i < TAMANO_TABLERO; i++)
	{
		std::cout << " |";

		for (int j = 0; j < TAMANO_TABLERO; j++) { 
			std::cout << " " << tablero[i][j] << " |";
			
		}
		std::cout << std::endl;
		 std::cout << "--------------" << std::endl;
		
	}
	std::cout << std::endl;

}