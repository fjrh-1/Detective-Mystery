#include "datos.h"

// Definicion de las variables globales declaradas en datos.h

string sospechosos[NUM_SOSPECHOSOS];
string armas[NUM_ARMAS];
string habitaciones[NUM_HABITACIONES];

int escenarioActual = 0;
string escenarioNombre = "";
string escenarioIntro = "";

bool secretoDesbloqueado = false;

int casoSospechoso = 0;
int casoArma = 0;
int casoHabitacion = 0;

int turnos = 0;
bool resuelto = false;

int acusacionesFalladas = 0;
int suposicionesUsadas = 0;
string calificacionFinal = "";

int turnosIniciales = 15;
int dificultad = 2;

string evidencias[MAX_EVIDENCIAS];
int numEvidencias = 0;

bool sospDescartado[NUM_SOSPECHOSOS] = { false };
bool armaDescartada[NUM_ARMAS] = { false };
bool lugarDescartado[NUM_HABITACIONES] = { false };

string nombreJugador = "";
