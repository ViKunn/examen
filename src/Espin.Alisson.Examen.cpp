#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include "../lib/aeColor.h"
#include "../lib/aeUtilitario.h"
#include "../lib/aeUtility.h"

using namespace std;

string aeValidarCredencial(const string& username, const string& password)
{
     const string user1 = "AE";
     const string password1 = "1600864845";
     const string user2 = "PROFE";
     const string password2 = "1234";

     // Validar las credenciales y devolver el nombre completo del usuario
     if (username == user1 && password == password1)
          return "Alisson Espín";
     else if (username == user2 && password == password2)
          return "PROFE";
     else
          return "";
}

void aeLogin3Times()
{
     int contador = 1;

     do
     {
          string username;
          string password;

          cout << "Ingrese su nombre de usuario: ";
          cin >> username;

          cout << "Ingrese su contraseña: ";
          cin >> password;

          string nombreUsuario = aeValidarCredencial(username, password);

          if (!nombreUsuario.empty())
          {
               cout << "Inicio de sesión exitoso." << endl;
               usleep(50000);

               aeClearTerminal();
               cout << "\nHola, " << nombreUsuario << "!" << endl;
               return;
          }
          else if (contador < 3)
          {
               cout << "Credenciales inválidas. Intente nuevamente." << "\n\n";
          }
          else if (contador == 3)
          {
               cout << "Se excedió el número de intentos. GRACIAS!" << endl;
               exit(0);
          }

          contador++;

     } while (contador <= 3);
}

string aeconvertirAMayuscula(const string& texto)
{
    string resultado = texto;
    for (char& c : resultado)
    {
        c = toupper(c);
    }
    return resultado;
}

string aeconvertirAMinuscula(const string& texto)
{
    string resultado = texto;
    for (char& c : resultado)
    {
        c = tolower(c);
    }
    return resultado;
}

void aeDatosEstudiante()
{
     int numCedula;
     string nombre, correo;

     numCedula = aeGetNum("Ingrese su número de cédula: ");

     cout << "Ingrese su nombre: ";
     getline(cin, nombre);

     cout << "Ingrese su correo electrónico: ";
     cin >> correo;

     correo = aeconvertirAMayuscula(correo);

     nombre = aeconvertirAMinuscula(nombre);

     aeSetTextColor(textColorRed);
     cout << "\n\tDATOS DEL ESTUDIANTE: " << endl;

     aeSetTextColor(textColorBlue);
     cout << "CÉDULA: " << numCedula << endl;
     cout << "CORREO: " << correo << endl;
     cout << "NOMBRE: " << nombre << endl;
}

int main()
{
     aeSetTextColor(textColorRed);
     cout << "INGRESE SUS DATOS " << endl;

     aeSetTextColor(textColorBlue);
     aeDatosEstudiante();

     aeSetTextColor(textColorRed);
     cout << "\nINICIO DE SESIÓN" << endl;
     
     aeSetTextColor(textColorBlue);
     aeLogin3Times();

     cout << "\nSe ejecuta el juego..." << endl;

     return 0;
}