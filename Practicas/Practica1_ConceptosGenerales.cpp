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
    do //CICLO QUE CONTROLA LA REPETICION DE TODO EL PROGRAMA
    {
        //Imprimimos un menu inicial para elegir el numero de ejercicio
        //Este menu se va a repetir hasta que se ingrese el caracter '0'
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
            //CASO 1 CALCULADORA ARITMETICA
            case '1':
            //CICLO QUE CONTROLA LA REPETICION DE LA CALCULADORA
                do
                {
                    //MENU DE CALCULADORA ARITMETICA
                    printf("\nCALCULADORA\n");
                    printf("(+) SUMA\n");
                    printf("(-) RESTA\n");
                    printf("(*) MULTIPLICACION\n");           
                    printf("(/) DIVISION\n");
                    printf("(x) SALIR\n");
                    printf("\nSeleccione una opcion: ");
                    fflush( stdin );
                    //VARIABLE 'OPERADOR' NOS DIRIGE A CADA OPCION
                    //n1 y n2 VARIABLES PARA ALMACENAR 2 NUMEROS
                    scanf("%c",&operador);
                    system("cls");
                    //SWITCH QUE DIRIGE A CADA OPERACION
                    switch (operador)
                    {
                    case '+':
                    printf("Ingresa un primer numero: ");
                    scanf("%d",&n1);
                    printf("Ingresa un segundo numero: ");
                    scanf("%d",&n2);
                    suma=n1+n2;
                    //EL RESULTADO DE LA SUMA SE GUARDA EN suma
                    printf("El resultado de la suma es: %d\n",suma);
                    break;

                    case '-':
                    printf("Ingresa un primer numero: ");
                    scanf("%d",&n1);
                    printf("Ingresa un segundo numero: ");
                    scanf("%d",&n2);
                    resta=n1-n2;
                    //EL RESULTADO DE LA RESTA SE GUARDA EN resta
                    printf("El resultado de la resta es: %d\n",resta);
                    break;

                    case '*':
                    printf("Ingresa un primer numero: ");
                    scanf("%d",&n1);
                    printf("Ingresa un segundo numero: ");
                    scanf("%d",&n2);
                    multiplicacion=n1*n2;
                    //EL RESULTADO DE LA MULTIPLICACION SE GUARDA EN multiplicacion
                    printf("El resultado de la multiplicacion es: %d\n",multiplicacion);
                    break;

                    case '/':
                    printf("Ingresa un primer numero: ");
                    scanf("%d",&n1);
                    printf("Ingresa un segundo numero: ");
                    scanf("%d",&n2);
                    division=float(n1/n2);
                    //EL RESULTADO DE LA DIVISION SE GUARDA EN division
                    printf("El resultado de la division es: %.2f\n",division);
                    break;

                    case 'x':
                    //CASO SALIR DEL MENU
                    //pongame 10 profe
                    printf("Pongame 10 profe :)\n");
                    break;
            
                    default:
                    //CASO EQUIVOCADO
                    printf("\nCaso equivocado, intente de nuevo.\n");
                    break;
                    }
                
                }while (operador != 'x');
                //SE EVALUA LA VARIABLE, SI ES IGUAL A 'x' SALE DEL MENU Y REGRESA AL SWITCH INICIAL
            break;

            //CASO 2 JUEGO DE ADIVINAR EL NUMERO
            case '2':
                //CICLO QUE CONTROLA QUE EL JUEGO TERMINE
                do
                {
                    //PLANTAMOS UNA SEMILLA PARA QUE CADA NUMERO ALEATORIO SEA DIFERENTE
                    srand(time(NULL));
                    //GENERAMOS EL NUMERO ALEATORIO Y LA GUARDAMOS EN numero
                    numero=rand() % 101 + 1;
                    printf("Bienvenido al juego de adivina el numero! \n(Entre 1 y 100)\n");
                    printf("Dime en que numero piensas... (yo te dare pistas)\n");
                    //GUARDAMOS EL NUMERO QUE OTORGA EL USUARIO EN n
                    scanf("%d",&n);
                    system("cls");
                    //COMPARAMOS n & numero SI NO ES IGUAL ENTRA EN EL CICLO
                    while (numero != n)
                    {
                        //SI n ES MAYOR IMPRIME ESTE MENSAJE
                        if(n>numero)
                        {
                        printf("\nDemasiado alto!\n");
                        }
                        else
                        {
                        //SI n ES MENOR IMPRIME ESTE MENSAJE
                        printf("\nDemasiado bajo!\n");
                        } 
                        printf("Vamos, intentalo de nuevo: ");
                        //ESCANEAMOS n DE NUEVO PARA VOLVER A COMPARARLO, ASI HASTA QUE n SEA IGUAL A numero
                        scanf("%d",&n);
                        system("cls");
                        
                    }
                    //EL USUARIO ACERTO, PUEDEN SEGUIR JUGANDO O SALIR AL SWTICH INICIAL
                    printf("\nAcertaste!\nSeguir jugando(1)/Salir del juego(0)\n");
                    scanf("%d",&n);
                    system("cls");
                //SI ELIGE 0 SALE DEL CICLO Y SE ACABA EL JUEGO
                }while (n != 0);
                printf("\nGracias por jugar!"); 
            break;
            
            //CASO 3 CALCULADORA DE AREAS ARITMETICAS
            case '3': 
                do
                {
                    //MENU DE LA CALCULADORA DE AREAS
                    printf("\nCALCULADORA DE AREAS\n");
                    printf("(1) TRIANGULO \n");
                    printf("(2) CIRCULO\n");
                    printf("(3) RECTANGULO\n");           
                    printf("(4) CUBO\n");
                    printf("(5) CILINDRO\n");
                    printf("(0) SALIR\n");
                    printf("\nSeleccione una opcion: ");
                    fflush(stdin);
                    // figura CONTROLA QUE FIGURA SE CALCULARA
                    scanf("%c",&figura);
                    system("cls");
                    //SWITCH QUE DIRIGE A CADA FIGURA
                    switch(figura)
                    {
                        case '1':
                        //TRIANGULO, PEDIMOS LA BASE Y LA ALTURA
                        printf("Base: ");
                        scanf("%d",&base);
                        printf("Altura: ");
                        scanf("%d",&altura);
                        //EN TODAS LAS FIGURA EL AREA SE ALMACENARA EN LA VARIABLE CON EL MISMO NOMBRE
                        area=(base*altura)/2; 
                        printf("\nEl area del triangulo es igual a: %.2f\n",area);
                        break;

                        case '2':
                        //CIRCULO, SOLO PEDIMOS EL RADIO
                        printf("\nRadio del circulo: ");
                        scanf("%d",&radio);
                        area=pi*(radio*radio);
                        printf("\nEl area del circulo es igual a: %.2f\n",area);
                        break;

                        case '3':
                        //RECTANGULO, REUTILIZAMOS LAS VARIABLES DEL TRIAGULO
                        printf("Base: ");
                        scanf("%d",&base);
                        printf("Altura: ");
                        scanf("%d",&altura);
                        area=base*altura;
                        printf("\nEl area del rectangulo es igual a: %.0f\n",area);
                        break;

                        case '4':
                        //CUBO, SOLO NECESITAMOS EL VALOR DE UN LADO
                        printf("\nValor de un lado del cubo: ");
                        scanf("%d",&lado);
                        area=6*(lado*lado);
                        printf("\nEl area del cubo es igual a: %.0f\n",area);
                        break;

                        case '5':
                        //CILINDRO, REUTILIZAMOS EL RADIO Y LA ALTURA
                        printf("\nRadio del cilindro: ");
                        scanf("%d",&radio);
                        printf("\nAltura del cilindro: ");
                        scanf("%d",&altura);
                        area=2*pi*radio*(altura+radio);
                        printf("\nEl area del cilindro es de: %.2f\n",area);
                        break;

                        case '0':
                        //CASO PARA SALIR
                        printf("\nGracias por utilizar la calculadora de areas.\n");
                        break;

                        default:
                        printf("\nFigura inexistente\n");
                        break;
                    }
                    //SE EVALUA QUE FIGURA NO SEA IGUAL A 0 PARA CONTINUAR
                } while (figura != '0');
            break;

            case '0':
            //SE TERMINO ESTA PERFECTISIMA PRACTICA
            system("cls");
            printf("Adios mundo.");
            break;
        
            default:
            printf("\nEste numero de ejercicio no existe");
            break;
        }
        //SE EVALUA inicial PARA CONTINUAR O TERMINAR LA EJECUCION
    } while (inicial != '0');
    return 0;
}

