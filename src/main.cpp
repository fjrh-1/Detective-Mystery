#include "data/datos.h"
#include "fun/utilidades.h"
#include "fun/juego.h"
#include "fun/archivos.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Semilla aleatoria, una sola vez al iniciar
    srand((unsigned int)time(0));

    // Escenario por defecto (Mansion); Nueva partida deja elegir otro
    cargarEscenario(0);

    // Saber si el escenario secreto ya se desbloqueo
    cargarProgreso();

    bool salir = false;

    while (!salir) {
        limpiarPantalla();
        mostrarMenuPrincipal();
        int opcion = leerOpcion(1, 5);

        switch (opcion) {
            case 1: // Nueva partida
                nuevaPartida();
                cicloJuego();
                break;

            case 2: // Cargar partida
                if (cargarPartida()) {
                    reconstruirTablero();
                    cout << "Partida cargada correctamente.\n";
                    pausar();
                    cicloJuego();
                } else {
                    cout << "No existe una partida guardada.\n";
                    pausar();
                }
                break;

            case 3: // Ranking
                mostrarRanking();
                pausar();
                break;

            case 4: // Instrucciones
                mostrarInstrucciones();
                pausar();
                break;

            case 5: // Salir
                salir = true;
                cout << "Gracias por jugar. Hasta luego!\n";
                break;
        }
    }

    return 0;
}
