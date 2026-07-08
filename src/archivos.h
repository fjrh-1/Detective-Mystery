#ifndef ARCHIVOS_H
#define ARCHIVOS_H

// Guarda el estado actual de la partida en partida.txt
void guardarPartida();

// Recupera una partida guardada. Devuelve true si lo logro.
bool cargarPartida();

// Registra el resultado final en ranking.txt
void guardarResultado();

// Muestra el historial de resultados
void mostrarRanking();

// Desbloqueo del escenario secreto (progreso.txt)
void guardarProgreso();
void cargarProgreso();

#endif
