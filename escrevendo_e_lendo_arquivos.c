#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char stringToFile(FILE * file, char * text[]){

    printf("Digite qualquer texto: \n");
    gets(text);

    strcat(text, "\n");

    fprintf(file, text);

    return text;
}

char moreInformation(FILE * file, char * text[]){

	char option;

    do{
        printf("Voce deseja inserir mais conteudo no arquivo? Digite S para Sim e N para Nao. \n");
        scanf("%c", &option);
        fflush(stdin);

        switch(option){
            case 'S':
                stringToFile(file, text);
            break;

            case 'N':
                printf("Informações adicionadas com sucesso. \n");
                return;
            break;

            default:
                printf("Digite uma opção valida! \n");
        }
    } while(option);
}

int main(){

    FILE * file;
    char * text[400];

    setlocale(LC_ALL,"");

    file = fopen("marco_taborda_texto.txt", "w");

    if (file == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    /* Passo 1 */
    stringToFile(file, text);

    /* Passos 2, 3, 4 e 5 */
    moreInformation(file, text);

    fclose(file);

    /* Passo 6 */
    file = fopen("marco_taborda_texto.txt", "r");

    if (file == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    while(fgets(text, 400, file) != NULL){
        /* Passos 7 e 8 */
        printf("O conteúdo do arquivo criado é: \n %s", text);
    }

    /* Passo 9 */
    fclose(file);

    /* Passo 10 */
    return 0;
}
