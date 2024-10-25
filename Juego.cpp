#include <iostream>
#include <ctime>
#include "Juego.h"
using namespace std;

/// 1. pide nombre del jugador
string PedirNombreJugador()
{
    (cin.ignore());
    string nombre;
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    return nombre;
}

/// 2. muestra el nombre del jugador
void MostrarNombreJugador1(string nombre)
{
    cout << "Turno del jugador: " << nombre << endl;
}

/// 3. funcion que tira un dado
int TirarDado()
{
    return rand() % 6 + 1;
}

/// 4. funcion que tira los dados bloqueadores
void TirarDadosBloqueadores(int (DadosBloqueadoresJugador1)[], int (DadosBloqueadoresJugador2)[])
{
    for (int i = 0; i < 2; i++)
    {
        DadosBloqueadoresJugador1[i] = TirarDado();
        DadosBloqueadoresJugador2[i] = TirarDado();
    }
}

/// 5. funcion que muestra los dados bloqueadores
void MostrarDadosBloqueadores(int DadosBloqueador[])
{
    cout << endl;
    cout << "                      _______" << endl;
    cout << "                     |" << "   |" << "   |" << endl;
    cout << "  Dados bloqueadores:| " << DadosBloqueador[0] << " | " << DadosBloqueador[1] << " |" << endl;
    cout << "                     |___|___|" << endl;
    cout << endl;
}
bool PreguntaPorProximaTirada(int DadosRestantes){
bool EleccionJugador;
if(DadosRestantes!=0){
cout << "Le quedan "<<DadosRestantes<<" dados, desea realizar un lanzamiento? Ingrese 1 o 0. Si=1 y No=0 " << endl;
    cin >> EleccionJugador;
}else{
cout<< "se ha quedado sin dados para tirar, ha perdido todos sus puntos"<<endl;
EleccionJugador=false;
}
    return EleccionJugador;
}
/// 6. funcion que consulta al jugador y ejecuta el lanzamiento si la respuesta es afirmativa (eleccionJugador lo deje por referencia para las demas rondas)
/*
void ejecutarConsultaLanzamiento(bool &eleccionJugador, int dados[], int cantidad, int DadosBloqueadoresJugador1[])
{
    cout << "¨Desea realizar un lanzamiento? Ingrese 1 o 0. Si=1 y No=0 " << endl;
    cin >> eleccionJugador;
    if (eleccionJugador)
    {
        cout << "Lanzando Dados..." << endl << endl;
        TiradaDeLosDados(dados, cantidad, DadosBloqueadoresJugador1);
    }
    else
    {
        cout << "Pasando a la siguiente ronda..." << endl; // Queda asi mientras dise¤amos la funci¢n de rondas.
    }
}
*/
/// 7. funcion para tirar los dados, en caso de querer quitar dados habria que restarle la cantidad a la variable "cantidad"
void TiradaDeLosDados(int Dados[], int Cantidad, int DadosBloqueadoresJugador1[])
{
    cout<<"Lanzando dados..."<<endl<<endl;
    for (int i = 0; i < Cantidad; i++)
    {
        Dados[i] = TirarDado();
    }
    for (int j = 0; j < Cantidad; j++)
    {
        cout << "Dado #" << j + 1 << ":" << Dados[j] << endl;
    }

}




