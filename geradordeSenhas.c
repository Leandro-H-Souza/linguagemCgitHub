#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void geraSenha(int comprimento, int maiuscula, int minuscula, int num, int caracEspecial){
    char comp[200] = "";
    char incmaiuscula[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char incminuscula[] = "abcdefghijklmnopqrstuvwxyz";
    char incnumero[] = "0123456789";
    char inccaracterespecial[] ="!@#$%¨&*()-_=[]{}~?/|:;";
    if(maiuscula){
        strcat(comp, incmaiuscula);

    }
    if(minuscula){
        strcat(comp, incminuscula);
    }
    if(num){
        strcat(comp, incnumero);
    }
    if(caracEspecial){
        strcat(comp, inccaracterespecial);
    }
    else{
        printf("Não há como gerar uma senha.\n");
        return 1;
    }
    for(int i = 0; i < comprimento; i++){
        int index = rand() % strlen(comp);
        printf("%c", comp[index]);
    }
    printf("\n");
}
//void salvarSenha ()
int main(){
    setlocale(LC_ALL, "Portuguese");
    //FILE *senha;
    //senha = fopen("senha.txt", "w");
    //if(senha == NULL){
      //  printf("Houve um erro ao abrir o arquivo");
    //    return 1;
    //}
    srand(time(0));
    int comprimento, maiuscula, minuscula, num, caracEspecial, novasenha;
    printf("----------GERADOR DE SENHAS----------\n");
    do{
            printf("Forneça o número de carateres: \n");
            scanf(" %d", &comprimento);
            printf("Incluir letras maisculas (1- Sim, 0- Não)?\n");
            scanf(" %d", &maiuscula);
            printf("Incluir letras minúsculas (1- Sim, 0- Não)?\n");
            scanf(" %d",&minuscula);
            printf("Incluir números (1- Sim, 0- Não)?\n");
            scanf(" %d", &num);
            printf("Incluir caracteres especiais (1- Sim, 0- Não)?\n");
            scanf(" %d", &caracEspecial);
            geraSenha(comprimento, maiuscula, minuscula, num, caracEspecial);
        printf("Gostaria de gerar uma nova senha (1- Sim, 0- Não)?\n");
        scanf(" %d", &novasenha);
    }
    while(novasenha != 0);
    printf("-----ENCERRANDO O PROGRAMA-----");
    return 0;
}
