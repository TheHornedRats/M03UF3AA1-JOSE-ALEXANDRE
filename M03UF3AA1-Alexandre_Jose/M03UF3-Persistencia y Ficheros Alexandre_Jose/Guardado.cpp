#include "Guardado.h"
#include "Tablero.h"
#include <iostream>
#include <fstream>

void guardarPartida(const std::string& nombreArchivo, char turnoActual) {
    std::ofstream archivo(nombreArchivo + ".tictacsave");
    if (!archivo) {
        std::cerr << "Error al abrir el archivo, no se pudo guardar" << std::endl;
        return;
    }

    for (int i = 0; i < TAMANO_TABLERO; i++) {
        for (int j = 0; j < TAMANO_TABLERO; j++) {
            archivo << tablero[i][j];
        }
        archivo << std::endl;
    }

    archivo << turnoActual << std::endl;
    archivo.close();

    std::cout << "Partida guardada correctamente en: " << nombreArchivo << ".tictacsave" << std::endl;
}

bool cargarPartida(const std::string& nombreArchivo, char& turnoActual) {
    std::ifstream archivo(nombreArchivo + ".tictacsave");
    if (!archivo) {
        std::cerr << "No se encontro el archivo: " << nombreArchivo << ".tictacsave" << std::endl;
        return false;
    }

    std::string linea;
    int fila = 0;

    while (std::getline(archivo, linea) && fila < TAMANO_TABLERO) {
        for (int columna = 0; columna < TAMANO_TABLERO; columna++) {
            if (columna < linea.length()) {
                tablero[fila][columna] = linea[columna];
            }
            else {
                tablero[fila][columna] = VACIO;
            }
        }
        fila++;
    }

    if (std::getline(archivo, linea)) {
        turnoActual = linea[0];
    }

    archivo.close();
    std::cout << "Partida cargada correctamente" << std::endl;
    return true;
}
