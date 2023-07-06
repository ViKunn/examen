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
#define ESPERA 950000

int aeCedula        = 1600864845,
    aeJuegoContador = 0;                //Quizás tenga que cambiar esta variable a una que no sea global
string aeNombre     = "Alisson Viviana Espin Ortega",
       aeCorreo     = "alisson.espin@epn.edu.ec",
       aeUser       = "",
       aePassword   = "";

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

     cout << "CEDULA:\t" << aeCedula << endl
          << "CORREO:\t" << aeCorreo << endl
          << "NOMBRE:\t" << aeNombre << "\n\n";
     usleep(ESPERA);
}

/*MÉTODOS PARA VALIDACIÓN DE CREDENCIALES*/

void aeCredencialesIngresar()
{     
     cout << "INICIO DE SESIÓN" << "\n\n"
          << "Ingrese su usuario: ";
     cin >> aeUser;

     cout << "Ingrese su contraseña: ";
     cin >> aePassword;
}
void aeCredencialesValidar()
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
               cout << "\nEl nombre de usuario y la clave son incorrectos." << endl
                    << "\tHa excedido el número de intentos." << endl
                    << endl << "\t\t...GRACIAS..." << endl;
               exit (0);
          }

          else
               cout << "\nEl nombre de usuario y la clave son incorrectos.\n"
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

/*Logica MAIN del programa*/

int main()
{
     aeClearTerminal();
     aeDatosEstudiante();
     aeCredencialesValidar();
     cout << endl << "Se ejecuta el juego " << endl;
     return 0;
}
