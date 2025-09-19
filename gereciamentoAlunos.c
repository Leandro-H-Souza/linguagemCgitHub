#include <stdio.h>
#include <locale.h>
#include <string.h>

#define maxAlunos 50

struct aluno{
    char nomeAluno[80];
    int idadeAluno;
    float nota1, nota2;
    float media;
    };
void addAluno(struct aluno Turma[], int *totalDeAlunos){
    //Checando se a turma está cheia
    if(*totalDeAlunos >= maxAlunos){
        printf("Turma Cheia! Não é possível adicionar mais alunos\n");
        return;
    }
    printf("\n----------ADICIONANDO ALUNOS-----------\n");
    printf("Nome do aluno: \n");
    //%[~\n] serve para ler todos os caracteres de uma var char (com mais de um caractere)
    scanf(" %[^\n]", &Turma[*totalDeAlunos].nomeAluno);
    printf("Idade do aluno: \n");
    scanf("%d", &Turma[*totalDeAlunos].idadeAluno);
    printf("Primeira nota: \n");
    scanf("%f", &Turma[*totalDeAlunos].nota1);
    printf("Segunda nota: \n" );
    scanf("%f", &Turma[*totalDeAlunos].nota2);
    (*totalDeAlunos)++;
    printf("Aluno adicionado\n");


}
void listAluno(struct aluno Turma[], int  totalDeAlunos){
    if(totalDeAlunos == 0){
        printf("Não consta nenhum aluno.\n");
        return;
    }
    printf("----------LISTA DE ALUNOS----------\n");
    for(int i=0; i < totalDeAlunos; i++){
        printf("Aluno #%d\n", i+1);
        printf("Nome do aluno:  %s\n", Turma[i].nomeAluno);
        printf("Idade do aluno: %d\n", Turma[i].idadeAluno);
        printf("Primeira nota: %.2f\n", Turma[i].nota1);
        printf("Segunda nota: %.2f\n", Turma[i].nota2);
//calculando a média
        float media = (Turma[i].nota1 + Turma[i].nota2)/2.0;
        printf("média do aluno: %.2f\n", media);
    }
}
void calculoMedia(struct aluno Turma[], int totalDeAlunos){
    if(totalDeAlunos == 0){
        printf("Não consta nenhum aluno.\n");
        return;
    }
    char buscarnome[80];
    printf("----------CALCULANDO A MÉDIA DO ALUNO----------\n");
    printf("Digite o nome do aluno: \n");
    scanf(" %[^\n]", buscarnome);
    int alunoEncontrado = 0;
    for(int i=0; i<totalDeAlunos; i++){
        if(strcmp(Turma[i].nomeAluno, buscarnome)==0){
            float media = (Turma[i].nota1 + Turma[i].nota2)/2.0;
            Turma[i].media= media;
            printf("Média do aluno %s: %.2f\n", Turma[i].nomeAluno, media);
            alunoEncontrado = 1;
            break;
        }
    }
    if(!alunoEncontrado){
        printf("Não foi encontrado nenhum aluno com esse nome.");
    }
}
void editAluno (struct aluno Turma[], int totalDeAlunos){
    if(totalDeAlunos == 0){
        printf("Não há alunos registrados.\n");
        return;
    }
    char buscarnome[80];
    printf("Digite o nome do aluno: \n");
    scanf(" %[^\n", buscarnome);
    int encontrado = 0;
    for(int i=0; i < totalDeAlunos; i++){
        printf("Aluno encontrado, exibindo dados atuais: \n");
        printf("Nome do aluno: %s\n", Turma[i].nomeAluno);
        printf("Idade do aluno: %d\n", Turma[i].idadeAluno);
        printf("Nota 1: %.2f\n", Turma[i].nota1);
        printf("Nota 2: %.2f\n", Turma[i].nota2);
        //adicionando novos dados
        printf("Digite os novos dados: \n");
        printf("Nova nota 1: \n");
        scanf("%f", &Turma[i].nota1);
        printf("Nova nota 2: \n");
        scanf("%f", &Turma[i].nota2);
        Turma[i].media = (Turma[i].nota1 + Turma[i].nota2)/2.0;
        printf("Notas atualizadas com sucesso!\n");
        encontrado = 1;
        break;
    }

}
void removerAluno(struct aluno Turma[], int *totalDeAlunos){
    if(*totalDeAlunos == 0){
        printf("Não há alunos cadastrados para poder remover.\n");
        return;
    }
    char buscarnome[80];
    printf("Digite o nome no aluno para remove-lo: \n");
    scanf("%[^\n]", buscarnome);
    int encontrado = 0;
    for(int i=0; i < totalDeAlunos; i++){
        if(strcmp(Turma[i].nomeAluno, buscarnome) == 0){
            for(int j = i; j < totalDeAlunos - 1; j++){
                Turma[j] = Turma[j + 1];
            }
            (*totalDeAlunos)--;
            printf("Aluno removido com sucesso.\n");
            encontrado = 1;
            break;
        }
    }
    if(!encontrado){
        printf("Não consta nenhum aluno com esse nome!\n");
    }
}
int main(){
    setlocale (LC_ALL, "portuguese");
//definindo o vetor de structs
    struct aluno Turma[maxAlunos];
    int totalDeAlunos = 0;
    int opcao;
    do{
//fazendo o menu principal
    printf("-----SISTEMA DE GERENCIAMENTO DE ALUNOS-----\n");
    printf("Selecione uma das opções: \n");
    printf("1. Adicionar aluno.\n");
    printf("2. Listar os alunos.\n");
    printf("3. Calcular a média do aluno.\n");
    printf("4. Para editar notas do aluno.\n");
    printf("5. Para remover aluno da sala.\n");
    printf("6. Para sair\n");
    scanf("%d", &opcao);
        switch(opcao){
            case 1:
                addAluno(Turma, &totalDeAlunos);
                break;
            case 2:
                listAluno(Turma, totalDeAlunos);
//listando alunos
            break;
            case 3:
                calculoMedia(Turma, totalDeAlunos);
                break;
            case 4:
                editAluno(Turma, totalDeAlunos);
            break;
            case 5:
                removerAluno(Turma, totalDeAlunos);
            break;
            case 6:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida! Verifique e tente novamente.");

        }
    }
    while (opcao != 6);
    return 0;
    }
