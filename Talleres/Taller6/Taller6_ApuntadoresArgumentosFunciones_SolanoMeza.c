#include "libreria.h"

void multiplicarPorDos(int *ptr);
void sumarElementos(int *ptr, int n);
int main()
{
    srand(time(NULL));
    int *ptr1, x = 5;
    int vector[7], *ptr2;

    /*
        Apuntadores Básicos: Dado un entero x, crea un apuntador ptr que apunte a x.
        Luego, imprime el valor de x y el valor al que apunta ptr.
    */
    ptr1 = &x;
    printf("Valor de x: %d\nValor del puntero: %p\n", x, ptr1);
    system("PAUSE");
    system("CLS");

    /*
        Pasar Apuntadores a una Función:Escribe una función llamada multiplicarPorDos que tome un apuntador a un entero como argumento.
        Dentro de la función, multiplica el valor al que apunta el apuntador por 2.
        Luego, llama a esta función desde main() y muestra el valor modificado.
    */
    multiplicarPorDos(ptr1);
    printf("Valor de x: %d\n", x, ptr1);
    system("PAUSE");
    system("CLS");

    /*
        Arreglos: Crea un arreglo de enteros de tamaño 7 (Los valores que genere sean random entre 1-50, y que los valores no sean repetidos).
        Luego, crea un apuntador que apunte al primer elemento del arreglo.
        Utiliza un bucle para imprimir todos los elementos del arreglo utilizando el apuntador.
    */
    LlenarVector(vector, 7, 1, 50, 1);
    ptr2 = &vector[0];
    for (int i = 0; i < 7; i++)
    {
        printf("[%d] --> %d\n", i, *ptr2++);
    }
    system("PAUSE");
    system("CLS");

    /*
        Modificar Elementos de un Arreglo: Escribe una función llamada
        sumarAElementos que tome un apuntador a un arreglo de enteros y un valor
        entero como argumentos. Dentro de la función, suma el valor entero a cada
        elemento del arreglo utilizando aritmética de direcciones. Llama a esta función
        desde main() y muestra el arreglo modificado.
       */
    ptr2 = &vector[0];
    sumarElementos(ptr2, 2);
    ptr2 = &vector[0];
    for (int i = 0; i < 7; i++)
    {
        printf("[%d] --> %d\n", i, *ptr2++);
    }
    system("PAUSE");
    system("CLS");

    return 0;
}

void multiplicarPorDos(int *ptr)
{
    *ptr = *ptr * 2;
}

void sumarElementos(int *ptr, int n)
{
    for (int i = 0; i < 7; i++)
    {
        *ptr += n;
        ptr++;
    }
}
