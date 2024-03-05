#include <stdio.h>

void tr(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void tr_r(int & x, int & y) {
    int temp = x;
    x = y;
    y = temp;
}

void tr_p(int * x, int * y) {
    int * temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 10, b = 20;
    printf("\na: %d, b: %d", a, b);
    tr(a, b);
    printf("\na: %d, b: %d", a, b);
    tr_r(a, b);
    printf("\na: %d, b: %d", a, b);
    tr_p(&a,&b);
    printf("\na: %d, b: %d", a, b);
}