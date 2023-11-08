/*
    NOmbre del archivo: Taller8_ExperimentacionConPunteros.c
    Autor: Solano Meza Angel Daniel
    Fecha de creación: 07 de Noviembre de 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M 100
#define N 15

int NUMERO();
void LlenarMatriz(int **q, int m, int n);
void Metodo1(int *p, int m, int n);
void Metodo2(int v[], int m, int n);
void Metodo3(int A[][3], int m, int n);
void Metodo4(int *p[], int m, int n);
void Metodo5(int **q, int m, int n);
void BusquedaMetodo1(int *p, int m, int n, int num);
void BusquedaMetodo2(int v[], int m, int n, int num);
void BusquedaMetodo3(int A[][3], int m, int n, int num);
void BusquedaMetodo4(int *p[], int m, int n, int num);
void BusquedaMetodo5(int **q, int m, int n, int num);

int main()
{
    srand(time(NULL));
    int num, i, k, n;
    clock_t inicio, fin;
    double TMetodo1 = 0, TMetodo2 = 0, TMetodo3 = 0, TMetodo4 = 0, TMetodo5 = 0;
    int b[M][N];
    int *q[M];
    int **r = q;

    for (i = 0; i < M; i++)
    {
        q[i] = &b[i][0];
    }

    LlenarMatriz(r, M, N);
    fflush(stdin);
    printf("NUMERO DE REPETICIONES: ");
    scanf("%d", &n);

    int NumeroRellenar[n];
    for (i = 0; i < n; i++)
    {
        NumeroRellenar[i] = rand() % 1000;
    }

    for (k = 0; k < n; k++)
    {
        num = NumeroRellenar[k];

        inicio = clock();
        Metodo1(&b[0][0], M, N);
        BusquedaMetodo1(&b[0][0], M, N, num);
        fin = clock();
        TMetodo1 += (double)(fin - inicio) / CLOCKS_PER_SEC;

        inicio = clock();
        Metodo2(&b[0][0], M, N);
        BusquedaMetodo2(&b[0][0], M, N, num);
        fin = clock();
        TMetodo2 += (double)(fin - inicio) / CLOCKS_PER_SEC;

        inicio = clock();
        Metodo3(b, M, N);
        BusquedaMetodo3(b, M, N, num);
        fin = clock();
        TMetodo3 += (double)(fin - inicio) / CLOCKS_PER_SEC;

        inicio = clock();
        Metodo4(q, M, N);
        BusquedaMetodo4(q, M, N, num);
        fin = clock();
        TMetodo4 += (double)(fin - inicio) / CLOCKS_PER_SEC;

        inicio = clock();
        Metodo5(r, M, N);
        BusquedaMetodo5(r, M, N, num);
        fin = clock();
        TMetodo5 += (double)(fin - inicio) / CLOCKS_PER_SEC;

        printf("\n");
    }

    printf("TIEMPO TOTAL METODO 1: %f \n", TMetodo1);
    printf("TIEMPO TOTAL METODO 2: %f \n", TMetodo2);
    printf("TIEMPO TOTAL METODO 3: %f \n", TMetodo3);
    printf("TIEMPO TOTAL METODO 4: %f \n", TMetodo4);
    printf("TIEMPO TOTAL METODO 5: %f \n", TMetodo5);

    return 0;
}

void LlenarMatriz(int **q, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            q[i][j] = rand() % 1000;
        }
    }
}

int NUMERO()
{
    int num;
    printf("INGRESE EL NUMERO QUE DESEE BUSCAR: \n");
    scanf("%d", &num);

    return num;
}

void Metodo1(int *p, int m, int n)
{
    int i, j;
    printf("LA MATRIZ ES: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", *(p + i * n + j));
        }
        printf("\n");
    }
    printf("\n");
}

void Metodo2(int v[], int m, int n)
{
    int i, j;
    printf("LA MATRIZ ES: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", v[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Metodo3(int A[][3], int m, int n)
{
    int i, j;
    printf("LA MATRIZ ES: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Metodo4(int *p[], int m, int n)
{
    int i, j;
    printf("LA MATRIZ ES: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Metodo5(int **q, int m, int n)
{
    int i, j;
    printf("LA MATRIZ ES: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", q[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void BusquedaMetodo1(int *p, int m, int n, int num)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (*(p + i * n + j) == num)
            {
                printf("NUMERO %d ENCONTRADO EN POSICION [%d][%d]\n", num, i, j);
                return;
            }
        }
    }
    printf("NUMERO %d NO ENCONTRADO \n", num);
}

void BusquedaMetodo2(int v[], int m, int n, int num)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i * n + j] == num)
            {
                printf("NUMERO %d ENCONTRADO EN POSICION [%d][%d]\n", num, i, j);
                return;
            }
        }
    }
    printf("NUMERO %d NO ENCONTRADO\n", num);
}

void BusquedaMetodo3(int A[][3], int m, int n, int num)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] == num)
            {
                printf("NUMERO %d ENCONTRADO EN POSICION [%d][%d]\n", num, i, j);
                return;
            }
        }
    }
    printf("NUMERO %d NO ENCONTRADO\n", num);
}

void BusquedaMetodo4(int *p[], int m, int n, int num)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (p[i][j] == num)
            {
                printf("NUMERO %d ENCONTRADO EN POSICION [%d][%d]\n", num, i, j);
                return;
            }
        }
    }
    printf("NUMERO %d NO ENCONTRADO\n", num);
}

void BusquedaMetodo5(int **q, int m, int n, int num)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (q[i][j] == num)
            {
                printf("NUMERO %d ENCONTRADO EN POSICION [%d][%d]\n", num, i, j);
                return;
            }
        }
    }
    printf("NUMERO %d NO ENCONTRADO\n", num);
}