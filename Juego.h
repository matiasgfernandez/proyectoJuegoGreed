#pragma once

int TirarDado();
int DadosQueCoincidenConDadosBloqueadores(int dados[],int cantidad, int DadosBloqueadoresJugador1[]);
int puntajesRondas(int dados[],int cantidad, bool &duplico);
int CalcularPuntosTotalesRondas(int puntosRondas[]);
bool ProximaTirada(bool DuplicoPuntos, int DadosQueLeQuedan);
bool DadosIguales(int dados[],int Cantidad);
bool PreguntaPorProximaTirada(int DadosRestantes);
std::string PedirNombreJugador();
void TirarDadosBloqueadores(int (DadosBloqueadoresJugador1)[]);
void MostrarDadosBloqueadores(int DadosBloqueador[]);
void TiradaDeLosDados(int Dados[],int Cantidad,int DadosBloqueadoresJugador1[]);
void MostrarPuntos(int puntosObtenidos);
void mostrarRondaActual(int ronda, std::string nombreJugador,int puntajeRonda[]);
void ejecutarRondaActual(int dados[],int cantidad, std::string nombreJugador);
void JuegoUnJugador(int &puntajes, std::string &NombresJugadoresEnElTop);
void PuntosDeRonda(int CantidadDados,int PuntosXtirada,int PuntosTotalesRonda[],int ronda);
void MostrarPuntosTotales(int puntos);
void dibujarDados(int cantidadDados,int  dados[]);
void HacerColorLetra(int Color);
void  CartelRonda(int NumeroRonda);
