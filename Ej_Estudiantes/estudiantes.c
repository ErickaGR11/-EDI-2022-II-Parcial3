#include <stdio.h>
#include <string.h>
#include "pilas.h"
#include "cola.h"

#define CIRCLE_SANDWICH 0
#define SQUARE_SANDWICH 1

void sell_sandwich(Cola *c, Stack1 *stack2);
int imprimir_pila(Stack1 stack2);
int imprimir_cola(Cola cola);
int main(){

    Stack1 stack2;
    Cola cola;
    Estudiante2 estudiante2;

    //INICIALIZACION DE ESTRUCTURAS
    inicializacion(&cola);
    setup(&stack2);

    //INSERTAR SANDWICH
    push(&stack2, CIRCLE_SANDWICH);
    push(&stack2, SQUARE_SANDWICH);
    push(&stack2, CIRCLE_SANDWICH);
    push(&stack2, SQUARE_SANDWICH);
    push(&stack2, CIRCLE_SANDWICH);
    push(&stack2, SQUARE_SANDWICH);
    push(&stack2, CIRCLE_SANDWICH);
    push(&stack2, SQUARE_SANDWICH);

    //INSERTAR ESTUDIANTES EN LA COLA
    strcpy(estudiante2.nombres, "Juan");
    estudiante2.sandwich=CIRCLE_SANDWICH;
    insertar(&cola, estudiante2);

    strcpy(estudiante2.nombres, "Pedro");
    estudiante2.sandwich=CIRCLE_SANDWICH;
    insertar(&cola, estudiante2);

    strcpy(estudiante2.nombres, "Amy");
    estudiante2.sandwich=SQUARE_SANDWICH;
    insertar(&cola, estudiante2);

    strcpy(estudiante2.nombres, "Brisa");
    estudiante2.sandwich=CIRCLE_SANDWICH;
    insertar(&cola, estudiante2);

    strcpy(estudiante2.nombres, "Luis");
    estudiante2.sandwich=SQUARE_SANDWICH;
    insertar(&cola, estudiante2);

    strcpy(estudiante2.nombres, "Angel");
    estudiante2.sandwich=SQUARE_SANDWICH;
    insertar(&cola, estudiante2);

    strcpy(estudiante2.nombres, "Ericka");
    estudiante2.sandwich=CIRCLE_SANDWICH;
    insertar(&cola, estudiante2);

    strcpy(estudiante2.nombres, "Anali");
    estudiante2.sandwich=SQUARE_SANDWICH;
    insertar(&cola, estudiante2);

     sell_sandwich(&cola, &stack2);
     printf("\n\nSandwiches:\n");
     imprimir_pila(stack2);
    printf("\n\nNombres:\n");
     imprimir_cola(cola);

    return 0;
}
void sell_sandwich(Cola *c, Stack1 *s){
    Estudiante2 estudianteActual;
    int sandwichActual;

    while (estaVacia(*c)==0) {    //!estavacia(*c)
        eliminar(c, &estudianteActual);
        pop(s, &sandwichActual);

        printf("\nEl estudiante %s quiere sandwich %d y en la pila hay %d", estudianteActual.nombres, estudianteActual.sandwich, sandwichActual);

        if (estudianteActual.sandwich!=sandwichActual) {
            printf("  No se pudo entregar, estudiante a cola, sandwich a pila");
            insertar(c, estudianteActual);
            push(s, sandwichActual);
        }
        else{
            printf("  El sandwich se entrego");
        }
    }
}
int imprimir_pila(Stack1 stack2){

    for (int i = 0; i < MAX; ++i) {
        printf("%d  ",stack2.data[i]);
    }
}

int imprimir_cola(Cola cola){
        for (int i = 0; i < MAX; ++i) {
            printf("%s  ",cola.datos[i]);
        }
}
