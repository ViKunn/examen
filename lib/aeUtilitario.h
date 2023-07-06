#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define SLEEP 50000
#define TIEMPO 100000

/** Entrada de NÚMERO ENTERO
 * Solicita al usuario ingresar un número entero y realiza la validación de entrada
 * @param label Mensaje que se presenta al momento de solicitar el número
 * @return El número entero ingresado por el usuario despues de su validación
*/
int aeGetNum(const char *label)
{
    int numero;
    char entrada[100];
    int conversionExitosa;

    do {
        printf("%s", label);
        fgets(entrada, sizeof(entrada), stdin);

        conversionExitosa = sscanf(entrada, "%d", &numero);
    } while (conversionExitosa != 1);

    return numero;
}

/** Booleano para entrada de NÚMERO ENTERO
 * @param str Cadena de caracteres a verificar
 * @return True si la cadena contiene solo números, False en caso contrario
*/
bool aeEsNumeroEntero(const string& str) 
{
    for (char c : str) 
    {
        if (!isdigit(c))
            return false;
    }

    return true;
}

/** Entrada de NÚMERO ENTERO 
 * Solicita al usuario un número y lo valida, en caso de no ingresar un número válido, vuelve a pedirlo
 * 
 * @param string Mensaje que se desea presentar al pedir el número
 * @return Número ingresado por el usuario
*/
int aeObtenerNumeroEntero(const string& label) {
    string entrada;
    bool conversionExitosa = false;
    int numero;

    while (!conversionExitosa) {
        cout << label;
        getline(cin, entrada);

        conversionExitosa = aeEsNumeroEntero(entrada);
        if (conversionExitosa) {
            numero = stoi(entrada);
        } else {
            cout << "Entrada inválida. Debe ingresar un número entero." << endl;
        }
    }

    return numero;
}

/** Entrada de NÚMERO ENTERO POSITIVO
 * Solicita al usuario ingresar un número entero y realiza la validación de entrada
 * @param label Mensaje que se presenta al momento de solicitar el número
 * @return El número entero POSITIVO ingresado por el usuario despues de su validación
*/
int aeGetPosNum(const char *label)
{
    int numero;
    char entrada[100];
    int conversionExitosa;

    do {
        printf("%s", label);
        fgets(entrada, sizeof(entrada), stdin);

        conversionExitosa = sscanf(entrada, "%d", &numero);
    } while (conversionExitosa != 1 || numero < 0);

    return numero;
}

/** Entrada de NÚMERO ENTERO NEGATIVO
 * Solicita al usuario ingresar un número entero y realiza la validación de entrada
 * @param label Mensaje que se presenta al momento de solicitar el número
 * @return El número entero POSITIVO ingresado por el usuario despues de su validación
*/
int aeGetNegNum(const char *label)
{
    int numero;
    char entrada[100];
    int conversionExitosa;

    do {
        printf("%s", label);
        fgets(entrada, sizeof(entrada), stdin);

        conversionExitosa = sscanf(entrada, "%d", &numero);
    } while (conversionExitosa != 1 || numero > 0);

    return numero;
}

/** FIBONACCI
 * 
 * Imprime la cantidad de números especificados
 * @param num cuantos números se generaran
*/
int aeFibonacci(int num)
{
    int a = 0, b = 1, c=1;
    
    for(int i=0 ; i<num ; i++)
    {
        printf("%i  ", c);
        c = a + b;
        a = b;
        b = c;
    }
    return 0;
}

/** Entrada de VOCALES
 * 
 * Ayuda a confirmar que el caracter sea vocal
 * Usa: String
*/
bool aeEsVocal(const string& letra)
{
    string vocales = "aeiouAEIOU";
    return (letra.length() == 1) && (vocales.find(letra) != string::npos);
}

/** Entrada de CONSONANTES
 * Ayuda a confirmar que el caracter sea consonante
*/
bool aeEsConsonante(const string& letra)
{
    string consonantes = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    return (letra.length() == 1) && (consonantes.find(letra) != string::npos);
}

