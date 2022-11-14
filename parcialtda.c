// PRACTICA TDA TALLER 2 AUS
// EZEQUIEL NICOLAS MARTINEZ
// DNI: 39755509

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT_LEGISLADORES 3

typedef struct legis
{
    char nombre[100];
    char voto[100];
    char presencia[100];
} legis;

typedef struct chicos_malos
{
    legis m;
    struct chicos_malos *siguiente;
} chicos_malos;

typedef struct chicos_buenos
{
    legis b;
    struct chicos_buenos *siguiente;
} chicos_buenos;

legis *legisladores[CANT_LEGISLADORES];

void crearLegisladores(); // CREA LOS LEGISLADORES
inserta(); //INSERTA LOS LEGISLADORES EN LOS GRUPOS
suprime(); //ELIMINA LOS LEGISLADORES DE LOS GRUPOS
miembro(); //DEVUELVE BOOLEANO SEGUN PRESENCIA
mostrar(); //MUESTRA LAS LISTAS ENLAZADAS

int main()
{
   crearLegisladores();
    return 0;
}

void crearLegisladores(){
     char *nombres[] = {

        "Esteban",

        "Dario",

        "Mireya",

        "Nubia",

        "Gustavo Adolfo",

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

    for (int i = 0; i < CANT_LEGISLADORES; i++)
    {
        printf("Legislador %d de %d\n", i+1, CANT_LEGISLADORES);
        legis *legisladorActual = malloc(sizeof(legis));

        // nombre
        strcpy(legisladorActual->nombre, nombres[i]);

        // voto
        printf("Ingrese el voto del legislador %s (F o D -- Favorable/Desfavorable)\n", nombres[i]);
        scanf("%s", legisladorActual->voto);
        int valvoto = 0;
        while (valvoto != 1) // CHECK DE INFORMACION INTRODUCIDA
        {
            if (strcmp(legisladorActual->voto, "F") == 0 || strcmp(legisladorActual->voto, "D") == 0)
            {
                valvoto = 1;
            }
            else
            {
                (strcmp(legisladorActual->voto, "F") != 0 || strcmp(legisladorActual->voto, "D") != 0);

                    printf("Ingrese nuevamente el comando\n");
                scanf("%s", legisladorActual->voto);
            }
        }

        // presencia

        printf("Ingrese presentismo del legislador %s (P o A -- Presente/Ausente)\n", nombres[i]);
        scanf("%s", legisladorActual->presencia);
        int valpresencia = 0;
        while (valpresencia != 1) // CHECK DE INFORMACION INTRODUCIDA
        {

            if (strcmp(legisladorActual->presencia, "P") == 0 || strcmp(legisladorActual->presencia, "A") == 0)
            {
                valpresencia = 1;
            }
            else
            {
                printf("Ingrese nuevamente el comando\n");
                scanf("%s", legisladorActual->presencia);
            }
        }

        legisladores[i] = legisladorActual;

        printf("El nombre del legislador %s:, %s\n", nombres[i], legisladores[i]->nombre);

        printf("El voto del legislador %s:, %s\n", nombres[i], legisladores[i]->voto);

        printf("El presentismo del legislador %s:, %s\n", nombres[i], legisladores[i]->presencia);
    }

}