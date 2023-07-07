//falta documentar métodos

#include <iostream>
#include <unistd.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include "../lib/aeUtility.h"
using namespace std;
#define DELAY 55000
#define ESPERA 1800000

/*Variables para Autenticación de usuario*/

int aeCedula        = 1600864845,
    aeJuegoContador = 0;                //Quizás tenga que cambiar esta variable a una que no sea global
string aeNombre     = "Alisson Viviana Espin Ortega",
       aeCorreo     = "alisson.espin@epn.edu.ec",
       aeUser,
       aePassword;


/*Variables para juego*/

bool aeObsEstaIzq = true;     //false = 0
enum {aeObservador, aeLobo, aeCaperucita, aeUvas, aeAnchoRio = 20};
int aeOpcionMenu = -1;        // aeAnchoRio = 20, aeObservador = 0, aeLobo = 1, aeCaperucita = 2, aeUvas = 3;

string aeArrIzq[]   = { "","Lobo", "Cape", "Uvas" },         //el número de caracteres de cada vector es 10
       aeArrDer[]   = { "", "",     "",     "" },
       aeActorCruza = "";                                 //Obse[0]  Lobo[1]  Cape[2]  Uvas[3]


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

string aeGetPassword(const string aeEtiqueta)
{
     char c;
     string aePassword;
     cout << aeEtiqueta;
     aeSetColor(celeste);
     while((c=getch()) && !(c=='\r'))
     {
          aePassword.push_back(c);
          _putch('*');
     }
     return aePassword;
}
void aeCredencialesIngresar()
{
     aeDatosEstudiante();
     cout << aeSetColor(rosado) +   "\t\tINICIO DE SESIÓN"  << "\n\n"
          << aeSetColor(rosado) + "Ingrese su usuario:    "    << aeSetColor(celeste);
     cin  >>  aeUser;
     aeSetColor(rosado);
     aePassword = aeGetPassword("Ingrese su contraseña: ");
     cout << endl;
     // cout << aeSetColor(rosado) + "Ingrese su contraseña: "  << aeSetColor(celeste) ;
     // cin  >>  aePassword;
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

     // aeConductor = aeUser;

     // return aeConductor;
}


/*MÉTODOS PARA LA EJECUCIÓN DEL JUEGO*/

/*
si añado los métodos que creamos en clases podría funcionar, pero tendria que modificar los strings para que 
en lugar de "observador" coloque "aeUser", creo que es facil pero tengo que comprobar

voy a hacer un commit antes de hacer esto commit - m "Funciones hechas: LOGIN, DATOS DEL ESTUDIANTE, falta JUEGO"
*/



/*LÓGICA DEL JUEGO*/

/**Se encarga de ejecutar el juego del vikingo que quiere cruzar un rio con un lobo, caperucita y unas uvas*/
void aeJuegoVikingo()
{
     /*Aqui dentro se añade la lógica que debería tomar el programa del juego*/
     cout << endl << aeUser << "\n";
     cout << endl << "Se ejecuta el juego..." << endl;
}

/*LÓGICA MAIN DEL PROGRAMA*/

int main()
{
     aeClearTerminal();
     
     //actualiza la variable global de aeUser
     aeCredencialesValidar();

     cout << endl;

     aeJuegoVikingo();
     
     return 0;
}

/*
LÓGICA DEL PROGRAMA SEGUN LA CAPTURA DEL POCO CÓDIGO QUE PUDE VER DEL ING

1. Declarar variables string para ladoIzq y ladoDer y para el actor que cruza
2. Declarar variable bool para confirmar el estado del observador
3. Declarar variables int para luego añadir en el menú

     int aeOpcionMenu = -1, aeAnchoRio = 20, aeObservador = 0, aeLobo = 1, aeCaperucita = 2, aeUvas = 3;

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
LÓGICA DEL PROGRAMA SEGUN COMO YO CREO QUE DEBERÍA FUNCIONAR (pseudocódigo)

*/