/** Entrada de VOCALES
 * Booleano, retorna valor verdadero (TRUE) o falso (FALSE)
 * @param vocal (char) El caracter ingresado será o no validado como vocal
*/
bool aeConfirmarVocal(char vocal) 
{
    vocal = tolower(vocal);
    return vocal == 'a' || vocal == 'e' || vocal == 'i' || vocal == 'o' || vocal == 'u';
}

/** Número Primo
 * Determina si un número es primo o no
*/
int aeEsPrimo(int num) 
{
    int i;

    if (num < 2) 
        return 0;     //Falso

    for (i = 2; i <= num / 2; i++) 
    {
        if (num % i == 0) 
            return 0;
    }

    return 1;      //verdadero
}

/** Presenta string de datos
 * @brief con ENTEROS
 * 
 * @param arr  (int)     Nombre del string que quiero presentar
 * @param len  (int)     Hasta qué posición del string quiero presentar (considerando que las posiciones empiezan en 0)
*/
void aeShowArray(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << "  ";
}

/** Presenta string de datos
 * @brief con CARACTERES
 * 
 * @param arr  (char)    Nombre del string que quiero presentar
 * @param len  (int)     Hasta qué posición del string quiero presentar (considerando que las posiciones empiezan en 0)
*/
void aeShowArray(char *arr, int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << "  ";
}

/** Crea un String
 * @brief con ENTEROS
 * @param arr Nombre del string en el se almacenará los datos
 * @param len Número de elementos que quiero generar
*/
void aeFillArrayEnteros(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        arr[i] = aeGetNum("Ingrese un número entero: ");
}

/** Generar PARES
 * @param arr Nombre del string en el se almacenará los datos
 * @param len Número de elementos (PARES) que quiero generar
*/
void aeFillArrayPares(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        arr[i] = i*2;
}

/** Generar IMPARES
 * @param arr Nombre del string en el que se almacenará los datos
 * @param len Número de elementos (IMPARES) que quiero generar
*/
void aeFillArrayImpares(int*arr, int len)
{
    for (int i = 0; i < len; i++)
    arr[i] = i*2+1;
}

void aeFillMatrizEnteros(int filas, int columnas, int **matriz)
{
    matriz[1000][1000];
    filas = aeGetPosNum("Digite el número de filas: ");
    columnas = aeGetPosNum("Digite el número de columnas: ");

    //Almacenando elementos en La matriz
    for (int i=0;i<filas;i++)               //controla el número de fila en la que se almacena el número
    {
        for(int j=0;j<columnas;j++)         //controla el número de columna en la que se almacena el número
        {
            cout << "["<<i<<"]["<<j<<"]" << "  ";
            matriz[i][j] = aeGetNum("Digite el número: ");
        }
    }

    //["<<i<<"]["<<j<<"];

    //Presenta la matriz
    for (int i=0;i<filas;i++)
    {
        for(int j=0;j<columnas;j++)
        {
            cout << matriz[i][j] << "  ";
        }
        cout << endl;
    }
}

string aeSetBar(string c, int size)
{
    string str=""; 
    for (int i = 0; i < size; i++)
        str += c;
    return str;
}


//Cambiar el caracter que se desplaza
/**
 * 
*/
void aeShowFace()
{
     for (int i = 0; i < 20; i++)                               //Cuantas veces se mueve la cara
     {
        cout << "\x1B[2J\x1B[H";                                //sirve para limpiar la pantalla antes de volver a mostrar la cara
        string desplazar = aeSetBar("  ",i);                      //setea los espacios que se va a desplazar la cara
        cout << "\r" << desplazar << "   \\|||/  " << endl;
        cout << "\r" << desplazar << "   (> <)   " << endl;
        cout << "\r" << desplazar << "ooO-(*)-Ooo" << endl;
        usleep(SLEEP*5);
     }
}

//Cambiar lo que se desplaza
void aeShowWaitingLoading(int size)
{
    bool avanzar=false;
    for (int i = 0; i <= 100; i++)
    {   
        if(i%size==0)
            avanzar =!avanzar;
        int ix = (avanzar)? i%size: (size - i%size);
        cout << "\r[" << aeSetBar(" ", size).replace(ix,0,"<>") << "] " <<setw(3) <<i << " % ";
        usleep(SLEEP);
    }
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