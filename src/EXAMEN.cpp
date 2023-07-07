#include <iostream>
#include <unistd.h>
#include <windows.h>
#include <stdio.h>
#include <string>
#include "../lib/aeUtility.h"
using namespace std;
#define DELAY 55000
#define ESPERA 1800000

int aeCedula        = 1600864845,
    aeJuegoContador = 0;                //Quizás tenga que cambiar esta variable a una que no sea global
string aeNombre     = "Alisson Viviana Espin Ortega",
       aeCorreo     = "alisson.espin@epn.edu.ec",
       aeUser,
       aePassword;

/*MÉTODOS PARA PASAR A MAYÚSCULAS O MINÚSCULAS LOS DATOS DEL ESTUDIANTE*/

string aeToUpper(const string& aeTexto)
{
    string resultado = aeTexto;
    for (char& c : resultado)
        c = toupper(c);
    return resultado;
}
string aeToLower(const string& aeTexto)
{
    string resultado = aeTexto;
    for (char& c : resultado)
        c = tolower(c);
    return resultado;
}
void aeDatosEstudiante()
{
     aeNombre = aeToLower(aeNombre);
     aeCorreo = aeToUpper(aeCorreo);

     cout << aeSetColor(rosado)   + "\t      DATOS DEL ESTUDIANTE"   << "\n\n";
     cout << aeSetColor(rosado)   + "Cedula:\t"   << aeSetColor(celeste) << aeCedula    << endl
          << aeSetColor(rosado)   + "Correo:\t"   << aeSetColor(celeste) << aeCorreo    << endl
          << aeSetColor(rosado)   + "Nombre:\t"   << aeSetColor(celeste) << aeNombre    << "\n\n";
}


/*MÉTODOS PARA VALIDACIÓN DE CREDENCIALES*/

void aeCredencialesIngresar()
{
     aeDatosEstudiante();
     cout << aeSetColor(rosado) +   "\t\tINICIO DE SESIÓN"  << "\n\n"
          << aeSetColor(rosado) + "Ingrese su usuario:    "    << aeSetColor(celeste);
     cin  >>  aeUser;

     cout << aeSetColor(rosado) + "Ingrese su contraseña: "  << aeSetColor(celeste) ;
     cin  >>  aePassword;
}
void aeCredencialesValidar()
{
     //Credenciales a validar
     int aeCredencialesContador = 1;

     const string aeUser1     = "ae",
                  aePassword1 = "1600864845",
                  aeUser2     = "profe",
                  aePassword2 = "1234";

     do
     {
          if(aeCredencialesContador == 1)
               usleep(ESPERA);

          aeCredencialesIngresar();

          if (((aeUser == aeUser1) && (aePassword == aePassword1)) ||
              ((aeUser == aeUser2) && (aePassword == aePassword2)))
          {
               //Cambia aUser dependiendo de que usuario ingresó
               (aeUser == aeUser1) ? (aeUser = "ALISSON") : (aeUser = "PROFE") ;
               
               aeSetColor(verde);
               cout << "\n\tINICIO DE SESION EXITOSO\n\n"
                    << "\t  Bienvenido/a " << aeUser << "\n\n";

               usleep(ESPERA + 2000);
               aeClearTerminal();
               break;
          }
          
          else if ((aeCredencialesContador == 3))
          {
               aeSetColor(verde);
               
               cout << "\n"     <<   "El nombre de usuario y/o la clave son incorrectos." << endl
                    << "\t"     <<   "Ha excedido el número de intentos."                 << endl
                    << "\n\t\t" <<   "...GRACIAS...\n";

               exit (0);
          }

          else
               cout << aeSetColor(verde) + "\nEl nombre de usuario y/o la clave son incorrectos.\n"
                    << "Quedan " << (3 - aeCredencialesContador) << " intentos\n";

          usleep(ESPERA);
          aeClearTerminal();
          aeCredencialesContador++;

     } while (aeCredencialesContador <= 3);
}


