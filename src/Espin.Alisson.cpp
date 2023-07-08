/**  
 * CORRECCIÓN EXAMEN I BIMESTRE
 * @author     ALISSON VIVVIANA ESPÍN ORTEGA
 * @date       07.07.2023
*/

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

//VARIABLES PARA PRESENTACIÓN DE DATOS DEL ESTUDIANTE

int aeCedula        = 1600864845;
string aeNombre     = "Alisson Viviana Espin Ortega",
       aeCorreo     = "alisson.espin@epn.edu.ec",
       aeUser,
       aePassword;

//VARIABLES PARA EL CASO PRÁCTICO (Juego)

bool aeObsEstaIzq = true;     //false = 0
enum {aeObservador, aeLobo, aeCaperucita, aeUvas, aeAnchoRio = 20};
int aeOpcionMenu = -1;

string aeArrIzq[]   = { " ", "Lobo", "Cape", "Uvas" },
       aeArrDer[]   = { " ", "",     "",     "" },
       aeActorCruza = "";                                 //Obse[0]  Lobo[1]  Cape[2]  Uvas[3]


//MÉTODOS PARA PRESENTACIÓN DE DATOS DEL ESTUDIANTE

/** Pasar a MINUSCULAS
 * @param aeTexto string, El texto que se quiere modificar 
*/
string aeToLower(const string& aeTexto)
{
    string resultado = aeTexto;
    for (char& c : resultado)
     c = tolower(c);
    return resultado;
}

/** Pasar a MAYUSCULAS
 * @param aeTexto string, El texto que se quiere modificar 
*/
string aeToUpper(const string& aeTexto)
{
    string resultado = aeTexto;
    for (char& c : resultado)
        c = toupper(c);
    return resultado;
}

/** Metodo para presentacion de datos del estudiante en consola
*/
void aeShowDatosEstudiante()
{
     aeNombre = aeToLower(aeNombre);
     aeCorreo = aeToUpper(aeCorreo);

     cout << aeSetColor(rosado)   + "\t      DATOS DEL ESTUDIANTE"   << "\n\n";
     cout << aeSetColor(rosado)   + "Cedula:\t"   << aeSetColor(celeste) << aeCedula    << endl
          << aeSetColor(rosado)   + "Correo:\t"   << aeSetColor(celeste) << aeCorreo    << endl
          << aeSetColor(rosado)   + "Nombre:\t"   << aeSetColor(celeste) << aeNombre    << "\n\n";
}

//MÉTODOS PARA LOGEO DE USUARIO

/** Encriptación de caracteres de contraseña en consola
 * @param aeEtiqueta string, La etiqueta que se presenta al momento de pedir al usuario el ingreso de datos
*/
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

/** Metodo para la lectura de USUARIO y CONTRASENA
 * Modifica las variables globales  dependiendo de los datos ingresados por el usuario
 * para su posterior validación
*/
void aeCredencialesIngresar()
{
     aeShowDatosEstudiante();
     cout << aeSetColor(rosado) +   "\t\tINICIO DE SESIÓN"  << "\n\n"
          << aeSetColor(rosado) + "Ingrese su usuario:    "    << aeSetColor(celeste);
     cin  >>  aeUser;
     aeSetColor(rosado);
     aePassword = aeGetPassword("Ingrese su contraseña: ");
     cout << endl;
     // cout << aeSetColor(rosado) + "Ingrese su contraseña: "  << aeSetColor(celeste) ;
     // cin  >>  aePassword;
}

/** Metodo para validacion de las credenciales dependiendo de los datos ingresados por el usuario
*/
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

//MÉTODOS PARA LA EJECUCIÓN DEL JUEGO

/** Muestra en consola los strings de actores creados
 * @param aeArr string que se quiere mostrar
*/
string aeShowActor(const string aeArr[])
{
     string aeActor = "";
     for(int i=0 ; i<4 ; i++)
          aeActor += aeArr[i] + ", ";           //concatenar strings
     return aeActor;
}

/** Genera "_ " cierta cantidad de veces
 * @param aeLenRio cantidad de caracteres que se quiere generar
*/
string aeShowRio(int aeLenRio)
{
     string aeRio = "";
     for (int i = 0; i < aeLenRio-1; i++)
          aeRio += "_ ";
     return aeRio;
}

/** Presenta en consola la barca navegando con los actores seleccionados por el menu
 *  
 * 
 * @param aeLenRio       la longitud del rio que va a tomar (aeShowRio)
 * @param aeActorIzq     los actores que se quiere presentar a la derecha
 * @param aeBarca        la barca con el actor seleccionado por el usuario seleccionados
 * @param aeActorDer     los actores que se quiere presentar a la izquierda
 * 
 * @return               string del ultimo estado de la barca
*/
string aeShowBarcaNavegando(int aeLenRio, string aeActorIzq, string aeBarca, string aeActorDer)
{
     aeSetColor(celeste);
     string aeBarcaEnRio = aeActorIzq + aeShowRio(aeLenRio) + aeBarca + aeShowRio(aeAnchoRio - aeLenRio) + "\t" + aeActorDer;
     usleep(DELAY);
     return aeBarcaEnRio;
}

