#pragma once

int menu();
int confimacion (int OpcionDeMenu);
void ejecutarConfirmacion(int DatoDeConfirmacion, int OpcionDeMenu, int &puntajeMasAlto, std::string &NombreJugadorMasAlto,bool &Jugaron);
void MostrarOpcion(int columna, int fila);
void BarraDeCarga();
void FinDelJuego();
void DibujarLinea(int cantidad, int Modelo);
void EjecutarMenu(int opcionElegida, int &puntajeMasAlto, std::string &NombreJugadorMasAlto,bool &Jugaron);


