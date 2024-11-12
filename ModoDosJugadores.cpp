#include <iostream>
#include <ctime>
#include "ModoDosJugadores.h"
#include "Estadisticas.h"
#include "rlutil.h"

using namespace std;

void DibujarDisenio(int cantidad, int Modelo)
{
    for(int i=1; i<=cantidad; i++)
    {
        cout<< (char) Modelo;
    }
}
void PedirNombresJugadores(string NombresJugadores[])
{
    (cin.ignore());
    for(int i=0; i<2; i++)
    {
        system("cls");
        ColorLetra(14);
        rlutil::locate(4,3);
        cout << "JUGADOR "<<i+1<<" INGRESE SU NOMBRE:";
        getline(cin, NombresJugadores[i]);
        system("cls");
    }
}
int TirarUnDado()
{
    return rand() % 6 + 1;
}

void ColorLetra(int Color)
{
    if(Color!=4)
    {
        rlutil::setColor(Color);
    }
}

bool PreguntarPorTirada(bool &duplicoPuntos, int DadosRestantes)
{
    int EleccionJugador;
    bool Error=false;
///en caso que haya multiplicado puntos la tirada es obligatoria
    if(duplicoPuntos==true)
    {
        cout<<endl<< "Tirada de dados obligatoria"<<endl;
        system("pause");
        EleccionJugador=true;
        duplicoPuntos=false;

    }
    else
    {
        if(DadosRestantes!=0)
        {
            do
            {
                if(Error==true)
                {
                    ColorLetra(7);
                    cout<< "ERROR! usted ha ingresado un numero invalido."<<endl;
                }
                ColorLetra(11);
                cout << "LE QUEDAN "<<DadosRestantes<<" DADOS";
                ColorLetra(14);

                cout<<", desea realizar un lanzamiento? Ingrese 1 o 0. Si=1 y No=0 " << endl;
                cin >> EleccionJugador;
                Error=true;
            }
            while(EleccionJugador!=0 && EleccionJugador!=1);
        }
        else
        {
            ColorLetra(15);
            cout<< "LUSER! te quedaste sin dados para tirar, perdiste todos tus puntos de esta ronda"<<endl<<endl;
            system("pause");
            EleccionJugador=0;
            ColorLetra(14);
        }
    }
    return EleccionJugador;
}

void TirarLosDadosBloqueadores(int (DadosBloqueadoresJugador1)[], int (DadosBloqueadoresJugador2)[])
{
    for (int i = 0; i < 2; i++)
    {
        DadosBloqueadoresJugador1[i] = TirarUnDado();
        DadosBloqueadoresJugador2[i] = TirarUnDado();
    }
}

void dibujarLosDados(int cantidadDados,int  dados[])
{
    ColorLetra(15);
/// Imprimir los dados uno al lado del otro
    for (int j = 0; j < cantidadDados; j++)
    {
        cout << "   ___  ";
    }
    cout << endl;

    for (int j = 0; j < cantidadDados; j++)
    {
        cout << "  |   | ";
    }
    cout << endl;

    for (int j = 0; j < cantidadDados; j++)
    {
        cout << "  | " << dados[j] << " | ";
    }
    cout << endl;

    for (int j = 0; j < cantidadDados; j++)
    {
        cout << "  |___| ";
    }
    cout << endl;
    ColorLetra(14);
}

void MostrarLosDadosBloqueadores(int DadosBloqueador[])
{
    cout<<endl<< "Dados bloqueadores: "<<endl;
    dibujarLosDados(2, DadosBloqueador);
    cout<<endl;
}

