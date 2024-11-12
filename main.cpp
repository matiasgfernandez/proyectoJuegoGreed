
#include <iostream>
#include <ctime>
#include "Menu.h"
#include "rlutil.h"

int main(){

    srand(time(0));
 ///declaracion de variables
    bool Jugaron=false;
     std::string NombreJugadorMasAlto;
     int puntajeMasAlto=0;
     int opcion;

     ///simula una barra de carga
    BarraDeCarga();

    do
    {
        ///menu
        opcion = menu();

        system("cls");
        ///ejecuta el menu con la opcion que ingresa el usuario. manda por referencia el puntaje mas alto, nombre del jugador con el puntaje mas alto y si jugaron, todo esto es para la estadisticas
        EjecutarMenu(opcion,puntajeMasAlto,NombreJugadorMasAlto, Jugaron);
    }
    while(opcion != 0);

    return 0;
}
