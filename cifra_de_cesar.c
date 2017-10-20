#include <stdio.h>
#include <stdlib.h>

/**
    Programa que simula a "Cifra de César"
    Uma frase é digitada e os caracteres são convertidos em inteiros utilizando a tabela ASCII.
    Depois disso, os números são somados a um números escolhidos, mudando seu valor na tabela e
    retornando uma frase com caracteres diferentes, criptografando a mensagem.
*/

main(){
    char text[50];
    int i, ref[30], cont, num, aux[50];

    printf("Digite uma frase: ");
    gets(text);
    fflush(stdin);
    cont = strlen(text);

    printf("Frase digitada segundo a tabela ASCII:\n");

    for(i = 0; i < cont; i++){
        printf("%d ", text[i]);
        aux[i] = text[i];
    }

    printf("\n");
    system("pause");
    system("\n");

    printf("Digite um numero: ");
    scanf("%d", &num);

    printf("\n");
    printf("Frase criptograda: ");

    for(i = 0; i < cont; i++){
        ref[i] = aux[i] + num;
        if(ref[i] > 89){
            ref[i] = ref[i] - 26;
        }
        if(ref[i] == 32){
            ref[i] = 32;
        }
        printf("%c", ref[i]);
    }
}
