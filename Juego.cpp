#include <iostream>
#include <ctime>
#include "Juego.h"
using namespace std;

///1.pide nombre del jugador
string PedirNombreJugador()
{
    /// 1.1 ignora el enter anterior
    (cin.ignore());
    string nombre;
    cout<< "Ingrese su nombre: ";
    /// 1.2 Guarda en el cin hasta que haya un enter
    getline(cin, nombre);
    return nombre;
}

/// 2. muestra el nombre del jugador
void MostrarNombreJugador1(string nombre)
{
    cout<< "Turno del jugador: "<<nombre<<endl;
}

/// 3.funcion que tira un dado
int TirarDado()
{
    return rand() % 6 + 1;
}

/// 4.funcion que tira los dados bloqueadores
void TirarDadosBloqueadores(int (DadosBloqueadoresJugador1)[], int (DadosBloqueadoresJugador2)[])
{
    for(int i = 0; i < 2; i++)
    {
        DadosBloqueadoresJugador1[i]= TirarDado();
        DadosBloqueadoresJugador2[i]= TirarDado();
    }
}

/// 5.funcion que muestra los dados bloqueadores
void MostrarDadosBloqueadores(int DadosBloqueador[])
{
    cout << endl;
    cout << "                      _______" << endl;
    cout << "                     |"<<"   |"<< "   |" <<endl;
    cout << "  Dados bloqueadores:| " << DadosBloqueador[0] << " | " << DadosBloqueador[1] << " |" << endl;
    cout << "                     |___|___|" << endl;
    cout<<endl;
}


/// 6.funcion que consulta al jugador y ejecuta el lanzamiento si la respuesta es afirmativa( eleccionJugador lo deje por referencia para las demas rondas)
void ejecutarConsultaLanzamiento(bool &eleccionJugador, int dados[], int cantidad, int DadosBloqueadoresJugador1[])
{
    cout << "¨Desea realizar un lanzamiento? Ingrese 1 o 0. Si=1 y No=0 " << endl;
    cin >> eleccionJugador;
    if (eleccionJugador)
    {
        cout<<"Lanzando Dados..."<<endl<<endl;
        TiradaDeLosDados(dados, cantidad, DadosBloqueadoresJugador1);
    }
    else
    {
        cout << "Pasando a la siguiente ronda..." << endl;//Queda asi mientras dise¤amos la funci¢n de rondas.

    }
}


/// 7.funcion para tirar los dados, en caso de querer quitar dados habria que restarle la cantidad a la variable "cantidad"
int TiradaDeLosDados(int Dados[], int Cantidad, int DadosBloqueadoresJugador1[])
{
    for(int i = 0; i < Cantidad; i++)
    {
        Dados[i] = TirarDado();
    }
    for(int j = 0; j < Cantidad; j++)
    {
        cout<< "Dado #" << j + 1 << ":" << Dados[j] << endl;
    }
    Cantidad = DadosQueCoincidenConDadosBloqueadores(Dados, Cantidad, DadosBloqueadoresJugador1);
    return Cantidad;
}

/// 8.funcion para saber que dado coincide con un dado bloqueador
int DadosQueCoincidenConDadosBloqueadores(int dados[], int cantidad, int DadosBloqueadoresJugador1[])
{
    int CoincideConDadoBloqueador = 0; // contador
    if(DadosBloqueadoresJugador1[0] != DadosBloqueadoresJugador1[1])
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < cantidad; j++)
            {
                if(dados[j] == DadosBloqueadoresJugador1[i])
                {
                    cout<< "El dado#" << j + 1 << " coincide con el dado bloqueador #" << i + 1 << endl;
                    CoincideConDadoBloqueador++;
                }

            }
        }

    }

    else
    {
        for(int i = 0; i < cantidad; i++)
        {
            if(dados[i] == DadosBloqueadoresJugador1[0])
            {
                cout<< "El dado#" << i + 1 << " coincide con los dados bloqueadores" << endl;
                CoincideConDadoBloqueador++;
            }
        }


        cantidad -= CoincideConDadoBloqueador;
    }
    return cantidad;
}

int puntajesRondas(int DadosBloqueadores[],int dados[],int cantidad)
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
        if(DadoIgualBloqueador==false)
        {
            duplicar=DadosIguales(dados,cantidad);
            if(duplicar==true)
            {
                PuntosJugadorRonda*=2;
            }
        }
    }
    return PuntosJugadorRonda;
}

//10. funcion para saber si todos los dados son iguales
bool DadosIguales(int dados[],int Cantidad)
{
    bool TodoDadosIguales=false;
    bool PrimerDado=true;
    int numeroanterior;
    bool DadosDiferentes=false;

    if(Cantidad>=2)
    {
        for(int i=0; i<Cantidad; i++)
        {
            if(PrimerDado==true)
            {
                numeroanterior=dados[i];
                PrimerDado=false;
            }
            else
            {
                if(numeroanterior==dados[i])
                {
                    numeroanterior=dados[i];
                }
                else
                {
                    DadosDiferentes=true;
                }
            }
        }
    }
    if(DadosDiferentes==false)
    {
        TodoDadosIguales=true;
    }
    return TodoDadosIguales;
}
void MostrarPuntos(int PuntosObtenidos){
cout<<endl<< "usted ha obtenido "<<PuntosObtenidos<<"  puntos en esta tirada"<<endl;
}

/// 9.funcion jugar, es la que se le pasa al menu para que pueda correr el juego
void JugarContraCPU()
{
    bool eleccionJugador;
    int DadosBloqueadoresJugador1[2] {};
    int DadosBloqueadoresJugador2[2] {};
    int cantidadDeDados = 5;
    int daditos[cantidadDeDados];
    int PuntosJugador=0;
    string nombreJugador;

    // pide el nombre del jugador
    nombreJugador = PedirNombreJugador();
    // borra pantalla
    system("cls");
    // muestra el nombre del jugador
    MostrarNombreJugador1(nombreJugador);
    // Tira los dados bloqueadores de los dos jugadores y lo guarda en las variables
    TirarDadosBloqueadores(DadosBloqueadoresJugador1, DadosBloqueadoresJugador2);
    // muestra los dados bloqueadores
    MostrarDadosBloqueadores(DadosBloqueadoresJugador1);
    // consulta y lanza los dados si el jugador lo desea
    ejecutarConsultaLanzamiento(eleccionJugador, daditos, cantidadDeDados, DadosBloqueadoresJugador1);
    PuntosJugador=puntajesRondas(DadosBloqueadoresJugador1, daditos,cantidadDeDados);
    MostrarPuntos(PuntosJugador);
}
