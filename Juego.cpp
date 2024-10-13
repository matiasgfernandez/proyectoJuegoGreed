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
void TirarDadosBloqueadores(int (&DadosBloqueadores)[2]){
  for(int i=0;i<2;i++){
    DadosBloqueadores[i]= TirarDado();
  }
}
///funcion jugar, es la que se le pasa al menu para que pueda correr el juego
void JugarContraCPU(){
    int DadosBloqueadores[2]{};
    int cantidadDeDados=5;
    int daditos[cantidadDeDados];
    TirarDadosBloqueadores(DadosBloqueadores);
    ///esto solo esta aca para desmostrar que efectivamente esta funcionando
    for(int i=0;i<2;i++){
        cout<<"Dado bloqueador #"<<i+1<<":"<<DadosBloqueadores[i]<<endl;
    }
    TiradaDeLosDados(daditos,cantidadDeDados);
}
