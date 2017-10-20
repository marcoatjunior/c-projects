#include <stdio.h>
#include <stdlib.h>

/**
    Invertendo posições de um vetor com ponteiro
*/

int main() {
    int v[] = { 1, 8, 3, 9, 5, 4 };
    int * p, * p2, i, qtd;

    qtd = (sizeof(v) / sizeof(int));

    p = &v[qtd - 1];

    for(i = 0; i < qtd; i++, p--) {
        printf("%d -> %d \n", i, *p);
    }
}
