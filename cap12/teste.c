#include <stdlib.h>
#include <stdio.h>

int main(){
    int x, z, i=50;
    //int **p;
    //x = **p;

    int y=1;
    if (!!y){
        printf("AQUIII\n");
        z = 0;
    }
    printf("AQUIII FORA\n");
    x = 1 + 2 - 3;
    x = y = 10;

    if(i>0 && i<120) printf("Idade correta");

 else printf("Idade inválida");
int indice, tamanho=10, chave=7, lista[10];

indice = 1;
while((indice < tamanho) && (lista[indice] != chave)) indice++;

    return 0;
}