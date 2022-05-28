#include <stdio.h>
#define QUEUE_CAPACITY 100

typedef struct cola{
    char datos[QUEUE_CAPACITY+1][50];
    int inicio;
    int fin;

}Cola;

void inicializacion(Cola *c){
    c->inicio=0;
    c->fin=0;
}

int estaVacia (Cola cola){
    int r=0;
    if(cola.inicio==cola.fin)
        r=1;
    return r;
}

int estaLlena(Cola cola){
    if(cola.fin == cola.inicio-1 || (cola.inicio == 0 && cola.fin ==QUEUE_CAPACITY))
        return 1;
    return 0;
}
int insertar(Cola *c, char valor[50]){
    int r=0;

    if(estaLlena(*c)==0){ //Hay espacio para insertar
        strcpy(c->datos[c->fin], valor);//poner el valor dentro del arreglo en la pos fin
        c->fin++;//mover fin a la sig casilla libre, incremento el valor de fin

        if(c->fin == QUEUE_CAPACITY+1)
            c->fin = 0;
        r=1;
    }
    return r;
}

int eliminar(Cola *c, char valor[50]){
    int r=0;
    if (!estaVacia(*c)){
        strcpy(valor, c->datos[c->inicio]);
        c->inicio=(c->inicio+1)%(QUEUE_CAPACITY+1);
        r=1;
    }
    return r;
}