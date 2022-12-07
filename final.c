// Ezequiel Nicolas Martinez
// DNI 39755509
// FINAL TALLER DE PROGRAMACION 2 - AUS
// Comision 1

#include <stdio.h>

#define VERTICES 6

int main()
{
    // matriz [vertice de arista que sale][vertice de arista que entra]
    int matrizCapacidad[VERTICES][VERTICES] = {{0, 4, 6, 0, 0, 0},
                                               {0, 0, 0, 3, 5, 0},
                                               {0, 0, 0, 0, 6, 0},
                                               {0, 0, 9, 0, 0, 5},
                                               {0, 0, 0, 0, 0, 4},
                                               {0, 0, 0, 0, 0, 0}};

    int matrizFlujo[VERTICES][VERTICES] = {{0, 0, 0, 0, 0, 0},
                                           {0, 0, 0, 0, 0, 0},
                                           {0, 0, 0, 0, 0, 0},
                                           {0, 0, 0, 0, 0, 0},
                                           {0, 0, 0, 0, 0, 0},
                                           {0, 0, 0, 0, 0, 0}};

    int matrizResultante[VERTICES][VERTICES]; // Matriz de capacidad - matriz de flujo

    int matrizVisita[VERTICES][VERTICES] = {{0, 1, 0, 0, 0, 0},
                                            {0, 1, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0},
                                            {0, 0, 1, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0}};

    // PRIMER CAMINO DE FLUJO MAS ALTO
    int numeroMaximo = 0;
    int bandera1 = 0;
    int aristaFlujoMinimo = 0;
    int semicamino[VERTICES];
    printf("Camino actual mas alto:\n");
    for (int k = 0; k < VERTICES; k++)
    {
        k = bandera1;
        for (int i = 0; i < VERTICES; i++)
        {
            if (numeroMaximo < matrizCapacidad[k][i])
            {
                numeroMaximo = matrizCapacidad[k][i];
                bandera1 = i;
            }
        }

        if (numeroMaximo > 0)
            printf("Arista (%d,%d) Capacidad: %d\n", k + 1, bandera1 + 1, numeroMaximo);

        // OBTENER EL NUMERO MINIMO DEL CAMINO
        
        /******IMPACTARLO EN MATRIZ DE FLUJO*****/
        matrizFlujo[k][bandera1] = numeroMaximo;
        numeroMaximo = 0;
    }

    // IMPRESION MATRIZ DE FLUJO
    for (int k = 0; k < VERTICES; k++)
    {
        for (int i = 0; i < VERTICES; i++)
        {
            printf("%d ", matrizFlujo[k][i]);
        }
        printf("\n");
    }
    /*********CHEQUEADOR DE MATRICES********/
    for (int k = 0; k < VERTICES; k++)
    {
        for (int i = 0; i < VERTICES; i++)
        {
            //  printf("La capacidad de la arista (%d,%d) es: %d\n", k, i, matrizCapacidad[k][i]);
            //  printf("El flujo actual de la arista (%d,%d) es: %d\n", k, i, matrizFlujo[k][i]);
            //   if(matrizVisita[k][i]==0)printf("El vertice no fue visitado\n");
            //   if(matrizVisita[k][i]==1)printf("El vertice fue visitado\n");
        }
    }
}
