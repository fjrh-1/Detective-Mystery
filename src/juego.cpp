#include "juego.h"
#include "datos.h"
#include "utilidades.h"
#include "archivos.h"
#include <iostream>
#include <cstdio>
using namespace std;

// ============ CONFIGURACION / MENUS ============

// Llena los catalogos y el nombre/intro segun el escenario elegido
void cargarEscenario(int id) {
    escenarioActual = id;
    switch (id) {
        case 1: // Crucero de lujo
            sospechosos[0] = "Capitan Reyes";
            sospechosos[1] = "Condesa Vidal";
            sospechosos[2] = "Doctor Salas";
            sospechosos[3] = "Marinero Tobias";
            sospechosos[4] = "Cantante Lola";

            armas[0] = "Ancla";
            armas[1] = "Botella rota";
            armas[2] = "Bengala";
            armas[3] = "Cuerda de amarre";
            armas[4] = "Veneno marino";

            habitaciones[0] = "Cubierta";
            habitaciones[1] = "Salon de baile";
            habitaciones[2] = "Sala de maquinas";
            habitaciones[3] = "Camarote real";
            habitaciones[4] = "Bodega";

            escenarioNombre = "Crucero de Lujo";
            escenarioIntro  = "En altamar, lejos de toda costa, el lujo del crucero\n"
                              "esconde un asesinato. Nadie puede bajar del barco...";
            break;

        case 2: // Estacion espacial
            sospechosos[0] = "Comandante Vega";
            sospechosos[1] = "Ingeniera Nova";
            sospechosos[2] = "Doctor Kaiser";
            sospechosos[3] = "Piloto Orion";
            sospechosos[4] = "Androide AX7";

            armas[0] = "Laser de mano";
            armas[1] = "Fuga de oxigeno";
            armas[2] = "Llave inglesa";
            armas[3] = "Sobrecarga electrica";
            armas[4] = "Inyeccion toxica";

            habitaciones[0] = "Puente de mando";
            habitaciones[1] = "Laboratorio";
            habitaciones[2] = "Bahia de carga";
            habitaciones[3] = "Modulo de descanso";
            habitaciones[4] = "Sala de reactores";

            escenarioNombre = "Estacion Espacial Orbital";
            escenarioIntro  = "A miles de kilometros de la Tierra, la estacion pierde\n"
                              "a un tripulante. El asesino sigue a bordo...";
            break;

        case 3: // Escenario secreto
            sospechosos[0] = "El Cuervo";
            sospechosos[1] = "Madame Iris";
            sospechosos[2] = "El Relojero";
            sospechosos[3] = "Vipera";
            sospechosos[4] = "El Titiritero";

            armas[0] = "Daga ritual";
            armas[1] = "Hilo de acero";
            armas[2] = "Frasco de sombra";
            armas[3] = "Reliquia maldita";
            armas[4] = "Guante envenenado";

            habitaciones[0] = "Sala del trono";
            habitaciones[1] = "Cripta";
            habitaciones[2] = "Galeria de mascaras";
            habitaciones[3] = "Torre del reloj";
            habitaciones[4] = "Jardin nocturno";

            escenarioNombre = "La Guarida de La Sombra";
            escenarioIntro  = "Desbloqueaste el caso prohibido. En la guarida de La Sombra\n"
                              "hasta sus propios aliados se traicionan entre si...";
            break;

        default: // 0 = Mansion Victoriana
            escenarioActual = 0;
            sospechosos[0] = "Cesar";
            sospechosos[1] = "Jorge";
            sospechosos[2] = "Mateo";
            sospechosos[3] = "Sofia";
            sospechosos[4] = "Jaime";

            armas[0] = "Pistola";
            armas[1] = "Cuchillo";
            armas[2] = "Veneno";
            armas[3] = "Martillo";
            armas[4] = "Cuerda";

            habitaciones[0] = "Biblioteca";
            habitaciones[1] = "Cocina";
            habitaciones[2] = "Sala";
            habitaciones[3] = "Dormitorio";
            habitaciones[4] = "Sotano";

            escenarioNombre = "Mansion Victoriana";
            escenarioIntro  = "Una tormenta aisla la vieja mansion. Esta noche, uno\n"
                              "de los invitados no vera el amanecer...";
            break;
    }
}

