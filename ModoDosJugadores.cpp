#include <iostream>
#include <ctime>
#include "ModoDosJugadores.h"
#include "rlutil.h"

using namespace std;

void PedirNombresJugadores(string NombresJugadores[])
{
    for(int i=0; i<2; i++)
    {
        (cin.ignore());

        ColorLetra(14);
        //rlutil::locate(4,3);

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

bool PreguntarPorTirada(int DadosRestantes)
{
    int EleccionJugador;
    bool Error=false;
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
        cout<< "¡POR CODICIOSO! se ha quedado sin dados para tirar, ha perdido todos los puntos de esta ronda"<<endl;
        EleccionJugador=0;
        ColorLetra(14);
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

void JuegoDosJugadores()
{
    int PuntajeRondaJugador1[3] {};
    int PuntajeRondaJugador2[3] {};
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
        int DadosJugador=5;
        bool eleccionJugador;

        ///informa la ronda actual, de cual jugador  es el turno y sus puntajes en cada ronda
        InformarRondaActual(i,NombresJugadores[0],PuntajeRondaJugador1);
        ///tira los dados bloqueadores de ambos jugadores
        TirarLosDadosBloqueadores(DadosBloqueadoresJugador1, DadosBloqueadoresJugador2);
        ///muestra los dados bloqueadores del jugador 1
        MostrarLosDadosBloqueadores(DadosBloqueadoresJugador1);
        ///pregunta si quiere tirar una tirada
        eleccionJugador=PreguntarPorTirada(DadosJugador);
        ///ciclo inexacto del jugador 1, finaliza el jugador lo decida o cuando el jugador se queda sin dados
        while(eleccionJugador==true && DadosJugador!=0)
        {
            system("cls");
            InformarRondaActual(i,NombresJugadores[0],PuntajeRondaJugador1);
            ///muestra nuevamente los dados bloqueadores
            MostrarLosDadosBloqueadores(DadosBloqueadoresJugador1);
            /*
            /// falta
            hacer la tirada de dados
            fijarse cual coincide con un dado bloqueador
            descontar la cantidad de dados que hayan coincido con un bloqueador
            sumar los puntos
            */
            ///le pregunta al jugador si quiere hacer otra tirada
            eleccionJugador=PreguntarPorTirada(DadosJugador);

        }
        system("pause");
        system("cls");
        ///jugador 2
        ///preguntar si quiere tirar una tirada
        InformarRondaActual(i,NombresJugadores[1],PuntajeRondaJugador2);
        MostrarLosDadosBloqueadores(DadosBloqueadoresJugador2);
        eleccionJugador=PreguntarPorTirada(DadosJugador);
        while(eleccionJugador==true && DadosJugador!=0)
        {
            system("cls");
            InformarRondaActual(i,NombresJugadores[1],PuntajeRondaJugador2);
            MostrarLosDadosBloqueadores(DadosBloqueadoresJugador2);
            eleccionJugador=PreguntarPorTirada(DadosJugador);
        }

    }

}
