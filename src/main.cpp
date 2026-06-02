#include <iostream>   // entrada y salida de información
#include <string>     // cadenas de texto
#include <cstdlib>    // randomizador
#include <ctime>      // tiempo
#include <fstream>    // archivos

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

int main(){
    // Randomizador de partidas, para que cada partida sea distinta
    srand(time(NULL));

    return 0;
}