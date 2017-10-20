#include <stdio.h>
#include <stdlib.h>

/**
    Fazendo um ponteiro receber valores de um vetor.
*/

int main() {
    int v[] = { 1, 8, 3, 9, 5, 4 };
    int * p, i, qtd;

    qtd = (sizeof(v) / sizeof(int));

    p = &v[0];

    for(i = 0; i < qtd; i++, p++) {
        printf("Posição %d -> %d \n", i, *p);
    }
}
