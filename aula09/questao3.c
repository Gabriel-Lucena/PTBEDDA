#include <stdio.h>

int buscaBinaria(int vetor[], int esquerda, int direita, int x)
{
    if (direita >= esquerda)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        // Se o elemento está presente no meio
        if (vetor[meio] == x)
            return meio;

        // Se o elemento é menor que o meio, ele só pode estar presente no subarray esquerdo
        if (vetor[meio] > x)
            return buscaBinaria(vetor, esquerda, meio - 1, x);

        // Senão, o elemento só pode estar presente no subarray direito
        return buscaBinaria(vetor, meio + 1, direita, x);
    }

    // O elemento não está presente no array
    return -1;
}

int main()
{
    int vetor[] = {2, 3, 4, 10, 40};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int x = 40;
    int resultado = buscaBinaria(vetor, 0, n - 1, x);
    if (resultado == -1)
        printf("Elemento não está presente no array");
    else
        printf("Elemento está presente no índice %d", resultado);
    return 0;
}
