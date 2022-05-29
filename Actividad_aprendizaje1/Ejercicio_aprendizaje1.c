#include <stdio.h>

typedef struct robot{
    int x, y;
}Robot;
void recorrido(int M,int N,int arr[M][N]);
void inicio_camino(Robot *r);

int main(){
    FILE *archivo;
    int cerrado;
    archivo= fopen("ejemplo.txt", "w");
    int M, N;
    int i, j;
    printf("Dame M:");
    scanf("%d", &M);
    //RESTRICCION
    if (!(M>=1 && M<=100)){
        printf("Valor invalido, intenta de nuevo:\n");
        scanf("%d", &M);
    }
    printf("Dame N: ");
    scanf("%d",&N);
    //RESTRICCION
    if (!(N>=1 && N<=100)){
        printf("Valor invalido, intenta de nuevo:\n");
        scanf("%d", &N);
    }
    //Se escriben los valores en el doc .txt
    printf("\n");
    int Mrobot[M][N];
    for( i=0;i<M;i++){
        for( j=0;j<N;j++){
            printf("Dame el valor[%d][%d]\n", i, j);
            scanf("%d",&Mrobot[i][j]);
            fprintf(archivo, "%d", Mrobot[i][j]);
        }
        fprintf(archivo, "\n");
    }
    //Cerrando archivo
    cerrado= fclose(archivo);
    if(cerrado==EOF){
        printf("No se cerro");
    }
    //Abriendo archivo de lectura
    archivo= fopen("ejemplo.txt","r");
    if (archivo == NULL) {
        printf("No se pudo abrir");
    }
    //leyendo archivo
    for( i=0;i<M;i++){
        for( j=0;j<N; ++j){
            fscanf(archivo, "%d", &Mrobot[i][j]);
            // printf("%d", Mrobot[i][j]);
        }
        //   printf( "\n");
    }
    //cerrando archivo
    cerrado= fclose(archivo);
    if(cerrado==EOF){
        printf("No se cerro");
    }

    recorrido(M,N,Mrobot);
}
void inicio_camino(Robot *r){
    r->x=0;
    r->y=0;
}
void recorrido(int M,int N,int arr[M][N]){
    Robot r;
    inicio_camino(&r); //inicializa
    printf("(%d,%d) ",r.x,r.y); //imprime comienzo[0],[0]
    while(r.x!=M-1||r.y!=N-1){
        printf("-> ");
        if(arr[r.y][r.x+1]==0 && r.x+1<M){ //si [y][x+1]==0 y es menor a M entonces ahora x valdra x+1
            r.x=r.x+1;
        }else if(arr[r.y+1][r.x]==0&&r.y+1<N){ //si no SI[x][y+1]==0 y es menor a N entonces ahora y valdra y+1
            r.y=r.y+1;
        }
        printf("(%d,%d) ",r.x,r.y);
    }
}
