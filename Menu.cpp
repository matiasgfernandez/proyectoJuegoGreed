#include <iostream>
#include "Menu.h"
#include "Juego.h"
using namespace std;
///funcion para mostrarle al usuario el menu por pantalla y pedirle una opcion
int  menu(){
    int opcion;
    cout<< "GREED";
    cout<<endl<< "__________________________"<<endl;
    cout<< "1 - MODO UN JUGADOR"<<endl;
    cout<< "2 - MODO DOS JUGADORES"<<endl;
    cout<< "3 - ESTADISTICAS"<<endl;
    cout<< "4 - CREDITOS"<<endl;
    cout<< "__________________________"<<endl;
    cout<< "0 - SALIR"<<endl;
    cout<<endl<< "ingrese alguna opcion: ";
 cin>>opcion;
///vuelve a donde fue llamada la funcion y se lleva el valor de la variable opcion
 return opcion;
}
///funcion para ejecutar el menu
void EjecutarMenu(int opcionElegida){
switch(opcionElegida){
case 1:
    ///ingresa en caso de que el usuario haya ingresado 1
    JugarContraCPU();
    break;
case 2:
     ///ingresa en caso de que el usuario haya ingresado 2
    cout<< "juego de dos jugadores"<<endl;
    break;

case 3:
     ///ingresa en caso de que el usuario haya ingresado 3
    cout<< "estadisticas"<<endl;
    break;

case 4:
     ///ingresa en caso de que el usuario haya ingresado 4
    cout<< "creditos"<<endl;
    break;

case 0:
     ///ingresa en caso de que el usuario haya ingresado 5
    cout<< "Gracias por jugar a nuestro juego :)"<<endl;
    break;
default:
     ///ingresa en caso de que el usuario haya ingresado un numero diferente entre el 1 al 4
    cout<< "Numero invalido"<<endl;

}
}
