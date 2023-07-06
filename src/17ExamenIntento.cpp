#include <iostream>
#include <unistd.h>
#include <windows.h>
// #include <stdio.h>
// #include <string>
using namespace std;
#define DELAY 55000

bool obsEstaIzq = true;  //false = 0
int opcionMenu = -1, anchoRio = 20, OBSE = 0, LOBO = 1, CAPE = 2, UVAS = 3;
string arrIzq[] = {"Observador", "   Lobo   ", "Caperucita", "   Uvas   "},     //el número de caracteres de cada vector es 10
       arrDer[] = {".",     "",     "",     ""},
       actorCruza = "";                                 //Obse[0]  Lobo[1]  Cape[2]  Uvas[3]

//No siempre es bueno utilizar variables globales

// MÉTODOS PARA INCLUIR EN LIBRERIAS

enum color { azul = 1, verde, celeste, rojo, rosado, salmon, blanco, plomo, rosaPalo = 13, naranja};

string setColor(color c)           //se utiliza como string para poder concatenar. "Hacer tunin"
{
     HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);          //pausa en el sistema para settear Color
     SetConsoleTextAttribute(col, c);
     return "";
}

void clearTerminal()
{
    cout << "\033[H\033[2J\033[3J" ;
    cin.clear();
}

// MÉTODOS DEL EXAMEN

string showActor(const string arr[])
{
     string actor = "";
     for(int i=0; i<4; i++)
          actor += arr[i] + ", ";           //concatenar strings
     return actor;
}

string showRio(int lenRio)
{
     string rio = "";
     for (int i = 0; i < lenRio-1; i++)
          rio += "_ ";
     return rio;
}

void menu()
{
     cout << "0 Solo"         << endl
          << "1 Lobo"         << endl
          << "2 Caperucita"   << endl
          << "3 Uvas"         << endl
          << "4 SALIR"        << endl;
              
     do{       //unicamente para escoger el actor no para cambiarlo de string
          try
          {
               string str = "";
               cout << ">Cruzar: ";
               cin >> str;                                       //Entrada de datos string y luego validación de datos
               opcionMenu = stoi(str);                           //string a int "stoi"
               actorCruza = (obsEstaIzq) ? arrIzq[opcionMenu] : arrDer [opcionMenu];      //modifica la variable global de acuerdo a donde está el observador
               if(opcionMenu == 4)      exit(0);
               if(actorCruza.empty())
                    throw invalid_argument("No hay actor");      //Se muere el programa
          //trow No hay actor cuando el string de alguno de los lados está vacío, dependiendo de donde está el observador
          }

          catch(...)                                             //recupera la muerte del programa y vuelve a intentar, los 3 puntos sirven para decir "no me importa"
          {
               actorCruza = "";
               opcionMenu = -1;                                  //se reinicia la opción del menú
               cout << ":(Opción no válida...) \n";              //cerr es lo mismo que cout
          }
     }while(opcionMenu<0);                                       //bucle hasta que la opción seleccionada sea válida
}

void navegar()
{
     string barca = "\\_Observador , "+actorCruza+"_/";            //concatenación de caracteres
     string actorIzq = showActor(arrIzq);
     string actorDer = showActor(arrDer);

     for (int i=0; i < anchoRio; i++)
     {
          cout << "\r" + actorIzq + showRio(i) + barca + showRio(anchoRio - i) + actorDer;             //CONCATENAR caracteres
          usleep(DELAY);
     }
}

int main()
{
     clearTerminal();
     cout << setColor(azul) + "Bienvenido al juego del lobito: " << endl;
     menu();
     cout << "Está cruzando: " << actorCruza << endl;
     navegar();
     cout << endl;

     return 0;
}

/*
LÓGICA DEL PROGRAMA
1. Declarar variables string para ladoIzq y ladoDer y para el actor que cruza
2. Declarar variable bool para confirmar el estado del observador
3. Declarar variables int para luego añadir en el menú

     int opcionMenu = -1, anchoRio = 20, OBSE = 0, LOBO = 1, CAPE = 2, UVAS = 3;

4. Crear métodos

     4.1. string aguaRio (int len)
          va a definir cual es la longitud del río por la que la barca va a pasar
          sirve para presentar caracteres _ a la izquierda y a la derecha conforme
          la barca va avanzando

     4.2. string getActores (const string arrActores[])
          va a funcionar como menú para que el usuario escoja que actor quiere que
          esté en la barca junto con el al momento de cruzar el río

     4.3. void validarReglas()
          sirve para determinar si las reglas del juego se están cumpliendo al
          momento de movilizar a los actores de un lado a otro

     4.4. void showBarcaRio(int 1, const string barca)
          va a presentar la barca movilizandose de un izquierda a derecha

     4.5. showNavegación()
          \\_patmic_,_?_/ reemplaza el ? por el actor que está cruzando
*/
/*
variables que se utilizan
string ladoIzq = "  ", ladoDer = "  ", actorCruza = "  ";
bool confirmar = false;
int anchoRio = 20, OBSE = 0, LOBO = 1, CAPE = 2, UVAS = 3;

*/
