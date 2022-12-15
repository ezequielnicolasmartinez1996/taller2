// Ezequiel Nicolas Martinez
// DNI 39755509
// FINAL TALLER DE PROGRAMACION 2 - AUS
// Comision 1

#include <stdio.h>

#define VERTICES 6

void mostrarMatriz(int g[][VERTICES]);
void calculaSemicamino(int g[][VERTICES]);
void igualaMatrices(int g[][VERTICES], int h[][VERTICES]);
void muestraSemicamino(int g[][1]);
void actualizaAuxiliar(int g[][VERTICES], int h[][1]);

int camino[VERTICES];
int n, m, k, i, distanciaCamino = 0;
int semiCamino[][1];
int aristaMaxima;
int algoritmoTermina = 0;
// matriz [vertice de arista que sale][vertice de arista que entra]
int matrizCapacidad[VERTICES][VERTICES] = {{0, 4, 6, 0, 0, 0},
                                           {0, 0, 0, 3, 5, 0},
                                           {0, 0, 0, 0, 6, 0},
                                           {0, 0, 9, 0, 0, 5},
                                           {0, 0, 0, 0, 0, 4},
                                           {0, 0, 0, 0, 0, 0}};
int matrizAuxiliar[VERTICES][VERTICES];
void borrarCamino();

int matrizFlujo[VERTICES][VERTICES] = {{0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0}};

int matrizResultante[VERTICES][VERTICES]; // Matriz de capacidad - matriz de flujo
int caminoVisita[VERTICES];
int matrizInicializada[VERTICES][VERTICES];
int aristaPesoMinimo;

int main()
{

    igualaMatrices(matrizAuxiliar, matrizCapacidad); // Iguala la matriz auxiliar a la de capacidad

    printf("Parte 1:\n"); // primer recorrido
    mostrarMatriz(matrizAuxiliar);
    calculaSemicamino(matrizAuxiliar);
    muestraSemicamino(semiCamino);
    actualizaAuxiliar(matrizAuxiliar, semiCamino);
    borrarCamino();

    printf("Parte 2:\n"); // segundo recorrido
    mostrarMatriz(matrizAuxiliar);
    calculaSemicamino(matrizAuxiliar);
    muestraSemicamino(semiCamino);
    actualizaAuxiliar(matrizAuxiliar, semiCamino);
    borrarCamino();
    
    printf("Parte 3:\n"); // tercer recorrido
    mostrarMatriz(matrizAuxiliar);
    calculaSemicamino(matrizAuxiliar);
    muestraSemicamino(semiCamino);
    actualizaAuxiliar(matrizAuxiliar, semiCamino);
    borrarCamino();

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

void borrarCamino()
{
    for (int i = 0; i < distanciaCamino; i++)
    {
        camino[i] = NULL;
        for (int k = 0; k < 2; k++)
        {
            semiCamino[i][k] = NULL;
        }
    }
}

void calculaSemicamino(int g[][VERTICES])
{
    for (int k = 0; k < VERTICES; k++)
    {
        caminoVisita[k] = 0;
    }
    aristaMaxima = 0;
    aristaPesoMinimo = 100;
    distanciaCamino = 0;
    n = 1;
    int bandera = 0;
    camino[0] = 0; // VERTICE SALIENTE
    caminoVisita[0] = 1;
    int antibucle = 0;
    int h = 0;
    for (int k = 0; k < VERTICES; k++)
    {
        // semiCamino[k][0] = NULL; // limpia la variable
        // semiCamino[k][1] = NULL; // limpia la variable
        k = bandera;
        for (int i = 0; i < VERTICES; i++)
        {
            if (aristaMaxima <= g[k][i] && caminoVisita[i] == 0)
            {
                aristaMaxima = g[k][i];
                bandera = i;
                if (bandera == 5 && g[k][i] == 0 && antibucle < 10) // si llega al ultimo vertice y la arista vale 0, busca otro camino
                {

                    for (h; h < n; h++)
                    {
                        caminoVisita[h] = 0;
                    }
                    bandera = 0;
                    n = 0;
                    distanciaCamino = -1;
                    h++;
                }
            }
            if (aristaPesoMinimo > aristaMaxima && aristaMaxima != 0)
            {
                aristaPesoMinimo = aristaMaxima;
            }
            camino[n] = bandera;
            caminoVisita[k] = 1;
        }
        antibucle++;
        n++;
        distanciaCamino++;
        aristaMaxima = 0;
    }
}

void muestraSemicamino(int g[][1])
{
    int flujoMaximo = 0;
    // limpia semicamino anterior:
    for (int k = 0; k < n; k++)
    {
        semiCamino[k][0] = NULL; // limpia la variable
        semiCamino[k][1] = NULL; // limpia la variable
    }
    for (int f = 0; f < n; f++)
    {
        if (camino[f] != camino[f + 1])
        {
            semiCamino[f][0] = camino[f];
            semiCamino[f][1] = camino[f + 1];
            if (semiCamino[f][0] == 0 && semiCamino[f][1] == 5)
            {

                printf("No hay mas caminos posibles. El algoritmo termino.\n");
                for (int j = 0; j < VERTICES; j++)
                {
                    flujoMaximo = matrizAuxiliar[5][j] + flujoMaximo;
                    algoritmoTermina = flujoMaximo;
                }
            }
        }
    }
    if (flujoMaximo > 0)
    {
        printf("El flujo maximo del grafo es: %d\n", flujoMaximo);
    }
    else
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
    n = 0;
}

void actualizaAuxiliar(int g[][VERTICES], int h[][1])
{
    for (int i = 0; i < distanciaCamino - 1; i++)
    {
        if (h[i][0] != h[i][1])
        {
            int coordx = h[i][0];
            int coordy = h[i][1];
            // printf("Coordx: %d, coordy;%d, semicamino:%d, semicamino:%d\n", coordx, coordy, h[i][0], h[i][1]);
            g[coordx][coordy] = g[coordx][coordy] - aristaPesoMinimo;
            g[coordy][coordx] = aristaPesoMinimo;
        }
    }
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