void seleccionarEscenario() {
    limpiarPantalla();
    cout << "=============== ESCENARIO ===============\n";
    cout << "Donde quieres resolver el crimen?\n\n";
    cout << "1. Mansion Victoriana  (clasico)\n";
    cout << "2. Crucero de Lujo\n";
    cout << "3. Estacion Espacial\n";

    int maxOp = NUM_ESCENARIOS;
    if (secretoDesbloqueado) {
        cout << "4. La Guarida de La Sombra  [SECRETO]\n";
        maxOp = 4;
    } else {
        cout << "4. ???  [BLOQUEADO - logra el rango ORO para desbloquearlo]\n";
    }
    cout << "-----------------------------------------\n";
    int op = leerOpcion(1, maxOp);
    cargarEscenario(op - 1);

    limpiarPantalla();
    cout << "===== " << escenarioNombre << " =====\n\n";
    cout << escenarioIntro << "\n";
    pausar();
}

void mostrarMenuPrincipal() {
    cout << "==============================================\n";
    cout << "     MISTERIO EN LA MANSION | Detective\n";
    cout << "==============================================\n";
    cout << "1. Nueva partida\n";
    cout << "2. Cargar partida\n";
    cout << "3. Ver ranking\n";
    cout << "4. Instrucciones\n";
    cout << "5. Salir\n";
    cout << "----------------------------------------------\n";
}

void mostrarMenuJuego() {
    cout << "\n--------- MENU DE INVESTIGACION ---------\n";
    cout << "1. Ver sospechosos\n";
    cout << "2. Ver armas\n";
    cout << "3. Ver habitaciones\n";
    cout << "4. Buscar pista\n";
    cout << "5. Revisar evidencias\n";
    cout << "6. Ver pizarra (deduccion)\n";
    cout << "7. Hacer suposicion\n";
    cout << "8. Hacer acusacion\n";
    cout << "9. Guardar partida\n";
    cout << "10. Salir al menu principal\n";
    cout << "-----------------------------------------\n";
}

void mostrarInstrucciones() {
    limpiarPantalla();
    cout << "================ INSTRUCCIONES ================\n\n";
    cout << "Resuelve el crimen descubriendo TRES cosas:\n";
    cout << "  - El culpable\n";
    cout << "  - El arma utilizada\n";
    cout << "  - La habitacion donde ocurrio\n\n";
    cout << "Tienes turnos limitados (mas en Facil, menos en Dificil).\n";
    cout << "Usa 'Buscar pista' para descartar sospechosos, armas o\n";
    cout << "habitaciones incorrectas.\n";
    cout << "Abre la 'Pizarra' para ver de un vistazo que sigue siendo\n";
    cout << "posible ([?]) y que ya descartaste ([X]). No necesitas anotar!\n";
    cout << "Cada pista NUEVA y cada acusacion FALLIDA gastan un turno.\n";
    cout << "Tambien puedes 'Hacer suposicion': propones quien/que/donde y\n";
    cout << "el juego te dice cuantas aciertas (de 3) sin decir cuales.\n";
    cout << "Cuando creas saber la respuesta, haz una acusacion.\n";
    cout << "Si te quedas sin turnos, pierdes.\n";
    cout << "==============================================\n";
}

// Tutorial corto, solo la primera vez que se juega
void mostrarBienvenida() {
    limpiarPantalla();
    cout << "========== BIENVENIDO, DETECTIVE ==========\n\n";
    cout << "Se cometio un crimen en la mansion. Tu mision es\n";
    cout << "descubrir TRES cosas: quien, con que arma y donde.\n\n";
    cout << "Como jugar, en 3 pasos:\n";
    cout << "  1) 'Buscar pista' va descartando opciones falsas.\n";
    cout << "  2) Mira la 'Pizarra': [?] sigue posible, [X] descartado.\n";
    cout << "  3) Cuando quede 1 de cada uno, haz tu 'Acusacion' y ganas.\n\n";
    cout << "Cada pista nueva gasta 1 turno. Si te quedas sin turnos, pierdes.\n";
    cout << "Consejo: empieza en dificultad FACIL.\n";
    cout << "===========================================\n";
    pausar();
}

