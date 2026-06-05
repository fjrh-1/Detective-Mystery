#include <iostream>
#include <limits>

using namespace std;

int leerOpcion(int minimo, int maximo);
void pausar();
void menuPrincipal();
void mostrarInstrucciones();
void menuPrincipal()

{
    int opcion;

    do
    {
        cout << "\n====================================\n";
        cout << "       DETECTIVE MYSTERY\n";
        cout << "====================================\n";
        cout << "1. Nueva Partida\n";
        cout << "2. Cargar Partida\n";
        cout << "3. Ranking\n";
        cout << "4. Instrucciones\n";
        cout << "5. Salir\n";
        cout << "====================================\n";
        cout << "Seleccione una opcion: ";

        opcion = leerOpcion(1, 5);

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = 0;
        }

        switch(opcion)
        {
            case 1:
                // Reemplazar por nuevaPartida()
                cout << "\n[Nueva Partida]\n";
                break;

            case 2:
                // Reemplazar por cargarPartida()
                cout << "\n[Cargar Partida]\n";
                break;

            case 3:
                // Reemplazar por mostrarRanking()
                cout << "\n[Ranking]\n";
                break;

            case 4:
                mostrarInstrucciones();
                pausar();
                break;

            case 5:
                cout << "\nSaliendo del juego...\n";
                break;

            default:
                cout << "\nOpcion invalida.\n";
        }

    } while(opcion != 5);
}

void mostrarInstrucciones()
{
    cout << "\n========== INSTRUCCIONES ==========\n";
    cout << "Descubre al culpable del crimen.\n";
    cout << "Investiga pistas y revisa evidencias.\n";
    cout << "Realiza una acusacion antes de quedarte sin turnos.\n";
    cout << "===================================\n";
}