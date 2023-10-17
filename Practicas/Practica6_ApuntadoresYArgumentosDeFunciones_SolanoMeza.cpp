/*
Nombre del archivo: Practica6_ApuntadoresYArgumentosDeFunciones_SolanoMeza.cpp
Autor: Solano Meza Angel Daniel
Fecha de creación: 16 de octube de 2023
Descripción: Practica de apuntadores y arreglos.
*/

#include "Libreria.h"
#define N 20

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
int SumaElementos(int *ptr);
void CopiarArreglo(int *origen, int *copia);
void ConcatenarArreglos(int *vect1, int *vect2, int *vect3);
int CompararArreglos(int *vect1, int *vect2);
int ValorAlto(int *vect1);
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
    printf("1.- SUMA DE ELEMENTOS DE UN ARREGLO \n");
    printf("2.- COPIAR ARREGLO \n");
    printf("3.- CONCATENAR ARREGLOS \n");
    printf("4.- COMPARAR ARREGLOS \n");
    printf("5.- VALOR MAS ALTO DEL ARREGLO \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//****************
void menu()
{
    int *ptr1, *ptr2, *ptr3;
    int vector1[N], vector2[N], vector3[N * 2];
    int op, suma, iguales, mayor;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            LlenarVector(vector1, N, 1, 50, 1);
            ImprimirVector(vector1, N, "VECTOR 1");
            ptr1 = &vector1[0];
            suma = SumaElementos(ptr1);
            printf("%d\n", suma);
            system("PAUSE");
            system("CLS");
            break;
        case 2:
            LlenarVector(vector1, N, 1, 50, 1);
            ptr1 = &vector1[0];
            ptr2 = &vector2[0];
            CopiarArreglo(ptr1, ptr2);
            ImprimirVector(vector1, N, "VECTOR ORGINAL");
            ImprimirVector(vector2, N, "VECTOR COPIA");
            system("CLS");
            break;
        case 3:
            LlenarVector(vector1, N, 1, 50, 1);
            LlenarVector(vector2, N, 1, 50, 1);
            LlenarVector(vector3, N * 2, 1, 50, 1);
            ptr1 = &vector1[0];
            ptr2 = &vector2[0];
            ptr3 = &vector3[0];
            ConcatenarArreglos(ptr1, ptr2, ptr3);
            ImprimirVector(vector1, N, "VECTOR 1");
            ImprimirVector(vector2, N, "VECTOR 2");
            ImprimirVector(vector3, N * 2, "VECTOR CONCATENADO");
            system("CLS");
            break;
        case 4:
            LlenarVector(vector1, N, 1, 50, 1);
            LlenarVector(vector2, N, 1, 50, 1);
            ptr1 = &vector1[0];
            ptr2 = &vector2[0];
            ImprimirVector(vector1, N, "VECTOR 1");
            ImprimirVector(vector2, N, "VECTOR 2");
            iguales = CompararArreglos(ptr1, ptr2);
            system("CLS");
            if (iguales == 1)
            {
                printf("ARREGLOS IGUALES\n");
            }
            else
            {
                printf("ARREGLOS NO SON IGUALES\n");
            }
            system("PAUSE");
            system("CLS");
            break;
        case 5:
            LlenarVector(vector1, N, 1, 50, 1);
            ptr1 = &vector1[0];
            ImprimirVector(vector1, N, "VECTOR 1");
            mayor = ValorAlto(ptr1);
            system("CLS");
            printf("VALOR MAS ALTO: %d\n", mayor);
            system("PAUSE");
            system("CLS");
            break;
        }

    } while (op != 0);
}

//*********************
/*
Función: SumaElementos
Descripción: Suma todos los elementos de un arreglo.
Parámetros:
- *ptr: El primer número entero a sumar.
Valor de retorno: La suma de los valores del arreglo
*/
int SumaElementos(int *ptr)
{
    int suma = 0;
    for (int i = 0; i < N; i++, ptr++)
    {
        suma += *ptr;
    }
    return suma;
}

//*************************
/*
Función: CopiarArreglo
Descripción: Copia un arreglo a otro.
Parámetros:
- *original: apunta al vector que se quiere copiar.
- *copia: apunta al vector que sera creado.
Valor de retorno: Ninguno
*/
void CopiarArreglo(int *original, int *copia)
{
    for (int i = 0; i < N; i++, original++, copia++)
    {
        *copia = *original;
    }
}
//****************************
/*
Función: ConcatenarArreglo
Descripción: Junta dos arreglos.
Parámetros:
- *vct1: apunta al vector que se concatenara.
- *vct2: apunta al vector que se concatenara.
- *vct3: apunta al vector donde se concatenaran los 2 arreglos.
Valor de retorno: Ninguno
*/
void ConcatenarArreglos(int *vect1, int *vect2, int *vect3)
{
    for (int i = 0; i < N; i++, vect1++, vect3++)
    {
        *vect3 = *vect1;
    }

    for (int i = 0; i < N; i++, vect2++, vect3++)
    {
        *vect3 = *vect2;
    }
}
//****************************
/*
Función: CompararArreglos
Descripción: Compara los valores de dos arreglos y te dice si son iguales.
Parámetros:
- *vect1: apunta al vect1.
- *vect1: apunta al vect2.
Valor de retorno:  Un 0 si son diferentes, 1 si son iguales.
*/
int CompararArreglos(int *vect1, int *vect2)
{
    for (int i = 0; i < N; i++, vect1++, vect2++)
    {
        if (*vect1 != *vect2)
        {
            return 0;
        }
    }
    return 1;
}
//****************************
/*
Función: ValorAlto
Descripción: Retorna el valor mas alto de un arreglo.
Parámetros:
- *vect1: apunta al vect1.
Valor de retorno:  el valor mas alto del arreglo.
*/
int ValorAlto(int *vect1)
{
    int mayor;
    mayor = *vect1;
    for (int i = 0; i < N; i++, vect1++)
    {
        if (*vect1 > mayor)
        {
            mayor = *vect1;
        }
    }
    return mayor;
}