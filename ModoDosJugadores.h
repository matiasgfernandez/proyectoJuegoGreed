#pragma once
#include <string>
void JuegoDosJugadores();
void PedirNombresJugadores(std::string NombreJugadores[]);
int TirarUnDado();
bool PreguntaPorTirada(bool &duplicoPuntos, int DadosRestantes);
void ColorLetra(int Color);
void TirarLosDadosBloqueadores(int (DadosBloqueadoresJugador1)[], int (DadosBloqueadoresJugador2)[]);
void dibujarLosDados(int cantidadDados,int  dados[]);
void MostrarLosDadosBloqueadores(int DadosBloqueador[]);
void InformarRondaActual(int ronda, std::string nombreJugador, int puntajeRonda[]);
void TiradaDeDados(int Dados[], int Cantidad);
int DadosIgualesABloqueadores(int dados[], int cantidad, int DadosBloqueadoresJugador[]);
bool ComprobarDadosIguales(int dados[], int Cantidad);
int puntajeTirada(int DadosBloqueadores[],int dados[],int cantidad, bool &duplico);
void MostrarLosPuntos(int PuntosObtenidos);
void PuntosDeLasRondas(int CantidadDados,int PuntosXtirada,int PuntosTotalesRonda[],int ronda);
