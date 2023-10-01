/*
Nombre del archivo: Practica5_ClasesDeAlmacenamiento_SolanoMeza_AngelDaniel.cpp.c
Autor: Solano Meza Angel Daniel
Fecha de creación: 30 de septiembre de 2023
Descripción: Este archivo contiene todo el contenido de la practica 5
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Loteria(void);
void iniciarCarrera(void);
int generarNumeroLoteria(void);
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
    printf("1.- LOTERIA \n");
    printf("2.- CARRERAS \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//****************
void menu()
{
    srand(time(NULL));
    int op;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            Loteria();
            break;
        case 2:
            iniciarCarrera();
            break;
        }

    } while (op != 0);
}

//*********************
/*
Función: Loteria
Descripción: Esta funcion realiza el juego de la loteria.
*/
void Loteria(void)
{
    //  VARIALES LOCALES
    static int ganador = rand() % 100 + 1;
    int numero;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   LOTERIA\n");
    numero = generarNumeroLoteria();
    if (numero == ganador)
    {
        printf("¡Felicidades, ganaste la lotería!\n");
    }
    else
    {
        printf("Lo siento, no ganaste esta vez.\n");
    }
    system("PAUSE");
}

//*************************
/*
Función: iniciarCarrera
Descripción: Esta funcion hace correr 3 carros y te dice quen gano.
*/
void iniciarCarrera(void)
{

    //  VARIALES LOCALES
    int register Checo = rand() % 101 + 100;
    int register Max = rand() % 101 + 100;
    int register Lewis = rand() % 101 + 100;
    float tiempo1, tiempo2, tiempo3;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("    CARRERAS\n");
    printf("UN CUARTO DE MILLA A RECORRER\n");
    sleep(1);
    printf("        3\n");
    sleep(1);
    printf("        2\n");
    sleep(1);
    printf("        1\n");
    sleep(1);
    tiempo1 = (402 + .1) / Checo;
    tiempo2 = (402 + .1) / Max;
    tiempo3 = (402 + .1) / Lewis;
    if ((tiempo1 < tiempo2) && (tiempo1 < tiempo2))
    {
        printf("\n    GANADOR: CHECO \n");
    }
    if ((tiempo2 < tiempo3) && (tiempo2 < tiempo1))
    {
        printf("\n    GANADOR: MAX \n");
    }
    if ((tiempo3 < tiempo2) && (tiempo3 < tiempo1))
    {
        printf("\n    GANADOR: LEWIS \n");
    }
    if ((tiempo1 == tiempo2) || (tiempo1 == tiempo3) || (tiempo2 == tiempo3))
    {
        printf("    EMPATE\n");
    }
    sleep(1);
    printf("\nPILOTO: Checo\nVELOCIDAD: %d\nTIEMPO: %f\n", Checo, tiempo1);
    sleep(1);
    printf("\nPILOTO: Max\nVELOCIDAD: %d\nTIEMPO: %f\n", Max, tiempo2);
    sleep(1);
    printf("\nPILOTO: Lewis\nVELOCIDAD: %d\nTIEMPO: %f\n", Lewis, tiempo3);
    system("PAUSE");
}
//****************************
/*
Función: generarNumeroLoteria
Descripción: Esta funcion genera un numero de loteria para compararlo con la variable estatica de la funcion Loteria.
Valor de retorno: Un numero aleatorio entre 1 y 100.
*/
int generarNumeroLoteria(void)
{
    //  VARIALES LOCALES
    int numero;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    numero = rand() % 100 + 1;
    return numero;
}