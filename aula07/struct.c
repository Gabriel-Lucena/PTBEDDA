#include <stdio.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[60];
    double ira;
} Aluno;

void ordenarMatricula(Aluno alunos[], int tamanho) {}

void ordenarIra(Aluno alunos[], int tamanho) {
    int i, j;
    Aluno temp; 

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (alunos[j].ira > alunos[j + 1].ira) {
                temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}

void listarVetor(Aluno alunos[], int tamanho) {

    printf("\nListando vetor:\n");
    for (int i = 0; i < tamanho; i++) {

        printf("\nMatrícula: %d\n", alunos[i].matricula);
        printf("Nome: %s\n", alunos[i].nome);
        printf("I.R.A.: %.2f\n", alunos[i].ira);
    }
}

int main() {
    
    Aluno alunos[10];

    // Leitura de arquivos
    
    FILE *arquivo;

    // Abertura do arquivo em modo leitura
    arquivo = fopen("alunos.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; // Retorna 1 em caso de erro
    }

    // Leitura dos dados do arquivo e registro nas variáveis
    
    int a = 0;

    while (fscanf(arquivo, "%d %s %lf", &alunos[a].matricula, alunos[a].nome, &alunos[a].ira) != EOF) {
        a++;
    }

    // Fechamento do arquivo
    fclose(arquivo);

    // for (int i = 0; i < 10; i++) {
    //     printf("Digite os dados do aluno %d:\n", i + 1);
    //
    //     printf("\nDigite a matricula desse aluno: ");
    //     scanf("%d", &alunos[i].matricula);
    //
    //     printf("\nDigite o nome desse aluno: ");
    //     getchar();
    //     fgets(alunos[i].nome, 60, stdin);
    //
    //     printf("\nDigite o I.R.A desse aluno: ");
    //     scanf("%lf", &alunos[i].ira);
    //
    //     printf("\n");
    // }

    // ordenarMatricula(alunos, 10);

// Dada a seguinte estrutura Aluno com os campos: Matrícula (número inteiro), Nome (60 caracteres), I.R.A - Índice de Rendimento Acadêmico (número com ponto flutuante).
//
// Implemente um programa em C ou C++ que receba os dados de 10 alunos e os armazene em um vetor.
//
// O programa deverá exibir os alunos por ordem de matrícula - implemente a ordenação utilizando o método da seleção ou inserção.
//
// Ordene e mostre o vetor ordenado pelo IRA - implemente a ordenação pelo método da bolha.
//
//
// É importante comentar o código e explicar as etapas de implementação.

    ordenarMatricula(alunos, 10);
    listarVetor(alunos, 10);

    ordenarIra(alunos, 10);
    listarVetor(alunos, 10);

    return 0;
}
