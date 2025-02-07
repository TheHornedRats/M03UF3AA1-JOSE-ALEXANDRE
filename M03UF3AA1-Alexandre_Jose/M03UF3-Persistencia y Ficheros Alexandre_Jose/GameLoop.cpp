#include "GameLoop.h"
#include "Tablero.h"
#include "Jugador.h"
#include "IA.h"
#include "Victoria.h"
#include "Guardado.h"
#include <iostream>

void GameLoop(char& turnoActual) {
	mostrarTablero();
	char ganador = VACIO;
	bool volverAlMenu = false;
	while (ganador == VACIO && !volverAlMenu)
	{
		char opcion;
		std::string nombreArchivo;
		if (turnoActual == JUGADOR)
		{
			std::cout << "Opciones:" << std::endl;
			std::cout << "1. Colocar ficha" << std::endl;
			std::cout << "2. Guardar partida" << std::endl;
			std::cout << "3. Volver al menu principal" << std::endl;
			std::cout << "Elige una opcion: ";
			std::cin >> opcion;
			if (opcion == '2')
			{
				std::cout << "Introduce el nombre del archivo:" << std::endl;
				std::cin >> nombreArchivo;
				guardarPartida(nombreArchivo, turnoActual);
				continue;

			}
			else if (opcion == '3')
			{
				std::cout << "Volviendo al menu principal" << std::endl;
				volverAlMenu = true;
				continue;


			}
			jugadorMueve();
			turnoActual = IA;

		}
		else
		{
			iaMueve();
			turnoActual = JUGADOR;

		}
		mostrarTablero();
		ganador = checkWin();

	}
	if (!volverAlMenu)
	{
		if (ganador == JUGADOR)
			std::cout << "Felicidades, has ganado a un juego de niños de 3 años" << std::endl;
		else if (ganador == IA)
			std::cout << "Te ha ganado una IA aleatoria..." << std::endl;
		else
			std::cout << "Este juego esta mal diseñado, empate" << std::endl;
	}
}
