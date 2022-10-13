// PARCIAL DE TALLER DE PROGRAMACION II
// EZEQUIEL NICOLAS MARTINEZ
// COMISION 1
// DNI 39755509

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define CANTIDAD_DE_PROCESOS 10

static int id;
char nuevo[] = "Nuevo";
char listo[] = "Listo";
char corriendo[] = "Corriendo";
char terminado[] = "Terminado";
char vacio[] = "Vacio";

void mostrarEnPantalla();
void iniciarScheduler();
void recorreCola();
void terminarProceso();

typedef struct proces {
int procesador;
int id_proceso;
int prioridad;
char estado[10];
}proces;

proces *procesos[CANTIDAD_DE_PROCESOS];

int main(){

iniciarScheduler();
recorreCola();
mostrarEnPantalla();
ingresarProceso();
ingresarProceso();
ingresarProceso();
ingresarProceso();
ingresarProceso();
mostrarEnPantalla();
terminarProceso();
ingresarProceso();
recorreCola();
mostrarEnPantalla();
terminarProceso();
ingresarProceso();
recorreCola();
mostrarEnPantalla();
terminarProceso();
ingresarProceso();
recorreCola();
mostrarEnPantalla();
terminarProceso();
ingresarProceso();
recorreCola();
mostrarEnPantalla();

return 0;
}

void iniciarScheduler(){
    for(int i = 0; i < CANTIDAD_DE_PROCESOS; i++){
    proces *esteProceso = malloc(sizeof(proces));
    esteProceso->procesador = NULL;
    esteProceso->id_proceso = NULL;
    esteProceso->prioridad = NULL;
    strcpy(esteProceso->estado,"Vacio");
    procesos[i]= esteProceso;
    }
printf("Scheduler Inicializado\n");
}

void mostrarEnPantalla(){
printf("Se muestra en pantalla el Scheduler\n");
    for(int i=0; i<CANTIDAD_DE_PROCESOS; i++){
    printf("[%d] {%d,%d,%d,%s}\n",i+1, procesos[i]->procesador, procesos[i]->id_proceso, procesos[i]->prioridad, procesos[i]->estado);
    }
}

void recorreCola(){
int procesadoresColapsados = 0;
    for(int i=0; i<CANTIDAD_DE_PROCESOS; i++){
        if(strcmp(procesos[i]->estado, corriendo) == 0){
        strcpy(procesos[i]->estado, terminado);
        }
        for(int k=0; k<CANTIDAD_DE_PROCESOS; k++){
                if(strcmp(procesos[k]->estado, corriendo) == 0){
                procesadoresColapsados++;
                }
        }
        if(strcmp(procesos[i]->estado, listo) == 0 && procesadoresColapsados<2){
        strcpy(procesos[i]->estado, corriendo);
        }
procesadoresColapsados=0;
        if(strcmp(procesos[i]->estado, nuevo) == 0){
        strcpy(procesos[i]->estado, listo);
        }
     }

}

void terminarProceso(){
    for(int i=0; i<CANTIDAD_DE_PROCESOS; i++){
        if(strcmp(procesos[i]->estado, terminado) == 0){
        strcpy(procesos[i]->estado, vacio);
        }
    }
}

void ingresarProceso(){
int bandera=0;
srand(time(NULL));
int procesador1, procesador2, id_proceso, prioridad =0;
     for(int i=0; i<CANTIDAD_DE_PROCESOS; i++){
        if(strcmp(procesos[i]->estado, vacio) == 0 && bandera==0){
        procesos[i]->id_proceso = rand()%9999;
        procesos[i]->prioridad=0;
        if(procesador2<procesador1){
        procesos[i]->procesador = 1;
        }else{
        procesos[i]->procesador =2;
             }
        strcpy(procesos[i]->estado, nuevo);
        bandera=1;
        system("pause");
        break;
        }
    }
}




