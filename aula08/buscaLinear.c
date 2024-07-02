#include <stdio.h>

int buscaLinear(int a[], int n, int x) {
	
	if (n == 0){
		return -1;
		} else {
	if (x==a[n-1]) {
		return n - 1;
	} else {
		return buscaLinear(a, n-1, x);}
	}

}

int main(void) {

	int a[] = {3,0,7,-1,2,10};

	printf("%d", buscaLinear(a, 6, -1));

	return 0;
}