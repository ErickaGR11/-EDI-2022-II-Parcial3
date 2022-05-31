#include <stdio.h>
#include <string.h>
#define MAX 10
void invertir_cadena(char *cadena, int pos);
int main()
{
    char cadena[MAX];
    printf("Dame la palabra:");
    scanf("%s", &cadena);
    int LONG= strlen(cadena);
    invertir_cadena(cadena,LONG);
}
void invertir_cadena(char *cadena, int pos){
    if (pos<0)
        return;
    printf("%c", cadena[pos]);
    invertir_cadena(cadena, pos-1);
}