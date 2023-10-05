#include <stdio.h>

int main()
{
    int n, i, j, op, suma;
    do
    {
        do
        {
            printf("Ingresa un rango para imprimir sus numeros perfectos\n(Un numero positivo)\n");
            scanf("%d", &n);
        } while (n < 1);

        for (i = 1; i < n; i++)
        {
            if (i % 2 == 0)
            {
                suma = 0;
                for (j = 1; j < i; j++)
                {
                    if (i % j == 0)
                    {
                        suma += j;
                    }
                }
                if (suma == i)
                {
                    printf("El numero %d es perfecto\nSuma: %d\n", i, suma);
                }
            }
        }
        printf("Desea hacerlo de nuevo?\n1.Si 0.No\n");
        scanf("%d", &op);
    } while (op != 0);
}