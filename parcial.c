// PARCIAL DE TALLER DE PROGRAMACION II
// EZEQUIEL NICOLAS MARTINEZ
// COMISION 1
// DNI 39755509
// PRUEBA VSCODE

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
int procesador1 = 0;
int procesador2 = 0;




typedef struct proces{
int procesador;
int id_proceso;
int prioridad;
char estado[10];
}proces;

void mostrarEnPantalla();
void iniciarScheduler();
void recorreCola();
void terminarProceso();

proces *procesos[CANTIDAD_DE_PROCESOS];


int main(){

srand(time(NULL));
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
terminarProceso();
ingresarProceso();
mostrarEnPantalla();
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
         procesos[i]->prioridad++;
        }
        for(int k=0; k<CANTIDAD_DE_PROCESOS; k++){
                if(strcmp(procesos[k]->estado, corriendo) == 0){
                procesadoresColapsados++;
                }
        }
        if(strcmp(procesos[i]->estado, listo) == 0 && procesadoresColapsados<2){
        strcpy(procesos[i]->estado, corriendo);
         procesos[i]->prioridad++;
        }
procesadoresColapsados=0;

        if(strcmp(procesos[i]->estado, nuevo) == 0){
        strcpy(procesos[i]->estado, listo);
        procesos[i]->prioridad++;
        }
     }
}

void terminarProceso(){
    for(int i=0; i<CANTIDAD_DE_PROCESOS; i++){
        if(strcmp(procesos[i]->estado, terminado) == 0){
        strcpy(procesos[i]->estado, vacio);
        if(procesos[i]->procesador=1){
        procesador1--;
        }
        if(procesos[i]->procesador=2){
        procesador2--;
        }
        procesos[i]->procesador=0;
        procesos[i]->prioridad=0;
        procesos[i]->id_proceso=0;
        }
    }
}

void ingresarProceso(){
int id_proceso, prioridad;
int bandera = 0;
prioridad=0;
     for(int i=0; i<CANTIDAD_DE_PROCESOS; i++){
        if(strcmp(procesos[i]->estado, vacio) == 0 && bandera == 0){
        procesos[i]->id_proceso = rand()%9999;
	    procesos[i]->prioridad=0;
        strcpy(procesos[i]->estado, nuevo);
        bandera=1;
        }
        if(strcmp(procesos[i]->estado, nuevo) ==0 && bandera == 1){
        	if(procesador1<procesador2){
        	procesos[i]->procesador=1;
        	procesador1++;
        	}	else{
        	procesos[i]->procesador=2;
        	procesador2++;
        		}
        }
    }
}




