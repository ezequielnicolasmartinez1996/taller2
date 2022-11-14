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


nodoLegislador *inicLista(nodoLegislador *lista);
nodoLegislador *ingresarDatos(nodoLegislador *lista);
nodoLegislador *crearLegislador(legislador p);
nodoLegislador *agregarAlPrincipio(nodoLegislador *lista, nodoLegislador *nuevo);
void mostrar();
legislador retornarLegislador();

int main()
{
    nodoLegislador *lista = inicLista(lista);
    lista = ingresarDatos(lista);
    mostrar(lista);

    return 0;
}

nodoLegislador *inicLista(nodoLegislador *lista)
{
    return lista = NULL;
}

nodoLegislador *crearLegislador(legislador p)
{
    nodoLegislador *legisladorActual = (nodoLegislador *)malloc(sizeof(nodoLegislador));
    strcpy(legisladorActual->p.nombre, p.nombre);
    strcpy(legisladorActual->p.presencia, p.presencia);
    strcpy(legisladorActual->p.grupo, p.grupo);
    strcpy(legisladorActual->p.votacion, p.votacion);
    legisladorActual->siguiente = NULL;
    return legisladorActual;
}
legislador retornarLegislador()
{
    legislador p;
    printf("Ingrese nombre: \n");
    scanf("%s", p.nombre);

    printf("Ingrese voto: \n");
    scanf("%s", p.votacion);

    printf("Ingrese presencia: \n");
    scanf("%s", p.presencia);

    printf("Ingrese grupo: \n");
    scanf("%s", p.grupo);
    return p;
}

nodoLegislador *agregarAlPrincipio(nodoLegislador *lista, nodoLegislador *nuevo)
{
    if (lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}

void mostrar(nodoLegislador *lista)
{
    nodoLegislador *seguidor = lista;
    while (seguidor != NULL)
    {
        printf("Nombre: %s\n", seguidor->p.nombre);
        printf("Presente: %s\n", seguidor->p.presencia);
        printf("Grupo: %s\n", seguidor->p.grupo);
        printf("Voto: %s\n", seguidor->p.votacion);
        seguidor = seguidor->siguiente;
    }
}

nodoLegislador *ingresarDatos(nodoLegislador *lista)
{
    nodoLegislador *nuevo;
    legislador p;
    int cont = 100;
    while (cont == 100)
    {
        p = retornarLegislador(p);
        nuevo = crearLegislador(p);
        lista = agregarAlPrincipio(lista, nuevo);
        printf("Desea continuar? Ingrese 100");
        scanf("%d", &cont);
    }
    return lista;
}