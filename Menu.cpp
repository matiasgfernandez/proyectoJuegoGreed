
#include <iostream>
#include "Menu.h"
#include "Juego.h"
#include "ModoDosJugadores.h"
#include "Estadisticas.h"
#include "Creditos.h"
#include "rlutil.h"

using namespace std;

void BarraDeCarga(){

int valor=0;

HacerColorLetra(11);
rlutil::locate(40,4);
cout<< "******************"<<endl;
cout<< "                                       *WELCOME TO GREED*"<<endl;
              cout<< "                                       ******************"<<endl<<endl;
              cout<< "                                            CARGANDO..."<<endl;

  while(valor<70){
  ///pone en color azul la barra
  rlutil::setBackgroundColor(1);

///ubica la barra en la columna 20 y fila 10
 rlutil::locate(20,10);
       for(int i=1;i<=valor;i++){
           ///caracter de ascii
           cout<< (char)186;
        }

HacerColorLetra(14);
///hace que la barra no cargue lineal
valor+=rand()%5;
///la velocidad de la barra
rlutil::msleep(rand()%300);
    }
}

void MostrarOpcion(int columna, int fila){
    rlutil::locate(columna,fila);
    cout<<  "*************************"<<endl;

    cout<< " *ingrese alguna opcion:"<<" *"<<endl;

    cout<< " *"<< "************************"<<endl;
}

void DibujarLinea(int cantidad, int Modelo){

    ///dibuja la cantidad el codigo de assci
    for(int i=1; i<=cantidad;i++){
          cout<< (char) Modelo;
    }
}

void FinDelJuego(){

    system("cls");
   ///oculta el cursor
    rlutil::hidecursor();
    for(int i=0;i<=10;i++){
    system("cls");
    ///muestra el mensaje solo cuando el numero es par
         if(i%2==0){
            ///hacer de color negro las letras
             HacerColorLetra(0);
             ///diseño de recuadro de ascii
             ///lo ubica en la columna 40 y fila 2
             rlutil::locate(49,11);
             DibujarLinea(1,201);
             DibujarLinea(13,205);
             DibujarLinea(1,187);
             cout<<endl;
             rlutil::locate(49,12);
             DibujarLinea(1,186);

             HacerColorLetra(rand()%16);

             cout<<"FIN DEL JUEGO";

            HacerColorLetra(0);

            DibujarLinea(1,186);
            cout<<endl;
            rlutil::locate(49,13);
            DibujarLinea(1,200);
            DibujarLinea(13,205);
            DibujarLinea(1,188);
            cout<<endl;
        }

    ///velocidad del parpadeo
    rlutil::msleep(100);

  }

    rlutil::locate(15,14);
    DibujarLinea(1,201);
    DibujarLinea(90,205);
    DibujarLinea(1,187);
    rlutil::locate(15,15);
    DibujarLinea(1,186);
    rlutil::locate(15,15);
    DibujarLinea(1,186);

    rlutil::locate(15,15);
    cout<< " GRACIAS POR JUGAR NUESTRO JUEGO...toque cualquier tecla para volver al MENU PRINCIPAL :) ";

    rlutil::locate(15,16);
    DibujarLinea(1,200);
    DibujarLinea(90,205);
    DibujarLinea(1,188);

    system("pause>nul");
}

