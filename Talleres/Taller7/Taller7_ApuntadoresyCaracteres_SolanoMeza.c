#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void ImprimirNombres(char *nombres[], int n, int m);
void OrdenarPalabras(char *palabras[], int n);
void InvertirCadena(char *cadena);
//****  main principal  *********
int main()
{
    menu();
    return 0;
}
//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************
int msges()
{
    int op;
    system("CLS");
    printf("   M  E   N   U \n");
    printf("1.- TRES NOMBRES \n");
    printf("2.- IMPRIMIR NOMBRES \n");
    printf("3.- FUNCION IMPRIMIR \n");
    printf("4.- INVERTIR CADENA \n");
    printf("5.- ORDENAR CADENAS \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//****************
void menu()
{
    char *nombres[6];
    char *palabras[5];
    char *funcion1[3][20];
    nombres[0] = strdup("DANIEL");
    nombres[1] = strdup("SOLANO");
    nombres[2] = strdup("ODIN");
    char palabra[50];
    int op;
    int i;
    do
    {
        op = msges();
        switch (op)
        {

        case 1:
            /*1. Declarar un arreglo de apuntadores a caracteres llamado nombres que
               contenga tres nombres (cadenas de texto). Luego, escribe un bucle que recorra
               este arreglo y, en cada iteración, imprima el nombre correspondiente.*/
            system("CLS");
            for (i = 0; i < 3; i++)
            {
                printf("EL NOMBRE %d ES: %s\n", i + 1, nombres[i]);
            }
            system("PAUSE");
            break;

        case 2:
            /*2. Escribe un programa que permita al usuario ingresar tres nombres y almacene
                estos nombres en el arreglo de apuntadores a caracteres nombres. Luego, usa
                un bucle para imprimir los nombres almacenados.*/
            system("CLS");
            for (i = 0; i < 3; i++)
            {
                printf("INGRESE EL NOMBRE %d: ", i + 1);
                scanf("%s", &funcion1[i]);
            }
            system("CLS");
            for (i = 0; i < 3; i++)
            {
                printf("EL NOMBRE %d ES: %s\n", i + 1, funcion1[i]);
            }
            system("PAUSE");
            break;
        case 3:
            /*3. Para los ejercicios anteriores crea una función que sirva para ambos ejercicios
            donde escribas una función llamada imprimirNombres que tome un arreglo de
            apuntadores a caracteres como argumento y lo recorra para imprimir cada
            nombre en una línea separada.*/
            ImprimirNombres(nombres, 3, 0);
            system("PAUSE");
            break;
        case 4:
            /*4. Escribe una función llamada "invertirCadena" que tome un apuntador a "char"
            como argumento y revierta la cadena original sin crear una nueva cadena.
            Luego, utiliza esta función para invertir una cadena y mostrar el resultado.*/
            InvertirCadena(nombres[0]);
            InvertirCadena(nombres[1]);
            InvertirCadena(nombres[2]);
            ImprimirNombres(nombres, 3, 0);
            system("PAUSE");
            break;
        case 5:
            /*5. Crea un programa que permita al usuario ingresar una lista de palabras
            (cadenas de caracteres) y luego ordene esas palabras alfabéticamente
            utilizando apuntadores a caracteres y arreglos de apuntadores.*/
            system("CLS");
            for (i = 0; i < 5; i++)
            {
                palabras[i] = strdup("");
            }
            for (i = 0; i < 5; i++)
            {
                printf("INGRESE LA PALABRA %d: ", i + 1);
                fflush(stdin);
                gets(palabra);
                strcpy(palabras[i], palabra);
            }
            OrdenarPalabras(palabras, 5);
            ImprimirNombres(palabras, 5, 0);
            system("PAUSE");
            break;
        }

    } while (op != 0);
}

void ImprimirNombres(char *nombres[], int n, int m)
{
    for (int i = m; i < n; i++)
    {
        printf("%s\n", nombres[i]);
    }
}

void InvertirCadena(char *cadena)
{
    int j = strlen(cadena) - 1;

    int i = 0;
    char temp;

    while (i < j)
    {
        temp = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = temp;
        i++;
        j--;
    }
}

void OrdenarPalabras(char *palabras[], int n)
{
    int i, j;
    char *temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(palabras[i], palabras[j]) > 0)
            {
                temp = palabras[i];
                palabras[i] = palabras[j];
                palabras[j] = temp;
            }
        }
    }
}