string nombreDificultad() {
    if (dificultad == 1) return "Facil";
    if (dificultad == 3) return "Dificil";
    return "Normal";
}

void seleccionarDificultad() {
    limpiarPantalla();
    cout << "=============== DIFICULTAD ===============\n";
    cout << "1. Facil   (recomendado si es tu primera vez)\n";
    cout << "     20 turnos | pizarra SIEMPRE visible\n";
    cout << "2. Normal\n";
    cout << "     15 turnos\n";
    cout << "3. Dificil\n";
    cout << "     10 turnos | suposicion cuesta 2 | sin pizarra automatica\n";
    cout << "-----------------------------------------\n";
    dificultad = leerOpcion(1, 3);

    if (dificultad == 1)      turnosIniciales = 20;
    else if (dificultad == 2) turnosIniciales = 15;
    else                      turnosIniciales = 10;
}

// ============ INICIO DE PARTIDA ============

void generarCaso() {
    casoSospechoso = numeroAleatorio(NUM_SOSPECHOSOS);
    casoArma = numeroAleatorio(NUM_ARMAS);
    casoHabitacion = numeroAleatorio(NUM_HABITACIONES);
}

void reiniciarVariables() {
    turnos = turnosIniciales;
    resuelto = false;
    acusacionesFalladas = 0;
    suposicionesUsadas = 0;
    calificacionFinal = "";
}

void limpiarEvidencias() {
    numEvidencias = 0;
    for (int i = 0; i < NUM_SOSPECHOSOS; i++)  sospDescartado[i] = false;
    for (int i = 0; i < NUM_ARMAS; i++)        armaDescartada[i] = false;
    for (int i = 0; i < NUM_HABITACIONES; i++) lugarDescartado[i] = false;
}

void nuevaPartida() {
    // Si no hay ranking todavia, es la primera vez que se juega
    if (!existeArchivo("ranking.txt")) {
        mostrarBienvenida();
    }
    seleccionarEscenario();
    seleccionarDificultad();
    generarCaso();
    reiniciarVariables();
    limpiarEvidencias();
    limpiarPantalla();
    cout << "Se ha generado un nuevo caso. La investigacion comienza!\n";
    cout << "Escenario : " << escenarioNombre << "\n";
    cout << "Dificultad: " << nombreDificultad()
         << " | Turnos: " << turnosIniciales << "\n";
    pausar();
}

// ============ MOSTRAR CATALOGOS ============

void mostrarSospechosos() {
    limpiarPantalla();
    cout << "=== SOSPECHOSOS ===\n";
    for (int i = 0; i < NUM_SOSPECHOSOS; i++) {
        cout << (i + 1) << ". " << sospechosos[i] << "\n";
    }
}

void mostrarArmas() {
    limpiarPantalla();
    cout << "=== ARMAS ===\n";
    for (int i = 0; i < NUM_ARMAS; i++) {
        cout << (i + 1) << ". " << armas[i] << "\n";
    }
}

void mostrarHabitaciones() {
    limpiarPantalla();
    cout << "=== HABITACIONES ===\n";
    for (int i = 0; i < NUM_HABITACIONES; i++) {
        cout << (i + 1) << ". " << habitaciones[i] << "\n";
    }
}

// ============ EVIDENCIAS / PISTAS ============

// Texto de cada tipo de pista, centralizado para no repetir literales
string pistaSospechoso(int i) {
    return "PISTA: El sospechoso " + sospechosos[i] + " es inocente.";
}
string pistaArma(int i) {
    return "PISTA: El arma " + armas[i] + " no fue utilizada.";
}
string pistaLugar(int i) {
    return "PISTA: El crimen no ocurrio en " + habitaciones[i] + ".";
}

bool evidenciaExiste(string evidencia) {
    for (int i = 0; i < numEvidencias; i++) {
        if (evidencias[i] == evidencia) {
            return true;
        }
    }
    return false;
}