/*MÉTODOS PARA LA EJECUCIÓN DEL JUEGO*/

/*
si añado los métodos que creamos en clases podría funcionar, pero tendria que modificar los strings para que 
en lugar de "observador" coloque "aeUser", creo que es facil pero tengo que comprobar

voy a hacer un commit antes de hacer esto commit - m "Funciones hechas: LOGIN, DATOS DEL ESTUDIANTE, falta JUEGO"
*/

bool aeObsEstaIzq = true;  //false = 0
int aeOpcionMenu = -1, aeAnchoRio = 20, aeObservador = 0, aeLobo = 1, aeCaperucita = 2, aeUvas = 3;

string aeArrIzq[]   = { aeUser, "   Lobo   ", "Caperucita", "   Uvas   "},     //el número de caracteres de cada vector es 10
       aeArrDer[]   = {".",     "",     "",     ""},
       aeActorCruza = "";                                 //Obse[0]  Lobo[1]  Cape[2]  Uvas[3]

string aeShowActor(const string aeArr[])
{
     string aeActor = "";
     for(int i=0; i<4; i++)
          aeActor += aeArr[i] + ", ";           //concatenar strings
     return aeActor;
}
string aeShowRio(int aeLenRio)
{
     string aeRio = "";
     for (int i = 0; i < aeLenRio-1; i++)
          aeRio += "_ ";
     return aeRio;
}
void aeMenu()
{
     cout << "0 Solo"         << endl
          << "1 Lobo"         << endl
          << "2 Caperucita"   << endl
          << "3 Uvas"         << endl
          << "4 SALIR"        << endl;
              
     do{       //unicamente para escoger el actor no para cambiarlo de string
          try
          {
               string aeStr = "";
               cout << ">Cruzar: ";
               cin >> aeStr;                                       //Entrada de datos string y luego validación de datos
               aeOpcionMenu = stoi(aeStr);                           //string a int "stoi"
               aeActorCruza = (aeObsEstaIzq) ? aeArrIzq[aeOpcionMenu] : aeArrDer [aeOpcionMenu];      //modifica la variable global de acuerdo a donde está el observador
               if(aeOpcionMenu == 4)      exit(0);
               if(aeActorCruza.empty())
                    throw invalid_argument("No hay actor");      //Se muere el programa
          //trow No hay actor cuando el string de alguno de los lados está vacío, dependiendo de donde está el observador
          }

          catch(...)                                             //recupera la muerte del programa y vuelve a intentar, los 3 puntos sirven para decir "no me importa"
          {
               aeActorCruza = "";
               aeOpcionMenu = -1;                                  //se reinicia la opción del menú
               cout << ":(Opción no válida...) \n";              //cerr es lo mismo que cout
          }
     }while(aeOpcionMenu<0);                                       //bucle hasta que la opción seleccionada sea válida
}
void aeNavegar()
{
     string aeBarca    = "\\_Observador , "+aeActorCruza+"_/";            //concatenación de caracteres
     string aeActorIzq = aeShowActor(aeArrIzq);
     string aeActorDer = aeShowActor(aeArrDer);

     for (int i=0; i < aeAnchoRio; i++)
     {
          cout << "\r" + aeActorIzq + aeShowRio(i) + aeBarca + aeShowRio(aeAnchoRio - i) + aeActorDer;             //CONCATENAR caracteres
          usleep(DELAY);
     }
}

/*LÓGICA DEL JUEGO*/

void aeJuego()
{

}

/*LÓGICA MAIN DEL PROGRAMA*/

int main()
{
     aeClearTerminal();
     aeCredencialesValidar();
     // aeUser = "Alisson";
     for (int i = 0; i < 4; i++)
     {
          cout << aeArrIzq[i] << ", ";
     }
     cout << endl;
     
     // aeJuego();
     cout << endl << "Se ejecuta el juego..." << endl;
     return 0;
}
