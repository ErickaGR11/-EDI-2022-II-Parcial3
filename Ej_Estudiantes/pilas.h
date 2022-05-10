#include <stdio.h>
#include "EnComun.h"
typedef struct {
    int data[MAX];
    int top;
} Stack1;

void setup(Stack1 *s){
    //inicializa el tope de la pila
    //se inicializa en -1 cpor que NO es un indice valido del arr, nos indica que esta vacia
    s->top=-1;
}
int isEmpty(Stack1 stack2){
    if (stack2.top==-1)
        return 1;
    return 0;

    //otra forma de ponerlo es return (stack1.top==-1)? 1 : 0;
    //return stack1.top==-1;
}
int isFull(Stack1 stack2){
    //regresa un 1 si esta llena y un 0 si esta vacia
    if (stack2.top== MAX-1)
        return 1;
    return 0;
}
int push(Stack1 *s, int value){
    //insertar valor en la pila
    //regresa un 1 si se pudo y un 0 si no
    int r=0;
    if (isFull(*s)==0){
        s->top++;
        s->data[s->top]=value;
        r=1;
    }
    return r;
}
int pop (Stack1 *s, int *v){
    //elimina el elemento del tope
    //regresa 1 si se pudo y 0 si no
    //regresa el dato que elimino

    if (!isEmpty(*s)){
        *v= s->data[s->top];
        s->top--;
        return 1;
    }
    return 0;
}

int imprimir(Stack1 stack2){

    for (int i = 0; i < MAX; ++i) {
        printf("%d\n",stack2.data[i]);
    }
}