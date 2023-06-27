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

void aeClearTerminal()
{
    // system("cls||clear"); 
    // fflush(stdout); 
    cout << "\033[H\033[2J\033[3J" ;
    cin.clear();
}

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

void aeLoading()
{
    int contadorC=0;
    char c[] ="\\|/- ";

    for (int i = 0; i <= 100; i++)
    {
        if(contadorC==5)
            contadorC =0;
        printf("%c%c%c %d %% ", RETORNO,TAB, c[contadorC++],i);
        usleep(TIEMPO);
    }
}

void aeLoadingShort()
{
    char c[] ="\\|/- ";
    for (int i = 0; i <= 100; i++)
    {
        //contadorC== (i%5==0) ? i%5 : 0;
        printf("\r%c %3d %% ",c[i%5],i);
        //usleep(TIEMPO);
    }
}

void aeLoadingBar(int size)
{ 
    char barra[size];
    float porcentaje = (float)100/(float)size;
    for (int i = 0; i <= size; i++)
        barra[i]=' ';
    
    for (int i = 0; i <= size; i++)
    {
        barra[i]='#';
        printf("%c%c [%s]  %.0f %%", RETORNO, TAB, barra, i*porcentaje);
        usleep(TIEMPO*2);
    }
}