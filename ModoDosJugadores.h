#pragma once
#include <string>
void JuegoDosJugadores();
void PedirNombresJugadores(std::string NombreJugadores[]);
int TirarUnDado();
bool PreguntaPorTirada(int DadosRestantes);
void ColorLetra(int Color);
void TirarLosDadosBloqueadores(int (DadosBloqueadoresJugador1)[], int (DadosBloqueadoresJugador2)[]);
void dibujarLosDados(int cantidadDados,int  dados[]);
void MostrarLosDadosBloqueadores(int DadosBloqueador[]);
void InformarRondaActual(int ronda, std::string nombreJugador, int puntajeRonda[]);
