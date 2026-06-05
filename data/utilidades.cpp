#include <iostream>
#include <limits>

using namespace std;

// Pausa la ejecución hasta que el usuario presione ENTER
void pausar()
{
    cout << "\nPresione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Valida una opción dentro de un rango
int leerOpcion(int minimo, int maximo)
{
    int opcion;

    do
    {
        cin >> opcion;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = minimo - 1;
        }

        if(opcion < minimo || opcion > maximo)
        {
            cout << "Opcion invalida. Intente nuevamente: ";
        }

    } while(opcion < minimo || opcion > maximo);

    return opcion;
}
