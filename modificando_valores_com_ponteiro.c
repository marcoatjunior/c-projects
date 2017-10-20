#include <stdio.h>
#include <stdlib.h>

/**
    Copiando valores de um vetor e adicionando valores com ponteiro
*/

int main() {
    int v[] = { 1, 8, 3, 9, 5, 4 };
    int * p, * p2, i, qtd;

    qtd = (sizeof(v) / sizeof(int));

    p = &v[0];

    for(i = 0; i < qtd; i++, p++) {
        * p += 2;
        printf("%d -> %d \n", i, *p);
    }
}
