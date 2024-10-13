#include <iostream>
#include <ctime>
#include "Menu.h"
#include "Juego.h"
#include <ctime>
int main(){
srand(time(0));
int opcion;
srand(time(0));
do{
///menu
opcion= menu();
///borra pantalla
  system("cls");
  ///ejecuta el menu con la opcion que ingresa el usuario
EjecutarMenu(opcion);
///pausa la pantalla hasta que el usuario toque una letra
 system("pause");
}while(opcion!=0);
    return 0;
}
