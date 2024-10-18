#pragma once
///para incluir el string
#include <string>
///declaracion de funciones
 void JugarContraCPU();
 std::string PedirNombreJugador();
void MostrarNombreJugador1(std::string nombre);
 int TirarDado();
void TirarDadosBloqueadores(int (DadosBloqueadoresJugador1)[],int (DadosBloqueadoresJugador2)[]);
void MostrarDadosBloqueadores(int DadosBloqueador[]);
void TiradaDeLosDados(int Dados[],int Cantidad,int DadosBloqueadoresJugador1[]);
int DadosQueCoincidenConDadosBloqueadores(int dados[],int cantidad, int DadosBloqueadoresJugador1[]);