int menu(){

 int opcion;

    rlutil::setBackgroundColor(rlutil::RED);

    rlutil::setColor(14);

    system("cls");

    cout<<endl<< "                                                  _______"<<endl;
    cout<<   "                                                 |       | "<<endl;
    cout << "                                                 | GREED |            "<<endl;
    cout<< "                                                 |_______|"<<endl;
    cout << "                                      _______________________________"<<endl;
    cout<< "                                     |                               |";
    cout <<endl<< "                                     |    1 - MODO UN JUGADOR        |" << endl;
    cout<< "                                     |                               |";
    cout <<endl<< "                                     |    2 - MODO DOS JUGADORES     |" << endl;
    cout<< "                                     |                               |";
    cout <<endl<< "                                     |    3 - ESTADISTICAS           |" << endl;
    cout<< "                                     |                               |";
    cout << endl<<"                                     |    4 - CREDITOS               |" << endl;
    cout<< "                                     |                               |";
    cout << endl<<"                                     |    0 - SALIR                  |" << endl;
    cout << "                                     |_______________________________|" <<endl;

HacerColorLetra(7);

    cout<<  "                                         *************************"<<endl;
    cout<< "                                         *ingrese alguna opcion:"<<" *"<<endl;
    cout<< "                                         *"<< "************************"<<endl;

    HacerColorLetra(14);

    rlutil::locate(65,19);
    cin >> opcion;

 return opcion;
}

int confimacion (int OpcionDeMenu){

 int Entrar;
 bool Error=false;

    switch(OpcionDeMenu){

     case 1:
            do{
            ///borra pantalla
            system("cls");
                 ///pregunta si Error es verdadero
                 if(Error==true){
                   ///da mensaje de error
                  cout<<endl<< "ERROR...Por favor ingrese un numero de 0 al 1"<<endl;
                 }

///Error se pone en true, en caso de que el usuario ingrese un numero invalido el ciclo inexacto va a volver a dar una vuelta, dando asi un mensaje de error
            Error=true;
///pregunta si esta seguro de entrar
            cout<<endl<< "Esta seguro que desea entrar al modo UN JUGADOR?  ingrese 1 o 0 [ 1 = si | 0 = no]"<<endl;
            MostrarOpcion(2,5);
            rlutil::locate(25,6);
            cin>> Entrar;

               ///da una vuelta hasta que el usuario ingrese un numero valido
            }while(Entrar!=0 && Entrar!=1);
    break;

    case 2:
           do{
            ///borra pantalla
            system("cls");
               ///pregunta si Error es verdadero
               if(Error==true){

                   ///da mensaje de error
                   cout<<endl<< "ERROR...Por favor ingrese un numero de 0 al 1"<<endl;
                }
             ///Error se pone en true, en caso de que el usuario ingrese un numero invalido el ciclo inexacto va a volver a dar una vuelta, dando asi un mensaje de error
            Error=true;
            ///pregunta si esta seguro de entrar
            cout<<endl<< "Esta seguro que desea entrar al modo DOS JUGADORES?  ingrese 1 o 0 [ 1 = si | 0 = no]"<<endl;
            MostrarOpcion(2,5);
            rlutil::locate(25,6);
            cin>> Entrar;
           ///da una vuelta hasta que el usuario ingrese un numero valido
           }while(Entrar!=0 && Entrar!=1);
    break;

    case 3:
           do{

            ///borra pantalla
            system("cls");
            ///pregunta si Error es verdadero
                if(Error==true){

                ///da mensaje de error
                cout<<endl<< "ERROR...Por favor ingrese un numero de 0 al 1"<<endl;
               }

            ///Error se pone en true, en caso de que el usuario ingrese un numero invalido el ciclo inexacto va a volver a dar una vuelta, dando asi un mensaje de error
            Error=true;
            ///pregunta si esta seguro de entrar
            cout<<endl<< "Esta seguro que desea entrar a las ESTADISTICAS?  ingrese 1 o 0 [ 1 = si | 0 = no]"<<endl;
            MostrarOpcion(2,5);
            rlutil::locate(25,6);
            cin>> Entrar;
       ///da una vuelta hasta que el usuario ingrese un numero valido
       }while(Entrar!=0 && Entrar!=1);
    break;

    case 4:
           do{
            ///borra pantalla
            system("cls");
               ///pregunta si Error es verdadero
                if(Error==true){

                  ///da mensaje de error
                  cout<<endl<< "ERROR...Por favor ingrese un numero de 0 al 1"<<endl;
                }
            ///Error se pone en true, en caso de que el usuario ingrese un numero invalido el ciclo inexacto va a volver a dar una vuelta, dando asi un mensaje de error
            Error=true;
            ///pregunta si esta seguro de entrar
            cout<<endl<< "Esta seguro que desea entrar a los CREDITOS?  ingrese 1 o 0 [ 1 = si | 0 = no]"<<endl;
            MostrarOpcion(2,5);
            rlutil::locate(25,6);
            cin>> Entrar;
///da una vuelta hasta que el usuario ingrese un numero valido
        }while(Entrar!=0 && Entrar!=1);
    break;

    case 0:
        Entrar=true;
        break;
    }
  return Entrar;
}

