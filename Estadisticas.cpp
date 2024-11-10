#include <iostream>
#include "rlutil.h"
using namespace std;

void Dibujolinea(int cantidad, int Modelo)
{
    for(int i=1; i<=cantidad; i++)
    {
        cout<< (char) Modelo;
    }
}
void MostrarEstadisticas(string NombreJugadorEnElTop, int PuntajeMasAlto, bool Jugaron){

if(Jugaron==true){
    rlutil::locate(45,6);
    Dibujolinea(1,201);
    rlutil::locate(46,6);
    Dibujolinea(14, 205);
    rlutil::locate(60,6);
    Dibujolinea(1,187);

    rlutil::locate(45,7);
    Dibujolinea(1,186);
        rlutil::locate(60,7);
    Dibujolinea(1,186);

        rlutil::locate(47,7);
        cout<< "ESTADISTICAS ";

          rlutil::locate(45,8);
    Dibujolinea(1,200);
    rlutil::locate(46,8);
    Dibujolinea(14, 205);
    rlutil::locate(60,8);
    Dibujolinea(1,188);

     rlutil::locate(26,10);
    Dibujolinea(1,201);
    rlutil::locate(27,10);
    Dibujolinea(53, 205);
    rlutil::locate(80,10);
    Dibujolinea(1,187);

    rlutil::locate(26,11);
    Dibujolinea(1,186);
    rlutil::locate(26,12);
    Dibujolinea(1,186);
    rlutil::locate(26,13);
    Dibujolinea(1,186);
        rlutil::locate(80,11);
    Dibujolinea(1,186);
     rlutil::locate(80,12);
    Dibujolinea(1,186);
  rlutil::locate(80,13);
    Dibujolinea(1,186);
        rlutil::locate(28,12);
     cout<< "El puntaje mas alto es de "<<NombreJugadorEnElTop<< " con: "<<PuntajeMasAlto<< " puntos"<<endl;

            rlutil::locate(26,14);
    Dibujolinea(1,200);
    rlutil::locate(27,14);
    Dibujolinea(53, 205);
    rlutil::locate(80,14);
    Dibujolinea(1,188);
cout<<endl;
system("pause");
}else{
  rlutil::locate(16,11);
    Dibujolinea(1,201);
    rlutil::locate(17,11);
    Dibujolinea(89, 205);
    rlutil::locate(106,11);
    Dibujolinea(1,187);

    rlutil::locate(16,12);
    Dibujolinea(1,186);
 rlutil::locate(106,12);
    Dibujolinea(1,186);

        rlutil::locate(18,12);
     cout<< "AUN NO SE HA JUGADO NINGUN MODO, POR FAVOR JUEGA PARA PODER COMPETIR CONTRA LOS MEJORES";

            rlutil::locate(16,13);
    Dibujolinea(1,200);
    rlutil::locate(17,13);
    Dibujolinea(89, 205);
   rlutil::locate(106,13);
   Dibujolinea(1,188);

    cout<<endl;
    system("pause");
}
}

void Estadisticas(int puntos, string nombre, int &puntajes, string &NombresJugadoresEnElTop){

 if(puntos>puntajes){
    puntajes=puntos;
    NombresJugadoresEnElTop=nombre;

}
}
