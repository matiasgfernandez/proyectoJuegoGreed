#pragma once
int menu();
void EjecutarMenu(int opcionElegida, int &puntajeMasAlto, std::string &NombreJugadorMasAlto);
int confimacion (int OpcionDeMenu);
void ejecutarConfirmacion(int DatoDeConfirmacion, int OpcionDeMenu, int &puntajeMasAlto, std::string &NombreJugadorMasAlto);
void MostrarOpcion(int columna, int fila);
void BarraDeCarga();
void FinDelJuego();
void DibujarLinea(int cantidad, int Modelo);
