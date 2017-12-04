#include <stdio.h>
#include <stdlib.h>

void ifIsUnreadable(FILE * file){
    if (file == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }
}

void readIntValue(FILE * file, const char * name, int values[]){
    file = fopen(name, "r");
    int i = 0, pos = 0;

    while (!feof (file)){
        fscanf (file, "%d", &i);
        values[pos] = i;
        pos++;
    }

    fclose (file);
}

int main(){
    FILE * fileOne;
    FILE * fileTwo;
    FILE * result;

    int i = 0, * sum;
    int values1[10], values2[10], results[10];

    // Verifica conteúdo dos arquivos
    ifIsUnreadable(fileOne);
    ifIsUnreadable(fileTwo);

    // Recebe inteiros retornados do arquivo
    readIntValue(fileOne, "LP_arquivo_1.txt", values1);
    readIntValue(fileTwo, "LP_arquivo_2.txt", values2);

    // Cria arquivo de resultado
    result = fopen("marco_taborda_resultado.txt", "w");

    // Verifica conteúdo do arquivo
    ifIsUnreadable(result);

    sum = &results[0];

    // Adiciona ao vetor results cada valor das posições somadas
    for(i = 0; i < 9; i++, sum++){
        results[i] = values1[i] + values2[i];
        printf("Soma Posicao %d = %d \n", i+1, results[i]);
        fprintf(result, sum);
        strcat(sum, "\n");
    }

    // Fecha o arquivo
    fclose(result);

    // Finaliza o programa
    return 0;
}
