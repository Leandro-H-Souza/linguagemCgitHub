#include <stdio.h>
#include <locale.h>
#include <string.h>
#define maxAlunos 50
#define MAX_STRING 79
#define Registro_Arquivo "dadosDosAlunos.txt"
struct aluno{
    char nomeAluno[80];
    int idadeAluno;
    float nota1, nota2;
    float media;
    };
void SalvarDados(struct aluno Turma[], int totalDeAlunos){
    FILE *arquivo = fopen(Registro_Arquivo, "w");
    if (arquivo == NULL){
        printf("Erro: Impossível abrir o arquivo para salvar!\n");
        return;
    }
    fprintf(arquivo, "%d\n", totalDeAlunos);
    for (int i = 0; i < totalDeAlunos; i++) {
        fprintf(arquivo, "%s, %d, %.2f, %.2f, %.2f\n",
                Turma[i].nomeAluno,
                Turma[i].idadeAluno,
                Turma[i].nota1,
                Turma[i].nota2,
                Turma[i].media);
    }
    fclose(arquivo);
    printf("Dados salvos com sucesso em %s.\n", Registro_Arquivo);
}
void CarregandoDados(struct aluno Turma[], int *totalDeAlunos){
    FILE *arquivo = fopen(Registro_Arquivo, "r");

    if(arquivo == NULL){
        printf("Arquivo de dados não encontrado. Iniciando com turma vazia.\n");
        *totalDeAlunos = 0;
        return;
    }
    if (fscanf(arquivo, "%d\n", totalDeAlunos) != 1) {
        printf("Erro de leitura: Arquivo vazio ou corrompido.\n");
        *totalDeAlunos = 0;
        fclose(arquivo);
        return;
    }
    for (int i = 0; i < *totalDeAlunos; i++) {
        if (fscanf(arquivo, " %79[^,], %d, %f, %f, %f\n",
               Turma[i].nomeAluno,
               &Turma[i].idadeAluno,
               &Turma[i].nota1,
               &Turma[i].nota2,
               &Turma[i].media) != 5) {
                printf("Aviso: Leitura de dados parciais. Arquivo pode estar incompleto.\n");
               *totalDeAlunos = i;
               break;
        }
    }
    fclose(arquivo);
    printf("Dados de %d alunos carregados com sucesso.\n", *totalDeAlunos);
}
void addAluno(struct aluno Turma[], int *totalDeAlunos){
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
    Turma[*totalDeAlunos].media = (Turma[*totalDeAlunos].nota1 + Turma[*totalDeAlunos].nota2) / 2.0;
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
//calculando a m�dia
        float media = (Turma[i].nota1 + Turma[i].nota2)/2.0;
        printf("Média do aluno: %.2f\n", Turma[i].media);
    }
}
void calculoMedia(struct aluno Turma[], int totalDeAlunos){
    if(totalDeAlunos == 0){
        printf("Não consta nenhum aluno.\n");
        return;
    }
    char buscarnome[80];
    printf("\n----------CALCULANDO A M�DIA DO ALUNO----------\n");
    printf("Digite o nome do aluno: \n");
    scanf(" %79[^\n]", buscarnome);
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
        printf("\nNão foi encontrado nenhum aluno com esse nome.\n");
    }
}
void editAluno (struct aluno Turma[], int totalDeAlunos){
    if(totalDeAlunos == 0){
        printf("Não há alunos registrados.\n");
        return;
    }
    char buscarnome[80];
    printf("Digite o nome do aluno: \n");
    scanf(" %79[^\n]", buscarnome);
    int encontrado = 0;
    for(int i=0; i < totalDeAlunos; i++){
        if(strcmp(Turma[i].nomeAluno, buscarnome) == 0){
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
    if(!encontrado){
        printf("\nNão consta nenhum(a) aluno com esse nome\n");
    }

}
void removerAluno(struct aluno Turma[], int *totalDeAlunos){
    if(*totalDeAlunos == 0){
        printf("Não há alunos cadastrados para poder remover.\n");
        return;
    }
    char buscarnome[80];
    printf("Digite o nome no aluno para remove-lo: \n");
    scanf(" %79[^\n]", buscarnome);
    int encontrado = 0;
        if(strcmp(Turma[i].nomeAluno, buscarnome) == 0){

            for(int j = i; j < *totalDeAlunos - 1; j++){
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
    setlocale(LC_ALL, "portuguese");
    struct aluno Turma[maxAlunos];
    int totalDeAlunos = 0;
    int opcao;
    CarregandoDados(Turma, &totalDeAlunos);
    do{

    printf("\n-----SISTEMA DE GERENCIAMENTO DE ALUNOS-----\n");
    printf("Selecione uma das opções: \n");
    printf("1. Adicionar aluno.\n");
    printf("2. Listar os alunos.\n");
    printf("3. Calcular a média do aluno.\n");
    printf("4. Para editar notas do aluno.\n");
    printf("5. Para remover aluno da sala.\n");
    printf("6. Para salvar os dados e sair.\n");
    scanf("%d", &opcao);
        while (getchar() != '\n');
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
                SalvarDados(Turma, totalDeAlunos);
                printf("Dados salvos com sucesso. Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida! Verifique e tente novamente.");

        }
    }
}