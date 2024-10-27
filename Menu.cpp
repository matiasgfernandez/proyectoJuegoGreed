#include <iostream>
#include "Menu.h"
#include "Juego.h"
#include "Creditos.h"
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
bool confimacion (int OpcionDeMenu){
    bool Entrar;
    switch(OpcionDeMenu){
case 1:
     cout<<endl<< "Esta seguro que desea entrar al modo UN JUGADOR?  ingrese 1 o 0 [ 1 = si | 2 = no]"<<endl;
            cout<<endl<< "ingrese opcion: ";
            cin>> Entrar;
    break;
    case 2:
            cout<<endl<<"Esta seguro que desea entrar al modo DOS JUGADORES?  ingrese 1 o 0 [ 1 = si | 2 = no]"<<endl;
            cout<<endl<< "ingrese opcion: ";
            cin>> Entrar;
            break;
        case 3:
             cout<<endl<< "Esta seguro que desea entrar a las ESTADISTICAS DEL JUEGO?  ingrese 1 o 0 [ 1 = si | 2 = no]"<<endl;
            cout<<endl<< "ingrese opcion: ";
            cin>> Entrar;
            break;
        case 4:
            cout<<endl<< "Esta seguro que desea entrar a los CREDITOS DEL JUEGO?  ingrese 1 o 0 [ 1 = si | 2 = no]"<<endl;
            cout<<endl<< "ingrese opcion: ";
            cin>> Entrar;
            break;
        case 0:
            cout<<endl<< "Esta seguro que desea SALIR DEL JUEGO?  ingrese 1 o 0 [ 1 = si | 2 = no]"<<endl;
            cout<<endl<< "ingrese opcion: ";
            cin>> Entrar;
            break;
    }
    return Entrar;
}
void ejecutarConfirmacion(bool DatoDeConfirmacion, int OpcionDeMenu){
system("cls");
 if(DatoDeConfirmacion==1){
switch(OpcionDeMenu){
case 1:
     JuegoUnJugador();
    break;
case 2:
            cout << "juego de dos jugadores" << endl;
            break;
        case 3:
            cout << "estadisticas" << endl;
            break;
        case 4:
         Creditos();
         system("pause");
            break;
        case 0:
            cout << "Gracias por jugar a nuestro juego :)" << endl;
            break;
}
    }
}
void EjecutarMenu(int opcionElegida) {
    switch(opcionElegida) {
bool Entrar;
        case 1:
           Entrar=confimacion(opcionElegida);
           ejecutarConfirmacion(Entrar,opcionElegida);
            /*
             int cantidad = 5;
            int dados[cantidad];

            string nombreJugador = PedirNombreJugador();

            ejecutarRondaActual(dados, cantidad, nombreJugador);
            */
            break;

        case 2:
            Entrar=confimacion(opcionElegida);
           ejecutarConfirmacion(Entrar,opcionElegida);
            break;
        case 3:
            Entrar=confimacion(opcionElegida);
           ejecutarConfirmacion(Entrar,opcionElegida);
            break;
        case 4:
            Entrar=confimacion(opcionElegida);
           ejecutarConfirmacion(Entrar,opcionElegida);
            break;
        case 0:
           Entrar=confimacion(opcionElegida);
           ejecutarConfirmacion(Entrar,opcionElegida);
            break;
        default:
            cout << "Numero invalido...por favor ingrese un numero de [0 al 4]" << endl;
            system("pause");
            break;
    }
}
