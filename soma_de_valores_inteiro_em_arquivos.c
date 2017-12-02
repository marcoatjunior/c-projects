#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE * fileOne;
    FILE * fileTwo;
    FILE * result;

    int number, i = 0, * values[20];
    int vet_lp_1[20], vet_lp_2[20];

    fileOne = fopen("LP_arquivo_1.txt", "r");

    if (fileOne == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < 9; i++){
        while(fscanf(fileOne,"%d",&number) > 0){
            vet_lp_1[i] = number;
        }
    }

    fclose(fileOne);

    fileTwo = fopen("LP_arquivo_2.txt", "r");

    if (fileTwo == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < 9; i++){
        while(fscanf(fileTwo,"%d",&number) > 0){
            vet_lp_2[i] = number;
        }
    }

    fclose(fileTwo);

    result = fopen("marco_taborda_resultado.txt", "w");

    if (result == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < 9; i++){
        values[i] = vet_lp_1[i] + vet_lp_2[i];
        fprintf(result, values);
    }

    fclose(result);

    return 0;
}
