#include <iostream>
#include <ctime>
#include "Juego.h"
#include "Estadisticas.h"
#include "rlutil.h"
using namespace std;

void HacerColorLetra(int Color){

    if(Color!=4){
        rlutil::setColor(Color);
    }
}

/// 1. pide nombre del jugador
string PedirNombreJugador(){

    ///ignora el ultimo enter
    (cin.ignore());

    string nombre;
    HacerColorLetra(14);

     rlutil::locate(4,3);
    cout << "INGRESE SU NOMBRE:";
    getline(cin, nombre);

 return nombre;
}

void dibujarDados(int cantidadDados,int  dados[]){

  HacerColorLetra(15);

    /// Imprimir los dados uno al lado del otro
    for (int j = 0; j < cantidadDados; j++) {
        cout << "   ___  ";
    }
    cout << endl;

    for (int j = 0; j < cantidadDados; j++) {
        cout << "  |   | ";
    }
    cout << endl;

    for (int j = 0; j < cantidadDados; j++) {
        cout << "  | " << dados[j] << " | ";
    }
    cout << endl;

    for (int j = 0; j < cantidadDados; j++) {
        cout << "  |___| ";
    }
    cout << endl;

  HacerColorLetra(14);
}

///  funcion que tira un dado
int TirarDado(){
 return rand() % 6 + 1;
}

///  funcion que tira los dados bloqueadores
void TirarDadosBloqueadores(int (DadosBloqueadoresJugador1)[]){

    for (int i = 0; i < 2; i++){
        DadosBloqueadoresJugador1[i] = TirarDado();
    }
}

/// 5. funcion que muestra los dados bloqueadores
void MostrarDadosBloqueadores(int DadosBloqueador[])
{
    cout<<endl<< "Dados bloqueadores: "<<endl;
    dibujarDados(2, DadosBloqueador);
    cout<<endl;
}
bool PreguntaPorProximaTirada(int DadosRestantes)
{
    int EleccionJugador;
    bool Error=false;
    if(DadosRestantes!=0)
    {
        do{
          if(Error==true){
              HacerColorLetra(7);
            cout<< "ERROR! usted ha ingresado un numero invalido."<<endl;
        }
        HacerColorLetra(11);
        cout << "LE QUEDAN "<<DadosRestantes<<" DADOS";
        HacerColorLetra(14);

        cout<<", desea realizar un lanzamiento? Ingrese 1 o 0. Si=1 y No=0 " << endl;
        cin >> EleccionJugador;
        Error=true;
        }while(EleccionJugador!=0 && EleccionJugador!=1);
    }
    else
    {
        HacerColorLetra(15);
        cout<< "¡LUSER! se ha quedado sin dados para tirar, ha perdido todos los puntos de esta ronda"<<endl;
        EleccionJugador=0;
        HacerColorLetra(14);
    }
    return EleccionJugador;
}

/// 7. funcion para tirar los dados, en caso de querer quitar dados habria que restarle la cantidad a la variable "cantidad"
void TiradaDeLosDados(int Dados[], int Cantidad, int DadosBloqueadoresJugador1[])
{
    cout<<"Lanzando dados..."<<endl<<endl;
    for (int i = 0; i < Cantidad; i++)
    {
        Dados[i] = TirarDado();
    }
   dibujarDados(Cantidad,Dados);
}
/// 8. funcion para saber que dado coincide con un dado bloqueador
int DadosQueCoincidenConDadosBloqueadores(int dados[], int cantidad, int DadosBloqueadoresJugador1[])
{
    int CoincideConDadoBloqueador = 0; // contador
    if(DadosBloqueadoresJugador1[0]!=DadosBloqueadoresJugador1[1])
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < cantidad; j++)
            {
                if (dados[j] == DadosBloqueadoresJugador1[i])
                {
                    cout <<endl<<"El dado#" << j + 1 << " coincide con el dado bloqueador #" << i + 1 << endl;
                    CoincideConDadoBloqueador++;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < cantidad; i++)
        {
            {
                if (dados[i] == DadosBloqueadoresJugador1[0])
                {
                    cout << "El dado#" << i + 1 << " coincide con los dados bloqueadores" << endl;
                    CoincideConDadoBloqueador++;
                }
            }
        }
    }
    cantidad -= CoincideConDadoBloqueador;
    return cantidad;
}


/// 9. funcion para calcular los puntajes de la ronda

