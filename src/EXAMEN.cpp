#include <iostream>
#include <unistd.h>
#include <windows.h>
#include <stdio.h>
#include <string>
#include "../lib/aeUtility.h"
// #include <stdio.h>
// #include <string>
using namespace std;
#define DELAY 55000

int aeCedula        = 1600864845,
    aeJuegoContador = 0; /*Quizás tenga que cambiar esta variable a una que no sea global*/
string aeNombre     = "Alisson Viviana Espin Ortega",
       aeCorreo     = "alisson.espin@epn.edu.ec",
       aeUser       = "",
       aePassword   = "";

/*Funcion para pasar a mayúsculas o minusculas los datos de estudiante*/


/*Funciones para validar credenciales*/

void aeCredencialesIngresar()
{     
     cout << "INICIO DE SESIÓN" << "\n\n"
          << "Ingrese su usuario: ";
     cin >> aeUser;

     cout << "Ingrese su contraseña: ";
     cin >> aePassword;
}
void aeCredencialesValidar(/*const string aeUserValidado, const string aePasswordValidado*/)
{
     //Credenciales a validar
     const string aeUser1 = "ae",
                  aePassword1 = "1600864845",
                  aeUser2 = "profe",
                  aePassword2 = "1234";

     int aeCredencialesContador = 1;

     do
     {
          aeCredencialesIngresar();

          if ((aeUser == aeUser1) && (aePassword == aePassword1))
          {
               aeClearTerminal();

               aeUser = "ALISSON";
               cout << "Bienvenido " << aeUser;
               break;
          }

          else if ((aeUser == aeUser2) && (aePassword == aePassword2))
          {
               aeClearTerminal();

               aeUser = "PROFE";
               cout << "Bienvenido " << aeUser;
               break;
          }
          
          else if ((aeCredencialesContador == 3))
          {
               cout << "El nombre de usuario y la clave son incorrectos." << endl
                    << "Ha excedido el número de intentos." << endl
                    << endl << "\t\t...GRACIAS..." << endl;
               exit (0);
          }

          else
               cout << "\nEl nombre de usuario y la clave son incorrectos.\n"
                    << "Quedan " << (3 - aeCredencialesContador) << " intentos\n\n";
          usleep(800000);
          aeClearTerminal();
          aeCredencialesContador++;
     } while (aeCredencialesContador <= 3);
}

/*Logica MAIN del programa*/

int main()
{
     aeClearTerminal();
     aeCredencialesValidar();

     cout << "\n\n" << aeUser << endl;
     return 0;
}
