#include <iostream>
#include <ctime>
#include "Juego.h"
using namespace std;

///funcion que tira un dado
int TirarDado(){
return rand() % 6+1;
}
///funcion para saber que dado coincide con un dado bloqueador
int DadosQueCoincidenConDadosBloqueadores(int dados[],int cantidad, int DadosBloqueadoresJugador1[]){
int CoincideConDadoBloqueador=0;
    if(DadosBloqueadoresJugador1[0]!=DadosBloqueadoresJugador1[1]){
    for(int i=0;i<2;i++){
        for(int j=0;j<cantidad;j++){
            if(dados[j]==DadosBloqueadoresJugador1[i]){
                cout<< "El dado#"<<j+1<< " coincide con el dado bloqueador #"<<i+1<<endl;
               CoincideConDadoBloqueador++;
            }
        }
    }
}else{
    for(int i=0;i<cantidad;i++){
            if(dados[i]==DadosBloqueadoresJugador1[0]){
                cout<< "El dado#"<<i+1<< " coincide con los dados bloqueadores"<<endl;
               CoincideConDadoBloqueador++;
}
}
}
cantidad-=CoincideConDadoBloqueador;
return cantidad;
}
///funcion para tirar los dados, en caso de querer quitar dados habria que restarle la cantidad a la variable "cantidad"
int TiradaDeLosDados(int Dados[],int Cantidad, int DadosBloqueadoresJugador1[])
{
     for(int i=0;i<Cantidad;i++){
            Dados[i]=TirarDado();
    }
    for(int j=0;j<Cantidad;j++){
    cout<< "Dado #" <<j+1<<":"<<Dados[j]<<endl;
    }
 Cantidad=DadosQueCoincidenConDadosBloqueadores(Dados,Cantidad,DadosBloqueadoresJugador1);
 return Cantidad;
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
        string nombre;
      cout<< "ingrese su nombre: ";
      ///Guarda en el cin hasta que haya un enter
      getline(cin, nombre);

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
///simula una tirada de dados y te dice que dados coinciden con un dado bloqueador
 cantidadDeDados =TiradaDeLosDados(daditos,cantidadDeDados,DadosBloqueadoresJugador1);
}