int puntajesRondas(int DadosBloqueadores[],int dados[],int cantidad, bool &duplico)
{
    int  PuntosJugadorRonda=0;
    bool  duplicar;
    bool DadoIgualBloqueador=false;

    if(cantidad>0)
    {
        for(int i=0; i<cantidad; i++)
        {
            if(dados[i]!=DadosBloqueadores[0] && dados[i]!=DadosBloqueadores[1])
            {
                PuntosJugadorRonda+=dados[i];
            }
            else
            {
                DadoIgualBloqueador=true;
            }
        }
        if(DadoIgualBloqueador==false && cantidad>=2)
        {
            duplicar=DadosIguales(dados,cantidad);
            if(duplicar==true)
            {
                PuntosJugadorRonda*=2;
                duplico=true;
            }
        }
    }
    return PuntosJugadorRonda;
}



/// 10. funcion para saber si todos los dados son iguales
bool DadosIguales(int dados[], int Cantidad)
{
    bool TodoDadosIguales = false;
    bool PrimerDado = true;
    int numeroanterior;
    bool DadosDiferentes = false;
    if (Cantidad >= 2)
    {
        for (int i = 0; i < Cantidad; i++)
        {
            if (PrimerDado == true)
            {
                numeroanterior = dados[i];
                PrimerDado = false;
            }
            else
            {
                if (numeroanterior == dados[i])
                {
                    numeroanterior = dados[i];
                }
                else
                {
                    DadosDiferentes = true;
                }
            }
        }
    }
    if (DadosDiferentes == false)
    {
        TodoDadosIguales = true;
    }
    return TodoDadosIguales;
}

/// 11. funcion para mostrar los puntos obtenidos en una tirada
void MostrarPuntos(int PuntosObtenidos)
{
    cout << endl << "usted ha obtenido " << PuntosObtenidos << " puntos en esta tirada" << endl;
}

/// 13. muestra la ronda actual del jugador
void mostrarRondaActual(int ronda, string nombreJugador, int puntajeRonda[])
{
    cout << "Ronda Numero: " << ronda <<endl;
    cout<< "Jugador: " << nombreJugador << endl;
    for(int i=0; i<3; i++)
    {
        cout << "Puntaje acumulado de la Ronda#"<<i+1<<": " << puntajeRonda[i] << endl;
    }

}

void PuntosDeRonda(int CantidadDados,int PuntosXtirada,int PuntosTotalesRonda[],int ronda)
{

    if(CantidadDados==0)
    {
        PuntosTotalesRonda[ronda]=0;
    }
    else
    {
        PuntosTotalesRonda[ronda]+= PuntosXtirada;
    }

}

int CalcularPuntosTotalesRondas(int puntosRondas[])
{
    int TotalDePuntosPartida=0;

    for(int i=0; i<3; i++)
    {

        TotalDePuntosPartida+=puntosRondas[i];
    }
    return TotalDePuntosPartida;

}
void MostrarPuntosTotales(int puntos)
{
    ///oculta el cursor
    rlutil::hidecursor();
    for(int i=0;i<=10;i++){
    system("cls");
    ///muestra el mensaje solo cuando el numero es par
    if(i%2==0){
          ///hacer de color negro las letras
            HacerColorLetra(0);
            ///lo ubica en la columna 40 y fila 2
             rlutil::locate(40,2);
    ///diseño de recuadro de ascii
    Dibujolinea(1,201);
    rlutil::locate(41,2);
    Dibujolinea(20,205);
     rlutil::locate(61,2);
     Dibujolinea(1,187);

        rlutil::locate(40,3);
        Dibujolinea(1,186);
      rlutil::locate(61,3);
      Dibujolinea(1,186);

    rlutil::locate(41,3);
    cout<< "FINAL DE LAS RONDAS";

    rlutil::locate(40,4);
    Dibujolinea(1,200);
    rlutil::locate(41,4);
    Dibujolinea(20,205);
      rlutil::locate(61,4);
      Dibujolinea(1,188);
    }
    ///velocidad del parpadeo
    rlutil::msleep(100);
    }
    rlutil::locate(33,5);
    HacerColorLetra(14);
    cout<< "SUS PUNTOS TOTALES OBTENIDOS SON: "<<puntos<<endl;
    ///pausa pantalla
    system("pause");
///vuelve a mostrar el cursor antes de irse de la funcion
rlutil::showcursor();
}
bool ProximaTirada(bool DuplicoPuntos, int DadosQueLeQuedan){

 bool Tirar;

     if(DuplicoPuntos==false){
            ///preguna al jugador si quiere tirar una proxima tirada
            Tirar=PreguntaPorProximaTirada(DadosQueLeQuedan);
     }else{
              cout<<endl<< "Tirada de dados obligatoria"<<endl;
              Tirar=true;
     }

return Tirar;
}

