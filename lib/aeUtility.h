#include <stdio.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

#define TIEMPO 100000

enum aeColor { azul = 1, verde, celeste, rojo, rosado, salmon, blanco, plomo, rosaPalo = 13, naranja};

/** permite cambiar el color de los caracteres que se presenten en consola
 * @param aeColor   Cual es el color que se va a utilizar de acuerdo con los ennumerados anteriormente
 * @return string para poder concatenar con otros que van a tomar el color definido
*/
string aeSetColor(aeColor c)           //se utiliza como string para poder concatenar. "Hacer tunin"
{
     HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);          //pausa en el sistema para settear Color
     SetConsoleTextAttribute(col, c);
     return "";
}

/** Limpia la consola
*/
void aeClearTerminal()
{
    cout << "\033[H\033[2J\033[3J" ;
    cin.clear();
}