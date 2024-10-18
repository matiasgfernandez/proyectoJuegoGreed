#include <iostream>
#include <ctime>
#include "Juego.h"
using namespace std;

///funcion que tira un dado
int TirarDado(){
///tira un numero random
return rand() % 6+1;
}
///funcion para saber que dado coincide con un dado bloqueador
int DadosQueCoincidenConDadosBloqueadores(int dados[],int cantidad, int DadosBloqueadoresJugador1[]){
///inicializo contador. El contador esta para contar la cantidad de numeros coinciden con un dado bloqueador
int CoincideConDadoBloqueador=0;
///if para saber si el dado bloqueador 1 es diferente o igual al dado bloqueador 2
    if(DadosBloqueadoresJugador1[0]!=DadosBloqueadoresJugador1[1]){
/// for para recorrer los 2 bloqueadores
    for(int i=0;i<2;i++){
/// for para recorrer todos los dados del jugador
        for(int j=0;j<cantidad;j++){
/// if para preguntar si el dado es igual al dado bloqueador
            if(dados[j]==DadosBloqueadoresJugador1[i]){
/// muestra por pantalla cuales dados coinciden con algun dado bloqueador
                cout<< "El dado#"<<j+1<< " coincide con el dado bloqueador #"<<i+1<<endl;
///cuenta la cantidad de dados que coinciden con algun dado bloqueador
               CoincideConDadoBloqueador++;
            }
        }
    }
///va para el else en caso de que los dados bloqueadores sean iguales
}else{
///for para recorrer los dados del jugador
    for(int i=0;i<cantidad;i++){
/// if para preguntar si el dado es igual al dado bloqueador
            if(dados[i]==DadosBloqueadoresJugador1[0]){
 /// muestra por pantalla cuales dados coinciden con algun dado bloqueador
                cout<< "El dado#"<<i+1<< " coincide con los dados bloqueadores"<<endl;
///cuenta la cantidad de dados que coinciden con algun dado bloqueador
               CoincideConDadoBloqueador++;
}
}
}
///le resta la cantidad de numeros que coincidieron con algun dado bloqueador al contador cantidad
cantidad-=CoincideConDadoBloqueador;
///vuelve a donde fue llamado y se lleva el valor de la variable cantidad
return cantidad;
}
///funcion para tirar los dados, en caso de querer quitar dados habria que restarle la cantidad a la variable "cantidad"
void TiradaDeLosDados(int Dados[],int Cantidad, int DadosBloqueadoresJugador1[])
{
/// for para recorrer la cantidad de vueltas que tenga la variable cantidad
     for(int i=0;i<Cantidad;i++){
///llama a la funcion tirarDado y carga el vector dados
            Dados[i]=TirarDado();
    }
/// for para recorrer la cantidad de vueltas que tenga la variable cantidad
    for(int j=0;j<Cantidad;j++){
/// muestra por pantalla los dados tirados
    cout<< "Dado #" <<j+1<<":"<<Dados[j]<<endl;
    }
}
///funcion que tira los dados bloqueadores (la variable esta pasada por referencia)
void TirarDadosBloqueadores(int (DadosBloqueadoresJugador1)[],int (DadosBloqueadoresJugador2)[]){
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
    ///ignora el enter anterior
    (cin. ignore());
    ///declaracion de la variable nombre
        string nombre;
///le pide al usuario que ingrese su nombre
      cout<< "ingrese su nombre: ";
      ///Guarda en el cin hasta que haya un enter
      getline(cin, nombre);
///vuelve a donde fue llamada y se lleva lo que contiene la varible nombre
      return nombre;
    }
///muestra por pantalla el nombre del jugador en su turno
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
///simula una tirada de dados y te dice que dados coinciden con un dado bloqueador
 TiradaDeLosDados(daditos,cantidadDeDados,DadosBloqueadoresJugador1);
 ///llama a la funcion DadosQueCoincidenConDadosBloqueadores y se e asigna el valor que traiga a la variable cantidadDeDados
 cantidadDeDados=DadosQueCoincidenConDadosBloqueadores(daditos, cantidadDeDados,DadosBloqueadoresJugador1);
}