void  CartelRonda(int NumeroRonda){
rlutil::hidecursor();
 for(int i=0;i<=10;i++){
    system("cls");
    ///muestra el mensaje solo cuando el numero es par
    if(i%2==0){
          ///hacer de color negro las letras
            HacerColorLetra(14);
            ///lo ubica en la columna 50 y fila 11
             rlutil::locate(50,11);
    ///diseño de recuadro de ascii
    Dibujolinea(1,201);
     rlutil::locate(51,11);
     Dibujolinea(10,205);
     rlutil::locate(61,11);
     Dibujolinea(1,187);

    rlutil::locate(50,12);
    Dibujolinea(1,186);
    rlutil::locate(61,12);
    Dibujolinea(1,186);
     rlutil::locate(52,12);
    cout<< "RONDA  "<<NumeroRonda;

    rlutil::locate(50,13);
    Dibujolinea(1,200);
    rlutil::locate(51,13);
    Dibujolinea(10,205);
    rlutil::locate(61,13);
    Dibujolinea(1,188);
    }
    ///velocidad del parpadeo
    rlutil::msleep(100);
    }

cout<<endl;
rlutil::locate(40,14);
system("pause");
system("cls");
   rlutil::showcursor();
}
///funcion que la llama menu.cpp
void JuegoUnJugador(int &puntajes, string &NombresJugadoresEnElTop)
{
///declaracion y inicializacion de acumulador que guardara el resultado de la suma de las 3 rondas
    int puntosTotales=0;
    ///declaracion y inicializacion de vector que va a guarda los puntos acumulados en las 3 rondas
    int puntajeRonda[3] {};
    ///le pide el nombre al usuario y lo guarda en la variable nombreJugador
    string nombreJugador = PedirNombreJugador();
///borra pantalla
    system("Cls");

///un for que recorre las tres rondas del juego
    for(int i=1; i<=3; i++)
    {
        CartelRonda(i);
        ///la cantidad de dados que tiene el jugador
        int DadosRestantes = 5;
        ///guarda los valores de los dados
        int dados[DadosRestantes];
        ///guarda los valores de los dados bloqueadores del jugador 1
        int DadosBloqueadoresJugador1[2] {};
        ///muestra numero de ronda, nombre del jugador, puntaje total
        mostrarRondaActual(i,nombreJugador,puntajeRonda);
        /// Tira los dados bloqueadores de los dos jugadores y lo guarda en las variables
        TirarDadosBloqueadores(DadosBloqueadoresJugador1);
        /// muestra los dados bloqueadores
        MostrarDadosBloqueadores(DadosBloqueadoresJugador1);
///pregunta al jugador si quiere tirar los dados y lo guarda en la variable eleccionJugador
        bool EleccionJugador=PreguntaPorProximaTirada(DadosRestantes);
        system("cls");
///ciclo que corre todas las tiradas, corta cuando la eleccion del jugador sea false o tambien corta cuando los dados restantes sean 0
        while(EleccionJugador==true && DadosRestantes!=0)
        {
            bool duplico=false;
            ///muestra la ronda actual, el nombre del jugador y el puntaje de las 3 rondas
            mostrarRondaActual(i,nombreJugador,puntajeRonda);
         ///muestra los 2 dados bloqueadores
            MostrarDadosBloqueadores(DadosBloqueadoresJugador1);
            ///simula la tirada de dados
            TiradaDeLosDados(dados,DadosRestantes,DadosBloqueadoresJugador1);
            ///suma los dados que no son iguales a un dado bloqueador
            int puntajeTirada = puntajesRondas(DadosBloqueadoresJugador1, dados, DadosRestantes,duplico);
            ///resta la cantidad de dados que coincidieron con un dado bloqueador
            DadosRestantes = DadosQueCoincidenConDadosBloqueadores(dados, DadosRestantes, DadosBloqueadoresJugador1);
            ///muestra los puntos que hizo el jugador en la tirada
            MostrarPuntos(puntajeTirada);
            ///va sumando los puntos de la tirada en el vector de puntajeRonda
            PuntosDeRonda(DadosRestantes,puntajeTirada,puntajeRonda,i-1);
            ///pausa la pantalla para que el usuario pueda analizar la tirada
            system("pause");
            ///borra la pantalla
            system("cls");
            ///muestra los puntos actualizados
            mostrarRondaActual(i,nombreJugador,puntajeRonda);
            ///muestra sus dados bloqueadores
            MostrarDadosBloqueadores(DadosBloqueadoresJugador1);
            ///el jugador elige si quiere hacer otra tirada
            EleccionJugador=ProximaTirada(duplico, DadosRestantes);
            ///pausa la pantalla
            system("pause");
            ///borra la pantalla
            system("cls");
        }
    }
    ///suma los puntos de todas las rondas y lo pasa al acumulador puntosTotales
    puntosTotales=CalcularPuntosTotalesRondas(puntajeRonda);
    ///muestra los puntosTotales
    MostrarPuntosTotales(puntosTotales);
Estadisticas(puntosTotales,nombreJugador, puntajes, NombresJugadoresEnElTop);

}


