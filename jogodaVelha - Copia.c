#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define linha 3
#define coluna 3
int main(){
    setlocale(LC_ALL, "Portuguese");
    printf("|----------Jogo da Velha----------|\n");
    char jogo[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            jogo[i][j]= 0;
        }
    }
    //exibindo
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("\t%d", jogo[i][j]);
        }
        printf("\n");
    }
    printf("Selecionem os campos.");
    for(int k = 0; k < 9; k++){
        if()
    }
}
