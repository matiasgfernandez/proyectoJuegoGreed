
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

void MensajeDeError(int Desde, int Hasta){

  rlutil::hidecursor();
                   system("cls");
                   rlutil::setBackgroundColor(0);
                   rlutil::locate(26,9);
                   DibujarLinea(65,32);
                   rlutil::locate(88,9);
                   DibujarLinea(1,88);
                   rlutil::locate(55,9);
                   cout<< "E R R O R !";


                   rlutil::setColor(1);
                   rlutil::locate(89,10);
                   DibujarLinea(2,219);
                   rlutil::locate(89,11);
                   DibujarLinea(2,219);
                   rlutil::locate(89,12);
                   DibujarLinea(2,219);
                   rlutil::locate(89,13);
                   DibujarLinea(2,219);
                   rlutil::locate(89,14);
                   DibujarLinea(2,219);
                   rlutil::locate(89,15);
                   DibujarLinea(2,219);

                   rlutil::locate(26,10);
                   DibujarLinea(2,219);
                   rlutil::locate(26,11);
                   DibujarLinea(2,219);
                   rlutil::locate(26,12);
                   DibujarLinea(2,219);
                   rlutil::locate(26,13);
                   DibujarLinea(2,219);
                   rlutil::locate(26,14);
                   DibujarLinea(2,219);
                   rlutil::locate(26,15);
                   DibujarLinea(2,219);

                   rlutil::setBackgroundColor(1);
                   rlutil::locate(26,15);
                   DibujarLinea(65,32);


                    rlutil::setBackgroundColor(15);
                    rlutil::locate(28,10);
                    DibujarLinea(61,32);
                    rlutil::locate(28,11);
                    DibujarLinea(61,32);
                    rlutil::locate(28,12);
                    DibujarLinea(61,32);
                    rlutil::locate(28,13);
                    DibujarLinea(61,32);
                    rlutil::locate(28,14);
                    DibujarLinea(61,32);

                   rlutil::setColor(4);
                   rlutil::locate(30,11);
                   cout << "NUMERO INVALIDO...por favor ingrese un numero de "<<Desde<< " al "<< Hasta<< endl;
                   rlutil::locate(34,13);
                   cout<< "presione cualquier letra para volver a intentarlo";
                   rlutil::setColor(14);

                   rlutil::setBackgroundColor(rlutil::RED);
                   system("pause>nul");
                   system("cls");
  rlutil::showcursor();
}

void MostrarOpcion(int columna, int fila){

    rlutil::locate(columna,fila);
    cout<<"*************************";
    rlutil::locate(columna,fila+1);
    cout<<"*ingrese alguna opcion:"<<" *";
    rlutil::locate(columna,fila+2);
    cout<<"*"<< "************************";
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

int CartelDeConfirmacion(){

  int Respuesta;

            HacerColorLetra(15);
            rlutil::locate(17,3);
            DibujarLinea(86,177);

            rlutil::locate(17,4);
            DibujarLinea(2,177);
            rlutil::locate(17,5);
            DibujarLinea(2,177);
            rlutil::locate(17,6);
            DibujarLinea(2,177);

            rlutil::locate(101,4);
            DibujarLinea(2,177);
            rlutil::locate(101,5);
            DibujarLinea(2,177);
            rlutil::locate(101,6);
            DibujarLinea(2,177);

            rlutil::locate(17,7);
            DibujarLinea(86,177);

            ///pregunta si esta seguro de entrar
             rlutil::locate(21,5);
            cout<< "Esta seguro que desea entrar a los CREDITOS?  ingrese 1 o 0 [ 1 = si | 0 = no]";
            MostrarOpcion(43,9);
            rlutil::locate(66,10);
            cin>> Respuesta;
            HacerColorLetra(14);
  return Respuesta;
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
                  MensajeDeError(0,1);
                 }

            ///Error se pone en true, en caso de que el usuario ingrese un numero invalido el ciclo inexacto va a volver a dar una vuelta, dando asi un mensaje de error
            Error=true;

            Entrar=CartelDeConfirmacion();

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
                   MensajeDeError(0,1);
                }
             ///Error se pone en true, en caso de que el usuario ingrese un numero invalido el ciclo inexacto va a volver a dar una vuelta, dando asi un mensaje de error
            Error=true;

            Entrar=CartelDeConfirmacion();
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
                MensajeDeError(0,1);
               }

            ///Error se pone en true, en caso de que el usuario ingrese un numero invalido el ciclo inexacto va a volver a dar una vuelta, dando asi un mensaje de error
            Error=true;

            Entrar=CartelDeConfirmacion();
       ///da una vuelta hasta que el usuario ingrese un numero valido
       }while(Entrar!=0 && Entrar!=1);
    break;

    case 4:
           do{
            ///borra pantalla
            system("cls");
               ///pregunta si Error es verdadero
                if(Error==true){

                 MensajeDeError(0,1);
                }
            ///Error se pone en true, en caso de que el usuario ingrese un numero invalido el ciclo inexacto va a volver a dar una vuelta, dando asi un mensaje de error
            Error=true;

            Entrar=CartelDeConfirmacion();
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

                 MensajeDeError(0,4);
        break;
    }
}
