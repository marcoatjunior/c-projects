#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 10;
    int y = 2;
    int * p1 = &x;
    int * p2 = &y;
    int * aux = p1;

    printf("Valor Original X -> %d \n", *p1);
    printf("Valor Original Y -> %d \n\n", *p2);

    p1 = p2;
    p2 = aux;

    printf("Valor Modificado X -> %d \n", *p1);
    printf("Valor Modificado Y -> %d \n", *p2);
}
