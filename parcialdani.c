

/*
*   PRIMER PARCIAL
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static int id = 1;

typedef struct proceso
{
    int procesador;
    int id_proceso;
    int prioridad;
    char estado[10];
} proceso;

proceso *scheduling[30];

/* Asigna el siguiente estado según el orden enunciado antes */
void asignaEstado(proceso *);
/* Ingresa el proceso al Scheduler en el primer espacio libre que encuentre*/
void ingresaProceso();
/*Quita el proceso de la cola liberando y retornando el lugar liberado*/
int terminaProceso();
/*Recorrera todos los procesos de la cola, haciendo el cambio del estado de los mismos*/
void recorreCola();
/*Lista los procesos de la cola*/
void mostrarScheduler();

int main()
{
    int i;
    printf("Inicia el programa\n");
    printf("Simulacion del proceso para probar el scheduler\n");
    ingresaProceso();
    ingresaProceso();
    ingresaProceso();
    ingresaProceso();
    ingresaProceso();
    ingresaProceso();
    mostrarScheduler();
    recorreCola();
    mostrarScheduler();
    ingresaProceso();
    ingresaProceso();
    mostrarScheduler();
    recorreCola();
    mostrarScheduler();
    recorreCola();
    mostrarScheduler();
    recorreCola();
    mostrarScheduler();
    recorreCola();
    mostrarScheduler();
    ingresaProceso();
    ingresaProceso();
    ingresaProceso();
    mostrarScheduler();
    return 0;
}

void asignaEstado(proceso *procesoActual)
{
    if (strcmp(procesoActual->estado, "Corriendo") == 0)
    {
        strcpy(procesoActual->estado, "Terminado");
    }
    if ((strcmp(procesoActual->estado, "Listo") == 0 || strcmp(procesoActual->estado, "Nuevo") == 0) && 
    (procesoActual->procesador == 1 || procesoActual->procesador == 2))
    {
        strcpy(procesoActual->estado, "Corriendo");
    }
    if (strcmp(procesoActual->estado, "Nuevo") == 0  && procesoActual->procesador == 0)
    {
        strcpy(procesoActual->estado, "Listo");
    }
}

void ingresaProceso()
{
    int i, j, pilaLlena = 0;
    srand(time(NULL));
    for (i = 0; i < 30; i++)
    {
        if (scheduling[i] == NULL)
        {
            proceso *procesoActual = (proceso *)malloc(sizeof(proceso));
            procesoActual->procesador = 0;
            procesoActual->id_proceso = rand() % 10000;
            
            if (i != 0)
            {
                for (j = i - 1 ; j >= 0; j--)
                {
                    if (scheduling[j]->id_proceso == procesoActual->id_proceso)
                    {
                        procesoActual->id_proceso = rand() % 10000;
                        j = i;
                    }
                }
            }
            procesoActual->prioridad = id;
            strcpy(procesoActual->estado, "Nuevo");
            scheduling[i] = procesoActual;
            id++;
            break;
        }
        else
        {
            pilaLlena++;
        }
    }
    if (pilaLlena == 30)
    {
        printf("Pila del procesador llena, no se puede ingresar mas procesos\n");
    }
}

int terminaProceso()
{
    int i;
    for (i = 0; i < 30; i++)
    {
        if (scheduling[i] != NULL)
        {
            if (strcmp(scheduling[i]->estado, "Terminado") == 0)
            {
                free(scheduling[i]);
                scheduling[i] = NULL;
            }
        }
    }
    return 1;
}

void recorreCola()
{
    int i, j, procesadorUno = 0, procesadorDos = 0, prioridadUno = 0, prioridadDos = 0, a;
    a = terminaProceso();
    for (i = 0; i < 30; i++)
    {
        if (scheduling[i] != NULL)
        {
            if (scheduling[i]->procesador == 1)
            {
                procesadorUno++;
            }
            if (scheduling[i]->procesador == 2)
            {
                procesadorDos++;
            }
        }
    }
    if (procesadorUno == 0)
    {
        for (i = 0; i < 30; i++)
        {
            if (scheduling[i] != NULL)
            {
                if (strcmp(scheduling[i]->estado, "Listo") == 0 || strcmp(scheduling[i]->estado, "Nuevo") == 0)
                {
                    if (prioridadUno < scheduling[i]->prioridad)
                    {
                        prioridadUno = scheduling[i]->prioridad;
                        scheduling[i]->procesador = 1;
                        break;
                    }
                }
            }
        }
    }
    if (procesadorDos == 0)
    {
        for (i = 0; i < 30; i++)
        {
            if (scheduling[i] != NULL)
            {
                if (strcmp(scheduling[i]->estado, "Listo") == 0 || strcmp(scheduling[i]->estado, "Nuevo") == 0)
                {
                    if (prioridadDos < scheduling[i]->prioridad)
                    {
                        prioridadDos = scheduling[i]->prioridad;
                        if (scheduling[i]->procesador != 1)
                        {
                            scheduling[i]->procesador = 2;
                            break;
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < 30; i++)
    {
        if (scheduling[i] != NULL)
        {
            asignaEstado(scheduling[i]);
        }
    }
}

void mostrarScheduler()
{
    int i;
    // saber el tipo de dato que se esta mostrando
    for (i = 0; i < 30; i++)
    {
        if (scheduling[i] != NULL)
        {
            printf("[%d]-> {%d;%d;%d;%s}\n", i, scheduling[i]->procesador, scheduling[i]->id_proceso, scheduling[i]->prioridad, scheduling[i]->estado);
        }else
        {
            printf("[%d]->\n", i);
        }
    }
    printf("FIN DE UN CICLO\n");
}