void agregarEvidencia(string evidencia) {
    if (numEvidencias < MAX_EVIDENCIAS) {
        evidencias[numEvidencias] = evidencia;
        numEvidencias++;
    }
}

void buscarPista() {
    limpiarPantalla();
    int tipo = numeroAleatorio(3) + 1; // 1=sospechoso, 2=arma, 3=habitacion
    string evidencia = "";
    int idx;

    if (tipo == 1) {
        do { idx = numeroAleatorio(NUM_SOSPECHOSOS); } while (idx == casoSospechoso);
        evidencia = pistaSospechoso(idx);
        sospDescartado[idx] = true;
    } else if (tipo == 2) {
        do { idx = numeroAleatorio(NUM_ARMAS); } while (idx == casoArma);
        evidencia = pistaArma(idx);
        armaDescartada[idx] = true;
    } else {
        do { idx = numeroAleatorio(NUM_HABITACIONES); } while (idx == casoHabitacion);
        evidencia = pistaLugar(idx);
        lugarDescartado[idx] = true;
    }

    if (evidenciaExiste(evidencia)) {
        cout << "Esta pista ya la conocias (no se gasta turno):\n";
        cout << evidencia << "\n";
    } else {
        agregarEvidencia(evidencia);
        turnos--; // solo una pista nueva gasta turno
        cout << "Nueva pista encontrada:\n";
        cout << evidencia << "\n";
        cout << "Turnos restantes: " << turnos << "\n";
    }
}

void revisarEvidencias() {
    limpiarPantalla();
    cout << "=== EVIDENCIAS ENCONTRADAS ===\n";
    if (numEvidencias == 0) {
        cout << "Aun no has encontrado ninguna pista.\n";
    } else {
        for (int i = 0; i < numEvidencias; i++) {
            cout << (i + 1) << ". " << evidencias[i] << "\n";
        }
    }
}

// ============ PIZARRA DE DEDUCCION ============

// Rellena con espacios a la derecha para alinear las columnas
string padDerecha(string s, int ancho) {
    while ((int)s.length() < ancho) {
        s = s + " ";
    }
    return s;
}

// Cuenta cuantos elementos siguen sin descartar
int contarPosibles(bool descartado[], int n) {
    int posibles = 0;
    for (int i = 0; i < n; i++) {
        if (!descartado[i]) posibles++;
    }
    return posibles;
}

// Dibuja la pizarra sin limpiar la pantalla (en Facil se muestra junto al menu)
void dibujarTablero() {
    const int COL_SOSP = 20;
    const int COL_ARMA = 25;
    cout << "================ PIZARRA DEL DETECTIVE ================\n";
    cout << " [X] = descartado      [?] = aun posible\n";
    cout << "------------------------------------------------------\n";
    cout << " " << padDerecha("SOSPECHOSOS", COL_SOSP)
         << padDerecha("ARMAS", COL_ARMA) << "LUGARES\n";

    // Las tres categorias miden lo mismo, por eso alcanza un solo for
    for (int i = 0; i < NUM_SOSPECHOSOS; i++) {
        string c1 = (sospDescartado[i]  ? "[X] " : "[?] ") + sospechosos[i];
        string c2 = (armaDescartada[i]  ? "[X] " : "[?] ") + armas[i];
        string c3 = (lugarDescartado[i] ? "[X] " : "[?] ") + habitaciones[i];
        cout << " " << padDerecha(c1, COL_SOSP) << padDerecha(c2, COL_ARMA) << c3 << "\n";
    }

    cout << "------------------------------------------------------\n";
    cout << " Aun posibles: "
         << contarPosibles(sospDescartado, NUM_SOSPECHOSOS)  << " sospechoso(s), "
         << contarPosibles(armaDescartada, NUM_ARMAS)        << " arma(s), "
         << contarPosibles(lugarDescartado, NUM_HABITACIONES)<< " lugar(es).\n";
    cout << " Cuando quede 1 de cada uno, ya sabes la respuesta!\n";
    cout << "======================================================\n";
}

void mostrarTablero() {
    limpiarPantalla();
    dibujarTablero();
}

