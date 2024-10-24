#include <iostream>
#include "Menu.h"
#include "Juego.h"
using namespace std;

int menu() {
    int opcion;
    cout << "GREED";
    cout << endl << "__________________________" << endl;
    cout << "1 - MODO UN JUGADOR" << endl;
    cout << "2 - MODO DOS JUGADORES" << endl;
    cout << "3 - ESTADISTICAS" << endl;
    cout << "4 - CREDITOS" << endl;
    cout << "__________________________" << endl;
    cout << "0 - SALIR" << endl;
    cout << endl << "ingrese alguna opcion: ";
    cin >> opcion;
    return opcion;
}

void EjecutarMenu(int opcionElegida) {
    switch(opcionElegida) {
        case 1: {
             int cantidad = 5;
            int dados[cantidad];

            string nombreJugador = PedirNombreJugador();

            ejecutarRondaActual(dados, cantidad, nombreJugador);
            break;
        }
        case 2:
            cout << "juego de dos jugadores" << endl;
            break;
        case 3:
            cout << "estadisticas" << endl;
            break;
        case 4:
            cout << "creditos" << endl;
            break;
        case 0:
            cout << "Gracias por jugar a nuestro juego :)" << endl;
            break;
        default:
            cout << "Numero invalido" << endl;
    }
}
