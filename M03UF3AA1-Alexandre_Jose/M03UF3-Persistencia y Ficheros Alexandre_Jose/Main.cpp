#include<iostream>
#include "Tablero.h"
#include "Jugador.h"
#include "IA.h"
#include "Victoria.h"
#include <ctime>
#include "Guardado.h"
#include "GameLoop.h"

int main() {
	bool salir = false;

	while (!salir) {
		char opcion;
		std::string nombreArchivo;
		char turnoActual = JUGADOR;

		std::cout << "Bienvenido al tres en raya, ¿serás capaz de ganar?" << std::endl;
		std::cout << "Opciones:" << std::endl;
		std::cout << "1. Empezar partida" << std::endl;
		std::cout << "2. Cargar partida" << std::endl;
		std::cout << "3. Salir del juego" << std::endl;
		std::cout << "Elige una opcion: ";
		std::cin >> opcion;

		if (opcion == '2') {
			bool archivoEncontrado = false;

			while (!archivoEncontrado) {
				std::cout << "Introduce el nombre del archivo (o escribe 'menu' para volver al menu principal): ";
				std::cin >> nombreArchivo;

				if (nombreArchivo == "menu" || nombreArchivo == "Menu") {
					std::cout << "Volviendo al menú principal..." << std::endl;
					break;
				}

				if (cargarPartida(nombreArchivo, turnoActual)) {
					archivoEncontrado = true;
				}
				
			}

			if (archivoEncontrado) {
				GameLoop(turnoActual);
			}
		}
		else if (opcion == '1') {
			inicializarTablero();
			GameLoop(turnoActual);
		}
		else if (opcion == '3') {
			std::cout << "Saliendo del juego... Gracias por participar!" << std::endl;
			salir = true;
		}
	}

	return 0;
}