// Al cargar partida las evidencias vuelven como texto, pero los bool de la
// pizarra no se guardan: se reconstruyen comparando con cada pista posible.
void reconstruirTablero() {
    for (int i = 0; i < NUM_SOSPECHOSOS; i++) {
        if (evidenciaExiste(pistaSospechoso(i))) sospDescartado[i] = true;
    }
    for (int i = 0; i < NUM_ARMAS; i++) {
        if (evidenciaExiste(pistaArma(i))) armaDescartada[i] = true;
    }
    for (int i = 0; i < NUM_HABITACIONES; i++) {
        if (evidenciaExiste(pistaLugar(i))) lugarDescartado[i] = true;
    }
}

// ============ ACUSACION Y CIERRE ============

bool verificarVictoria(int sospechoso, int arma, int habitacion) {
    return (sospechoso == casoSospechoso &&
            arma == casoArma &&
            habitacion == casoHabitacion);
}

bool verificarDerrota() {
    return (turnos <= 0);
}

void hacerSuposicion() {
    limpiarPantalla();
    cout << "=== HACER SUPOSICION ===\n\n";
    int costo = (dificultad == 3) ? 2 : 1;
    cout << "Propon una combinacion. Te dire cuantas son correctas,\n";
    cout << "pero NO cuales. Esto gasta " << costo << " turno(s) y sirve para deducir.\n\n";

    mostrarSospechosos();
    int s = leerOpcion(1, NUM_SOSPECHOSOS) - 1;

    mostrarArmas();
    int a = leerOpcion(1, NUM_ARMAS) - 1;

    mostrarHabitaciones();
    int h = leerOpcion(1, NUM_HABITACIONES) - 1;

    int aciertos = 0;
    if (s == casoSospechoso) aciertos++;
    if (a == casoArma)       aciertos++;
    if (h == casoHabitacion) aciertos++;

    turnos -= costo;
    suposicionesUsadas++;

    limpiarPantalla();
    cout << "=== RESULTADO DE LA SUPOSICION ===\n\n";
    cout << "Tu suposicion:\n";
    cout << "  Sospechoso: " << sospechosos[s] << "\n";
    cout << "  Arma      : " << armas[a] << "\n";
    cout << "  Lugar     : " << habitaciones[h] << "\n\n";
    cout << "Resultado: " << aciertos << " de 3 son correctas.\n";
    if (aciertos == 3) {
        cout << "\nLas TRES son correctas! Usa 'Hacer acusacion' para ganar.\n";
    }
    cout << "Turnos restantes: " << turnos << "\n";
    pausar();
}

void hacerAcusacion() {
    limpiarPantalla();
    cout << "=== HACER ACUSACION ===\n\n";
    cout << "Una acusacion es definitiva: si fallas, pierdes 1 turno.\n";
    cout << "1. Si, estoy listo para acusar\n";
    cout << "2. No, volver a investigar\n";
    if (leerOpcion(1, 2) == 2) {
        return;
    }

    mostrarSospechosos();
    int s = leerOpcion(1, NUM_SOSPECHOSOS) - 1;

    mostrarArmas();
    int a = leerOpcion(1, NUM_ARMAS) - 1;

    mostrarHabitaciones();
    int h = leerOpcion(1, NUM_HABITACIONES) - 1;

    if (verificarVictoria(s, a, h)) {
        resuelto = true;
    } else {
        turnos--;
        acusacionesFalladas++;
        cout << "\nAcusacion INCORRECTA. Pierdes un turno.\n";
        cout << "Turnos restantes: " << turnos << "\n";
        pausar();
    }
}

// Narra como ocurrio el crimen (se muestra al perder)
void mostrarReconstruccion() {
    cout << "------------ RECONSTRUCCION DEL CRIMEN ------------\n";
    cout << "Sin un detective que lo detuviera, la verdad sale a la luz\n";
    cout << "demasiado tarde:\n\n";
    cout << "Fue " << sospechosos[casoSospechoso] << " quien, oculto en "
         << habitaciones[casoHabitacion] << ",\n";
    cout << "espero el momento exacto. Con " << armas[casoArma]
         << " cometio el crimen\n";
    cout << "y borro toda huella. Nadie lo acuso a tiempo... y asi, el\n";
    cout << "asesino se desvanece en la noche.\n";
    cout << "--------------------------------------------------\n\n";
}

