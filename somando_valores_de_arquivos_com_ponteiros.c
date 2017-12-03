#include <stdio.h>
#include <stdlib.h>

void ifIsUnreadable(FILE * file){
    if (file == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }
}

int readIntValue(FILE * file, const char * name){
    file = fopen(name, "r");
    int i = 0, * values;

    fscanf (file, "%d", &i);

    while (!feof (file)){
        fscanf (file, "%d", &i);
        printf("%d", i);
    }

    fclose (file);

    return values;
}

int main(){

    FILE * fileOne;
    FILE * fileTwo;
    FILE * result;

    int * vet1, * vet2, * values;
    int i = 0;

    // Verifica conteúdo dos arquivos
    ifIsUnreadable(fileOne);
    ifIsUnreadable(fileTwo);

    // Recebe inteiros retornados do arquivo
    vet1 = readIntValue(fileOne, "LP_arquivo_1.txt");
    vet2 = readIntValue(fileTwo, "LP_arquivo_2.txt");

    // Cria arquivo de resultado
    result = fopen("marco_taborda_resultado.txt", "w");

    // Verifica conteúdo do arquivo
    ifIsUnreadable(result);

    // Adiciona ao ponteiro values cada valor das posições somadas
    for(i = 0; i < 9; i++, vet1++, vet2++, values++){
        * values = * vet1 + * vet2;
        fprintf(result, * values);
        strcat(* values, "\n");
    }

    // Fecha o arquivo
    fclose(result);

    // Finaliza o progrmada
    return 0;
}
