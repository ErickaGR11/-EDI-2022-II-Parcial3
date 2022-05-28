//Estructura de datos compleja
//vertices-elementos que queremos reacionar
//aristas-indican cuando un elemento esta relacionado
//TIPOS DE GRAFOS
//Dirigidos: sus aristas tienen direccion
//No dirigidos: sus aristas son bidireccionales

//OPERACIONES:
//inicializar
//insertar vertices
//insertar aristas(edges)/relaciones
//eliminar vertices
//eliminar relaciones
//si existe relacion entre dos vertices
//imprimir

#include <stdio.h>
#include <string.h>
#include "cola2.h"
#define GRAPH_CAPACITY 32
typedef struct graph{
    int edges[GRAPH_CAPACITY][GRAPH_CAPACITY];
    char vertices[GRAPH_CAPACITY][20];
    int flag[GRAPH_CAPACITY];
    int size;
}Graph;
int initGraph(Graph *g);
int AddVertice(Graph *g, char vertice[20]);
int AddEdge(Graph *g,char VerticeSource[20], char VerticeDestinity[20]);
void printGraph(Graph graph);
int findVertice(Graph graph, char vertice[20]);

int EstaLlena (Graph g);
int existeRelation(Graph *graph, char vertice1[20], char vertice2[20]);
int EliminarEdge(Graph *g, char *v1, char *v2);
int EliminarVertice (Graph *g, char *vertice);

void createGraph(Graph *g);
void resetFlags(Graph *g);
void bfs(Graph *graph, char vertice[50]);

int main (){
    Graph graph;
    int relacion;
    initGraph(&graph);

    createGraph(&graph);
    printGraph(graph);
   // int temp= findVertice(graph,"Nuevo leon");
    //    printf("%d\n", temp);
    //    //  temp= findVertice(graph,"Algo");

    //r=renglon c=columna
    //for (int r = 0; r < graph.size; ++r) {
    //        for (int c = r; c < graph.size; ++c) {
    //            printf("%s tiene relacion con %s? (1=si, 0=no)\n", graph.vertices[r], graph.vertices[c]);
    //            scanf("%d", &relacion);
    //            if (relacion==1)
    //                AddEdge(&graph, graph.vertices[r], graph.vertices[c]);
    //        }
    //    }
    printf("bfs1: ");
    bfs(&graph, "A");
    printf("\n");
    resetFlags(&graph);
    printf("bfs2: ");
    bfs(&graph, "B");

    int existe= existeRelation(&graph, "A", "B");
    printf("\nExiste Relacion 1:si, 0:No ?   %d", existe);
    int eliminar= EliminarEdge(&graph, "A", "B");
    printf("\nSe elimino la relacion 1:si, 0:No?  %d", eliminar);
    int eliminarVert= EliminarVertice(&graph, "H");
        printf("\nSe elimino el vertice 1:si, 0:No?  %d", eliminarVert);
        printf("\n\n");
    printGraph(graph);

}
int initGraph(Graph *g){
    g->size=0;
    resetFlags(g);
    //return 1;
}
void createGraph(Graph *g){
    AddVertice(g, "A");
    AddVertice(g, "B");
    AddVertice(g, "C");
    AddVertice(g, "D");
    AddVertice(g, "E");
    AddVertice(g, "H");

    AddEdge(g, "A", "B");
    AddEdge(g, "A", "D");
    AddEdge(g, "A", "E");
    AddEdge(g, "B", "C");
    AddEdge(g, "B", "E");
    AddEdge(g, "B", "H");

}
void resetFlags(Graph *g){
    for (int i = 0; i < GRAPH_CAPACITY; ++i) {
        g->flag[i]=0;
    }
}
void bfs(Graph *graph, char vertice[50]){
    Cola colavertice;
    int posVertice= findVertice(*graph, vertice);
    char verticeActual[50];
    inicializacion(&colavertice);
    //marca el vertice
    graph->flag[posVertice]=1; //marcadl clml visitado
    insertar(&colavertice, vertice);
    while (!estaVacia(colavertice)){
       eliminar(&colavertice, verticeActual);
       posVertice= findVertice(*graph, verticeActual);
        printf("%s", verticeActual);
        //meter relaciones de vertices
        for (int i = 0; i < graph->size; ++i) {
            if (posVertice!=1 && graph->edges[posVertice][i]==1 &&graph->flag[i]==0){
                graph->flag[i]=1;
                insertar(&colavertice, graph->vertices[i]);
            }

        }
    }
}
int EliminarEdge(Graph *g, char vertice1[20], char vertice2[20])
{
    int posVertice1 = findVertice(*g, vertice1);
    int posVertice2 = findVertice(*g, vertice2);
        if (g->edges[posVertice1][posVertice2] == 1) {
            g->edges[posVertice1][posVertice2] == 0;
            return 1;
        }else{
            return 0;
        }
    }
int EliminarVertice (Graph *g, char *vertice)
{
    int index = findVertice(*g, vertice);
    if (EstaLlena(*g)==-1 && index == - 1 )
    for (; index < g->size-1 ; ++index) {
        strcpy(g->vertices[index], g->vertices[index+1]);
    }
    g-> size --;
    return 1;
}
int existeRelation(Graph *graph, char vertice1[20], char vertice2[20]) {
    int posVertice1 = findVertice(*graph, vertice1);
    int posVertice2 = findVertice(*graph, vertice2);
    for (int i = 0; i < graph->size; ++i) {
        if (posVertice1 != 1 && graph->edges[posVertice1][posVertice2] == 1) {
            return 1;
        }else{
            return 0;
        }
    }
}

int findVertice(Graph graph, char vertice[20]){
    int i;
    int result= -1; //el valor no va estar en el arreglo

    for ( i = 0; i < graph.size && result == -1; ++i) {
        if (strcmp(graph.vertices[i], vertice)==0)
            result = i;
    }
    return result;
}

int EstaLlena (Graph g){
    if (g.size==GRAPH_CAPACITY) {
        return -1;
    } else {
         return 0;
     }
}
int AddVertice(Graph *g, char vertice[20]) {
    if (g->size < GRAPH_CAPACITY) { //TODAVIA PUEDO INSERTAR
        //Validar que el vertice no exista
        if (findVertice(*g, vertice) == - 1 &&  (EstaLlena(*g)!= -1))
        strcpy(g->vertices[g->size], vertice);
      //  g->size++;

        for (int r = 0; r < GRAPH_CAPACITY; ++r) {
            g->edges[r][g->size] = 0;
        }

    for (int c = 0; c < GRAPH_CAPACITY; ++c) {
        g->edges[g->size][c] = 0;
    }
        g->size++;

    }
    return 1;
}
int AddEdge(Graph *g,char VerticeSource[20], char VerticeDestinity[20]) {
    int posSource = findVertice(*g, VerticeSource);//0
    int posDestinity = findVertice(*g, VerticeDestinity);//1

    if (posSource !=-1 && posDestinity !=-1){ //Encontro los dos vertices
        g->edges[posSource][posDestinity]=1;
        g->edges[posDestinity][posSource]=1;
        return 1;
    }
    return -1;
}
void printGraph(Graph graph){
    printf("\t");
    for (int index = 0; index < graph.size; ++index) {
       printf("\t%s\t", graph.vertices[index]);
    }
    printf("\n");
    for (int r = 0; r < graph.size; ++r) {
        printf("%s  ", graph.vertices[r]);
       // printf("\t");
            for (int c = 0; c < graph.size; ++c) {
                printf("\t\t%d", graph.edges[r][c]);
               // printf("\t");
        }
        printf("\n");
    }

}