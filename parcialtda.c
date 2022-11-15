// PRACTICA TDA TALLER 2 AUS
// EZEQUIEL NICOLAS MARTINEZ
// DNI: 39755509

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT_LEGISLADORES 5

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
legis *legisladorActual;

chicos_malos *chicos_Malos;
chicos_buenos *chicos_Buenos;
chicos_malos *nuevos_Malos;
chicos_buenos *nuevos_Buenos;
chicos_malos *siguemalos;
chicos_buenos *siguebuenos;

void crearLegisladores(); // CREA LOS LEGISLADORES -ok
void insertaAntes();      // INSERTA LOS LEGISLADORES EN LOS GRUPOS ANTES DEL VOTO (SEGUN CARGA DEL USUARIO)
void mostrar();           // MUESTRA LAS LISTAS ENLAZADAS
void pideVotoYpres();     // PIDE AL USUARIO EL VOTO Y PRESENCIA DE LOS LEGISLADORES
// inserta();                // INSERTA LOS LEGISLADORES DESPUES DEL VOTO
// suprime();                // ELIMINA LOS LEGISLADORES DE LOS GRUPOS DESPUES DEL VOTO
// miembro();                // DEVUELVE BOOLEANO SEGUN PRESENCIA

int main()
{
    crearLegisladores();
    insertaAntes();
    mostrar();
    pideVotoYpres();
}

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
}
void insertaAntes()
{
    chicos_Malos = malloc(sizeof(chicos_malos));
    chicos_Buenos = malloc(sizeof(chicos_buenos));
    nuevos_Malos = malloc(sizeof(chicos_malos));
    nuevos_Buenos = malloc(sizeof(chicos_buenos));
    // ubicar a los legisladores en sus grupos antes de la votacion (InsertaAntes)
    nuevos_Malos->siguiente = NULL;  // EL primero apunta a NULL
    nuevos_Buenos->siguiente = NULL; // El primero apunta a NULL
    chicos_Malos = NULL;
    chicos_Buenos = NULL;

    for (int i = 0; i < CANT_LEGISLADORES; i++)
    {
        if (strcmp("M", legisladores[i]->grupo) == 0)
        {
            nuevos_Malos = malloc(sizeof(chicos_malos));

            // printf("El legislador %s pertenece al grupo Chicos Malos\n", legisladores[i]->nombre);
            strcpy(nuevos_Malos->legisladores.nombre, legisladores[i]->nombre);
            strcpy(nuevos_Malos->legisladores.grupo, legisladores[i]->grupo);
            if (nuevos_Malos->siguiente = NULL)
            {
                nuevos_Malos->siguiente = NULL;
                chicos_Malos = nuevos_Malos;
            }
            else
            {
                nuevos_Malos->siguiente = chicos_Malos;
                chicos_Malos = nuevos_Malos;
            }
        }

        if (strcmp("B", legisladores[i]->grupo) == 0)
        {
            nuevos_Buenos = malloc(sizeof(chicos_buenos));

            // printf("El legislador %s pertenece al grupo Chicos Buenos\n", legisladores[i]->nombre);
            strcpy(nuevos_Buenos->legisladores.nombre, legisladores[i]->nombre);
            strcpy(nuevos_Buenos->legisladores.grupo, legisladores[i]->grupo);
            if (nuevos_Buenos->siguiente = NULL)
            {
                nuevos_Buenos->siguiente = NULL;
                chicos_Buenos = nuevos_Buenos;
            }
            else
            {
                nuevos_Buenos->siguiente = chicos_Buenos;
                chicos_Buenos = nuevos_Buenos;
            }
        }
    }
}
void mostrar()
{
    chicos_malos *siguemalos = malloc(sizeof(chicos_malos));
    siguemalos = chicos_Malos;
    while (siguemalos != NULL)
    {
        printf("Nombre: %s\n", siguemalos->legisladores.nombre);
        printf("Presente: %s\n", siguemalos->legisladores.presencia);
        if (strcmp("M", siguemalos->legisladores.grupo) == 0)
        {
            printf("Grupo: chicos_malos\n");
        }
        printf("Voto: %s\n", siguemalos->legisladores.voto);
        siguemalos = siguemalos->siguiente;
    }

    chicos_buenos *siguebuenos = malloc(sizeof(chicos_buenos));
    siguebuenos = chicos_Buenos;
    while (siguebuenos != NULL)
    {
        printf("Nombre: %s\n", siguebuenos->legisladores.nombre);
        printf("Presente: %s\n", siguebuenos->legisladores.presencia);
        if (strcmp("B", siguebuenos->legisladores.grupo) == 0)
        {
            printf("Grupo: chicos_buenos\n");
        }

        printf("Voto: %s\n", siguebuenos->legisladores.voto);
        siguebuenos = siguebuenos->siguiente;
    }
}

