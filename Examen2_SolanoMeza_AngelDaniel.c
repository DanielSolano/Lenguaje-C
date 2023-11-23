#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _mascotas
{
    char nombre[50];
    int edad;
    char raza[30];
} Mascotas;

int msges();
void menu();
Mascotas AgregarMascotas(void);

int main()
{
    menu();
    return 0;
}
//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************
int msges()
{
    int op;
    system("CLS");
    printf("   M  E   N   U \n");
    printf("1.- AGREGAR REGISTRO \n");
    printf("2.- ACTUALIZAR REGISTRO \n");
    printf("3.- MOSTRAR REGISTRO \n");
    printf("4.- CREAR ARCHIVO \n");
    printf("5.- CARGAR ARCHIVO \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//****************
void menu()
{
    Mascotas VectorMascotas[100], reg;
    int op, i = 0;
    LeerTXT(&i, VectorMascotas);
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            system("cls");
            reg = AgregarMascotas();
            VectorMascotas[i++] = reg;
            system("cls");
            break;
        case 2:
            system("cls");
            BusquedaActualizar(VectorMascotas, i);
            system("pause");
            break;
        case 3:
            system("cls");
            Mostrar(VectorMascotas, i);
            system("pause");
            break;
        case 0:
            CrearTXT(VectorMascotas, i);
            break;
        }
    } while (op != 0);
}

Mascotas AgregarMascotas(void)
{
    Mascotas reg;
    printf("NOMBRE DE LA MASCOTA: ");
    fflush(stdin);
    gets(reg.nombre);
    printf("EDAD DE LA MASCOTA: ");
    fflush(stdin);
    scanf("%d", &reg.edad);
    printf("RAZA DE LA MASCOTA: ");
    fflush(stdin);
    gets(reg.raza);

    return reg;
}

void BusquedaActualizar(Mascotas vect[], int n)
{
    char nombre[50];
    printf("INGRESA EL NOMBRE DE LA MASCOTA A BUSCAR: ");
    fflush(stdin);
    gets(nombre);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(nombre, vect[i].nombre) == 0)
        {
            printf("NOMBRE DE LA MASCOTA: %s\n", vect[i].nombre);
            printf("EDAD DE LA MASCOTA: %d\n", vect[i].edad);
            printf("RAZA DE LA MASCOTA: %s\n", vect[i].raza);
            system("pause");
            system("cls");
            printf("EDITAR REGISTRO\n");
            printf("NOMBRE DE LA MASCOTA: ");
            fflush(stdin);
            gets(vect[i].nombre);
            printf("EDAD DE LA MASCOTA: ");
            fflush(stdin);
            scanf("%d", &vect[i].edad);
            printf("RAZA DE LA MASCOTA: ");
            fflush(stdin);
            gets(vect[i].raza);
            break;
        }
    }
}

void Mostrar(Mascotas vect[], int n)
{
    char nombre[50];
    printf("INGRESA EL NOMBRE DE LA MASCOTA A BUSCAR: ");
    fflush(stdin);
    gets(nombre);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(nombre, vect[i].nombre) == 0)
        {
            printf("NOMBRE DE LA MASCOTA: %s\n", vect[i].nombre);
            printf("EDAD DE LA MASCOTA: %d\n", vect[i].edad);
            printf("RAZA DE LA MASCOTA: %s\n", vect[i].raza);
            system("pause");
            system("cls");
        }
    }
}

void CrearTXT(Mascotas vect[], int n)
{
    FILE *fa;
    fa = fopen("historial.txt", "w");
    for (int j = 0; j < n; j++)
    {
        fprintf(fa, "%s %d %s", vect[j].nombre, vect[j].edad, vect[j].raza);
    }
    fclose(fa);
}

void LeerTXT(int *i, Mascotas vect[])
{
    FILE *fa;
    Mascotas reg;
    fa = fopen("historial.txt", "r");
    if (fa)
    {
        do
        {
            fscanf(fa, "%s %d %s", &reg.nombre, &reg.edad, &reg.raza);
            vect[(*i)++] = reg;
        } while (!feof(fa));
        fclose(fa);
    }
}
