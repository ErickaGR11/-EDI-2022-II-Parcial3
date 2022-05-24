#include <stdio.h>
#include <string.h>
#define MAX 10
//NECESITAMOS:
//Arreglo;   un tope;    indice o indicador para la pos en que esta el arreglo

typedef struct {
    char data[MAX];
    int top;
} Stack1;

//funciones
void setup(Stack1 *s);
int isEmpty(Stack1 stack1);
int isFull(Stack1 stack2);
int push(Stack1 *s, char value);
int pop (Stack1 *s, char *v);
int equality(Stack1 *s, Stack1 *t, int str1);


int main() {
    Stack1 stack_t;
    Stack1 stack_s;
    setup(&stack_t);
    setup(&stack_s);//inicialiaza

    char s[MAX];
    char t[MAX];

    printf("Dame la cadena 1 de caracteres:");
    scanf("%s", &s);

    printf("Dame la cadena 2 de caracteres:");
    scanf("%s", &t);

    int str1 = strlen(s);
    int str2 = strlen(t);

    for (int i = 0; i < str1; i++) {
        if (s[i] == '#') {
            pop(&stack_s, s);
        } else {
            push(&stack_s, s[i]);
        }
    }
    for (int i = 0; i < str2; i++) {
        if (t[i] == '#') {
            pop(&stack_t, t);
        } else {
            push(&stack_t, t[i]);
        }
    }
    int n=  equality(&stack_s, &stack_t,  str1);
    printf("%d", n);
}


int equality(Stack1 *s, Stack1*t, int str1){
    if(s == t)
        return 1;

    for(int i = 0; i < str1; i++)
    {
        if(s->data != t->data)
            return -1;

    }
    return -1;
}
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
int push(Stack1 *s, char value){
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
int pop (Stack1 *s, char *v){
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
