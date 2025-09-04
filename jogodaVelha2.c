#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define LINHA 3
#define COLUNA 3

// Exibindo o tabuleiro
void mostrarTabuleiro(char tab[LINHA][COLUNA]) {
    printf("\n   1   2   3\n");
    for (int i = 0; i < LINHA; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLUNA; j++) {
            printf(" %c ", tab[i][j]);
            if (j < COLUNA - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < LINHA - 1) {
            printf("  -----------\n");
        }
    }
    printf("\n");
}

// Verificando vitória
int verificarVitoria(char tab[LINHA][COLUNA], char player) {
    for (int i = 0; i < LINHA; i++) {
        if (tab[i][0] == player && tab[i][1] == player && tab[i][2] == player) return 1;
        if (tab[0][i] == player && tab[1][i] == player && tab[2][i] == player) return 1;
    }
    if (tab[0][0] == player && tab[1][1] == player && tab[2][2] == player) return 1;
    if (tab[0][2] == player && tab[1][1] == player && tab[2][0] == player) return 1;
    return 0;
}

// Modo vs computador
void jogadaComputador(char tab[LINHA][COLUNA]) {
    int i, j;
    //\Ele tenta vencer
    for(int i=0; i < LINHAS; i++){
        for(int j=0; j < COLUNAS; j++){
            if(tab[i][j] == ' '){
                tab[i][j] = 'o'
                //simula a jogada
                if(verificarVitoria (tab, 'o')){
                    printf("Computador jogou em: %d %d\n", i+1, j+1 );
                    return; 
                    //caso vença o jogo
                }
                tab[i][j] = ' ';
                //Desfaz a simulação
            }
        }
    }
    //Tenta bloquear o jogador
    for(int i =  0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){
            if(tab[i][j] == ' '){
                tab[i][j] = 'x';
                //simula de novo a jogada do jogador
                if(verificarVitoria(tab, 'x')){
                    printf("Computador jogou em: %d %d\n ", i+1, j+1);
                    return;
                }
                tab[i][j] = ' ';
            }
        }
    }
    //agora para ocupar as posições
    if(tab[1][1] == ' '){
        tab[1][1] = 'o';
        printf("O computador jogou em : %d %d\n");
        return;
    }
    if(tab[0][0] == ' '){
        tab[0][0] = 'o';
        printf("O computador jogou em : %d %d\n");
        return;
    }
    if(tab[0][2] == ' '){
        tab[0][2] = 'o';
        printf("O computador jogou em : %d %d\n");
        return;
    }
    if(tab[2][0] == ' '){
        tab[2][0] = 'o';
        printf("O computador jogou em : %d %d\n");
        return;
    }
    if(tab[2][2] == ' '){
        tab[2][2] = 'o';
        printf("O computador jogou em : %d %d\n");
        return;
    }
    do {
        i = rand() % LINHA;
        j = rand() % COLUNA;
    } while (tab[i][j] != ' ');
    tab[i][j] = 'o';
    printf("Computador jogou em: %d %d\n", i + 1, j + 1);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int modoJogo;
    int placarX = 0, placarO = 0, empates = 0;

    printf("|---------- JOGO DA VELHA ----------|\n");

    do {
        char tab[LINHA][COLUNA];
        char jogadorAtual = 'x';
        int jogadas = 0;
        int linhaEscolhida, colunaEscolhida;

        // Inicializa tabuleiro
        for (int i = 0; i < LINHA; i++)
            for (int j = 0; j < COLUNA; j++)
                tab[i][j] = ' ';

        // Opções do jogador 
        printf("Escolha o modo de jogo:\n");
        printf("1 - Jogador vs Jogador\n");
        printf("2 - Jogador vs Computador\n");
        printf("Modo: ");
        scanf("%d", &modoJogo);

        while (1) {
            mostrarTabuleiro(tab);

            if (modoJogo == 2 && jogadorAtual == 'o') {
                jogadaComputador(tab);
            } else {
                // Ações do jogador 
                while (1) {
                    printf("Jogador %c, escolha linha e coluna (ex: 1 2): ", jogadorAtual);
                    scanf("%d %d", &linhaEscolhida, &colunaEscolhida);
                    linhaEscolhida--;
                    colunaEscolhida--;

                    if (linhaEscolhida >= 0 && linhaEscolhida < LINHA &&
                        colunaEscolhida >= 0 && colunaEscolhida < COLUNA) {
                        if (tab[linhaEscolhida][colunaEscolhida] == ' ') {
                            tab[linhaEscolhida][colunaEscolhida] = jogadorAtual;
                            break;
                        } else {
                            printf("Posição já ocupada.\n");
                        }
                    } else {
                        printf("Posição inválida.\n");
                    }
                }
            }

            jogadas++;

            // Verificando vitória
            if (verificarVitoria(tab, jogadorAtual)) {
                mostrarTabuleiro(tab);
                printf("O vencedor é: Jogador %c\n", jogadorAtual);
                if (jogadorAtual == 'x') placarX++;
                else placarO++;
                break;
            }

            // Em caso de empate
            if (jogadas == LINHA * COLUNA) {
                mostrarTabuleiro(tab);
                printf("Empate!\n");
                empates++;
                break;
            }

            // Para trocar de jogador
            jogadorAtual = (jogadorAtual == 'x') ? 'o' : 'x';
        }

        // Mostra placar
        printf("\nPlacar:\n");
        printf("Jogador X: %d\n", placarX);
        printf("Jogador O: %d\n", placarO);
        printf("Empates  : %d\n", empates);

        // Para continuar 
        int continuar;
        printf("\nDeseja jogar novamente? (1 = sim / 0 = não): ");
        scanf("%d", &continuar);
        if (!continuar) break;
        system("cls");
    } while (1);

    printf("Obrigado por jogar!\n");
    return 0;
}