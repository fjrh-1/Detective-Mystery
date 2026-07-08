#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <string>
using namespace std;

// Lee una opcion y valida que este dentro del rango [min, max]
int leerOpcion(int min, int max);

// Numero aleatorio entre 0 y (maximo - 1)
int numeroAleatorio(int maximo);

// Pausa hasta que el usuario presione ENTER
void pausar();

// Limpia la pantalla (Windows / Mac / Linux)
void limpiarPantalla();

// Comprueba si un archivo existe
bool existeArchivo(string ruta);

#endif
