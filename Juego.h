#pragma once
#include <string>
 void JugarContraCPU();
 std::string PedirNombreJugador();
void MostrarNombreJugador1(std::string nombre);
 int TirarDado();
void TirarDadosBloqueadores(int (DadosBloqueadoresJugador1)[],int (DadosBloqueadoresJugador2)[]);
void MostrarDadosBloqueadores(int DadosBloqueador[]);
int TiradaDeLosDados(int Dados[],int Cantidad,int DadosBloqueadoresJugador1[]);
int DadosQueCoincidenConDadosBloqueadores(int dados[],int cantidad, int DadosBloqueadoresJugador1[]);
int puntajesRondas(int &PuntosJugadorRonda, int ContenidoDados[]);
bool DadosIguales(int dados[],int Cantidad);
