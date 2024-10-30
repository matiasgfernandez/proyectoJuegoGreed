#include <iostream>
#include "Menu.h"
#include "Juego.h"
#include "Creditos.h"
using namespace std;

int menu()
{
    system("cls");
    int opcion;
    cout<<endl<< "        _______"<<endl;
    cout<<   "       |       | "<<endl;
    cout << "       | GREED |            "<<endl;
    cout<< "       |_______|"<<endl;
    cout << " ______________________________"<<endl;
    cout<< "|                              |";
    cout <<endl<< "|1 - MODO UN JUGADOR           |" << endl;
    cout<< "|                              |";
    cout <<endl<< "|2 - MODO DOS JUGADORES        |" << endl;
    cout<< "|                              |";
    cout <<endl<< "|3 - ESTADISTICAS              |" << endl;
    cout<< "|                              |";
    cout << endl<<"|4 - CREDITOS                  |" << endl;
    cout<< "|                              |";
    cout << endl<<"|0 - SALIR                     |" << endl;
    cout << "|______________________________|" <<endl;
    cout << endl << "ingrese alguna opci¢n: ";
    cin >> opcion;
    return opcion;
}

void EjecutarMenu(int opcionElegida)
{
    switch(opcionElegida)
    {
        int Entrar;
    case 1:
        Entrar=confimacion(opcionElegida);
        ejecutarConfirmacion(Entrar,opcionElegida);
        break;

    case 2:
        Entrar=confimacion(opcionElegida);
        ejecutarConfirmacion(Entrar,opcionElegida);
        break;
    case 3:
        Entrar=confimacion(opcionElegida);
        ejecutarConfirmacion(Entrar,opcionElegida);
        break;
    case 4:
        Entrar=confimacion(opcionElegida);
        ejecutarConfirmacion(Entrar,opcionElegida);
        break;
    case 0:
        Entrar=confimacion(opcionElegida);
        ejecutarConfirmacion(Entrar,opcionElegida);
        break;
    default:
        cout << "Numero invalido...por favor ingrese un numero de [0 al 4]" << endl;
        system("pause");
        break;
    }
}

int confimacion (int OpcionDeMenu)
{
    int Entrar;
    bool Error=false;
    switch(OpcionDeMenu)
    {
    case 1:
        do
        {
            ///borra pantalla
            system("cls");
            ///pregunta si Error es verdadero
            if(Error==true)
            {
                ///da mensaje de error
                cout<<endl<< "ERROR...Por favor ingrese un numero de 0 al 1"<<endl;
            }
///Error se pone en true, en caso de que el usuario ingrese un numero invalido el ciclo inexacto va a volver a dar una vuelta, dando asi un mensaje de error
            Error=true;
///pregunta si esta seguro de entrar
            cout<<endl<< "Esta seguro que desea entrar al modo UN JUGADOR?  ingrese 1 o 0 [ 1 = si | 0 = no]"<<endl;
            cout<<endl<< "ingrese opcion: ";
            cin>> Entrar;
///da una vuelta hasta que el usuario ingrese un numero valido
        }
        while(Entrar!=0 && Entrar!=1);
        system("pause");
        break;
    case 2:
        do
        {
            ///borra pantalla
            system("cls");
            ///pregunta si Error es verdadero
            if(Error==true)
            {
                ///da mensaje de error
                cout<<endl<< "ERROR...Por favor ingrese un numero de 0 al 1"<<endl;
            }
///Error se pone en true, en caso de que el usuario ingrese un numero invalido el ciclo inexacto va a volver a dar una vuelta, dando asi un mensaje de error
            Error=true;
///pregunta si esta seguro de entrar
            cout<<endl<< "Esta seguro que desea entrar al modo DOS JUGADORES?  ingrese 1 o 0 [ 1 = si | 0 = no]"<<endl;
            cout<<endl<< "ingrese opcion: ";
            cin>> Entrar;
///da una vuelta hasta que el usuario ingrese un numero valido
        }
        while(Entrar!=0 && Entrar!=1);
        break;
    case 3:
        do
        {
            ///borra pantalla
            system("cls");
            ///pregunta si Error es verdadero
            if(Error==true)
            {
                ///da mensaje de error
                cout<<endl<< "ERROR...Por favor ingrese un numero de 0 al 1"<<endl;
            }
///Error se pone en true, en caso de que el usuario ingrese un numero invalido el ciclo inexacto va a volver a dar una vuelta, dando asi un mensaje de error
            Error=true;
///pregunta si esta seguro de entrar
            cout<<endl<< "Esta seguro que desea entrar a las ESTADISTICAS?  ingrese 1 o 0 [ 1 = si | 0 = no]"<<endl;
            cout<<endl<< "ingrese opcion: ";
            cin>> Entrar;
///da una vuelta hasta que el usuario ingrese un numero valido
        }
        while(Entrar!=0 && Entrar!=1);
        break;
    case 4:
        do
        {
            ///borra pantalla
            system("cls");
            ///pregunta si Error es verdadero
            if(Error==true)
            {
                ///da mensaje de error
                cout<<endl<< "ERROR...Por favor ingrese un numero de 0 al 1"<<endl;
            }
///Error se pone en true, en caso de que el usuario ingrese un numero invalido el ciclo inexacto va a volver a dar una vuelta, dando asi un mensaje de error
            Error=true;
///pregunta si esta seguro de entrar
            cout<<endl<< "Esta seguro que desea entrar a los CREDITOS?  ingrese 1 o 0 [ 1 = si | 0 = no]"<<endl;
            cout<<endl<< "ingrese opcion: ";
            cin>> Entrar;
///da una vuelta hasta que el usuario ingrese un numero valido
        }
        while(Entrar!=0 && Entrar!=1);
        system("pause");
        break;
    case 0:
    /*
        do
        {
            ///borra pantalla
            system("cls");
            ///pregunta si Error es verdadero
            if(Error==true)
            {
                ///da mensaje de error
                cout<<endl<< "ERROR...Por favor ingrese un numero de 1 al 2"<<endl;
            }
///Error se pone en true, en caso de que el usuario ingrese un numero invalido el ciclo inexacto va a volver a dar una vuelta, dando asi un mensaje de error
            Error=true;
///pregunta si esta seguro de entrar
            cout<<endl<< "Esta seguro que desea entrar al modo UN JUGADOR?  ingrese 1 o 0 [ 1 = si | 2 = no]"<<endl;
            cout<<endl<< "ingrese opcion: ";
            cin>> Entrar;
///da una vuelta hasta que el usuario ingrese un numero valido
        }
        while(Entrar!=1 && Entrar!=2);
        system("pause");
        break;
        */
        Entrar=true;
    }
    return Entrar;
}


void ejecutarConfirmacion(int DatoDeConfirmacion, int OpcionDeMenu)
{
    system("cls");
    if(DatoDeConfirmacion==1)
    {
        switch(OpcionDeMenu)
        {
        case 1:
            JuegoUnJugador();
            break;
        case 2:
            cout << "juego de dos jugadores" << endl;
            break;
        case 3:
            cout << "estadisticas" << endl;
            break;
        case 4:
            Creditos();
            system("pause");
            break;
        case 0:
            cout << "Gracias por jugar a nuestro juego :)" << endl;
            break;
        }
    }
}

