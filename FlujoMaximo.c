#include <limits.h>
#include <string.h>
#include "tail.h"

#define V 6
#define true 1
#define false 0
#define min (X, Y)(((X) < (Y)) ? (X) : (Y))


// cf = red residual (capacidad -  flujo)
int Grafo_aux[V][V];

int semicamino[V];

int red[V][V] = {{0, 4, 6, 0, 0, 0},
                 {0, 0, 0, 3, 5, 0},
                 {0, 0, 0, 0, 6, 0},
                 {0, 0, 9, 0, 0, 5},
                 {0, 0, 0, 0, 0, 4},
                 {0, 0, 0, 0, 0, 0}};

int busqueda_camino(int red_aux[V][V], int s, int t, int semicamino[])
{

    int visitado[V];
    memset(visitado, 0, sizeof(visitado));
    memset(semicamino, 0, sizeof(V));

    printf("procesamiento \n");
    struct nodo *vertice = NULL;
    encola(&vertice, s);
    visitado[s] = 1;
    int aristasEnSemicamino = 0;
    int verticeOrigen = 0;
    while ((esta_vacia(&vertice)) == false)
    {
        int temp = desencola(&vertice);
        printf("vertice a analizar : %d \n", temp);

        for (int i = 0; i < V; i++)
        {
            if (red[temp][i] != 0 && visitado[i] == 0 && Grafo_aux[temp][i] != 0)
            {
                verticeOrigen = temp;
                semicamino[verticeOrigen] = i;
                printf("vertice adyacente encontrado : %d \n", i);
                visitado[i] = 1;
                aristasEnSemicamino++;
                Grafo_aux[verticeOrigen][i] = Grafo_aux[verticeOrigen][i] - red[verticeOrigen][i];
                encola(&vertice, i);
                break;
            }
        }
    }

    printf("ultimo vertice del semicamino hallado : %d \n", verticeOrigen);

    if (visitado[t] == true)
    {
        int j = t;
        int flujoMenor = 0;
        int verticeAnterior = 0;

        while (j != 0)
        {

            int k = 0;
            while (semicamino[k] != verticeOrigen)
            {
                k++;
            }

            verticeAnterior = k;

            if (flujoMenor == 0)
            {
                flujoMenor = red[semicamino[verticeAnterior]][semicamino[verticeOrigen]];
            }

            if (red[verticeAnterior][verticeOrigen] < flujoMenor && red[verticeAnterior][verticeOrigen] != 0)
            {
                flujoMenor = red[verticeAnterior][verticeOrigen];
                printf("flujo menor : %d \n", flujoMenor);
            }

            verticeOrigen = verticeAnterior;
            j = semicamino[verticeAnterior];
        }

        printf("flujo posible encontrado del camino : %d \n", flujoMenor);
        printf("\n");

        int i = 0;
        printf("semicamino encontrado : \n");
        printf("cantidad de aristas que lo conforman : %d \n", aristasEnSemicamino);
        while (semicamino[i] != 0)
        {
            Grafo_aux[i][semicamino[i]] = flujoMenor;

            red[i][semicamino[i]] = red[i][semicamino[i]] - flujoMenor;
            printf("arista : ( %d %d ) , flujo : %d \n", i, semicamino[i], Grafo_aux[i][semicamino[i]]);
            i = semicamino[i];
        }
    }
    else
    {
        printf("no se ha encontrado un nuevo camino \n");
    }

    return (visitado[t] == true);
}

int fordFulkerson(int red[V][V], int s, int t)
{

    int cf;
    int i = 0;
    while (semicamino[i] != 0)
    {
        if (i == 0)
            cf = red[i][semicamino[i]];

        if (red[i][semicamino[i]] < cf && i != 0)
            cf = red[i][semicamino[i]];

        i++;
    }

    int j = 0;
    int flujoMaximoDelCamino = Grafo_aux[j][semicamino[j]] + cf;
    while (semicamino[j] != 0)
    {
        Grafo_aux[j][semicamino[j]] = Grafo_aux[j][semicamino[j]] + cf;
        Grafo_aux[semicamino[j]][j] = -Grafo_aux[j][semicamino[j]];
        j++;
    }

    return flujoMaximoDelCamino;
}

int main(int argc, char const *argv[])
{

    int flujoMaximoTotal = 0;

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
        {
            Grafo_aux[i][j] = red[i][j];
        }

    while (busqueda_camino(Grafo_aux, 0, 5, semicamino))
    {
        printf("MAIN : 1 camino encontrado \n \n");
        printf("flujo maximo total posible circulando en el grafico: %d \n \n",
               flujoMaximoTotal += fordFulkerson(red, 0, 5));
    }

    return 0;
}