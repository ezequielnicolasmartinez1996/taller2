// Ezequiel Nicolas Martinez
// DNI 39755509
// FINAL TALLER DE PROGRAMACION 2 - AUS
// Comision 1

#include <stdio.h>

#define VERTICES 6

void mostrarMatriz(int g[][VERTICES]);
void semicamino(int g[][VERTICES]);
void pesoMinimoSemicamino(int p);
void imprimeFlujo(int g[][VERTICES]);

int n, m, k, i, distanciaCamino = 0;
int semiCamino[][2];
// matriz [vertice de arista que sale][vertice de arista que entra]
int matrizCapacidad[VERTICES][VERTICES] = {{0, 4, 6, 0, 0, 0},
                                           {0, 0, 0, 3, 5, 0},
                                           {0, 0, 0, 0, 6, 0},
                                           {0, 0, 9, 0, 0, 5},
                                           {0, 0, 0, 0, 0, 4},
                                           {0, 0, 0, 0, 0, 0}};
int matrizAuxiliar[VERTICES][VERTICES];

int matrizFlujo[VERTICES][VERTICES] = {{0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0}};
;
int matrizResultante[VERTICES][VERTICES]; // Matriz de capacidad - matriz de flujo
int matrizVisita[VERTICES][VERTICES];
int matrizInicializada[VERTICES][VERTICES];
int aristaPesoMinimo;

int main()
{
    mostrarMatriz(matrizCapacidad);
    semicamino(matrizCapacidad);
  //  mostrarMatriz(matrizFlujo);
    imprimeSemicamino(semiCamino);
}

void mostrarMatriz(int g[][VERTICES])
{
    int k, i;
    for (k = 0; k < VERTICES; k++)
    {
        for (i = 0; i < VERTICES; i++)
        {
            printf("%d ", g[k][i]);
        }
        printf("\n");
    }
}

void semicamino(int g[][VERTICES])
{
    n = 0;
    m = 0;
    i = 0;
    k = 0;
    distanciaCamino = 0;
    int numeroMaximo = 0;
    int bandera1 = 0;
    printf("Semicamino:\n");
    for (k = 0; k < VERTICES; k++)
    {
        k = bandera1;
        for (i = 0; i < VERTICES; i++)
        {
            if (numeroMaximo < matrizCapacidad[k][i])
            {
                numeroMaximo = matrizCapacidad[k][i];
                bandera1 = i;
            }
        }
        if (numeroMaximo > 0)
        {
            m=0;
            semiCamino[n][m] = k;
            m++;
            semiCamino[n][m] = bandera1; // guarda la ruta del semicamino
            n++;
            pesoMinimoSemicamino(numeroMaximo);
            // RESETEAR VARIABLE
            numeroMaximo = 0;
            // Distancia del camino
            distanciaCamino++;
        }
    }
}

void imprimeSemicamino(int g[][2])
{
    printf("El semicamino es:\n");
    for (int i = 0; i < distanciaCamino; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            printf("%d ", g[i][k]+1);
        }
        printf("- El peso de la arista es: %d", aristaPesoMinimo);
        printf("\n");
    }
}

void pesoMinimoSemicamino(int p)
{
    aristaPesoMinimo = p;
    if (p < aristaPesoMinimo)
        aristaPesoMinimo = p;
    // printf("Arista de peso minimo:%d\n", aristaPesoMinimo);
}
