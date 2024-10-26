#include <iostream>
#include "Menu.h"
#include "Juego.h"
using namespace std;

int menu() {
    system("cls");
    int opcion;
    cout<<endl<< "        _______"<<endl;
   cout<<   "       |       | "<<endl;
    cout << "       | GREED |            "<<endl;
    cout<< "       |_______|"<<endl;
    cout << " ______________________________"<<endl;
    cout<< "|                              |";
    cout <<endl<< "|1 - MODO UN JUGADOR           |" << endl;
    cout<< "|                              |";
    cout <<endl<< "|2 - MODO DOS JUGADORES        |" << endl;
    cout<< "|                              |";
    cout <<endl<< "|3 - ESTADISTICAS              |" << endl;
    cout<< "|                              |";
    cout << endl<<"|4 - CREDITOS                  |" << endl;
    cout<< "|                              |";
    cout << endl<<"|0 - SALIR                     |" << endl;
    cout << "|______________________________|" <<endl;
    cout << endl << "ingrese alguna opci¢n: ";
    cin >> opcion;
    return opcion;
}

void EjecutarMenu(int opcionElegida) {
    switch(opcionElegida) {
int confirmacion;
        case 1:
            cout<< "Esta seguro que desea entrar al modo UN JUGADOR?      ingrese 1 o 0 - | 1 = si | 2 = no|"<<endl;
            cout<<endl<< "ingrese opcion: ";
            cin>> confirmacion;
            ///si el usuario ingresa 1 entra a la funcion juegoUnJugador - si el usuario ingresa 0 vuelve al menu
            if(confirmacion==1){
             system("cls");
            JuegoUnJugador();
            }
            /*
             int cantidad = 5;
            int dados[cantidad];

            string nombreJugador = PedirNombreJugador();

            ejecutarRondaActual(dados, cantidad, nombreJugador);
            */
            break;

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
