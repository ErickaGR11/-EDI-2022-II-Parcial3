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
//void printGraph(Graph graph);
int findVertice(Graph graph, char vertice[20]);
int EstaLlena (Graph g);
void createGraph(Graph *g);
void resetFlags(Graph *g);
void bfs(Graph *graph, char vertice[50]);

int main (){
    Graph graph;
    initGraph(&graph);
    createGraph(&graph);
   // printGraph(graph);
    printf("Recorrido en amplitud: ");
    bfs(&graph, "A");
    printf("\n");
    resetFlags(&graph);
}
int initGraph(Graph *g){
    g->size=0;
    resetFlags(g);
    return 1;
}
void createGraph(Graph *g){
    AddVertice(g, "A");
    AddVertice(g, "B");
    AddVertice(g, "C");
    AddVertice(g, "D");
    AddVertice(g, "E");
    AddVertice(g, "F");
    AddVertice(g, "G");
    AddVertice(g, "H");

    AddEdge(g, "A", "B");
    AddEdge(g, "A", "E");
    AddEdge(g, "A", "D");
    AddEdge(g, "A", "G");
    AddEdge(g, "B", "C");
    AddEdge(g, "B", "E");
    AddEdge(g, "D", "H");
    AddEdge(g, "G", "H");
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