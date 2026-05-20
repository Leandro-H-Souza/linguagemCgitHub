#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAX_SENHA 80
#define PROXIMIDADE 1//proximidade da senha
int menor(int a, int b, int c){
    //para ajudar a encontrar menor de três valores
    int m = a;
    if(b < m) m = b;
    if(c < m) m = c;
    return m;
}
int levenshtein(const char*s1, const char *s2){
    // testando a distância de levenshtein
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matriz[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) matriz[i][0] = i;
    for (int j = 0; j <= len2; j++) matriz[0][j] = j;
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            int custo = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matriz[i][j] = menor(matriz[i - 1][j] + 1, matriz[i][j - 1] + 1, matriz[i - 1][j - 1] + custo);    
        }
    }
    return matriz[len1][len2];
}
void limpaLinha(char *str){
    str[strcspn(str, "\r\n")] = 0;
}
int main(){
    char senhaUsuario[MAX_SENHA];
    char senhaLista[MAX_SENHA];
    FILE *arq;
    int exata = 0; //caso encontre senhas exatas da biblioteca
    int parcial = 0;// caso encontre alguma senha próxima
    printf("Digite sua senha para verificar: \n");
    if(fgets(senhaUsuario, sizeof(senhaUsuario), stdin) == NULL){
        printf("Erro ao ler entrada!\n");
        return 1;
    }
    limpaLinha(senhaUsuario);
    arq = fopen("listaTeste.txt", "r");
    if(arq == NULL){
        perror("Erro ao abrir o arquivo!\n");
        return 1;
    }
    printf("Analizando a seguranca da senha\n");
    while (fgets(senhaLista, sizeof(senhaLista), arq) != NULL) {
        limpaLinha(senhaLista);

        if (strlen(senhaLista) == 0) continue;
        /*printf("Usuario = [%s] (%lu bytes) | Lista = [%s] (%lu bytes)\n", 
               senhaUsuario, (unsigned long)strlen(senhaUsuario), senhaLista, (unsigned long)strlen(senhaLista));*/
        if (strcmp(senhaUsuario, senhaLista) == 0) { 
            printf("Senha encontrada exatamente igual na lista!\n");
            exata = 1;
            break;
        }
        int distancia = levenshtein(senhaUsuario, senhaLista);
        if(distancia <= PROXIMIDADE) {
            printf("Senha muito proxima de '%s' (Distancia: %d)\n", senhaLista, distancia);
            parcial = 1;
        }
    }
    if(!exata && !parcial){
        printf("Sua senha nao foi encontrada na lista nem uma versao proxima dela!");
    }   
    fclose(arq);
    return 0;
}