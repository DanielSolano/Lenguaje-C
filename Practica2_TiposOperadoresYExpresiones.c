#include <stdio.h>
//*********************************************************************************************************
void inventario(void) // Funcion para el inventario
{
    int size, op, obj, continuar, i;
    i = 0;
    printf("---INVENTARIO---\n");
    printf("Seleccione el tamanio de su inventario: \n");
    scanf("%d", &size);
    int inventario[size];
    for(int i=0;i<=size;i++)
    {
        inventario[i]=0;
    }
    system("CLS");
    do
    {
        printf("1.Agregar elementos\n2.Retirar elementos\n3.Mostrar inventario\n0.Salir del inventario\n");
        scanf("%d", &op); // Desplegamos un menu para elegir que operacion hacer
        switch (op)
        {
        case 1: // Agregar objetos al inventario

            continuar = 1; // Reiniciamos continuar

            if (i != size) // Avisa si el inventario esta lleno
            {
                while (continuar != 0) // Utilizamos un ciclo para agregar objetos al inventario
                {
                    printf("Ingresa un elemento en el espacio %d del inventario: \n", i + 1);
                    scanf("%d", &obj);
                    inventario[i] = obj;
                    system("CLS");
                    printf("Seguir rellenando inventario\n1.Si\n0.No\n");
                    scanf("%d", &continuar);
                    i++;

                    if ((i == size) || (continuar == 0)) // Sale del ciclo si llena el inventario o si el usuario lo pide
                    {
                        continuar = 0;
                    }
                }
            }

            break;
        case 2: // Retirar objetos
            if ((i != 0))
            {
                continuar = 1; //Reiniciamos continuar
                while (continuar != 0)
                {
                    printf("Objeto del espacio %d del inventario removido: \n", i);
                    inventario[i-1]=0; //Asigna 0 para vaciar el espacio
                    i--;
                    system("CLS");
                    printf("Quieres retirar otro objeto?: \n1.Si\n0.No\n");
                    scanf("%d", &continuar);
                    if ((i == 0) || (continuar == 0)) // Sale del ciclo si el inventario esta vacio o si el usuario lo pide
                    {
                        continuar = 0;
                    }
                }
            }

            break;

        case 3:
            system("CLS");
            continuar = 1; //Reiniciamos continuar
            if (i == 0)
            {
                printf("No imprimimos inventarios vacios\n");
            }
            else
            {
                do
                {
                    for (int i = 0; i <= size - 1; i++)
                    {
                        printf("Espacio %d:| %d |\n",i+1,inventario[i]); //Imprime el numero de espacio y su valor
                    }
                    printf("1. Continuar\n");
                    scanf("%d", &continuar);
                } while (continuar != 1);
            }
            break;
        }

        system("CLS");
        if (i == size) // Inventario lleno
        {
            printf("Inventario lleno\n");
        }
        else
        {
            if (i == 0) // Inventario vacio
            {
                printf("Inventario vacio\n");
            }
            else // Indica la cantidad de objetos
            {
                printf("Hay %d objetos en el inventario: \n", i);
            }
        }

    } while (op != 0);
}
//*********************************************************************************************************
char printMenu() //Funcion que imprime el menu
{
    char n;
    printf("\n---MENU---\n1.Binario\n2.Calificaciones\n3.Invenario\n0.-Salir\nSeleccione una opcion: ");
    scanf("%c", &n);
    return n;
}
//*********************************************************************************************************
char convCalf() // Funcion que returna calificaciones con operaodres ternarios
{
    int calif;
    printf("Escribe tu calificacion (0-100): ");
    scanf("%d", &calif);
    if (calif >= 80) // Si es mayor a 80 puede ser B o A
    {
        return printf("Tu calificacion %d es equivalente a %c\n", calif, (calif <= 89) ? 'B' : 'A');
    }
    else
    {
        if (calif >= 60) //Si es vayor a 60 pero no a 80 puede ser D o C
        {
            return printf("Tu calificacion %d es equivalente a %c\n", calif, (calif <= 69) ? 'D' : 'C');
        }
        else // Si no es ninguna de las anteriores es F
        {
            return printf("Tu calificacion %d es igual a F\n", calif);
        }
    }
}
//*********************************************************************************************************
void conBin() // Funcion que convierte decimal binario
{
    int decimal, n_bits, temp, bit_encendido, i, j, k;
    printf("Ingresa un numero decimal: \n");
    scanf("%d", &decimal);

    // Validar numero positivo
    if (decimal < 0)
    {
        printf("\nO");
    }
    else
    {
        // Calcular bits necesarios
        temp = decimal;
        n_bits = 0;
        while (temp > 0)
        {
            temp /= 2;
            n_bits++;
        }

        // Crear arreglo
        int bit[n_bits];
        i = 0;
        while (decimal > 0)
        {
            bit[i] = decimal % 2;
            decimal /= 2;
            i++;
        }

        printf("Numero en binario:\n");
        for (j = i - 1; j >= 0; j--)
        {
            printf("%d", bit[j]);
        }

        // Buscar bits encendidos
        bit_encendido = -1;
        printf("\nLos bits encendidos estan en la posicion: \n");
        for (k = 0; k < i; k++)
        {
            if (bit[k] == 1)
            {
                bit_encendido = k;
                printf("%d ", bit_encendido);
            }
        }

        // Si no se encontraron bits
        if (bit_encendido == -1)
        {
            printf("No se encontraron bits encendidos\n");
        }
    }
}
//*********************************************************************************************************
int main()
{
    char inicial;
    do
    {
        fflush(stdin);
        inicial = printMenu();
        switch (inicial)
        {
        case '1':
            system("CLS");
            conBin();

            break;

        case '2':
            system("CLS");
            convCalf();
            break;

        case '3':
            system("CLS");
            inventario();
            break;

        case '0':
            system("CLS");
            printf("Adios mundo\n"); 
            break;

        default:
            printf("Caso incorrecto\n");
            break;
        }

    } while (inicial != '0');

    return 0;
}
//*********************************************************************************************************