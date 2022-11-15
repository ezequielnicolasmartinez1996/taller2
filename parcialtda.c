// PRACTICA TDA TALLER 2 AUS
// EZEQUIEL NICOLAS MARTINEZ
// DNI: 39755509

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT_LEGISLADORES 4

typedef struct legis
{
    char nombre[15];
    char voto[10];
    char presencia[10];
    char grupo[10]; // Grupo al que pertenecen antes de votar
} legis;

typedef struct chicos_malos
{
    legis legisladores;
    struct chicos_malos *siguiente;
} chicos_malos;

typedef struct chicos_buenos
{
    legis legisladores;
    struct chicos_buenos *siguiente;
} chicos_buenos;

legis *legisladores[CANT_LEGISLADORES];

void crearLegisladores(); // CREA LOS LEGISLADORES -ok
// insertaAntes();           // INSERTA LOS LEGISLADORES EN LOS GRUPOS ANTES DEL VOTO (SEGUN CARGA DEL USUARIO)
// inserta();                // INSERTA LOS LEGISLADORES DESPUES DEL VOTO
// suprime();                // ELIMINA LOS LEGISLADORES DE LOS GRUPOS DESPUES DEL VOTO
// miembro();                // DEVUELVE BOOLEANO SEGUN PRESENCIA
// mostrar();                // MUESTRA LAS LISTAS ENLAZADAS

int main()
{
    crearLegisladores();
    chicos_malos *chicos_Malos = malloc(sizeof(chicos_malos));
    chicos_buenos *chicos_Buenos = malloc(sizeof(chicos_buenos));
    chicos_malos *nuevos_Malos = malloc(sizeof(chicos_malos));
    chicos_buenos *nuevos_Buenos = malloc(sizeof(chicos_buenos));

    // ubicar a los legisladores en sus grupos antes de la votacion (InsertaAntes)
    nuevos_Malos->siguiente = NULL;  // EL primero apunta a NULL
    nuevos_Buenos->siguiente = NULL; // El primero apunta a NULL

    /**************** LEGISLADOR 1**************/
    if (strcmp("M", legisladores[0]->grupo) == 0)
    {
        nuevos_Malos = malloc(sizeof(chicos_malos));

        printf("El legislador %s pertenece al grupo Chicos Malos\n", legisladores[0]->nombre);
        strcpy(nuevos_Malos->legisladores.nombre, legisladores[0]->nombre);
        strcpy(nuevos_Malos->legisladores.grupo, legisladores[0]->grupo);
        nuevos_Malos->siguiente = NULL;
        chicos_Malos = nuevos_Malos;
    }

    /**************** LEGISLADOR 2**************/
    if (strcmp("M", legisladores[1]->grupo) == 0)
    {
        nuevos_Malos = malloc(sizeof(chicos_malos));

        printf("El legislador %s pertenece al grupo Chicos Malos\n", legisladores[1]->nombre);
        strcpy(nuevos_Malos->legisladores.nombre, legisladores[1]->nombre);
        strcpy(nuevos_Malos->legisladores.grupo, legisladores[1]->grupo);
        nuevos_Malos->siguiente = chicos_Malos;
        chicos_Malos = nuevos_Malos;
    }

    /**************** LEGISLADOR 3**************/
    if (strcmp("M", legisladores[2]->grupo) == 0)
    {
        nuevos_Malos = malloc(sizeof(chicos_malos));

        printf("El legislador %s pertenece al grupo Chicos Malos\n", legisladores[2]->nombre);
        strcpy(nuevos_Malos->legisladores.nombre, legisladores[2]->nombre);
        strcpy(nuevos_Malos->legisladores.grupo, legisladores[2]->grupo);
        nuevos_Malos->siguiente = chicos_Malos;
        chicos_Malos = nuevos_Malos;
    }

        /**************** LEGISLADOR 4**************/
    if (strcmp("M", legisladores[3]->grupo) == 0)
    {
        nuevos_Malos = malloc(sizeof(chicos_malos));

        printf("El legislador %s pertenece al grupo Chicos Malos\n", legisladores[3]->nombre);
        strcpy(nuevos_Malos->legisladores.nombre, legisladores[3]->nombre);
        strcpy(nuevos_Malos->legisladores.grupo, legisladores[3]->grupo);
        nuevos_Malos->siguiente = chicos_Malos;
        chicos_Malos = nuevos_Malos;
    }

    chicos_malos *siguemalos = malloc(sizeof(chicos_malos));
    siguemalos = chicos_Malos;
    while (siguemalos != NULL)
    {
        printf("Nombre: %s\n", siguemalos->legisladores.nombre);
        printf("Presente: %s\n", siguemalos->legisladores.presencia);
        printf("Grupo: %s\n", siguemalos->legisladores.grupo);
        printf("Voto: %s\n", siguemalos->legisladores.voto);
        siguemalos = siguemalos->siguiente;
    }
}
/*
if (strcmp("B", legisladores[i]->grupo) == 0)
{
    nuevos_Buenos = malloc(sizeof(chicos_buenos));
    printf("El legislador %s pertenece al grupo Chicos Buenos\n", legisladores[i]->nombre);
    strcpy(nuevos_Buenos->legisladores.nombre, legisladores[i]->nombre);
    nuevos_Buenos->siguiente = NULL; // El primero apunta a NULL
}
*/

// recorrer chicos_malos

void crearLegisladores()
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
    printf("Ingreso de lista de Legisladores y sus grupos antes de la votacion\n");
    for (int i = 0; i < CANT_LEGISLADORES; i++)
    {
        printf("Legislador %s, %d de %d\n", nombres[i], i + 1, CANT_LEGISLADORES);
        legis *legisladorActual = malloc(sizeof(legis));

        // nombre
        strcpy(legisladorActual->nombre, nombres[i]);

        printf("Ingrese el grupo del legislador %s (M o B -- Malos/Buenos)\n", nombres[i]);
        scanf("%s", legisladorActual->grupo);
        int valgrupo = 0;
        while (valgrupo != 1) // CHECK DE INFORMACION INTRODUCIDA
        {
            if (strcmp(legisladorActual->grupo, "M") == 0 || strcmp(legisladorActual->grupo, "B") == 0)
            {
                valgrupo = 1;
            }
            else
            {
                (strcmp(legisladorActual->grupo, "M") != 0 || strcmp(legisladorActual->grupo, "B") != 0);
                printf("Ingrese nuevamente el comando\n");
                scanf("%s", legisladorActual->grupo);
            }
        }

        legisladores[i] = legisladorActual;
    }

    printf("Los datos ingresados para cada legislador son:\n");

    for (int i = 0; i < CANT_LEGISLADORES; i++)
    {
        // printf("El nombre del legislador %s:, %s\n", nombres[i], legisladores[i]->nombre);

        printf("El grupo del legislador %s:, %s\n", nombres[i], legisladores[i]->grupo);

        // printf("El presentismo del legislador %s:, %s\n", nombres[i], legisladores[i]->presencia);
    }
}

/*VOTACION()
{
    legis *legisladorActual = malloc(sizeof(legis));
    for (int i = 0; i < CANT_LEGISLADORES; i++)
    {
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
    }
}

insertaAntes()
{
}
inserta()
{
}
suprime()
{
}
miembro()
{
}
mostrar()
{
} */