// Careo final contra La Sombra. Solo se entra tras lograr el rango ORO:
// tres mentiras y hay que elegir la prueba que desmonta cada una.
void rutaDeLaVerdad() {
    limpiarPantalla();
    cout << "============== RUTA DE LA VERDAD ==============\n\n";
    cout << "Cuando creias que todo termino, una voz resuena:\n";
    cout << "  \"Atrapaste a un simple peon, detective.\"\n\n";
    cout << "De entre las sombras aparece LA SOMBRA, el verdadero\n";
    cout << "cerebro detras del crimen. Te arrastra a su guarida para\n";
    cout << "un ultimo duelo: no de armas, sino de VERDADES.\n";
    cout << "Desmonta sus 3 mentiras antes de perder la credibilidad.\n";
    cout << "==============================================\n";
    pausar();

    string mentira[3] = {
        "Atrapaste a tu culpable. Yo no tengo nada que ver con esto.",
        "No existe una sola prueba que me conecte con la guarida.",
        "Esa noche yo estaba lejos. Era imposible que fuera yo."
    };
    string opcion[3][3] = {
        { "La confesion del culpable: obedecia ordenes de La Sombra.",
          "El arma estaba impecable, sin huellas.",
          "Esa noche hubo una fuerte tormenta." },
        { "El culpable jamas te ha visto en persona.",
          "El plano de la guarida llevaba TU firma.",
          "La puerta principal estaba cerrada con llave." },
        { "Un testigo dice haberte visto en otra ciudad.",
          "El barco zarpo recien al amanecer siguiente.",
          "El reloj de la torre se detuvo a la hora del crimen, contigo dentro." }
    };
    int correcto[3] = { 0, 1, 2 };

    int credibilidad = 3;
    bool atrapado = true;

    for (int fase = 0; fase < 3 && atrapado; fase++) {
        limpiarPantalla();
        cout << "--- CAREO " << (fase + 1) << " de 3 ---   Credibilidad: "
             << credibilidad << "\n\n";
        cout << "LA SOMBRA: \"" << mentira[fase] << "\"\n\n";
        cout << "Que prueba la desmonta?\n";
        for (int i = 0; i < 3; i++) {
            cout << (i + 1) << ". " << opcion[fase][i] << "\n";
        }

        int eleccion = leerOpcion(1, 3) - 1;
        while (eleccion != correcto[fase]) {
            credibilidad--;
            if (credibilidad <= 0) {
                atrapado = false;
                break;
            }
            cout << "\nEsa prueba no la desmonta. Te queda " << credibilidad
                 << " de credibilidad.\nIntenta otra vez:\n";
            eleccion = leerOpcion(1, 3) - 1;
        }

        if (eleccion == correcto[fase]) {
            cout << "\nEXACTO! La Sombra retrocede un paso, acorralada...\n";
            pausar();
        }
    }

    limpiarPantalla();
    cout << "================== FINAL ==================\n\n";
    if (atrapado) {
        cout << "*** FINAL VERDADERO ***\n\n";
        cout << "Sin una sola mentira donde esconderse, La Sombra cae de\n";
        cout << "rodillas. El verdadero cerebro del crimen esta tras las\n";
        cout << "rejas. Resolviste el caso que nadie pudo. Eres una LEYENDA.\n";
    } else {
        cout << "*** CASI LO TIENES... ***\n\n";
        cout << "Perdiste toda tu credibilidad. La Sombra escapa entre la\n";
        cout << "niebla, riendo y jurando volver. La caza continuara otro dia.\n";
    }
    cout << "==========================================\n";
    pausar();
}

