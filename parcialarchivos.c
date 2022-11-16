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
    char tipoPlan[10]
} persona;

persona *inscriptos[CANT_DE_PERSONAS];
FILE *personas;
FILE *plan;
void creadorDeInscriptos(); // CREA LA LISTA DE PERSONAS INSCRIPTAS
void creaYAbreArchivos();   // CREA LOS ARCHIVOS PERSONA.TXT Y PLAN.TXT
void escribeArchivos();     // ESCRIBE EN LOS ARCHIVOS LOS DATOS NECESARIOS

int main()
{
    FILE *personas;
    personas = fopen("./personas.txt", "w+");
    if (personas != NULL)
    {
        printf("El archivo personas.txt se abrio correctamente\n");
    }
    else
    {
        printf("Hubo un error al abrir el archivo\n");
    }

    FILE *plan;
    plan = fopen("./plan.txt", "w+");
    if (plan != NULL)
    {
        printf("El archivo plan.txt se abrio correctamente\n");
    }
    else
    {
        printf("Hubo un error al abrir el archivo\n");
    }
    srand(time(NULL));
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

    persona *inscriptos = malloc(sizeof(persona) * CANT_DE_PERSONAS);
    printf("Los inscriptos creados son: \n");
    for (int i = 0; i < CANT_DE_PERSONAS; i++)
    {
        strcpy(inscriptos[i].nombre, nombres[i]);
        strcpy(inscriptos[i].apellido, apellido[i]);
        strcpy(inscriptos[i].sexo, sexo[rand() % 2]);
        inscriptos[i].edad = rand() % 60 + 15;
        inscriptos[i].mesesInscripto = rand() % 24;
        strcpy(inscriptos[i].tipoPlan, tipoPlan[rand() % 3]);
    }
    for (int i = i; i < CANT_DE_PERSONAS; i++)
    {
        printf("%s - %s - %s - %d - %s\n", inscriptos[i].nombre, inscriptos[i].apellido, inscriptos[i].sexo, inscriptos[i].edad, inscriptos[i].tipoPlan);
    }

    for (int i = 0; i < CANT_DE_PERSONAS; i++)
    {
        fprintf(personas, "%s - %s - %s - %d - %s\n", inscriptos[i].nombre, inscriptos[i].apellido, inscriptos[i].sexo, inscriptos[i].edad, inscriptos[i].tipoPlan);
    }
}