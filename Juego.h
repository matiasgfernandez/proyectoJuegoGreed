#pragma once

bool JugarContraCPU(int dados[], int &cantidad, int &puntajeRonda, bool &eleccionJugador, int DadosBloqueadoresJugador1[], std::string nombreJugador);

std::string PedirNombreJugador();
void MostrarNombreJugador1(std::string nombre);
int TirarDado();
void TirarDadosBloqueadores(int (DadosBloqueadoresJugador1)[],int (DadosBloqueadoresJugador2)[]);
void MostrarDadosBloqueadores(int DadosBloqueador[]);
void TiradaDeLosDados(int Dados[],int Cantidad,int DadosBloqueadoresJugador1[]);
int DadosQueCoincidenConDadosBloqueadores(int dados[],int cantidad, int DadosBloqueadoresJugador1[]);
bool DadosIguales(int dados[],int Cantidad);
int puntajesRondas(int dados[],int cantidad);
void MostrarPuntos(int puntosObtenidos);
void mostrarRondaActual(int ronda, std::string nombreJugador,int puntajeRonda[]);
void ejecutarRondaActual(int dados[],int cantidad, std::string nombreJugador);
void JuegoUnJugador();
bool PreguntaPorProximaTirada(int DadosRestantes);
void PuntosDeRonda(int CantidadDados,int PuntosXtirada,int PuntosTotalesRonda[],int ronda);
int CalcularPuntosTotalesRondas(int puntosRondas[]);
void MostrarPuntosTotales(int puntos);
