/*
Nombre del archivo: Practica4_FuncionesConRetornoSinRetorno.cpp
Autor: Solano Meza Angel Daniel
Fecha de creación: 21 de septiembre de 2023
Descripción: Practica 4 completa, funciones con y sin retorno
*/
#include <stdio.h>
#include <stdlib.h>
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Fibonacci(int n);
int Fibonacci_Rec(int n);
void Pascal(int n);
int Factorial(int n);
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
    printf("1.- FIBONACCI \n");
    printf("2.- FIBONACCI RECURSIVO \n");
    printf("3.- TRIANGULO DE PASCAL \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//****************
void menu()
{
    int op, n, repetido, cont, resul;
    do
    {
        op = msges();
        if (op == 1)
        {
            system("cls");
            printf("   FIBONACCI FOR\n");
            printf("Cuantas veces se repetira la serie: \n");
            scanf("%d", &n);
        }
        if (op == 2)
        {
            system("cls");
            printf("   FIBONACCI RECURSIVO\n");
            printf("Cuantas veces se repetira la serie: \n");
            scanf("%d", &n);
        }
        if (op == 3)
        {
            system("cls");
            printf("   TRIANGULO DE PASCAL\n");
            printf("Numero de filas a imprimir: \n");
            scanf("%d", &n);
        }
        switch (op)
        {
        case 1:
            repetido = 0;
            do
            {

                if (repetido == 1)
                {
                    system("cls");
                    printf("   FIBONACCI FOR\n");
                    printf("Cuantas veces se repetira la serie: \n");
                    scanf("%d", &n);
                }
                Fibonacci(n);
                printf("<- Valor del termino %d\n", n);
                system("pause");
                repetido = 1;
                printf("Repetir\n1.Si 0.Salir\n");
                scanf("%d", &cont);

            } while (cont != 0);
            system("cls");
            break;

        case 2:
            repetido = 0;
            do
            {

                if (repetido == 1)
                {
                    system("cls");
                    printf("   FIBONACCI RECURSIVO\n");
                    printf("Cuantas veces se repetira la serie: \n");
                    scanf("%d", &n);
                }
                resul = Fibonacci_Rec(n);
                printf("El valor del termino %d de la serie es %d\n", n, resul);
                repetido = 1;
                printf("Repetir\n1.Si 0.Salir\n");
                scanf("%d", &cont);

            } while (cont != 0);
            system("cls");
            break;
        case 3:
            do
            {
                if (repetido == 1)
                {
                    system("cls");
                    printf("   TRIANGULO DE PASCAL\n");
                    printf("Numero de filas a imprimir: \n");
                    scanf("%d", &n);
                }
                Pascal(n);
                repetido = 1;
                printf("Repetir\n1.Si 0.Salir\n");
                scanf("%d", &cont);
            } while (cont != 0);

            break;
        }
    } while (op != 0);
}

//*********************
/*
Función: Fibonacci
Descripción: Calcula la seria fibonacci hasta el numero que el usuario desee.
Parámetros:
- n: Entero positivo.
Valor de retorno: Sin valor de retorno.
*/
void Fibonacci(int n)
{
    //  VARIALES LOCALES
    int ante, sig, resul, i;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    ante = -1;
    sig = 1;
    system("CLS");
    for (i = 0; i < n; i++)
    {
        resul = ante + sig;
        ante = sig;
        sig = resul;
        printf("%d ", resul);
    }
}

//*************************
/*
Función: Fibonacci_Rec
Descripción: Calcula el valor del termino de la serie fibonacci que el usuario decida
Parámetros:
- n: Entero positivo.
Valor de retorno: Valor de la serie de n.
*/
int Fibonacci_Rec(int n)
{

    //  VARIALES LOCALES
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return Fibonacci_Rec(n - 1) + Fibonacci_Rec(n - 2);
    }
    system("PAUSE");
}
//****************************
/*
Función: Pascal
Descripción: Calcula las filas del triangulo de pascal hasta n
Parámetros:
- n: Entero positivo.
Valor de retorno: Sin valor de retorno.
*/
void Pascal(int n)
{
    //  VARIALES LOCALES
    int i, j;
    //  AQUI DESARROLLO PROGRAMA
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j <= i; j++)
        {
            printf("%d ", (Factorial(i) / (Factorial(j) * Factorial(i - j))));
        }
    }
    printf("\n");

    system("PAUSE");
}
//****************************
//Funcion de factorial para el triangulo de pascal.
int Factorial(int n)
{
    //  VARIALES LOCALES
    int i, resul;
    //  AQUI DESARROLLO PROGRAMA
    resul = 1;
    for (i = 1; i <= n; i++)
    {
        resul *= i;
    }
    return resul;
}