/// 8. funcion para saber que dado coincide con un dado bloqueador
int DadosQueCoincidenConDadosBloqueadores(int dados[], int cantidad, int DadosBloqueadoresJugador1[])
{
    int CoincideConDadoBloqueador = 0; // contador
    if(DadosBloqueadoresJugador1[0]!=DadosBloqueadoresJugador1[1]){
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < cantidad; j++)
        {
            if (dados[j] == DadosBloqueadoresJugador1[i])
            {
                cout << "El dado#" << j + 1 << " coincide con el dado bloqueador #" << i + 1 << endl;
                CoincideConDadoBloqueador++;
            }
        }
    }
    }else{
    for (int i = 0; i < cantidad; i++){
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
        if(DadoIgualBloqueador==false && cantidad>=2)
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

/// 12. funcion jugar, es la que se le pasa al menu para que pueda correr el juego
bool JugarContraCPU(int dados[], int &cantidad, int &puntajeRonda, bool &eleccionJugador, int DadosBloqueadoresJugador1[], string nombreJugador)
{
    int DadosBloqueadoresJugador2[2] {};
    // muestra el nombre del jugador
    MostrarNombreJugador1(nombreJugador);
    // Tira los dados bloqueadores de los dos jugadores y lo guarda en las variables
    TirarDadosBloqueadores(DadosBloqueadoresJugador1, DadosBloqueadoresJugador2);
    // muestra los dados bloqueadores
    MostrarDadosBloqueadores(DadosBloqueadoresJugador1);

    while (true)
    {
        // consulta si el jugador desea lanzar los dados
        cout << "¨Desea realizar un lanzamiento? Ingrese 1 o 0. Si=1 y No=0 " << endl;
        cin >> eleccionJugador;
        if (!eleccionJugador)
        {
            return false; // Si el jugador no quiere lanzar, terminar la ronda
        }

        // Lanzar dados y calcular el puntaje de la tirada
        TiradaDeLosDados(dados,cantidad,DadosBloqueadoresJugador1);
        int puntajeTirada = puntajesRondas(DadosBloqueadoresJugador1, dados, cantidad);
        int dadosRestantes = DadosQueCoincidenConDadosBloqueadores(dados, cantidad, DadosBloqueadoresJugador1);


        // Mostrar los puntos obtenidos en la tirada
        MostrarPuntos (puntajeTirada);

        // Sumamos los puntos de la tirada a los puntos de la ronda//si la cantidad de dados es igual a 0 los puntos de la ronda sera 0
        if(dadosRestantes==0){
            puntajeRonda=0;
        }else{
        puntajeRonda += puntajeTirada;
        }
        // Mostrar los puntos acumulados en la ronda
        cout << "Puntaje acumulado de la Ronda: " << puntajeRonda << endl;
        system("pause");
        system("cls");
MostrarDadosBloqueadores(DadosBloqueadoresJugador1);
cout<<endl <<"puntaje total en la ronda: "<<puntajeRonda<<endl;
        // Actualizar cantidad de dados restantes para el pr¢ximo lanzamiento
        cantidad = dadosRestantes;

        // Mostrar los dados restantes
        cout << "Dados restantes: " << cantidad << endl;

        if (cantidad == 0)
        {
            break; // Si no hay dados restantes, terminar la ronda
        }
    }

    return true;
}



/// 13. muestra la ronda actual del jugador
void mostrarRondaActual(int ronda, string nombreJugador, int puntajeRonda[])
{
    cout << "Ronda Numero: " << ronda <<endl;
    cout<< "Jugador: " << nombreJugador << endl;
    for(int i=0;i<3;i++){
    cout << "Puntaje acumulado de la Ronda#"<<i+1<<": " << puntajeRonda[i] << endl;
    }
    //MostrarPuntos(puntajeRonda);
}


// 14. ejecuta la ronda actual con todos los elementos de la funcion jugar contra cpu
void ejecutarRondaActual(int dados[], int cantidad, string nombreJugador)
{
    int puntajeTotal = 0;
    bool eleccionJugador = true;

    for (int i = 0; i < 3; i++)
    {
        system("cls");
        cout << "Ronda " << i + 1 << endl; // Mostrar solo la ronda
        //cout << "Turno del jugador: " << nombreJugador << endl; // Mostrar el nombre del jugador en la siguiente l¡nea

        int puntajeRonda = 0;
        int dadosRestantes = cantidad;
        int DadosBloqueadoresJugador1[2] {};

        while (true)
        {

            if (!JugarContraCPU(dados, dadosRestantes, puntajeRonda, eleccionJugador, DadosBloqueadoresJugador1, nombreJugador))
            {
                break; // Si el jugador no quiere lanzar, terminar la ronda
            }

            // Mostrar el puntaje acumulado de la ronda despu‚s de cada tirada
//            mostrarRondaActual(i + 1, nombreJugador, puntajeRonda);

            // Verificar si quedan dados para lanzar
            if (dadosRestantes <= 0)
            {
                break;
            }
        }

        // Sumar los puntos de la ronda al puntaje total
        puntajeTotal += puntajeRonda;

        // Mostrar el puntaje total acumulado al final de la ronda
        cout << "Puntaje total acumulado: " << puntajeTotal << endl;

    }
    system("pause");
}
void PuntosDeRonda(int CantidadDados,int PuntosXtirada,int PuntosTotalesRonda[],int ronda){

if(CantidadDados==0){
 PuntosTotalesRonda[ronda]=0;
        }else{
        PuntosTotalesRonda[ronda]+= PuntosXtirada;
        }

    }

int CalcularPuntosTotalesRondas(int puntosRondas[]){
int TotalDePuntosPartida=0;

 for(int i=0;i<3;i++){

    TotalDePuntosPartida+=puntosRondas[i];
 }
return TotalDePuntosPartida;

}
void MostrarPuntosTotales(int puntos){
cout<<endl<< "sus puntos totales obtenidos son: "<<puntos<<endl;
}
///-------------------------------------------------------------------------------------------------------ALTERNATIVA
void JuegoUnJugador(){

int puntosTotales=0;
int puntajeRonda[3]{};
string nombreJugador = PedirNombreJugador();

system("Cls");

///un for que recorre las tres rondas del juego
for(int i=1;i<=3;i++){
int DadosRestantes = 5;
int dados[DadosRestantes];
int DadosBloqueadoresJugador1[2] {};
 int DadosBloqueadoresJugador2[2] {};
    ///muestra numero de ronda, nombre del jugador, puntaje total
    mostrarRondaActual(i,nombreJugador,puntajeRonda);
    /// Tira los dados bloqueadores de los dos jugadores y lo guarda en las variables
    TirarDadosBloqueadores(DadosBloqueadoresJugador1, DadosBloqueadoresJugador2);
    /// muestra los dados bloqueadores
    MostrarDadosBloqueadores(DadosBloqueadoresJugador1);
 ///pregunta al jugador si quiere tirar los dados y lo guarda en la variable eleccionJugador
bool EleccionJugador=PreguntaPorProximaTirada(DadosRestantes);
system("cls");
///ciclo que corre todas las tiradas, corta
      while(EleccionJugador==true && DadosRestantes!=0){
        mostrarRondaActual(i,nombreJugador,puntajeRonda);
        MostrarDadosBloqueadores(DadosBloqueadoresJugador1);
        ///simula la tirada de dados
    TiradaDeLosDados(dados,DadosRestantes,DadosBloqueadoresJugador1);

        int puntajeTirada = puntajesRondas(DadosBloqueadoresJugador1, dados, DadosRestantes);
         DadosRestantes = DadosQueCoincidenConDadosBloqueadores(dados, DadosRestantes, DadosBloqueadoresJugador1);
        MostrarPuntos(puntajeTirada);
        PuntosDeRonda(DadosRestantes,puntajeTirada,puntajeRonda,i-1);


    EleccionJugador=PreguntaPorProximaTirada(DadosRestantes);
    system("pause");
    system("cls");
      }
}
puntosTotales=CalcularPuntosTotalesRondas(puntajeRonda);
MostrarPuntosTotales(puntosTotales);
}


