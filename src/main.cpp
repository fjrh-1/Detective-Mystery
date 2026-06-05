#include <iostream>   // entrada y salida de información
#include <string>     // cadenas de texto
#include <cstdlib>    // randomizador
#include <ctime>      // tiempo
#include <fstream>    // archivos

using namespace std;

//  Arreglo de datos en formato cadena de texto
string sospechosos[5];
string armas[5];
string habitaciones[5];
string evidencias[20];

//  Variables para el calculo de turnos, acusaciones y la lógica del juego.
int cantidadEvidencias = 0;
int culpable;
int armaCorrecta;
int habitacionCorrecta;
int turnos;
int acusaciones;

bool jugando;

// Prototipos
void inicializarDatos();
void menuPrincipal();

int main()
{
    srand(time(NULL));

    inicializarDatos();

    menuPrincipal();

    return 0;
}