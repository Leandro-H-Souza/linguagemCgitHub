#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int sala[10][20], opcao;
    int fila, cadeira;
    int livres, ocupados;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            sala[i][j] = 0;
        }
    }
    do {
        printf("\n|---------CINEMA SUPERCINE--------| \n");
        printf("Iniciando sala...\n");
        printf("Sala iniciada com sucesso.\n");
        printf("O que gostaria de fazer?\n");
        printf("1 - Mostrar sala\n");
        printf("2 - Reservar lugar\n");
        printf("3 - Contar lugares livres e ocupados\n");
        printf("4 - Sair\n");
        printf("Escolha uma das opcoes: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Mostrando a sala ...\n");
                for(int i = 0; i < 10; i++){
                    printf("Fila %d:", i);
                    for(int j = 0; j < 20; j++){
                        printf("%d", sala[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 2:
                printf("Reservando lugar ...\n");
                int quantidade = 0;
                printf("Quantos lugares deseja reservar?\n");
                scanf("%d", &quantidade);

                for(int k = 0; k < quantidade; k++){
                    printf("Reserva %d de %d\n", k + 1, quantidade);
                    printf("Digite a fila (0-9): \n");
                    scanf("%d", &fila);
                    printf("Digite a cadeira (0-19): \n");
                    scanf("%d", &cadeira);

                    if(fila >= 0 && fila < 10 && cadeira >= 0 && cadeira < 20){
                        if(sala[fila][cadeira] == 0){
                            sala[fila][cadeira] = 1;
                            printf("Reserva concluida\n");
                        } else {
                            printf("Lugar ocupado, escolha outro lugar.\n");
                            k--;
                        }
                    } else {
                        printf("Posicao invalida!\n");
                        k--;
                    }
                }
                break;
            case 3:
                printf("Contando lugares livres/ocupados\n");
                livres = 0;
                ocupados = 0;
                for(int i = 0; i < 10; i++){
                    for(int j = 0; j < 20; j++){
                        if(sala[i][j] == 0){
                            livres++;
                        } else {
                            ocupados++;
                        }
                    }
                }
                printf("|--------Lugares disponiveis: %d\n", livres);
                printf("|--------Lugares ocupados: %d\n", ocupados);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 4);

    return 0;
}
