#include <iostream>
#include "Menu.h"


int main(){
int opcion;
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
