#ifndef DATOS_H
#define DATOS_H

#include <string>
using namespace std;

// Constantes del juego
const int NUM_SOSPECHOSOS = 5;
const int NUM_ARMAS = 5;
const int NUM_HABITACIONES = 5;
const int MAX_EVIDENCIAS = 50;
const int NUM_ESCENARIOS = 3;
const int ESCENARIO_SECRETO = 3;

// Variables globales compartidas entre modulos.
// Se declaran con "extern" aqui y se definen una sola vez en datos.cpp.

// Catalogos
extern string sospechosos[NUM_SOSPECHOSOS];
extern string armas[NUM_ARMAS];
extern string habitaciones[NUM_HABITACIONES];

// Escenario actual: 0=Mansion, 1=Crucero, 2=Estacion, 3=secreto
extern int escenarioActual;
extern string escenarioNombre;
extern string escenarioIntro;

// true cuando ya se logro el rango ORO (se guarda en progreso.txt)
extern bool secretoDesbloqueado;

// Caso a resolver (indices del culpable, arma y habitacion)
extern int casoSospechoso;
extern int casoArma;
extern int casoHabitacion;

// Control de la partida
extern int turnos;
extern bool resuelto;

// Contadores para la calificacion final
extern int acusacionesFalladas;
extern int suposicionesUsadas;
extern string calificacionFinal; // "ORO" / "PLATA" / "BRONCE" / "DERROTA"

extern int turnosIniciales; // lo fija la dificultad elegida
extern int dificultad;      // 1=Facil, 2=Normal, 3=Dificil

// Evidencias encontradas
extern string evidencias[MAX_EVIDENCIAS];
extern int numEvidencias;

// Pizarra de deduccion: true = ya descartado por una pista
extern bool sospDescartado[NUM_SOSPECHOSOS];
extern bool armaDescartada[NUM_ARMAS];
extern bool lugarDescartado[NUM_HABITACIONES];

// Nombre del jugador para el ranking
extern string nombreJugador;

#endif
