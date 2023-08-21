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
printf("\nCALCULADORA\n");
                 printf("SUMA '+'\n");
                 printf("RESTA '-'\n");
                 printf("MULTIPLICACION '*'\n");
                 printf("DIVISION '/'\n");
                 printf("Ingrese 'x' para salir\n");
                 printf("Seleccione una opcion: ");
                 scanf("%c",&operador);
*/
#include<stdio.h>
int main()
{
    char operador, inicial;
    int n1, n2, suma, resta, random;
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
                printf("\nCALCULADORA\n");
                printf("SUMA '+'\n");
                printf("RESTA '-'\n");
                printf("MULTIPLICACION '*'\n");           
                printf("DIVISION '/'\n");
                printf("Ingrese 'x' para salir\n");
                printf("\nSeleccione una opcion: ");
                fflush( stdin );
                scanf("%c",&operador);
                switch (operador)
                {
                 case '+':
                 printf("Ingresa un primer numero: ");
                 scanf("%d",&n1);
                 printf("Ingresa un segundo numero: ");
                 scanf("%d",&n2);
                 suma=n1+n2;
                 printf("El resultado de la suma es: %d\n",suma);
                  break;

                 case '-':
                 printf("Ingresa un primer numero: ");
                 scanf("%d",&n1);
                 printf("Ingresa un segundo numero: ");
                 scanf("%d",&n2);
                 resta=n1-n2;
                 printf("El resultado de la resta es: %d\n",resta);
                  break;

                 case '*':
                 printf("Ingresa un primer numero: ");
                 scanf("%d",&n1);
                 printf("Ingresa un segundo numero: ");
                 scanf("%d",&n2);
                 multiplicacion=n1*n2;
                 printf("El resultado de la multiplicacion es: %.2f\n",multiplicacion);
                 break;

                 case '/':
                 printf("Ingresa un primer numero: ");
                 scanf("%d",&n1);
                 printf("Ingresa un segundo numero: ");
                 scanf("%d",&n2);
                 division=n1/n2;
                 printf("El resultado de la division es: %.2f\n",division);
                 break;

                 case 'x':
                 printf("Pongame 10 profe :)\n");
                 break;
        
                 default:
                 printf("\nCaso equivocado, intente de nuevo.\n");
                 break;
                }
             
            }while (operador != 'x');
        
        break;

        case '2':

        break;
    
     default:
     printf("\nEste numero de ejercicio no existe");
     break;
    }
    return 0;
}