/** Presenta la barca navegan de DER a IZQ o visceversa dependiendo del donde se encuentra el observador
*/
void aeNavegar()
{
     string aeBarca    = "\\_"+aeUser+" , "+aeActorCruza+"_/";   //Concatenación de caracteres
     string aeActorIzq = aeShowActor(aeArrIzq);
     string aeActorDer = aeShowActor(aeArrDer);

     aeArrIzq[aeObservador] = aeArrDer[aeObservador] = " ";
     aeArrIzq[aeOpcionMenu] = aeArrDer[aeOpcionMenu] = "";

     if(aeObsEstaIzq)
     {
          aeArrIzq[aeObservador]= "_";
          aeArrDer[aeOpcionMenu]= aeActorCruza;
          aeActorIzq = aeShowActor(aeArrIzq);
     }
     else
     {
          aeArrDer[aeObservador]= "_";
          aeArrIzq[aeOpcionMenu]= aeActorCruza;
          aeActorDer = aeShowActor(aeArrDer);
     }

     // --------->  De IZQ a DERS
     if(aeObsEstaIzq)
     {
          for (int i = 0; i < aeAnchoRio ; i++)
               cout << "\r" << aeShowBarcaNavegando(i, aeActorIzq, aeBarca, aeActorDer);
     }
     
     // <--------- De DER a IZQ
     else
          for (int i = aeAnchoRio; i > 0 ; i--)
               cout << "\r" << aeShowBarcaNavegando(i, aeActorIzq, aeBarca, aeActorDer);
     
     aeObsEstaIzq=!aeObsEstaIzq;

     cout << endl;
}

/** Validacion de las reglas del juego conforme a la rubrica del examen
 * Cedula termina en 5, entonces Caperucita NO se come las Uvas 
*/
void aeValidarReglasJuego()
{
     string aeMensajeJuego = "";

     bool aeTodosCruzaron  =  (!aeArrDer[aeObservador].empty() && !aeArrDer[aeLobo].empty()
                              && !aeArrDer[aeCaperucita].empty() && !aeArrDer[aeUvas].empty());

     bool aeLoboCaperucita =  (aeObsEstaIzq) ? 
                              (!aeArrDer[aeLobo].empty() && !aeArrDer[aeCaperucita].empty()) :
                              (!aeArrIzq[aeLobo].empty() && !aeArrIzq[aeCaperucita].empty());
     
     aeMensajeJuego  +=   (aeLoboCaperucita) ? "\n\t\t   El LOBO se comió a CAPERUCITA, OH NO" : "" ;
     aeMensajeJuego  +=   (aeTodosCruzaron ) ? "\n\t\t\t     FELICIDADES GANASTE"              : "";

     if (!aeMensajeJuego.empty())
     {
          if(aeLoboCaperucita /* || aeCaperucitaUvas */)
          {
               aeSetColor(rojo);
               aeMensajeJuego += "\n\n\t\t\t\t  PERDISTE\n";
          }
          else
          {
               aeSetColor(verde);
               aeMensajeJuego += "\n\n\t\t\t      TE SALVASTE UVITA";
          }
          cout << "\n\t\t\t\tFIN DEL JUEGO" << endl << aeMensajeJuego << "\n";
          exit(0);
     }
}

/** Menu que se presenta en consola para que el usuario escoja la opcion que desea mover junto con la barca
*/
bool aeMenu()
{
     cout <<   endl 
          <<   aeSetColor(rosado) + "0." << aeSetColor(celeste) + " Solo\n"
          <<   aeSetColor(rosado) + "1." << aeSetColor(celeste) + " Lobo\n"
          <<   aeSetColor(rosado) + "2." << aeSetColor(celeste) + " Caperucita\n" 
          <<   aeSetColor(rosado) + "3." << aeSetColor(celeste) + " Uvas\n" 
          <<   aeSetColor(rosado) + "4." << aeSetColor(celeste) + " Salir\n";

     //se encarga de validar la opción ingresada por el usuario
     do
     {
          try                 //Entrada de opción ingresada por el usuario
          {
               string aeOpcionIngresada = "";
               cout << aeSetColor(blanco) + "\nCruzar con: ";
               cin >> aeOpcionIngresada;               //lectura de la opción ingresada
               aeOpcionMenu = stoi(aeOpcionIngresada); //Transformación de string a int "stoi" para poder leer la opción ingresada con condicionales

               //SEGMENTATION FAULT?
               aeActorCruza = (aeObsEstaIzq) ? aeArrIzq[aeOpcionMenu] : aeArrDer[aeOpcionMenu];     //Confirmación de estado del observador IZQ o DER
               if(aeOpcionMenu == 4) exit(0);          //si la opción es 4, terminar el programa
               if(aeActorCruza.empty())
                    throw invalid_argument("No hay acto\n\n ");       //muerte del programa a prósito para controlar errores cuando la opcion ingresada no es válida
          }
          catch(...)          //captura cualquier tipo de muerte del programa y la maneja de esta forma
          {
               aeActorCruza = "";
               aeOpcionMenu = -1;
               cout << "\nOpcion no valida\n\n";
          }
     
     } while (aeOpcionMenu < 0);
     return true;
}

/** Metodo que contiene la logica de como va a funcionar el juego
*/
void aeJuegoVikingo()
{
     // bool aeEstadoMenu = aeMenu();
     while (aeMenu())
     {
          if(aeOpcionMenu == 0)
               cout << "Esta cruzando: " << aeUser       << "\n\n";
          else
               cout <<"Esta cruzando: "  << aeActorCruza << "\n\n";
          aeClearTerminal();
          aeNavegar();
          aeValidarReglasJuego();
     }
}


//LÓGICA MAIN DEL PROGRAMA

int main()
{
     aeClearTerminal();
     aeCredencialesValidar();      //actualiza la variable global de aeUser que luego se utiliza en la barca
     aeJuegoVikingo();

     return 0;
}