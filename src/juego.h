#ifndef JUEGO_H
#define JUEGO_H

#include <string>
using namespace std;

// Configuracion / menus
void cargarEscenario(int id);
void seleccionarEscenario();
void mostrarMenuPrincipal();
void mostrarMenuJuego();
void mostrarInstrucciones();
void mostrarBienvenida();
void seleccionarDificultad();
string nombreDificultad();

// Inicio de partida
void nuevaPartida();
void generarCaso();
void reiniciarVariables();
void limpiarEvidencias();

// Mostrar catalogos
void mostrarSospechosos();
void mostrarArmas();
void mostrarHabitaciones();

// Evidencias / pistas
void buscarPista();
void agregarEvidencia(string evidencia);
bool evidenciaExiste(string evidencia);
void revisarEvidencias();
string pistaSospechoso(int i);
string pistaArma(int i);
string pistaLugar(int i);

// Pizarra de deduccion
void dibujarTablero();
void mostrarTablero();
void reconstruirTablero();

// Suposicion
void hacerSuposicion();

// Acusacion y cierre
void hacerAcusacion();
bool verificarVictoria(int sospechoso, int arma, int habitacion);
bool verificarDerrota();
void mostrarResultadoFinal();
void mostrarReconstruccion();
void rutaDeLaVerdad();

// Ciclo principal de juego
void cicloJuego();

#endif
