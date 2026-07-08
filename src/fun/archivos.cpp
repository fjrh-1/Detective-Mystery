#include "archivos.h"
#include "../data/datos.h"
#include "utilidades.h"
#include "juego.h"
#include <iostream>
#include <fstream>
using namespace std;

void guardarPartida() {
    ofstream archivo("files/partida.txt");
    if (!archivo) {
        cout << "No se pudo guardar la partida.\n";
        return;
    }

    // Primera linea: estado numerico. Se guarda el escenario porque
    // las pistas usan indices de su catalogo.
    archivo << escenarioActual << " "
            << casoSospechoso << " "
            << casoArma << " "
            << casoHabitacion << " "
            << turnos << " "
            << resuelto << " "
            << numEvidencias << " "
            << acusacionesFalladas << " "
            << suposicionesUsadas << "\n";

    // Cada evidencia en su propia linea (pueden tener espacios)
    for (int i = 0; i < numEvidencias; i++) {
        archivo << evidencias[i] << "\n";
    }

    archivo.close();
    cout << "Partida guardada correctamente.\n";
}

bool cargarPartida() {
    if (!existeArchivo("files/partida.txt")) {
        return false;
    }

    ifstream archivo("files/partida.txt");
    if (!archivo) {
        return false;
    }

    archivo >> escenarioActual
            >> casoSospechoso
            >> casoArma
            >> casoHabitacion
            >> turnos
            >> resuelto
            >> numEvidencias
            >> acusacionesFalladas
            >> suposicionesUsadas;

    archivo.ignore(10000, '\n');

    // Cargar el catalogo del escenario guardado antes de usar los indices
    cargarEscenario(escenarioActual);

    for (int i = 0; i < numEvidencias; i++) {
        getline(archivo, evidencias[i]);
    }

    archivo.close();
    return true;
}

void guardarResultado() {
    // ios::app agrega al final sin borrar lo anterior
    ofstream archivo("files/ranking.txt", ios::app);
    if (!archivo) {
        return;
    }

    archivo << nombreJugador << " - "
            << (resuelto ? "GANO" : "PERDIO")
            << " [" << calificacionFinal << "]"
            << " - " << escenarioNombre
            << " - turnos restantes: " << turnos << "\n";

    archivo.close();
}

void guardarProgreso() {
    ofstream archivo("files/progreso.txt");
    if (!archivo) {
        return;
    }
    archivo << (secretoDesbloqueado ? 1 : 0) << "\n";
    archivo.close();
}

void cargarProgreso() {
    if (!existeArchivo("files/progreso.txt")) {
        secretoDesbloqueado = false;
        return;
    }
    ifstream archivo("files/progreso.txt");
    if (!archivo) {
        return;
    }
    int valor = 0;
    archivo >> valor;
    secretoDesbloqueado = (valor == 1);
    archivo.close();
}

void mostrarRanking() {
    limpiarPantalla();
    cout << "================ RANKING ================\n";

    if (!existeArchivo("files/ranking.txt")) {
        cout << "Aun no hay resultados registrados.\n";
        return;
    }

    ifstream archivo("files/ranking.txt");
    string linea;
    bool hayRegistros = false;

    while (getline(archivo, linea)) {
        cout << linea << "\n";
        hayRegistros = true;
    }
    archivo.close();

    if (!hayRegistros) {
        cout << "Aun no hay resultados registrados.\n";
    }
    cout << "=========================================\n";
}
