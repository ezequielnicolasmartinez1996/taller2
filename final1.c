// Ezequiel Nicolas Martinez
// DNI 39755509
// FINAL TALLER DE PROGRAMACION 2 - AUS
// Comision 1

#include <stdio.h>

#define VERTICES 6

void mostrarMatriz(int g[][VERTICES]);
void calculaSemicamino(int g[][VERTICES]);
void pesoMinimoSemicamino(int p);
void igualaMatrices(int g[][VERTICES], int h[][VERTICES]);
void muestraSemicamino(int g[][1]);
void actualizaAuxiliar(int g[][VERTICES], int h[][1]);

int camino[VERTICES];
int n, m, k, i, distanciaCamino = 0;
int semiCamino[][1];
int aristaMaxima = 0;
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
    mostrarMatriz(matrizAuxiliar);
    igualaMatrices(matrizAuxiliar, matrizCapacidad);
    mostrarMatriz(matrizAuxiliar);
    calculaSemicamino(matrizCapacidad);
    mostrarMatriz(matrizAuxiliar);
    muestraSemicamino(semiCamino);
    actualizaAuxiliar(matrizAuxiliar, semiCamino);
    mostrarMatriz(matrizAuxiliar);
}

void mostrarMatriz(int g[][VERTICES])
{
    printf("Matriz:\n");
    for (int k = 0; k < VERTICES; k++)
    {
        for (int i = 0; i < VERTICES; i++)
        {
            printf("%d ", g[k][i]);
        }
        printf("\n");
    }
}

void calculaSemicamino(int g[][VERTICES])
{

    aristaPesoMinimo = 100;
    distanciaCamino = 0;
    int n = 1;
    int bandera;
    int k = 0;
    camino[0] = 0; // VERTICE SALIENTE
    while (k < VERTICES)
    {
        semiCamino[k][0] = NULL; // limpia la variable
        semiCamino[k][1] = NULL; // limpia la variable

        k = bandera;
        for (int i = 0; i < VERTICES; i++)
        {

            if (aristaMaxima <= g[k][i])
            {
                aristaMaxima = g[k][i];
                bandera = i;
            }
            if (aristaMaxima > 0)
            {
                pesoMinimoSemicamino(aristaMaxima);
            }
            camino[n] = bandera;
        }
        n++;

        distanciaCamino++;
        aristaMaxima = 0;
        k++;
    }
    printf("Camino: ");

    for (int f = 0; f < distanciaCamino; f++)
    {
        printf("%d ", camino[f] + 1);
        if (camino[f] != camino[f + 1])
        {
            semiCamino[f][0] = camino[f];
            semiCamino[f][1] = camino[f + 1];
        }
    }
    printf("\n");
    printf("Arista de peso minimo: %d\n", aristaPesoMinimo);
}

void muestraSemicamino(int g[][1])
{
    printf("El semicamino es:\n");
    for (int i = 0; i < distanciaCamino - 1; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            printf("%d ", g[i][k] + 1);
        }
        printf("- El peso minimo de la arista es: %d", aristaPesoMinimo);
        printf("\n");
    }
}

void actualizaAuxiliar(int g[][VERTICES], int h[][1])
{
    for (int i = 0; i < distanciaCamino - 1; i++)
    {
        int coordx = h[i][0];
        int coordy = h[i][1];
        printf("Coordx: %d, coordy;%d, semicamino:%d, semicamino:%d\n", coordx, coordy, h[i][0], h[i][1]);
        g[coordx][coordy] = g[coordx][coordy] - aristaPesoMinimo;
    }
}

void pesoMinimoSemicamino(int p)
{
    if (p < aristaPesoMinimo)
        aristaPesoMinimo = p;
}

void igualaMatrices(int g[][VERTICES], int h[][VERTICES]) // Asigna la segunda a la primera
{
    for (int k = 0; k < VERTICES; k++)
    {
        for (int i = 0; i < VERTICES; i++)
        {
            g[k][i] = h[k][i];
        }
    }
}