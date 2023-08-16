/*
int main()
{
int limite;
int resultado=0;
printf("Ingrese un numero entero positivo:");
scanf("%d",&limite);
for (int i=1;i<=limite;i++)
{
    resultado +=1;
}
printf("La suma de los primeros %d numeros es: %d\n",limite, resultado);
return 0;
}
*/
#include<stdio.h>
int main()
{
    char operador, inicial;
    int n1, n2, suma, resta;
    float multiplicacion, division;
    printf("MENU\n");
    printf("1. 1er Ejercicio\n");
    printf("2. 2do Ejercicio\n");
    printf("3. 3er Ejercicio\n");
    scanf("%c",&inicial);
    switch (inicial)
    {
        case '1':
        do
        {
            printf("CALCULADORA");
            printf("SUMA '+'\n");
            printf("RESTA '-'\n");
            printf("MULTIPLICACION '*'\n");
            printf("DIVISION '/'\n");
            printf("Ingrese 'x' para salir");
            printf("Seleccione una opcion: ");
            scanf("%c",&operador);
            printf("Ingresa un primer numero: ");
            scanf("%d",&n1);
            printf("Ingresa un segundo numero: ");
            scanf("%d",&n2);
            switch (operador)
         {
            case '+':
                suma=n1+n2;
                printf("El resultado de la suma es: %d",suma);
            break;

            case '-':
                resta=n1-n2;
                printf("El resultado de la resta es: %d",resta);
            break;

            case '*':
                multiplicacion=n1*n2;
                printf("El resultado de la multiplicacion es: %f",multiplicacion);
            break;

            case '/':
                division=n1/n2;
                printf("El resultado de la division es: %f",division);

            break;

            case 'x':
                printf("Pongame 10 profe :)\n");
            break;
        
        default:
            printf("Caso equivocado, intente de nuevo.\n");
            break;
        }
        break;
        } while (operador != 'x');
    default:
        printf("Este numero de ejercicio no existe");
        break;
    }
    return 0;
}

