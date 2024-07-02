#include <stdio.h>

void ordenarPorInsercao(int a[], int n) {
    if (n >= 0) {
        ordenarPorInsercao(a, n - 1);
        int i =n;
        while(i >= 1 && (a[i] < a[i-1])) {
            int aux = a[i];
            a[i] = a[i-1];
            a[i-1] = aux;
            i--;
        }
    }
}

int main(void) {
    int a[] = {5, 4, 3, 2, 1};
    ordenarPorInsercao(a, 4);
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}