/*
    Nombre del archivo: Practica7_Punteros_SolanoMeza_AngelDaniel.c
    Autor: Solano Meza Angel Daniel
    Fecha de creación: 8 de noviembre de 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PALABRAS 5  

void argumentos(char *argv[]);
void matriz();
void ordenacion();

int main(int argc, char *argv[])
{
    int op;

    do
    {
        printf("   M   E   N   U   \n");
        printf("1.- OPERACIONES CON ARGUMENTOS \n");
        printf("2.- ANALISIS DE MATRIZ \n");
        printf("3.- ORDENACION DE PALABRAS \n");
        printf("0. Salir\n");

        scanf("%d", &op);
        system("CLS");

        switch (op)
        {
        case 1:
            argumentos(argv);
            system("PAUSE");
            break;
        case 2:
            matriz();
            system("PAUSE");
            break;
        case 3:
            ordenacion();
            system("PAUSE");
            break;
        case 0:
            printf("Saliendo...\n");
            break;
        }

        system("CLS");
        printf("\n");
    } while (op != 0);

    return 0;
}

void argumentos(char *argv[])
{
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    printf("LA SUMA DE %d + %d = %d\n", num1, num2, num1 + num2);
    printf("LA RESTA DE %d - %d = %d\n", num1, num2, num1 - num2);
    printf("LA MULTIPLICACION DE %d * %d = %d\n", num1, num2, num1 * num2);
    printf("LA DIVISION %d / %d = %d\n", num1, num2, num1 / num2);
}

void matriz()
{
    int matriz[3][3] = {{12, 24, 35},
                        {46, 52, 67},
                        {71, 89, 69}};

    int maximo = 0, fila = 0, col = 0, suma = 0;

    int *ptr = &matriz[0][0];

    for (int i = 0; i < 3 * 3; i++)
    {
        suma += *ptr;
        if (*ptr > maximo)
        {
            maximo = *ptr;
            fila = i / 3;
            col = i % 3;
        }
        ptr++;
    }

    printf("\nSUMA DE LA MATRIZ: %d\n", suma);
    printf("ELEMENTO MAS GRANDE: %d\n", maximo);
    printf("FILA %d\nCOLUMNA %d\n", fila, col);
}

void ordenacion()
{
    char *palabras[PALABRAS] = {"MANZANA", "BANANA", "CEREZA", "UVA", "NARANJA"};
    char *temp;
    int i, j;

    // Ordenar
    for (i = 0; i < PALABRAS - 1; i++)
    {
        for (j = i + 1; j < PALABRAS; j++)
        {
            if (strcmp(palabras[i], palabras[j]) > 0)
            {
                temp = palabras[i];
                palabras[i] = palabras[j];
                palabras[j] = temp;
            }
        }
    }

    // Imprimir
    for (i = 0; i < PALABRAS; i++)
    {
        printf("%s\n", palabras[i]);
    }
}