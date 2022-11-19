// PRACTICA ARCHIVOS TALLER 2 AUS
// EZEQUIEL NICOLAS MARTINEZ
// DNI: 39755509

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT_DE_PERSONAS 10
typedef struct persona
{
    char nombre[10];
    char apellido[10];
    int edad;
    char sexo[10];
    int mesesInscripto;
    char tipoPlan[10];
    int totalAPagar
} persona;
typedef struct planes
{
    char tipoPlan[10];
    int precio;
} planes;

planes *planyprecio[];
persona *inscriptos[CANT_DE_PERSONAS];
FILE *personas;
FILE *plan;
void creadorDeInscriptos(); // CREA LA LISTA DE PERSONAS INSCRIPTAS
void creadorDePlanes();     // CREA LOS PLANES Y SUS PRECIOS

int main()
{
    FILE *plan;
    FILE *personas;
    personas = fopen("./personas.txt", "w+");
    plan = fopen("./plan.txt", "w+");

    if (personas != NULL)
        printf("El archivo personas.txt se abrio correctamente\n");
    else
        printf("Hubo un error al abrir el archivo\n");
    if (plan != NULL)
        printf("El archivo plan.txt se abrio correctamente\n");
    else
        printf("Hubo un error al abrir el archivo\n");

    /**************ESCRIBE EN EL ARCHIVO PERSONAS LA LISTA DE CLIENTES*********/
    creadorDeInscriptos();
    for (int i = 0; i < CANT_DE_PERSONAS; i++)
    {
        fprintf(personas, "%s - %s - %s - %d - %s\n", inscriptos[i]->nombre, inscriptos[i]->apellido, inscriptos[i]->sexo, inscriptos[i]->edad, inscriptos[i]->tipoPlan);
    }
    /************ESCRIBE EN EL ARCHIVO LOS PLANES Y LOS PRECIOS ************/
    creadorDePlanes();
    for (int i = 0; i < 3; i++)
    {
        fprintf(plan, "%s - %d\n", planyprecio[i]->tipoPlan, planyprecio[i]->precio);
    }
    /****************ASIGNA EL VALOR SIN DESCUENTO A PAGAR A CADA PERSONA********************/
    for (int i = 0; i < CANT_DE_PERSONAS; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (strcmp(inscriptos[i]->tipoPlan, planyprecio[k]->tipoPlan) == 0)
                inscriptos[i]->totalAPagar = planyprecio[k]->precio;
        }
    }
    /**********************ESTABLECE EL DESCUENTO PARA CADA PERSONA***************/
    for (int i = 0; i < CANT_DE_PERSONAS; i++)
    {
        if (inscriptos[i]->edad<12 | inscriptos[i]->edad> 65)
            inscriptos[i]->totalAPagar = inscriptos[i]->totalAPagar - (inscriptos[i]->totalAPagar * 5 / 100);
        if (inscriptos[i]->mesesInscripto > 24)
            inscriptos[i]->totalAPagar = inscriptos[i]->totalAPagar - (inscriptos[i]->totalAPagar * 5 / 100);
    }
    /**************ESCRIBE PERSONAS.TXT CON ULTIMA COLUMNA CON DESCUENTOS************/
    for (int i = 0; i < CANT_DE_PERSONAS; i++)
    {
        fprintf(personas, "%s - %s - %s - %d - %s - %d\n", inscriptos[i]->nombre, inscriptos[i]->apellido, inscriptos[i]->sexo, inscriptos[i]->edad, inscriptos[i]->tipoPlan, inscriptos[i]->totalAPagar);
    }
    fclose(personas);
    fclose(plan);
}

void creadorDeInscriptos()
{

    char *nombres[] = {

        "Esteban",

        "Dario",

        "Mireya",

        "Nubia",

        "Gustavo",

        "Julio",

        "Carlos",

        "Helena",

        "Sebastian",

        "Nicolai",

        "Daniel",

        "Carolina",

        "Hugo",

        "Sandra",

        "Cristina",

    };
    char *apellido[] = {

        "Martinez",

        "Garcia",

        "Perez",

        "Kirchner",

        "Macri",

        "Peron",

        "Alfonsin",

        "Illia",

        "Irigoyen",

        "Manoukian",

        "Rodriguez",

        "Ramis",

        "Villar",

        "Severino",

        "Peña",

    };
    char *sexo[] = {
        "Masculino",
        "Femenino",
    };
    char *tipoPlan[] = {
        "Completo",
        "Normal",
        "Aficionado",
    };
    srand(time(NULL));
    printf("Los inscriptos creados son: \n");
    for (int i = 0; i < CANT_DE_PERSONAS; i++)
    {
        inscriptos[i] = malloc(sizeof(persona));
        strcpy(inscriptos[i]->nombre, nombres[i]);
        strcpy(inscriptos[i]->apellido, apellido[i]);
        strcpy(inscriptos[i]->sexo, sexo[rand() % 2]);
        inscriptos[i]->edad = rand() % 70 + 9;
        inscriptos[i]->mesesInscripto = rand() % 48;
        strcpy(inscriptos[i]->tipoPlan, tipoPlan[rand() % 3]);
    }
}

void creadorDePlanes()
{
    char *tipoPlan1[] = {
        "Completo",
        "Normal",
        "Aficionado",
    };
    for (int i = 0; i < 3; i++)
    {
        planyprecio[i] = malloc(sizeof(planes));
        strcpy(planyprecio[i]->tipoPlan, tipoPlan1[i]);
        if (strcmp(planyprecio[i]->tipoPlan, "Completo") == 0)
            planyprecio[i]->precio = 200;
        if (strcmp(planyprecio[i]->tipoPlan, "Normal") == 0)
            planyprecio[i]->precio = 150;
        if (strcmp(planyprecio[i]->tipoPlan, "Aficionado") == 0)
            planyprecio[i]->precio = 100;
    }
}
