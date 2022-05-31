#include <stdio.h>
typedef struct alumno {
    char name[50];
    float average;
} Alumno;
void Creararchivo( char Nombre_archivo[50], int cantAlumnos);

int main() {
    int cantAlumnos;
    printf("Dame cantidad de alumnos:");
    scanf("%d", &cantAlumnos);

    Creararchivo( "ListAlumnos.txt" , cantAlumnos);


}
void Creararchivo( char Nombre_archivo[50], int cantAlumnos){
    Alumno alumnos;
    FILE *archivo;
    int cerrado;
    archivo= fopen(Nombre_archivo, "w");
    if (archivo == NULL) {
        printf("No se pudo abrir");
    }
    int i;

    //Se escriben los valores en el doc .txt
    for( i=0;i<cantAlumnos;i++){
            printf("Dame el nombre del alumno[%d]\n", i);
            scanf("%s",alumnos.name);
            fprintf(archivo, "\n");
            printf("Dame la calificacion del alumno [%d]\n", i);
            scanf("%f",&alumnos.average);
            fprintf(archivo, "%s  %.2f", alumnos.name, alumnos.average);
        }
    //Cerrando archivo
    cerrado= fclose(archivo);
    if(cerrado==EOF){
        printf("No se cerro");
    }
}
