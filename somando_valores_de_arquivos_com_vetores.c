#include <stdio.h>
#include <stdlib.h>

void ifIsUnreadable(FILE * file){

    if (file == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

}

void readIntValue(FILE * file, const char * name, int values[]){

    int i = 0, pos = 0;

    file = fopen(name, "r");

    ifIsUnreadable(file);

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

    int i = 0;
    int values1[10], values2[10], results[10];

    // Recebe inteiros retornados do arquivo
    readIntValue(fileOne, "LP_arquivo_1.txt", values1);
    readIntValue(fileTwo, "LP_arquivo_2.txt", values2);

    // Cria arquivo de resultado
    result = fopen("marco_taborda_resultado.txt", "w");

    // Verifica conteúdo do arquivo
    ifIsUnreadable(result);

    // Adiciona ao vetor results cada valor das posições somadas
    for(i = 0; i < 9; i++){
        results[i] = values1[i] + values2[i];
    }

    // Adiciona ao arquivo os resultados, de três em três
    for(i = 0; i < 9; i+=3){
        fprintf(result, "%d %d %d \n", results[i], results[i+1], results[i+2]);
    }

    // Fecha o arquivo
    fclose(result);

    // Finaliza o programa
    return 0;
}
