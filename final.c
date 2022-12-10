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

    int matrizFLujo[VERTICES][VERTICES] = {{0, 0, 0, 0, 0, 0},
                                           {0, 0, 0, 0, 0, 0},
                                           {0, 0, 0, 0, 0, 0},
                                           {0, 0, 0, 0, 0, 0},
                                           {0, 0, 0, 0, 0, 0},
                                           {0, 0, 0, 0, 0, 0}};

    int matrizAuxiliarFLujo[VERTICES][VERTICES] = {{0, 0, 0, 0, 0, 0},
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
        {
            aristaFlujoMinimo = numeroMaximo;
            printf("Arista (%d,%d) Capacidad: %d\n", k + 1, bandera1 + 1, numeroMaximo);

            // OBTENER EL NUMERO MINIMO DEL CAMINO
            if (numeroMaximo <= aristaFlujoMinimo)
            {
                aristaFlujoMinimo = numeroMaximo;
            }
        }
        // IMPACTAR EN MATRIZ AUX DE FLUJO
        matrizAuxiliarFLujo[k][bandera1] = numeroMaximo;

        // RESETEAR VARIABLE
        numeroMaximo = 0;
    }

    /******CAMBIAR MATRIZ AUX DE FLUJO POR FLUJOS MINIMOS*****/
    for (int k = 0; k < VERTICES; k++)
    {
        for (int i = 0; i < VERTICES; i++)
        {
            if (matrizAuxiliarFLujo[k][i] > aristaFlujoMinimo)
            {
                matrizAuxiliarFLujo[k][i] = aristaFlujoMinimo;
            }
        }
    }

    /*********GENERAR MATRIZ RESULTANTE (RESIDUAL)********/
    for (int k = 0; k < VERTICES; k++)
    {
        for (int i = 0; i < VERTICES; i++)
        {
            matrizResultante[k][i] = matrizCapacidad[k][i] - matrizAuxiliarFLujo[k][i];
        }
    }

    printf("Arista de flujo minimo: %d\n", aristaFlujoMinimo);

    // IMPRESION MATRIZ DE CAPACIDAD
    printf("Matriz capacidad\n");
    for (int k = 0; k < VERTICES; k++)
    {
        for (int i = 0; i < VERTICES; i++)
        {
            printf("%d ", matrizCapacidad[k][i]);
        }
        printf("\n");
    }

    // IMPRESION MATRIZ AUX DE FLUJO
    printf("Matriz aux de flujo\n");
    for (int k = 0; k < VERTICES; k++)
    {
        for (int i = 0; i < VERTICES; i++)
        {
            printf("%d ", matrizAuxiliarFLujo[k][i]);
        }
        printf("\n");
    }

    // IMPRESION MATRIZ DE RESULTANTE
    printf("Matriz resultante\n");
    for (int k = 0; k < VERTICES; k++)
    {
        for (int i = 0; i < VERTICES; i++)
        {
            printf("%d ", matrizResultante[k][i]);
        }
        printf("\n");
    }

    /*********CHEQUEADOR DE MATRICES********/
    for (int k = 0; k < VERTICES; k++)
    {
        for (int i = 0; i < VERTICES; i++)
        {
            //  printf("La capacidad de la arista (%d,%d) es: %d\n", k, i, matrizCapacidad[k][i]);
            //  printf("El flujo AUX actual de la arista (%d,%d) es: %d\n", k, i, matrizAuxiliarFLujo[k][i]);
            //   if(matrizVisita[k][i]==0)printf("El vertice no fue visitado\n");
            //   if(matrizVisita[k][i]==1)printf("El vertice fue visitado\n");
        }
    }
}
