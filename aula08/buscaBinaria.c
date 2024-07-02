#include <stdio.h>

int buscaBinaria(int a[], int inicio, int fim, int x) {
    int meio;

    if(inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (x == a[meio]) {
            return meio;

        } else {
            if(a[meio] < x) {
                return buscaBinaria(a, meio + 1, fim, x);
            } else {
                return buscaBinaria(a, inicio, meio - 1, x);
            }
        }
    } else {
        return -1;
    }
}

int main(void) {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7};

    printf("%d", buscaBinaria(a, 6, -1));

    return 0;
}