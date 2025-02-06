#include<iostream>
#include "Tablero.h"
#include "Jugador.h"
#include "IA.h"
#include "Victoria.h"
#include <ctime>
#include "Guardado.h"
#include "IniciarJuego.h"

int main() {

	bool salir = false;

	while (!salir)
	{
		char opcion;
		std::string nombreArchivo;
		char turnoActual = JUGADOR;
	
		std::cout << "Bienvenido al tres en raya, ¿seras capaz de ganar?" << std::endl;
		std::cout << "Opciones:" << std::endl;
		std::cout << "1. Colocar ficha" << std::endl;
		std::cout << "2. Cargar partida" << std::endl;
		std::cout << "3. Volver al menu principal" << std::endl;
		std::cout << "Elige una opcion: ";
		std::cin >> opcion;
	
		if (opcion == '2')
		{
			std::cout << "Introduce el nombre del archivo:" << std::endl;
			std::cin >> nombreArchivo;
			if (!cargarPartida(nombreArchivo, turnoActual))
			{
				std::cout << "No se ha podido cargar la partida, empezamos una nueva" << std::endl;
				inicializarTablero();


			}

		}
		else
		{
			inicializarTablero();

		}
		iniciarJuego(turnoActual);

	}
	std::cout << "Gracias por jugar, hasta nunca" << std::endl;
	return 0;

}


//Defi