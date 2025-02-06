#include "Guardado.h"
#include "Tablero.h"
#include <iostream>
#include <fstream>

void guardarPartida(const std::string& nombreArchivo, char turnoActual) {
	std::ofstream archivo(nombreArchivo + ".tictacsave", std::ios::binary);
	if (!archivo)
	{
		std::cerr << "Error al abrir el archivo, no se pudo guardar" << std::endl;
		return;
	}

	archivo.write(reinterpret_cast<char*>(tablero), sizeof(tablero));

	archivo.write(reinterpret_cast<char*>(&turnoActual), sizeof(turnoActual));
	archivo.close();

	std::cout << "Partida guardada correctamente en:" << nombreArchivo << ".tictacsave" << std::endl;
}

bool cargarPartida(const std::string& nombreArchivo, char& turnoActual) {
	std::ifstream archivo(nombreArchivo + ".tictacsave", std::ios::binary);
	if (!archivo)
	{
		std::cerr << "No se encontro el archivo" << nombreArchivo << ".tictacsave" << std::endl;
		return false;
	}

	archivo.read(reinterpret_cast<char*>(tablero), sizeof(tablero));
	archivo.read(reinterpret_cast<char*>(&turnoActual), sizeof(turnoActual));
	archivo.close();
	std::cout << "Partida cargada correctamente" << std::endl;
	return true;
}