void InformarRondaActual(int ronda, string nombreJugador, int puntajeRonda[])
{
    cout << "Ronda Numero: " << ronda <<endl;
    cout<< "TURNO DEL JUGADOR: " << nombreJugador << endl;
    for(int i=0; i<3; i++)
    {
        cout << "Puntaje acumulado de la Ronda#"<<i+1<<": " << puntajeRonda[i] << endl;
    }

}
void TiradaDeDados(int Dados[], int Cantidad)
{
    cout<<"Lanzando dados..."<<endl<<endl;
    for (int i = 0; i < Cantidad; i++)
    {
        Dados[i] = TirarUnDado();
    }
    dibujarLosDados(Cantidad,Dados);
}
int DadosIgualesABloqueadores(int dados[], int cantidad, int DadosBloqueadoresJugador[])
{
    int CoincideConDadoBloqueador = 0; // contador
    if(DadosBloqueadoresJugador[0]!=DadosBloqueadoresJugador[1])
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < cantidad; j++)
            {
                if (dados[j] == DadosBloqueadoresJugador[i])
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
                if (dados[i] == DadosBloqueadoresJugador[0])
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
int puntajeTirada(int DadosBloqueadores[],int dados[],int cantidad, bool &duplico)
{
    int  PuntosJugadorTirada=0;
    bool  duplicar;
    bool DadoIgualBloqueador=false;

    if(cantidad>0)
    {
        for(int i=0; i<cantidad; i++)
        {
            if(dados[i]!=DadosBloqueadores[0] && dados[i]!=DadosBloqueadores[1])
            {
                PuntosJugadorTirada+=dados[i];
            }
            else
            {
                DadoIgualBloqueador=true;
            }
        }
        if(DadoIgualBloqueador==false && cantidad>=2)
        {
            duplicar=ComprobarDadosIguales(dados,cantidad);
            if(duplicar==true)
            {
                PuntosJugadorTirada*=2;
                duplico=true;
            }
        }
    }
    return PuntosJugadorTirada;
}
void MostrarLosPuntos(int PuntosObtenidos)
{
    cout << endl << "usted ha obtenido " << PuntosObtenidos << " puntos en esta tirada" << endl;
}
bool ComprobarDadosIguales(int dados[], int Cantidad)
{
    bool SonDadosIguales = false;
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
        SonDadosIguales = true;
    }
    return SonDadosIguales;
}
void PuntosDeLasRondas(int CantidadDados,int PuntosXtirada,int PuntosTotalesRonda[],int ronda)
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
void CalcularPuntosTotalesJugadores(int puntosRondasJugador1[], int puntosRondasJugador2[],int puntosTotalesJugador[])
{
    ///carga todos los puntos de la rondas de los 2 jugadores
    for(int i=0; i<3; i++)
    {
        puntosTotalesJugador[0]+=puntosRondasJugador1[i];
        puntosTotalesJugador[1]+=puntosRondasJugador2[i];
    }

}
void MostrarGanador(int puntosTotalesJugadores[],string NombreJugador[],string ganador, bool empate)
{
    ///oculta el cursor
    rlutil::hidecursor();
    for(int i=0; i<=10; i++)
    {
        system("cls");
        ///muestra el mensaje solo cuando el numero es par
        if(i%2==0)
        {
            ///hacer de color negro las letras
            ColorLetra(0);
            ///lo ubica en la columna 40 y fila 2
            rlutil::locate(40,2);
            ///diseño de recuadro de ascii
            DibujarDisenio(1,201);
            DibujarDisenio(19,205);
            DibujarDisenio(1,187);
            cout<<endl;
            rlutil::locate(40,3);
            cout<<(char)186<< "FINAL DE LAS RONDAS"<<(char)186<<endl;
            rlutil::locate(40,4);
            DibujarDisenio(1,200);
            rlutil::locate(41,4);
            DibujarDisenio(19,205);
            rlutil::locate(60,4);
            DibujarDisenio(1,188);
            cout<<endl;

        }
        ///velocidad del parpadeo
        rlutil::msleep(100);
    }

    ColorLetra(14);
    rlutil::locate(11,5);
    DibujarDisenio(1,201);
    DibujarDisenio(80,205);
    DibujarDisenio(1,187);
    rlutil::locate(11,6);
    DibujarDisenio(1,186);
    rlutil::locate(92,6);
    DibujarDisenio(1,186);
    rlutil::locate(11,7);
    DibujarDisenio(1,186);
    rlutil::locate(92,7);
    DibujarDisenio(1,186);

    if(empate==false)
    {
        rlutil::locate(37,6);
        DibujarDisenio(1,201);
        rlutil::locate(38,6);
        DibujarDisenio(35,205);
        rlutil::locate(37,7);
        DibujarDisenio(1,186);
        rlutil::locate(73,6);
        DibujarDisenio(1,187);
        rlutil::locate(39,7);
        cout<< "EL GANADOR ES... "<<ganador;
        rlutil::locate(73,7);
        DibujarDisenio(1,186);
        rlutil::locate(37,8);
        DibujarDisenio(1,200);
        rlutil::locate(38,8);
        DibujarDisenio(35,205);
        rlutil::locate(73,8);
        DibujarDisenio(1,188);
        rlutil::locate(13,11);
        cout<< "PUNTOS TOTALES OBTENIDOS DEL JUGADOR "<<NombreJugador[0]<<": "<< puntosTotalesJugadores[0];
        rlutil::locate(92,8);
        DibujarDisenio(1,186);
        rlutil::locate(92,9);
        DibujarDisenio(1,186);
        rlutil::locate(92,10);
        DibujarDisenio(1,186);
        rlutil::locate(92,11);
        DibujarDisenio(1,186);
        rlutil::locate(11,9);
        DibujarDisenio(1,186);
        rlutil::locate(11,8);
        DibujarDisenio(1,186);
        rlutil::locate(11,10);
        DibujarDisenio(1,186);
        rlutil::locate(11,11);
        DibujarDisenio(1,186);
        rlutil::locate(11,12);
        DibujarDisenio(1,186);
        rlutil::locate(92,12);
        DibujarDisenio(1,186);
        rlutil::locate(11,13);
        DibujarDisenio(1,186);
        rlutil::locate(92,13);
        DibujarDisenio(1,186);
        rlutil::locate(13,13);

        cout<< "PUNTOS TOTALES OBTENIDOS DEL JUGADOR "<<NombreJugador[1]<<": "<< puntosTotalesJugadores[1];
        rlutil::locate(11,14);
        DibujarDisenio(1,186);
        rlutil::locate(92,14);
        DibujarDisenio(1,186);
        rlutil::locate(11,15);
        DibujarDisenio(1,200);
        DibujarDisenio(80,205);
        DibujarDisenio(1,188);
        cout<<endl;


    }
    else
    {
        rlutil::locate(46,6);
        DibujarDisenio(1,201);
        rlutil::locate(47,6);
        DibujarDisenio(6,205);
        rlutil::locate(53,6);
        DibujarDisenio(1,187);
        rlutil::locate(46,7);
        DibujarDisenio(1,186);
        rlutil::locate(47,7);
        cout<<"EMPATE";
        rlutil::locate(53,7);
        DibujarDisenio(1,186);
        rlutil::locate(46,8);
        DibujarDisenio(1,200);
        rlutil::locate(47,8);
        DibujarDisenio(6,205);
        rlutil::locate(53,8);
        DibujarDisenio(1,188);
        rlutil::locate(13,11);
        cout<< "PUNTOS TOTALES OBTENIDOS DEL JUGADOR "<<NombreJugador[0]<<": "<< puntosTotalesJugadores[0];
        rlutil::locate(11,12);
        DibujarDisenio(1,186);
        rlutil::locate(92,12);
        DibujarDisenio(1,186);
        rlutil::locate(11,13);
        DibujarDisenio(1,186);
        rlutil::locate(92,13);
        DibujarDisenio(1,186);

             rlutil::locate(11,8);
              DibujarDisenio(1,186);
    rlutil::locate(11,9);
      DibujarDisenio(1,186);
            rlutil::locate(11,10);
              DibujarDisenio(1,186);
    rlutil::locate(11,11);
      DibujarDisenio(1,186);
     rlutil::locate(11,12);
       DibujarDisenio(1,186);
       rlutil::locate(11,13);
        DibujarDisenio(1,186);

        rlutil::locate(92,8);
        DibujarDisenio(1,186);
        rlutil::locate(92,9);
        DibujarDisenio(1,186);
        rlutil::locate(92,10);
        DibujarDisenio(1,186);
        rlutil::locate(92,11);
        DibujarDisenio(1,186);
        rlutil::locate(92,12);
        DibujarDisenio(1,186);

         rlutil::locate(13,13);
        cout<< "PUNTOS TOTALES OBTENIDOS DEL JUGADOR "<<NombreJugador[1]<<": "<< puntosTotalesJugadores[1];
        rlutil::locate(11,14);
        DibujarDisenio(1,186);
        rlutil::locate(92,14);
        DibujarDisenio(1,186);
        rlutil::locate(11,15);
        DibujarDisenio(1,200);
        DibujarDisenio(80,205);
        DibujarDisenio(1,188);
        cout<<endl;

///vuelve a mostrar el cursor antes de irse de la funcion
        rlutil::showcursor();
    }
}
string AveriguarGanador(int puntosTotalesJugadores[],std::string NombreJugador[], bool &Empate, int &puntajes, std::string &NombresJugadoresEnElTop)
{
    string ganador;
    if(puntosTotalesJugadores[0] > puntosTotalesJugadores[1])
    {
        ganador= NombreJugador[0];
        Estadisticas(puntosTotalesJugadores[0],NombreJugador[0], puntajes, NombresJugadoresEnElTop);
    }
    else if(puntosTotalesJugadores[1]>puntosTotalesJugadores[0])
    {
        ganador= NombreJugador[1];
         Estadisticas(puntosTotalesJugadores[1],NombreJugador[1], puntajes, NombresJugadoresEnElTop);
    }
    else
    {
        Empate=true;
        Estadisticas(puntosTotalesJugadores[0],NombreJugador[0], puntajes, NombresJugadoresEnElTop);
    }
    return ganador;
}
void  MostrarRonda(int NumeroRonda){
rlutil::hidecursor();
 for(int i=0;i<=10;i++){
    system("cls");
    ///muestra el mensaje solo cuando el numero es par
    if(i%2==0){
          ///hacer de color negro las letras
            ColorLetra(14);
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
void MostrarTurno(string NombreJugador){

 rlutil::locate(37,6);
        DibujarDisenio(1,201);
        rlutil::locate(38,6);
        DibujarDisenio(35,205);
        rlutil::locate(37,7);
        DibujarDisenio(1,186);
        rlutil::locate(73,6);
        DibujarDisenio(1,187);
        rlutil::locate(39,7);

cout<< "TURNO DEL JUGADOR "<<NombreJugador;

  rlutil::locate(73,7);
        DibujarDisenio(1,186);

        rlutil::locate(37,8);
        DibujarDisenio(1,200);
        rlutil::locate(38,8);
        DibujarDisenio(35,205);
        rlutil::locate(73,8);
        DibujarDisenio(1,188);

cout<<endl;
system("pause");
system("cls");
}
void JuegoDosJugadores(int &puntajes, string &NombresJugadoresEnElTop)
{
    bool Empate=false;
    bool Duplico=false;
    int PuntajeRondaJugador1[3] {};
    int PuntajeRondaJugador2[3] {};
    int puntajeTotalesJugadores[2] {};
    string NombresJugadores[2];

    ///guarda los valores de los dados bloqueadores del jugador 1
    int DadosBloqueadoresJugador1[2] {};
    ///guarda los valores de los dados bloqueadores del jugador 2
    int DadosBloqueadoresJugador2[2] {};
    PedirNombresJugadores(NombresJugadores);
    ///rondas armadas
    for(int i=1; i<=3; i++)
    {
        system("cls");
        int DadosRestantes=5;
        bool eleccionJugador;

        int  PuntosTirada;

        MostrarRonda(i);
        MostrarTurno(NombresJugadores[0]);
        ///informa la ronda actual, de cual jugador  es el turno y sus puntajes en cada ronda
        InformarRondaActual(i,NombresJugadores[0],PuntajeRondaJugador1);
        ///tira los dados bloqueadores de ambos jugadores
        TirarLosDadosBloqueadores(DadosBloqueadoresJugador1, DadosBloqueadoresJugador2);
        ///muestra los dados bloqueadores del jugador 1
        MostrarLosDadosBloqueadores(DadosBloqueadoresJugador1);
        ///pregunta si quiere tirar una tirada
        eleccionJugador=PreguntarPorTirada(Duplico,DadosRestantes);
        ///ciclo inexacto del jugador 1, finaliza el jugador lo decida o cuando el jugador se queda sin dados
        while(eleccionJugador==true && DadosRestantes!=0)
        {
            int DadosJugador[DadosRestantes];

            system("cls");
            InformarRondaActual(i,NombresJugadores[0],PuntajeRondaJugador1);
            ///muestra nuevamente los dados bloqueadores
            MostrarLosDadosBloqueadores(DadosBloqueadoresJugador1);
            TiradaDeDados(DadosJugador,DadosRestantes);
            PuntosTirada=puntajeTirada(DadosBloqueadoresJugador1,DadosJugador,DadosRestantes,Duplico);
            DadosRestantes=DadosIgualesABloqueadores(DadosJugador,DadosRestantes,DadosBloqueadoresJugador1);
            MostrarLosPuntos(PuntosTirada);
            PuntosDeLasRondas(DadosRestantes,PuntosTirada,PuntajeRondaJugador1,i-1);
            system("pause");
            system("cls");
            InformarRondaActual(i,NombresJugadores[0],PuntajeRondaJugador1);
            MostrarLosDadosBloqueadores(DadosBloqueadoresJugador1);

            ///le pregunta al jugador si quiere hacer otra tirada
            eleccionJugador=PreguntarPorTirada(Duplico,DadosRestantes);

        }
        ///jugador 2

        system("cls");
        DadosRestantes=5;
        Duplico=false;

        MostrarTurno(NombresJugadores[1]);
        ///preguntar si quiere tirar una tirada
        InformarRondaActual(i,NombresJugadores[1],PuntajeRondaJugador2);
        MostrarLosDadosBloqueadores(DadosBloqueadoresJugador2);
        eleccionJugador=PreguntarPorTirada(Duplico,DadosRestantes);
        while(eleccionJugador==true && DadosRestantes!=0)
        {
            system("cls");
            int DadosJugador2[DadosRestantes];
            InformarRondaActual(i,NombresJugadores[1],PuntajeRondaJugador2);
            MostrarLosDadosBloqueadores(DadosBloqueadoresJugador2);
            TiradaDeDados(DadosJugador2,DadosRestantes);
            PuntosTirada=puntajeTirada(DadosBloqueadoresJugador2,DadosJugador2,DadosRestantes,Duplico);
            DadosRestantes=DadosIgualesABloqueadores(DadosJugador2,DadosRestantes,DadosBloqueadoresJugador2);
            MostrarLosPuntos(PuntosTirada);
            PuntosDeLasRondas(DadosRestantes,PuntosTirada,PuntajeRondaJugador2,i-1);
            system("pause");
            system("cls");
            InformarRondaActual(i,NombresJugadores[1],PuntajeRondaJugador2);
            MostrarLosDadosBloqueadores(DadosBloqueadoresJugador2);

            eleccionJugador=PreguntarPorTirada(Duplico,DadosRestantes);

        }

    }
    system("cls");

    CalcularPuntosTotalesJugadores(PuntajeRondaJugador1,PuntajeRondaJugador2,puntajeTotalesJugadores);
    string jugadorGanador=AveriguarGanador(puntajeTotalesJugadores,NombresJugadores, Empate, puntajes, NombresJugadoresEnElTop);
    MostrarGanador(puntajeTotalesJugadores,NombresJugadores,jugadorGanador,Empate);
    system("pause");
}
