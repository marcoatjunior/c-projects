#include <stdlib.h>
#include <stdio.h>

/**
    Exibir apenas números que não se repetem em um vetor com valores repetidos.
*/

int main(){
    int v[]={1,2,3,4,1,63,75,3,9,2,4,8,2, 5,21};
    int size = 15;
    int i, n, c, find;

    for (i = 0; i < size; i++){
        c = v[i];
        find = 0;

        for (n = 0; n < size; n++){
            if (n != i){
                if(v[n] == c){
                    find = 1;
                    break;
                }
            }
        }

        if (find == 0){
            printf("%d,", c);
        }
    }
}
