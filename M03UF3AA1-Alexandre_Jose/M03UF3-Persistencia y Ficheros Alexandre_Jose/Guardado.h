#ifndef GUARDADO_H
#define GUARDADO_H
#include <string>

void guardarPartida(const std::string& nombreArchivo, char turnoActual);
bool cargarPartida(const std::string& nombreArchivo, char& turnoActual);
#endif

