#include <stdio.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[60];
    double ira;
} Aluno;

// Função para ordenar os alunos por matrícula usando o método da seleção
void ordenarMatricula(Aluno alunos[], int tamanho) {
    int i, j;
    Aluno temp;

    for (i = 0; i < tamanho - 1; i++) {
        // Encontra o índice do menor elemento no subarray não ordenado
        int menor = i;
        for (j = i + 1; j < tamanho; j++) {
            if (alunos[j].matricula < alunos[menor].matricula) {
                menor = j;
            }
        }
        // Troca o menor elemento com o primeiro elemento do subarray não ordenado
        temp = alunos[i];
        alunos[i] = alunos[menor];
        alunos[menor] = temp;
    }
}

// Função para ordenar os alunos por IRA usando o método da bolha
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

// Função para listar os alunos
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

    // Ordena os alunos por matrícula e lista o vetor ordenado
    ordenarMatricula(alunos, 10);
    listarVetor(alunos, 10);

    // Ordena os alunos por IRA e lista o vetor ordenado
    ordenarIra(alunos, 10);
    listarVetor(alunos, 10);

    return 0;
}
