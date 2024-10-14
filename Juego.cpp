#include <iostream>
#include <ctime>
#include "Juego.h"
using namespace std;
///funcion que tira un dado
int TirarDado(){
return rand() % 6+1;
}
///funcion para tirar los dados, en caso de querer quitar dados habria que restarle la cantidad a la variable "cantidad"
void TiradaDeLosDados(int Dados[],int Cantidad)
{
     for(int i=0;i<Cantidad;i++){
            Dados[i]=TirarDado();
    }
    for(int j=0;j<Cantidad;j++){
    cout<< "Dado #" <<j+1<<":"<<Dados[j]<<endl;
    }
}
///funcion que tira los dados bloqueadores (la variable esta pasada por referencia)
void TirarDadosBloqueadores(int (&DadosBloqueadoresJugador1)[2],int (&DadosBloqueadoresJugador2)[2]){
  for(int i=0;i<2;i++){
    DadosBloqueadoresJugador1[i]= TirarDado();
    DadosBloqueadoresJugador2[i]= TirarDado();
  }
}
///funcion que muestra los dados bloqueadores
void MostrarDadosBloqueadores(int DadosBloqueador[]){
     cout << endl;
cout << "                      _______" << endl;
cout << "                     |"<<"   |"<< "   |" <<endl;
cout << "  Dados bloqueadores:| " << DadosBloqueador[0] << " | " << DadosBloqueador[1] << " |" << endl;
cout << "                     |___|___|" << endl;
    }
///pide nombre del jugador
string PedirNombreJugador(){
        string nombre;
      cout<< "ingrese su nombre: ";
      cin>>nombre;

      return nombre;
    }
///muestra el nombre del jugador
    void MostrarNombreJugador1(string nombre){
    cout<< "Turno del jugador: "<<nombre<<endl;
    }


///funcion jugar, es la que se le pasa al menu para que pueda correr el juego
void JugarContraCPU(){
///declaracion de variables
    int DadosBloqueadoresJugador1[2]{};
    int DadosBloqueadoresJugador2[2]{};
    int cantidadDeDados=5;
    int daditos[cantidadDeDados];
    string nombreJugador;
///pide el nombre del jugador
    nombreJugador =  PedirNombreJugador();
///borra pantalla
    system("cls");
///muestra el nombre del jugador
    MostrarNombreJugador1(nombreJugador);
///Tira los dados bloqueadores de los dos jugadores y lo guarda en la variables
    TirarDadosBloqueadores(DadosBloqueadoresJugador1,DadosBloqueadoresJugador2);
///muestra los dados bloqueadores
    MostrarDadosBloqueadores(DadosBloqueadoresJugador1);
///simula una tirada de dados
    TiradaDeLosDados(daditos,cantidadDeDados);
}
