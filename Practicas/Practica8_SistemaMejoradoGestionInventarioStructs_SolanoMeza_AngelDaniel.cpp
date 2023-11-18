#include "junior.h"
#define N 10

int msges();
void menu();
void Mostrar(TReg inventario[], int i);
int Total(TReg inventario[], int i);
TReg AgregarProducto(void);

int main()
{
    menu();
    return 0;
}

int msges()
{
    int op;
    system("CLS");
    printf("   M  E   N   U \n");
    printf("1.- AGREGAR PRODUCTO \n");
    printf("2.- RETIRAR PRODUCTOS \n");
    printf("3.- MOSTRAR PRODUCTOS \n");
    printf("4.- CALCULAR VALOR DEL INVENTARIO \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}

void menu()
{
    int op, i, total, apagar, encontrado, confirmar;
    TReg Inventario[100];
    TReg producto;
    i = 0;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            system("cls");
            producto = AgregarProducto();
            while (BusquedaTReg(Inventario, i, producto.key) != -1)
            {
                system("cls");
                printf("CODIGO DE PRODUCTO REPETIDO, INGRESELO DE NUEVO\n");
                producto.key = Validar(1, 20000);
                producto.Codigo = producto.key;
            }
            if (i <= N)
            {
                Inventario[i++] = producto;
                printf("PRODUCTO AGREGADO AL INVENTARIO\n");
            }
            break;
        case 2:
            system("CLS");
            if (i == 0)
            {
                printf("INCAPAZ DE ELIMINAR REGISTROS VACIOS\n");
            }
            else
            {
                printf("CODIGO DE PRODUCTO A RETIRAR\n");
                apagar = Validar(1, 2000);
                encontrado = BusquedaTReg(Inventario, i, apagar);

                if (encontrado == -1)
                {
                    printf("NUMERO DE EMPLEADO NO EXISTENTE\n");
                }
                else // Encontrada
                {
                    if (Inventario[encontrado].Status == 0)
                    {
                        printf("PRODUCTO YA ELIMINADO\n");
                    }
                    else
                    {
                        system("CLS");
                        printf("---DATOS DEL PRODUCTO---\n");
                        printf("PRODUCTO EN REGISTRO: %d\n", encontrado);
                        printf("CODIGO DE PRODUCTO: %d\n", Inventario[encontrado].Codigo);
                        printf("NOMBRE DEL PRODUCTO: %s\n", Inventario[encontrado].Producto);
                        printf("PRECIO: %d\n", Inventario[encontrado].Precio);
                        printf("CANTIDAD: %d\n", Inventario[encontrado].Cantidad);
                        system("pause");
                        system("cls");
                        printf("DESEA ELIMINAR EL REGISTRO: 1.SI 0.NO\n");
                        confirmar = Validar(0, 1);
                        system("cls");
                        if (confirmar == 1)
                        {
                            Inventario[encontrado].Status = 0;
                            system("CLS");
                            printf("PRODUCTO ELIMINADO\n");
                        }
                        else
                        {
                            system("CLS");
                            printf("PRODUCTO NO ELIMINADO\n");
                        }
                    }
                }
            }
            system("PAUSE");
            break;
        case 3:
            Mostrar(Inventario, i);
            break;
        case 4:
            system("cls");
            total = Total(Inventario, i);
            printf("EL VALOR TOTAL DEL INVENTARIO ES: %d\n", total);
            system("pause");
            break;
        }

    } while (op != 0);
}

TReg AgregarProducto(void)
{
    TReg elemento;
    ValiCadena(elemento.Producto, "INGRESA NOMBRE DEL PRODUCTO: ");
    system("cls");

    printf("INGRESE EL NUMERO DE PRODUCTOS: (MAXIMO 100) \n");
    elemento.Cantidad = Validar(1, 100);
    system("cls");

    printf("INGRESE EL PRECIO DEL PRODUCTO: \n");
    elemento.Precio = Validar(1, 10000000);
    system("cls");

    printf("INGRESA EL CODIGO DEL PRODUCTO: \n");
    elemento.Codigo = Validar(1, 20000);
    elemento.key = elemento.Codigo;
    system("cls");

    elemento.Status = 1;

    return elemento;
}

void Mostrar(TReg inventario[], int i)
{
    system("cls");
    int j;
    printf("|  CODIGO DE PRODUCTO  |  CANTIDAD  |  NOMBRE DE PRODUCTO  |  PRECIO  |\n");
    for (j = 0; j < i; j++)
    {
        printf("            %-4d          %5-d             %-15s     %-8d\n", inventario[j].Codigo, inventario[j].Cantidad, inventario[j].Producto, inventario[j].Precio);
    }
    system("pause");
}

int Total(TReg inventario[], int i)
{
    int j, total;
    total = 0;
    for (j = 0; j < i; j++)
    {
        total += inventario[j].Cantidad * inventario[j].Precio;
    }
    return total;
}