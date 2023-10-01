#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Loteria(void);
void Velocidad(void);
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
    printf("2.- VELOCIDAD \n");
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
            Velocidad();
            break;
        }

    } while (op != 0);
}

//*********************
void Loteria(void)
{
    //  VARIALES LOCALES
    static int ganador = rand() % 100 + 1;
    int numero;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   LOTERIA\n");
    numero =  generarNumeroLoteria();
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
void Velocidad(void)
{

    //  VARIALES LOCALES
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   FACTORIAL\n");
    system("PAUSE");
}
//****************************
int generarNumeroLoteria(void)
{
    //  VARIALES LOCALES
    int numero;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    numero = rand() % 100 + 1;
    return numero;
}