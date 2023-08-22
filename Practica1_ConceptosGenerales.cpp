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
#include <time.h>
#include <stdlib.h>
#define pi 3.14159
int main()
{
    char operador, inicial, figura;
    int n1, n2, suma, resta, numero, n, base, altura, multiplicacion, radio, lado;
    float division, area;
    do
    {
        printf("\nMENU INICIAL\n");
        printf("(1) CALCULADORA\n");
        printf("(2) JUEGO\n");
        printf("(3) CALCULADORA DE AREAS\n");
        printf("(0) FIN DE ESTA EXCELENTE PRACTICA\n");
        printf("Seleccione una opcion: \n");
        fflush(stdin);
        scanf("%c",&inicial);
        system("cls");
        switch (inicial)
        {
            case '1':
                do
                {
                    printf("\nCALCULADORA\n");
                    printf("(+) SUMA\n");
                    printf("(-) RESTA\n");
                    printf("(*) MULTIPLICACION\n");           
                    printf("(/) DIVISION\n");
                    printf("(x) SALIR\n");
                    printf("\nSeleccione una opcion: ");
                    fflush( stdin );
                    scanf("%c",&operador);
                    system("cls");
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
                    printf("El resultado de la multiplicacion es: %d\n",multiplicacion);
                    break;

                    case '/':
                    printf("Ingresa un primer numero: ");
                    scanf("%d",&n1);
                    printf("Ingresa un segundo numero: ");
                    scanf("%d",&n2);
                    division=float(n1/n2);
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
                do
                {
                    srand(time(NULL));
                    numero=rand() % 101 + 1;
                    printf("Bienvenido al juego de adivina el numero! \n(Entre 1 y 100)\n");
                    printf("Dime en que numero piensas... (yo te dare pistas)\n");
                    scanf("%d",&n);
                    system("cls");
                    printf("Recuerda que es un numero entre 1 y 100\n");
                    while (numero != n)
                    {
                        if(n>numero)
                        {
                        printf("\nDemasiado alto!\n");
                        }
                        else
                        {
                        printf("\nDemasiado bajo!\n");
                        } 
                        printf("Vamos, intentalo de nuevo: ");
                        scanf("%d",&n);
                        system("cls");
                        
                    }
                    printf("\nAcertaste!\nSeguir jugando(1)/Salir del juego(0)\n");
                    scanf("%d",&n);
                    system("cls");
                }while (n != 0);
                printf("\nGracias por jugar!"); 
            break;

            case '3':
                
                do
                {
                    printf("\nCALCULADORA DE AREAS\n");
                    printf("(1) TRIANGULO \n");
                    printf("(2) CIRCULO\n");
                    printf("(3) RECTANGULO\n");           
                    printf("(4) CUBO\n");
                    printf("(5) CILINDRO\n");
                    printf("(0) SALIR\n");
                    printf("\nSeleccione una opcion: ");
                    fflush(stdin);
                    scanf("%c",&figura);
                    system("cls");
                    switch(figura)
                    {
                        case '1':
                        printf("Base: ");
                        scanf("%d",&base);
                        printf("Altura: ");
                        scanf("%d",&altura);
                        area=(base*altura)/2;
                        printf("\nEl area del triangulo es igual a: %.2f\n",area);
                        break;

                        case '2':
                        printf("\nRadio del circulo: ");
                        scanf("%d",&radio);
                        area=pi*(radio*radio);
                        printf("\nEl area del circulo es igual a: %.2f\n",area);
                        break;

                        case '3':
                        printf("Base: ");
                        scanf("%d",&base);
                        printf("Altura: ");
                        scanf("%d",&altura);
                        area=base*altura;
                        printf("\nEl area del rectangulo es igual a: %.0f\n",area);
                        break;

                        case '4':
                        printf("\nValor de un lado del cubo: ");
                        scanf("%d",&lado);
                        area=6*(lado*lado);
                        printf("\nEl area del cubo es igual a: %.0f\n",area);
                        break;

                        case '5':
                        printf("\nRadio del cilindro: ");
                        scanf("%d",&radio);
                        printf("\nAltura del cilindro: ");
                        scanf("%d",&altura);
                        area=2*pi*radio*(altura+radio);
                        printf("\nEl area del cilindro es de: %.2f\n",area);
                        break;

                        case '0':
                        printf("\nGracias por utilizar la calculadora de areas.\n");
                        break;

                        default:
                        printf("\nFigura inexistente\n");
                        break;
                    }
                } while (figura != '0');
            break;

            case '0':
            system("cls");
            printf("Adios mundo.");
            break;
        
            default:
            printf("\nEste numero de ejercicio no existe");
            break;
        }
        
    } while (inicial != '0');
    return 0;
}

