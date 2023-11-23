/*
Nombre del archivo: Practica8_SistemaMejoradoGestionInventarioStructs_SolanoMeza_AngelDaniel.cpp.c
Autor: Solano Meza Angel Daniel
Fecha de creación: 22 de Noviembre de 2023
Descripción: Este archivo contiene el código principal de mi programa.
*/
#include "junior.h"
#define N 100
#define MAX 1000
int msges();
void menu();
void Mostrar(TReg inventario[], int i);
int Total(TReg inventario[], int i);
int CrearBIN(TReg vect[], int i, char nombre[]);
int CargarBIN(TReg vect[], int *i, char nombre[], int *elementos, int max);
TReg AgregarProducto(void);
void NombreArch(char archivo[]);

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
    printf("5.- ORDENAR \n");
    printf("6.- CREAR ARCHIVO \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}

void menu()
{
    int op, i, total, apagar, encontrado, confirmar, elementos, ordenar;
    char archivo[30];
    TReg Inventario[N];
    TReg producto;
    i = 0;
    elementos = 0;
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
                producto.key = Validar(1, 1000);
                producto.Codigo = producto.key;
            }
            elementos += producto.Cantidad;
            if (elementos <= N)
            {
                Inventario[i++] = producto;
                printf("PRODUCTO AGREGADO AL INVENTARIO\n");
            }
            else
            {
                elementos -= producto.Cantidad;
                printf("CANTIDAD DE ELEMENTOS SOBREPASAN LA CAPACIDAD\n");
            }
            system("pause");
            break;
        case 2:
            system("CLS");
            if (elementos == 0)
            {
                printf("INVENTARIO VACIO\n");
            }
            else
            {

                printf("CODIGO DE PRODUCTO A RETIRAR\n");
                apagar = Validar(1, 2000);
                encontrado = BusquedaTReg(Inventario, i, apagar);
                if (encontrado == -1)
                {
                    printf("CODIGO DE PRODUCTO NO EXISTE\n");
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
                            elementos -= Inventario[encontrado].Cantidad;
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
            system("cls");
            if (elementos == 0)
            {
                printf("INVENTARIO VACIO\n");
            }
            else
            {
                Mostrar(Inventario, i);
            }
            system("pause");
            break;
        case 4:
            system("cls");
            if (elementos == 0)
            {
                printf("INVENTARIO VACIO\n");
            }
            else
            {
                total = Total(Inventario, i);
                printf("EL VALOR TOTAL DEL INVENTARIO ES: %d\n", total);
            }
            system("pause");
            break;
        case 5:
            system("cls");
            printf("SELECCIONE CAMPO POR EL CUAL ORDENAR: \n1. CODIGO DE PRODUCTO\n2. CANTIDAD DE PRODUCTO\n3. PRECIO DEL PRODUCTO\n");
            ordenar = Validar(1, 3);
            switch (ordenar)
            {
            case 1:
                for (int j = 0; j < i; j++)
                {
                    Inventario[j].key = Inventario[j].Codigo;
                }
                OrdenarTReg(Inventario, i);
                printf("INVENTARIO ORDENADO POR CODIGO DE PRODUCTO\n");
                break;
            case 2:
                for (int j = 0; j < i; j++)
                {
                    Inventario[j].key = Inventario[j].Cantidad;
                }
                OrdenarTReg(Inventario, i);
                for (int j = 0; j < i; j++)
                {
                    Inventario[j].key = Inventario[j].Codigo;
                }
                printf("INVENTARIO ORDENADO POR CANTIDAD DE PRODUCTO\n");
                break;
            case 3:
                for (int j = 0; j < i; j++)
                {
                    Inventario[j].key = Inventario[j].Precio;
                }
                OrdenarTReg(Inventario, i);
                for (int j = 0; j < i; j++)
                {
                    Inventario[j].key = Inventario[j].Codigo;
                }
                printf("INVENTARIO ORDENADO POR PRECIO DEL PRODUCTO\n");
                break;
            }
            system("pause");
            break;
        case 6:
            system("cls");
            NombreArch(archivo);
            if (CrearBIN(Inventario, elementos, archivo))
            {
                printf("ARCHIVO CREADO CON EXITO\n");
            }
            system("pause");
            break;
        }

    } while (op != 0);
}
/*
Función: AgregarProducto
Descripción: Esta función genera un registro de producto.
Parámetros: Void
Valor de retorno: Un registro llenado.
*/
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
/*
Función: Mostrar
Descripción: Esta función muestra los registros de productos.
Parámetros: Void
Valor de retorno: Void.
*/
void Mostrar(TReg inventario[], int i)
{
    int j;
    printf("|  CODIGO DE PRODUCTO  |  CANTIDAD  |  NOMBRE DE PRODUCTO  |  PRECIO  |\n");
    for (j = 0; j < i; j++)
    {
        if (inventario[j].Status == 1)
        {
            printf("            %-4d          %5-d             %-15s     %-8d\n", inventario[j].Codigo, inventario[j].Cantidad, inventario[j].Producto, inventario[j].Precio);
        }
    }
}
/*
Función: Total
Descripción: Esta función Calcula el valor total del inventario.
Parámetros: Vector de registros e indice que indica hasta donde se lleno el vector
Valor de retorno: Total del valor de los registros
*/
int Total(TReg inventario[], int i)
{
    int j, total;
    total = 0;
    for (j = 0; j < i; j++)
    {
        if (inventario[j].Status == 1)
        {
            total += inventario[j].Cantidad * inventario[j].Precio;
        }
    }
    return total;
}
/*
Función: CrearBin
Descripción: Esta función crea un archivo binario.
Parámetros: Vector de registros, indice que indica hasta donde se lleno el vector y nombre del archivo
Valor de retorno: Void, solo crea el archivo en output
*/
int CrearBIN(TReg vect[], int n, char nom[])
{
    char archivo[30];
    strcpy(archivo, nom);
    TReg reg;
    int i;
    strcat(archivo, ".dll");
    FILE *fa;
    fa = fopen(archivo, "ab");
    for (i = 0; i < n; i++)
    {
        reg = vect[i];
        fwrite(&reg, sizeof(TReg), 1, fa);
    }
    fclose(fa);
    return 1;
}

void NombreArch(char archivo[])
{

    system("CLS");
    printf("NOMBRE DEL ARCHIVO SIN EXTENSION: \n");
    fflush(stdin);
    gets(archivo);
}
