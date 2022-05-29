#include <stdio.h>
#include <string.h>
#define MAX 10
typedef struct alumno {
    char name[50];
    char lastName[50];
    float average;
} Alumno;
int leerAlumnos(Alumno *alumnos, char *archivo_alumnos);
void ordenar(Alumno *Arr_alumnos);
void imprimir(Alumno *a, int s);

int main() {
    Alumno Arr_alumnos[MAX];

    leerAlumnos(Arr_alumnos, "aprendizaje2.dat");

    printf("\nArreglo Ordenado por Apellido\n\n");
    ordenar(Arr_alumnos);

    imprimir(Arr_alumnos, MAX);
}

int leerAlumnos(Alumno *alumnos, char *archivo_alumnos) {
    FILE *archivo;

    archivo = fopen(archivo_alumnos, "rb");
    if (archivo == NULL) {
        return -1;
    }

    fread(alumnos, sizeof(struct alumno), MAX, archivo);
    imprimir(alumnos, MAX);
    int cerrado = fclose(archivo);
    if (cerrado == EOF) {
        return -1;
    }
    return 0;
}
void imprimir(Alumno *a, int s) {
    for (int i = 0; i < s; i++)
        printf("%s, %s: %.1f\n", a[i].lastName, a[i].name, a[i].average);
}
void ordenar(Alumno *Arr_alumnos) {
    int i, j;
    float aux;
    Alumno auxN[50];
    Alumno aux2[50];
    int intercambio = 1;

    for (i = 0; i < MAX && intercambio == 1; i++) {
        intercambio = 0;
        for (j = 0; j < MAX - i - 1; j++) {
            // if (arreglofloat[j] < arreglofloat[j + 1]) {
            if (strcmp(Arr_alumnos[j].lastName, Arr_alumnos[j + 1].lastName) >
                0) { // compara dos cadenas
                strcpy(aux2, Arr_alumnos[j].lastName);
                strcpy(
                        auxN,
                        Arr_alumnos[j]
                                .name); // La función strcpy recibe dos parámetros, primero la
                // string donde se va a copiar el contenido, y segundo la
                // string del cual será copiado su contenido.
                aux = Arr_alumnos[j].average;

                strcpy(Arr_alumnos[j].lastName, Arr_alumnos[j + 1].lastName);
                strcpy(Arr_alumnos[j].name, Arr_alumnos[j + 1].name);
                Arr_alumnos[j].average = Arr_alumnos[j + 1].average;

                strcpy(Arr_alumnos[j + 1].lastName, aux2);
                strcpy(Arr_alumnos[j + 1].name, auxN);
                Arr_alumnos[j + 1].average = aux;

                intercambio = 1;
            }
        }
    }
}