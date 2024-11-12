#pragma once
#include <string>
void DibujarDisenio(int cantidad, int Modelo);
void JuegoDosJugadores(int &puntajes, std::string &NombresJugadoresEnElTop);
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
void CalcularPuntosTotalesJugadores(int puntosRondasJugador1[], int puntosRondasJugador2[],int puntosTotalesJugador[]);
void MostrarGanador(int puntosTotalesJugadores[],std::string NombreJugador[], std::string Ganador, bool empate);
std::string AveriguarGanador(int puntosTotalesJugadores[],std::string NombreJugador[], bool &Empate, int &puntajes, std::string &NombresJugadoresEnElTop);
void  MostrarRonda(int NumeroRonda);
void MostrarTurno(std::string NombreJugador);
