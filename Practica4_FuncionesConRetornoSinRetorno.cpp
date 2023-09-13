#include <stdio.h>
#include <stdlib.h>
#define N 10
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
    int op, n;
    if ((op==1) || (op==2))
    {
        printf("Cuantas veces se repetira la serie: \n");
        scanf("%d",&n);
    }
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            Fibonacci(n);
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
void Fibonacci(void)
{
    //  VARIALES LOCALES
    int ante, sig, resul, n, i;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   FIBONACCI FOR\n");
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
void Factorial(void)
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