#include <stdio.h>

int main(void) {

    int y = 5;
    int * yPtr;

    yPtr = &y;

    printf("%d", *yPtr); // conteúdo do ponteiro
    printf("%p", &yPtr); // endereço do ponteiro

    *yPtr = 9;

    return 0;
}