void mostrarResultadoFinal() {
    limpiarPantalla();
    cout << "================ RESULTADO FINAL ================\n\n";

    if (resuelto) {
        // ORO: gana rapido, sin errores y con pocas suposiciones
        bool legendario = (acusacionesFalladas == 0 &&
                           suposicionesUsadas <= 2 &&
                           turnos >= turnosIniciales / 2);
        if (legendario) {
            calificacionFinal = "ORO";
            cout << "[ RANGO ORO ]  DETECTIVE LEGENDARIO\n\n";
            cout << "Resolviste el caso con rapidez y sin un solo error.\n";
            cout << "Pocos detectives llegan a este nivel.\n";
            if (!secretoDesbloqueado) {
                secretoDesbloqueado = true;
                guardarProgreso();
                cout << "\n>>> DESBLOQUEASTE un escenario secreto: 'La Guarida de\n";
                cout << "    La Sombra'. Aparecera al elegir escenario. <<<\n";
            }
        } else if (turnos <= 2) {
            calificacionFinal = "BRONCE";
            cout << "[ RANGO BRONCE ]  VICTORIA AL LIMITE\n\n";
            cout << "Lo resolviste justo a tiempo: el culpable casi escapa.\n";
        } else {
            calificacionFinal = "PLATA";
            cout << "[ RANGO PLATA ]  CASO RESUELTO\n\n";
            cout << "Buen trabajo, detective. Atrapaste al culpable.\n";
        }
    } else {
        calificacionFinal = "DERROTA";
        if (acusacionesFalladas > 0) {
            cout << "[ DERROTA ]  ACUSASTE A UN INOCENTE\n\n";
            cout << "Tus acusaciones erradas dejaron libre al verdadero asesino.\n\n";
        } else {
            cout << "[ DERROTA ]  CASO SIN RESOLVER\n\n";
            cout << "Se acabo el tiempo y el crimen quedo impune.\n\n";
        }
        mostrarReconstruccion();
    }

    cout << "\nEl caso real era:\n";
    cout << "  Culpable : " << sospechosos[casoSospechoso] << "\n";
    cout << "  Arma     : " << armas[casoArma] << "\n";
    cout << "  Lugar    : " << habitaciones[casoHabitacion] << "\n";
    cout << "  Pistas usadas: " << numEvidencias
         << " | Suposiciones: " << suposicionesUsadas
         << " | Acusaciones falladas: " << acusacionesFalladas << "\n\n";

    cout << "Ingrese su nombre para el ranking: ";
    getline(cin, nombreJugador);
    if (nombreJugador == "") {
        nombreJugador = "Anonimo";
    }

    guardarResultado();

    // La partida termino: se borra el archivo de guardado si existia
    remove("partida.txt");

    pausar();

    // El rango ORO da paso al careo final
    if (calificacionFinal == "ORO") {
        rutaDeLaVerdad();
    }
}

// ============ CICLO PRINCIPAL DE JUEGO ============

void cicloJuego() {
    bool salirAlMenu = false;

    while (turnos > 0 && !resuelto && !salirAlMenu) {
        limpiarPantalla();
        cout << escenarioNombre << "  |  " << nombreDificultad()
             << "  |  Turnos restantes: " << turnos << "\n";
        if (turnos == 1) {
            cout << ">>> ULTIMO TURNO: una pista nueva o acusacion fallida "
                    "termina el caso! <<<\n";
        }
        if (dificultad == 1) { // en Facil la pizarra queda siempre a la vista
            dibujarTablero();
        }
        mostrarMenuJuego();
        int accion = leerOpcion(1, 10);

        switch (accion) {
            case 1:  mostrarSospechosos(); pausar(); break;
            case 2:  mostrarArmas();       pausar(); break;
            case 3:  mostrarHabitaciones();pausar(); break;
            case 4:  buscarPista();        pausar(); break;
            case 5:  revisarEvidencias();  pausar(); break;
            case 6:  mostrarTablero();     pausar(); break;
            case 7:  hacerSuposicion();    break;
            case 8:  hacerAcusacion();     break;
            case 9:  guardarPartida();     pausar(); break;
            case 10: salirAlMenu = true;   break;
        }
    }

    // Solo se muestra el resultado si el juego termino de verdad
    if (!salirAlMenu) {
        mostrarResultadoFinal();
    }
}