void ejecutarConfirmacion(int DatoDeConfirmacion, int OpcionDeMenu,int &puntajeMasAlto, string &NombreJugadorMasAlto,bool &Jugaron){

  system("cls");
    if(DatoDeConfirmacion==1){

        switch(OpcionDeMenu){

            case 1:
                    JuegoUnJugador(puntajeMasAlto,NombreJugadorMasAlto);
                    FinDelJuego();
                    Jugaron=true;
             break;

             case 2:
                     JuegoDosJugadores(puntajeMasAlto,NombreJugadorMasAlto);
                     FinDelJuego();
                     Jugaron=true;
            break;

            case 3:
                    MostrarEstadisticas(NombreJugadorMasAlto,puntajeMasAlto, Jugaron);
            break;

           case 4:
                   Creditos();
            break;

            case 0:
                   rlutil::locate(37,8);
                   DibujarLinea(45,178);

                   rlutil::locate(37,9);
                   DibujarLinea(2,178);
                   rlutil::locate(37,10);
                   DibujarLinea(2,178);
                   rlutil::locate(37,11);
                   DibujarLinea(2,178);

                   rlutil::locate(80,9);
                   DibujarLinea(2,178);
                   rlutil::locate(80,10);
                   DibujarLinea(2,178);
                   rlutil::locate(80,11);
                   DibujarLinea(2,178);

                   rlutil::locate(37,12);
                   DibujarLinea(45,178);

                    rlutil::locate(41,10);
                    cout << "Gracias por jugar a nuestro juego :)";

                    rlutil::locate(41,13);
                    system("pause");
            break;
         }
    }
}

void EjecutarMenu(int opcionElegida, int &puntajeMasAlto, string &NombreJugadorMasAlto,bool &Jugaron){

    switch(opcionElegida){

     int Entrar;

       case 1:
               Entrar=confimacion(opcionElegida);
               ejecutarConfirmacion(Entrar,opcionElegida, puntajeMasAlto, NombreJugadorMasAlto, Jugaron);
        break;

        case 2:
                Entrar=confimacion(opcionElegida);
                ejecutarConfirmacion(Entrar,opcionElegida, puntajeMasAlto, NombreJugadorMasAlto,Jugaron);
        break;

        case 3:
                Entrar=confimacion(opcionElegida);
                ejecutarConfirmacion(Entrar,opcionElegida, puntajeMasAlto, NombreJugadorMasAlto,Jugaron);
        break;

        case 4:
                Entrar=confimacion(opcionElegida);
                ejecutarConfirmacion(Entrar,opcionElegida, puntajeMasAlto, NombreJugadorMasAlto,Jugaron);
        break;

        case 0:
                Entrar=confimacion(opcionElegida);
                ejecutarConfirmacion(Entrar,opcionElegida, puntajeMasAlto, NombreJugadorMasAlto,Jugaron);
        break;

        default:
                   rlutil::setColor(rlutil::YELLOW);


                   rlutil::locate(30,10);
                   cout << "NUMERO INVALIDO...por favor ingrese un numero de [0 al 4]" << endl;
                   system("pause");
                   rlutil::setColor(rlutil::WHITE);
        break;
    }
}
