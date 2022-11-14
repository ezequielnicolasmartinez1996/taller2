// PRACTICA TDA TALLER 2 AUS
// EZEQUIEL NICOLAS MARTINEZ
// DNI: 39755509

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct legislador
{
    char nombre[10];
    char votacion[15];
    char presencia[15];
    char grupo[15];
} legislador;

typedef struct nodoLegislador
{
    legislador p;
    struct nodoLegislador *siguiente;
} nodoLegislador;

int main()
{
    nodoLegislador *inicioLista = NULL;
    nodoLegislador *primerLegislador = (nodoLegislador *)malloc(sizeof(nodoLegislador));

    strcpy(primerLegislador->p.nombre, "J.D.Peron");
    strcpy(primerLegislador->p.presencia, "Presente");
    strcpy(primerLegislador->p.grupo, "ChicosMalos");
    strcpy(primerLegislador->p.votacion, "Afirmativo");
    primerLegislador->siguiente = NULL;

    inicioLista = primerLegislador;

    primerLegislador = (nodoLegislador *)malloc(sizeof(nodoLegislador));

    strcpy(primerLegislador->p.nombre, "E.M.Peron");
    strcpy(primerLegislador->p.presencia, "Presente");
    strcpy(primerLegislador->p.grupo, "ChicosBuenos");
    strcpy(primerLegislador->p.votacion, "Negativo");
    primerLegislador->siguiente = NULL;

    primerLegislador->siguiente = inicioLista;
    inicioLista = primerLegislador;

    primerLegislador = (nodoLegislador *)malloc(sizeof(nodoLegislador));

    strcpy(primerLegislador->p.nombre, "C.F.K");
    strcpy(primerLegislador->p.presencia, "Presente");
    strcpy(primerLegislador->p.grupo, "ChicosMalos");
    strcpy(primerLegislador->p.votacion, "Afirmativo");
    primerLegislador->siguiente = NULL;

    primerLegislador->siguiente = inicioLista;
    inicioLista = primerLegislador;
    /************************************************************************/

    nodoLegislador *seguidor = inicioLista;

    while (seguidor != NULL)
    {
        printf("Nombre: %s\n", seguidor->p.nombre);
        printf("Presente: %s\n", seguidor->p.presencia);
        printf("Grupo: %s\n", seguidor->p.grupo);
        printf("Voto: %s\n", seguidor->p.votacion);
        seguidor = seguidor->siguiente;
    }
    /************************************************************************/
    return 0;
}
