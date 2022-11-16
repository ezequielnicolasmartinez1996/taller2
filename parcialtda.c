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
chicos_malos *auxmalos;
chicos_buenos *auxbuenos;

void crearLegisladores(); // CREA LOS LEGISLADORES -ok
void insertaAntes();      // INSERTA LOS LEGISLADORES EN LOS GRUPOS ANTES DEL VOTO (SEGUN CARGA DEL USUARIO)
void mostrar();           // MUESTRA LAS LISTAS ENLAZADAS
void votacion();          // SE HACE LA VOTACION: SE PREGUNTA PRESENCIA Y SU VOTO

int main()
{
    crearLegisladores();
    insertaAntes();
    mostrar();
    votacion();
    mostrar();
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
void votacion()
{
    auxmalos = malloc(sizeof(chicos_malos));
    auxmalos = chicos_Malos;
    int validar_presencia = 0;
    int validar_voto = 0;
    while (auxmalos != NULL)
    {
        validar_presencia = 0;
        printf("Ingrese presencia del legislador %s: (P O A, PRESENTE O AUSENTE)\n", auxmalos->legisladores.nombre);
        scanf("%s", auxmalos->legisladores.presencia);

        strcpy(chicos_Malos->legisladores.presencia, auxmalos->legisladores.presencia); // PRESENCIAMALOS
        while (validar_presencia != 1)
        {
            if (strcmp(auxmalos->legisladores.presencia, "P") == 0 | strcmp(auxmalos->legisladores.presencia, "A") == 0)
            {
                validar_presencia = 1;
            }
            else
            {
                printf("Ingrese correctamente el comando");
                scanf("%s", auxmalos->legisladores.presencia);
                strcpy(chicos_Malos->legisladores.presencia, auxmalos->legisladores.presencia);
            }
        }

        validar_voto = 0;
        if (strcmp(chicos_Malos->legisladores.presencia, "P") == 0) // VOTO MALOS
        {
            printf("Ingrese el voto del legislador %s: (F O D FAVORABLE/DESFAVORABLE)\n", auxmalos->legisladores.nombre);
            scanf("%s", auxmalos->legisladores.voto);
            if (strcmp(auxmalos->legisladores.voto, "F") == 0 | strcmp(auxmalos->legisladores.voto, "D") == 0)
            {
                validar_voto = 1;
            }
            else
            {
                printf("Ingrese correctamente el comando");
                scanf("%s", auxmalos->legisladores.voto);
                strcpy(chicos_Malos->legisladores.voto, auxmalos->legisladores.voto);
            }
        }
        If
        {
            strcpy(chicos_Malos->legisladores.voto, "Ausente");
        }
        auxmalos = auxmalos->siguiente;
    }

    auxbuenos = malloc(sizeof(chicos_buenos));
    auxbuenos = chicos_Buenos;
    validar_presencia = 0;
    while (auxbuenos != NULL)
    {
        validar_presencia = 0;
        printf("Ingrese presencia del legislador %s: (P O A, PRESENTE O AUSENTE)\n", auxbuenos->legisladores.nombre);
        scanf("%s", auxbuenos->legisladores.presencia);

        strcpy(chicos_Buenos->legisladores.presencia, auxbuenos->legisladores.presencia);
        while (validar_presencia != 1)
        {
            if (strcmp(auxbuenos->legisladores.presencia, "P") == 0 | strcmp(auxbuenos->legisladores.presencia, "A") == 0) // PRESENCIABUENO
            {
                validar_presencia = 1;
            }
            else
            {
                printf("Ingrese correctamente el comando");
                scanf("%s", auxbuenos->legisladores.presencia);
                strcpy(chicos_Buenos->legisladores.presencia, auxbuenos->legisladores.presencia);
            }

            validar_voto = 0; // VOTOBUENO
            if (strcmp(chicos_Buenos->legisladores.presencia, "P") == 0)
            {
                printf("Ingrese el voto del legislador %s: (F O D FAVORABLE/DESFAVORABLE)\n", auxbuenos->legisladores.nombre);
                scanf("%s", auxbuenos->legisladores.voto);
                if (strcmp(auxbuenos->legisladores.voto, "F") == 0 | strcmp(auxbuenos->legisladores.voto, "D") == 0)
                {
                    validar_voto = 1;
                }
                else
                {
                    printf("Ingrese correctamente el comando");
                    scanf("%s", auxbuenos->legisladores.voto);
                    strcpy(chicos_Buenos->legisladores.voto, auxbuenos->legisladores.voto);
                }
            }
            else
            {
                strcpy(chicos_Buenos->legisladores.voto, "Ausente");
            }
        }
        auxbuenos = auxbuenos->siguiente;
    }
}
