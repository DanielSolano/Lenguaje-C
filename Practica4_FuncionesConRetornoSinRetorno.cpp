#include <stdio.h>
#include <stdlib.h>
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Fibonacci(int n);
void Fibonacci_Rec(int n);
void Digitos(void);
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
    printf("3.- DIGITOS \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//****************
void menu()
{
    int op, n, cont;
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
        switch (op)
        {
        case 1:
            Fibonacci(n);
            system("cls");
            printf("Desea continuar\n1.Si\n0.Salir\n");
            scanf("%d", &cont);
            break;

        case 2:
            Fibonacci_Rec(n);
            break;
        case 3:
            Digitos();
            break;
        }

    } while (op != 0);
}

//*********************
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
        printf("%d\n", resul);
    }
    system("PAUSE");
}

//*************************
void Fibonacci_Rec(int n)
{

    //  VARIALES LOCALES
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   FACTORIAL\n");
    system("PAUSE");
}
//****************************
void Digitos(void)
{
    //  VARIALES LOCALES
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DIGITOS\n");
    system("PAUSE");
}