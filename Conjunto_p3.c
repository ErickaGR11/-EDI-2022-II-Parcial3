//set conjunto
//grupo de elementos que no se repiten
//2. operaciones:
//2.1 agregar el conjunto- verificar que el elemento no exista dentro del conjunto, si hay espacio
//2.2 eliminar un elemento de un conjunto- exista-elimina
//2.3 pertenencia-elemento x pertenece al conjunto
//3. operaciones entre conjuntos- dado dos conjuntos
//3.1 calcular su interseccion . valores comunes a los dos conjuntos
//3.2 union- todos los elementos de A- todos los elementos de B sin repetirlos
// 3.3 complemento-complemento de A. Todos los elementos que no pertenezcan a A
//3.4 Diferencia- A-B Tod lo que este en A que no este en B

#include <stdio.h>
#define SET_CAPACITY 10
typedef struct set{
    int data[SET_CAPACITY];
    int size; //cuantos elementos se han insertado en el conjunto
}Set;
int add(Set *s, int value);
int init_set (Set *s);
int find(Set set, int value);
int remover(Set *s, int value);
int exist(Set set, int value);
void intersect(Set setA, Set setB, Set *setC);
void printSet(Set set);
void Union(Set set, Set setB, Set *setC);
void Complement(Set set, Set setB, Set *setC);
void DifSet(Set set, Set setB, Set *setC);
int main(){
    Set set; Set setB; Set setC;

    init_set(&set);
    add(&set, 23);
    add(&set, 11);
    add(&set, 16);
    add(&set, 5);
    add(&set, 7);

    init_set(&setB);
    add(&setB, 10);
    add(&setB, 11);
    add(&setB, 21);
    add(&setB, 5);

    init_set(&setC);
    printSet(set);
    printSet(setB);
    printSet(setC);

    intersect(set,  setB,  &setC);
    printf("\nDespues de obtener la interseccion\n");
    printSet(setC);

    init_set(&setC);
    Complement(set, setB, &setC); //10, 21
    printf("\nDespues de obtener el complemento\n");
    printSet(setC);

    init_set(&setC);
    DifSet(set,  setB,  &setC);
    printf("\nDespues de obtener la diferencia\n");
    printSet(setC);


    init_set(&setC);
    Union(set,  setB,  &setC);
    printf("\nDespues de obtener la Union\n");
    printSet(setC);

    int a= remover(&setC,16);
    printf("removio?= %d\n", a);
    printSet(setC);
    int e= exist(setC,  7);
    printf("existe?= %d ", e);
}
void Union(Set set, Set setB, Set *setC) {
//TODOS LOS ELEMENTOS DE SETA Y SETB SIN REPETIR
    int e, e2;

    for (int index = 0; index < set.size; ++index) {
        e = exist(set, setB.data[index]);//DIFERENCIA
        e2 = exist(setB, set.data[index]);//INTERSEC
        if (e != 1 || e2 == 1) {
            add(setC, set.data[index]);
            add(setC, set.data[index]);
        }
    }

    for (int index = 0; index < setB.size; ++index) {
        e = exist(set, setB.data[index]);//COMPLEMENTO
        if (e != 1)
            add(setC, setB.data[index]);
    }
}

void Complement(Set set, Set setB, Set *setC){
//SON LOS VALORES B QUE NO EXISTAN A, VALORES QUE LE FALTAN AL SET A
    int e;
    for (int index = 0; index < setB.size; ++index) {
        printf("SetB.data [%d]= %d\n", index, setB.data[index]);
        e= exist(set, setB.data[index]);
        if (e!=1)
        {
            printf("%d NO existe en A\n", setB.data[index]);
            add(setC, setB.data[index]);
        }
    }
}

void DifSet(Set set, Set setB, Set *setC) {
//SON LOS VALORES A QUE NO EXISTAN B, VALORES QUE LE FALTAN AL SET B
    int e;
    for (int index = 0; index < set.size; ++index) {
        printf("SetA.data [%d]= %d\n", index, set.data[index]);
        e= exist(set, setB.data[index]);
        if (e!=1)
        {
            printf("%d NO existe en B\n", set.data[index]);
            add(setC, set.data[index]);
        }
    }
}
void intersect(Set set, Set setB, Set *setC){
    int e;
    for (int index = 0; index < set.size; ++index) {
        printf("SetA.data [%d]= %d\n", index, set.data[index]);
        e= exist(setB, set.data[index]);
        if (e==1)
        {
            printf("%d existe en B\n", set.data[index]);
            add(setC, set.data[index]);
        }
    }
}

int add(Set *s, int value) {
    int exists;
    int result = 0;
    //si hay espacio y el valor no existe en el conjunto
    if (s->size < SET_CAPACITY) { //hay espacio
        //find es una funcion que busca el dentro del conjunto (busqueda binaria)
        //regresa -1 si no lo encontro y si no regrsa el indice
        exists = find(*s, value);

        if (exists==-1) {//no encontro el valor

            //insertar el valor de forma ordenada
            //revisar desde size-1 mientras que el valor este en la posicion
            // sea mayor al valor que voy a insertar-> lo recorra

            int index;
            for (index = s->size - 1; index >= 0 && s->data[index] > value; index--) {
                s->data[index + 1] = s->data[index];
            }
            s->data[index + 1] = value;
            s->size++;
            result = 1;
        }
    }
    return result;
}

int find(Set set, int value){
    //Debe buscar el valor value dentro del arreglo
    //set.data y regresar -1 si no lo encontro y el indice si si lo encontro usando busqueda binaria
    int inicio=0;
    int fin= set.size-1;
    int mitad;
    int encontrado=0;
    // Mientras los indices no se crucen y no haya encontrado el valor
    while(inicio <= fin && encontrado == 0){
        mitad = inicio + (fin - inicio) / 2;

        if(set.data[mitad] == value)
            encontrado = 1;
        else
        if(set.data[mitad] > value) // Seguiria buscando en la mitad inferior
            fin = mitad - 1;
        else // Seguiria buscando en la mitad superior
            inicio = mitad + 1;
    }

    if(encontrado == 1)
        return mitad;
    else{
        return -1;
    }
}

int init_set (Set *s){
    s->size=0;
    return 1;
}

int remover(Set *s, int value){
    int index= find(*s, value);
    //find regresa -1 si no encontro valor y sisi regresa posicion

    if (index!=-1){ //si lo encontro
        s->size--;
        for (; index <= s->size-1 ; ++index) {
            s->data[index]=s->data[index+1];
        }
        return 1;
    }
    return -1;
}

int exist(Set set, int value){
    int index= find(set, value);
//si no existe el valor regresar 0 si no regresar 1
    if (index==-1)
        return 0;
    return 1;
}
void printSet(Set set){
    printf("[");
    for (int index = 0; index < set.size; ++index) {
        printf("  %d  ", set.data[index]);
    }
    printf("]\n");
}