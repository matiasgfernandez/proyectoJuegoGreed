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

bool PreguntarPorTirada(bool &duplicoPuntos, int DadosRestantes)
{
    int EleccionJugador;
    bool Error=false;
///en caso que haya multiplicado puntos la tirada es obligatoria
if(duplicoPuntos==true){
    cout<<endl<< "Tirada de dados obligatoria"<<endl;
    system("pause");
    EleccionJugador=true;
    duplicoPuntos=false;

}else{
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
void JuegoDosJugadores()
{
    bool Duplico=false;
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
         int DadosRestantes=5;
        bool eleccionJugador;

          int  PuntosTirada;
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

}
