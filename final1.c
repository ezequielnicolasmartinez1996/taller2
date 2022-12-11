// Ezequiel Nicolas Martinez
// DNI 39755509
// FINAL TALLER DE PROGRAMACION 2 - AUS
// Comision 1

#include <stdio.h>

#define VERTICES 6

void mostrarMatriz(int g[][VERTICES]);
void calculaSemicamino();
void pesoMinimoSemicamino(int p);
void igualaMatrices(int g[][VERTICES], int h[][VERTICES]);
void muestraSemicamino(int g[][1]);
void actualizaAuxiliar(int g[][VERTICES], int h[][1]);

int n, m, k, i, distanciaCamino = 0;
int semiCamino[][1];
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
    igualaMatrices(matrizAuxiliar, matrizCapacidad);
    mostrarMatriz(matrizAuxiliar);
    calculaSemicamino();
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

void calculaSemicamino()
{
    n = 0;
    distanciaCamino = 0;
    int aristaMaxima = 0;
    int bandera1 = 0;
    for (int k = 0; k < VERTICES; k++)
    {

        k = bandera1;
        for (int i = 0; i < VERTICES; i++)
        {
            if (aristaMaxima < matrizCapacidad[k][i])
            {
                aristaMaxima = matrizCapacidad[k][i];
                bandera1 = i;
            }
        }
        if (aristaMaxima > 0)
        {
            semiCamino[n][0] = k;
            semiCamino[n][1] = bandera1; // guarda la ruta del semicamino
            pesoMinimoSemicamino(aristaMaxima);
            // RESETEAR VARIABLE
            aristaMaxima = 0;
            // Distancia del camino
            distanciaCamino++;
            n++;
           // semiCamino[n][1] = NULL; // liberamos este espacio de memoria porque trae error
        }
    }
}

void muestraSemicamino(int g[][1])
{
    printf("El semicamino es:\n");
    for (int i = 0; i < distanciaCamino; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            printf("%d ", g[i][k] + 1);
        }
        printf("- El peso de la arista es: %d", aristaPesoMinimo);
        printf("\n");
    }
}

void actualizaAuxiliar(int g[][VERTICES], int h[][1])
{
    for (int i = 0; i < distanciaCamino; i++)
    {
        int coordx = h[i][0];
        int coordy = h[i][1];
        printf("Coordx: %d, coordy;%d, semicamino:%d, semicamino:%d\n", coordx, coordy, h[i][0], h[i][1]);
        g[coordx][coordx]= g[coordx][coordy] - aristaPesoMinimo;
    }
}

void pesoMinimoSemicamino(int p)
{
    aristaPesoMinimo = p;
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