#include "GameLoop.h"
#include "Tablero.h"
#include "Jugador.h"
#include "IA.h"
#include "Victoria.h"
#include "Guardado.h"
#include <iostream>
#include <fstream>

void GameLoop(char& turnoActual) {
	mostrarTablero();
	char ganador = VACIO;
	bool volverAlMenu = false;

	while (ganador == VACIO && !volverAlMenu) {
		char opcion;
		std::string nombreArchivo;

		if (turnoActual == JUGADOR) {
			std::cout << "Opciones:" << std::endl;
			std::cout << "1. Colocar ficha" << std::endl;
			std::cout << "2. Guardar partida" << std::endl;
			std::cout << "3. Volver al menu principal" << std::endl;
			std::cout << "Elige una opcion: ";
			std::cin >> opcion;

			if (opcion == '2') {
				bool nombreValido = false;

				while (!nombreValido) {
					std::cout << "Introduce el nombre del archivo:" << std::endl;
					std::cin >> nombreArchivo;

					if (nombreArchivo == "Menu" || nombreArchivo == "menu") {
						std::cout << "No puedes usar este nombre, introduce otro por favor: " << std::endl;
						continue;
					}

					std::ifstream archivoExistente(nombreArchivo + ".tictacsave");
					if (archivoExistente) {
						char respuesta;
						std::cout << "Tate, que ya hay un archivo con ese nombre, lo quieres sobrescribir? (S/N)" << std::endl;
						std::cin >> respuesta;
						if (respuesta == 'N' || respuesta == 'n') {
							std::cout << "Pues más te vale estar escogiendo otro nombre" << std::endl;
							continue;
						}
					}

					nombreValido = true;
				}

				guardarPartida(nombreArchivo, turnoActual);
				continue;
			}
			else if (opcion == '3') {
				std::cout << "Volviendo al menu principal" << std::endl;
				volverAlMenu = true;
				continue;
			}

			jugadorMueve();
			turnoActual = IA;
		}
		else {
			iaMueve();
			turnoActual = JUGADOR;
		}

		mostrarTablero();
		ganador = checkWin();
	}

	if (!volverAlMenu) {
		if (ganador == JUGADOR)
			std::cout << "Felicidades, has ganado a un juego de niños de 3 años" << std::endl;
		else if (ganador == IA)
			std::cout << "Te ha ganado una IA aleatoria..." << std::endl;
		else {
			std::cout << "Este juego esta mal diseñado, empate" << std::endl;
			std::cout << "Te vamos a dar otra Chance" << std::endl;
			inicializarTablero();
			GameLoop(turnoActual);
			return;
		}
	}
}
