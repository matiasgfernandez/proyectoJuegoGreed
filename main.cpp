
#include <iostream>
#include <ctime>
#include "Menu.h"
#include "rlutil.h"
int main()
{
    srand(time(0));
    bool Jugaron=false;
     std::string NombreJugadorMasAlto;
     int puntajeMasAlto=0;
     int opcion;

    BarraDeCarga();
    do
    {
        ///menu
        opcion = menu();
        ///borra pantalla
        system("cls");
        ///ejecuta el menu con la opcion que ingresa el usuario
        EjecutarMenu(opcion,puntajeMasAlto,NombreJugadorMasAlto, Jugaron);
    }
    while(opcion != 0);

    return 0;
}
