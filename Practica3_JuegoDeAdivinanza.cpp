#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numero, n, intentos = 0;
    srand(time(NULL));
    numero = rand() % 101 + 1;

    inicio:
        printf("Bienvenido al juego de adivina el numero! \n(Entre 1 y 100)\n");

    adivinanza:
        printf("Dime en que numero piensas... (yo te dare pistas)\n");
        scanf("%d", &n);
    
        intentos++; // Al imprimir el resultado le restamos 1
        if (numero == n)
        {
            printf("Felicidades, ganaste en %d intentos\n", intentos - 1);
            goto reinicio;
        }
        if (n > numero) // SI n ES MAYOR IMPRIME ESTE MENSAJE
        {
            printf("\nDemasiado alto!\n");
            goto adivinanza;
        }
        if(n<numero) // SI n ES MENOR IMPRIME ESTE MENSAJE
        {
            
            printf("\nDemasiado bajo!\n");
            goto adivinanza;
        }

    reinicio:
        printf("\nAcertaste!\n(1)Seguir jugando\n(0)Salir del juego\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
                goto inicio;
                break;
            case 0:
                printf("Gracias por jugar\n");
                break;
            default:
                goto reinicio;
        }

    
}