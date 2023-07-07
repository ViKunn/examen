/**
 * Copyright 2023. 
 * All rights reserved, pat_mic
 * libreria de utilitarios para fines académicos
 **/
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

#define TIEMPO 100000
enum escapes { 
	BELL 		= '\a', 
	RETROCESO 	= '\b',
	TAB 		= '\t',
	ENTER 		= '\n', 
	TAB_V 		= '\v', 
	RETORNO 	= '\r'
};

enum months { ENE = 1, FEB, MAR, ABR, MAY, JUN, JUL, AGO, SEP, OCT, NOV, DIC };

int aeGetNumeroPositivo(char *label) //
{
    int numero;
    char str[3];  //999 abc
    do
    {
        printf("\n %s", label);
        gets(str);
        sscanf(str,"%d", &numero);   
    } while (numero <= 0 );
    fflush(stdin);
    return numero;  
}

char aeMenuGeneral( char *showOpc)
{
    char opc='-';
    do{
        printf("\n %s", showOpc);
        scanf("%c",&opc);
    }while ( !((opc =='1') || (opc =='2') || (opc =='3')) ) ;
    return opc;
}

void aeGetLinea(char *str)    // line[lim = 10] -->   {h|o|l|a| |c|o|m|o|\n|\0|~|~|~|}
{      
    char c;
    int i =0;  
    do{
        c = getchar();
        str[i++] = c;
    }while(c != '\n');
    str[i]  == '\0';
}

enum aeColor { azul = 1, verde, celeste, rojo, rosado, salmon, blanco, plomo, rosaPalo = 13, naranja};

string aeSetColor(aeColor c)           //se utiliza como string para poder concatenar. "Hacer tunin"
{
     HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);          //pausa en el sistema para settear Color
     SetConsoleTextAttribute(col, c);
     return "";
}

void aeClearTerminal()
{
    cout << "\033[H\033[2J\033[3J" ;
    cin.clear();
}