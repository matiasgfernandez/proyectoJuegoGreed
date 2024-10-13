#include <iostream>
#include "Juego.h"
using namespace std;

int TirarDado(){
return rand() % 6+1;
}
void TiradaDeLosDados(int Dados[],int Cantidad)
{
     for(int i=0;i<Cantidad;i++){
            cout<<TirarDado<<endl;
    }
    for(int j=0;j<Cantidad;j++){
    cout<< "Dado #" <<j+1<<":"<<Dados[j]<<endl;
    }
}

void JugarContraCPU(){
    int cantidadDeDados=5;
    int daditos[cantidadDeDados];
//hola
    TiradaDeLosDados(daditos,cantidadDeDados);
}
