#include "utilidades.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int leerOpcion(int min, int max) {
    int opcion;
    bool valido = false;
    do {
        cout << "Elija una opcion (" << min << "-" << max << "): ";
        cin >> opcion;
        if (cin.fail()) {
            if (cin.eof()) {
                cout << "\nEntrada finalizada. Cerrando el juego.\n";
                exit(0);
            }
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Debe ingresar un numero.\n";
        } else {
            cin.ignore(10000, '\n');
            if (opcion >= min && opcion <= max) {
                valido = true;
            } else {
                cout << "Opcion fuera de rango. Intente de nuevo.\n";
            }
        }
    } while (!valido);
    return opcion;
}

int numeroAleatorio(int maximo) {
    return rand() % maximo;
}

void pausar() {
    cout << "\nPresione ENTER para continuar...";
    cin.get();
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

bool existeArchivo(string ruta) {
    ifstream archivo(ruta.c_str());
    return archivo.good();
}