void pideVotoYpres()
{
    chicos_malos *siguemalos = malloc(sizeof(chicos_malos));
    siguemalos = chicos_Malos;
    int valvoto = 0;
    int valpresencia = 0;

    /**************INGRESAR VOTO Y PRESENCIA A CADA LEGISLADOR***************/
    while (siguemalos != NULL)
    {
        printf("Inserta el VOTO del legislador %s (D O F // DESFAVORABLE O FAVORABLE) \n", siguemalos->legisladores.nombre);
        scanf("%s", siguemalos->legisladores.voto);
        while (valvoto != 1) // CHECK DE INFORMACION INTRODUCIDA
        {
            if (strcmp(siguemalos->legisladores.voto, "D") == 0 || strcmp(siguemalos->legisladores.voto, "F") == 0)
            {
                valvoto = 1;
            }
            else
            {
                printf("Ingrese nuevamente el comando\n");
                scanf("%s", siguemalos->legisladores.voto);
            }
        }
    }
    /*  if (strcmp(chicos_Malos->legisladores.grupo, "M") == 0)
      {
          strcpy(chicos_Malos->legisladores.voto, legisladorActual->voto);
      }

    printf("Inserta el PRESENTISMO del legislador %s (P o A //PRESENTE O AUSENTE) \n", siguemalos->legisladores.nombre);
    scanf("%s", legisladorActual->presencia);

    while (valpresencia != 1) // CHECK DE INFORMACION INTRODUCIDA
    {
        if (strcmp(legisladorActual->presencia, "P") == 0 || strcmp(legisladorActual->presencia, "A") == 0)
        {
            valpresencia = 1;
        }
        else
        {
            (strcmp(legisladorActual->presencia, "P") != 0 || strcmp(legisladorActual->presencia, "A") != 0);
            printf("Ingrese nuevamente el comando\n");
            scanf("%s", legisladorActual->presencia);
        }
*/
    /*******************************ASIGNAR Y MOSTRAR DATOS COMPLETOS DE CADA LEGISLADOR**********************************/
    siguemalos = malloc(sizeof(chicos_malos));
    siguemalos = chicos_Malos;
    while (siguemalos != NULL)
    {
        printf("Nombre: %s\n", siguemalos->legisladores.nombre);
        printf("Presente: %s\n", siguemalos->legisladores.presencia);
        if (strcmp("M", siguemalos->legisladores.grupo) == 0)
        {
            printf("Grupo: chicos_malos\n");
        }
        printf("Voto: %s\n", siguemalos->legisladores.voto);
        siguemalos = siguemalos->siguiente;
    }

    siguebuenos = malloc(sizeof(chicos_buenos));
    siguebuenos = chicos_Buenos;
    while (siguebuenos != NULL)
    {
        printf("Nombre: %s\n", siguebuenos->legisladores.nombre);
        printf("Presente: %s\n", siguebuenos->legisladores.presencia);
        if (strcmp("B", siguebuenos->legisladores.grupo) == 0)
        {
            printf("Grupo: chicos_buenos\n");
        }

        printf("Voto: %s\n", siguebuenos->legisladores.voto);
        siguebuenos = siguebuenos->siguiente;
    }
}


/*
/**************** LEGISLADOR 1**************
if (strcmp("M", legisladores[0]->grupo) == 0)
{
    nuevos_Malos = malloc(sizeof(chicos_malos));

    printf("El legislador %s pertenece al grupo Chicos Malos\n", legisladores[0]->nombre);
    strcpy(nuevos_Malos->legisladores.nombre, legisladores[0]->nombre);
    strcpy(nuevos_Malos->legisladores.grupo, legisladores[0]->grupo);
    nuevos_Malos->siguiente = NULL;
    chicos_Malos = nuevos_Malos;
}

/**************** LEGISLADOR 2**************
if (strcmp("M", legisladores[1]->grupo) == 0)
{
    nuevos_Malos = malloc(sizeof(chicos_malos));

    printf("El legislador %s pertenece al grupo Chicos Malos\n", legisladores[1]->nombre);
    strcpy(nuevos_Malos->legisladores.nombre, legisladores[1]->nombre);
    strcpy(nuevos_Malos->legisladores.grupo, legisladores[1]->grupo);
    nuevos_Malos->siguiente = chicos_Malos;
    chicos_Malos = nuevos_Malos;
}

/**************** LEGISLADOR 3**************
if (strcmp("M", legisladores[2]->grupo) == 0)
{
    nuevos_Malos = malloc(sizeof(chicos_malos));

    printf("El legislador %s pertenece al grupo Chicos Malos\n", legisladores[2]->nombre);
    strcpy(nuevos_Malos->legisladores.nombre, legisladores[2]->nombre);
    strcpy(nuevos_Malos->legisladores.grupo, legisladores[2]->grupo);
    nuevos_Malos->siguiente = chicos_Malos;
    chicos_Malos = nuevos_Malos;
}

/**************** LEGISLADOR 4**************
if (strcmp("M", legisladores[3]->grupo) == 0)
{
    nuevos_Malos = malloc(sizeof(chicos_malos));

    printf("El legislador %s pertenece al grupo Chicos Malos\n", legisladores[3]->nombre);
    strcpy(nuevos_Malos->legisladores.nombre, legisladores[3]->nombre);
    strcpy(nuevos_Malos->legisladores.grupo, legisladores[3]->grupo);
    nuevos_Malos->siguiente = chicos_Malos;
    chicos_Malos = nuevos_Malos;
}
*/

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
/*
if (strcmp("B", legisladores[i]->grupo) == 0)
{
nuevos_Buenos = malloc(sizeof(chicos_buenos));
printf("El legislador %s pertenece al grupo Chicos Buenos\n", legisladores[i]->nombre);
strcpy(nuevos_Buenos->legisladores.nombre, legisladores[i]->nombre);
nuevos_Buenos->siguiente = NULL; // El primero apunta a NULL
}
*/
