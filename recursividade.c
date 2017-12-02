#include <stdio.h>
#include <stdlib.h>

/** 1. Escreva uma fun��o em C, recursiva, para imprimir todos os n�meros de 0 at� N em ordem crescente. N deve ser solicitado ao usu�rio. */
int recursionIncreasing(int n, int aux){
    printf("%d \n", aux);
    return n > aux ? recursionIncreasing(n, aux + 1) : 0;
}

/** 2. Escreva uma fun��o em C, recursiva, para imprimir todos os n�meros naturais de 0 at� N em ordem decrescente. N deve ser solicitado ao usu�rio. */
int recursionDecreasing(int n){
    printf("%d \n", n);
    return n > 0 ? recursionDecreasing(n - 1) : 0;
}

/** 3. Crie uma fun��o recursiva que retorne a soma dos elementos de um vetor de inteiros. */
int recursionWithVector(int vector[], int aux, int amount){
    amount += vector[aux];
    return vector[aux] ? recursionWithVector(vector, aux + 1, amount) : amount;
}

int createVector(int vector[]){
    int i = 0;
    for(i = 0; i < 10; i++){
        printf("Digite um numero: ");
        scanf("%d", &vector[i]);
    }
    return vector;
}

int main(){
    int num, aux = 0, amount = 0;
    int vector[9];

    printf("Digite um numero: ");
    scanf("%d", &num);

    /** Chamando recurs�o crescente */
    printf("\n");
    printf("Sequencia Crescente: \n");
    recursionIncreasing(num, aux);

    /** Chamando recurs�o decrescente */
    printf("\n");
    printf("Sequencia Decrescente: \n");
    recursionDecreasing(num);

    printf("\n");
    system("pause");
    system("cls");

    /** Criando vetor */
    createVector(vector);

    /** Chamando recurs�o de soma dos elementos do vetor */
    printf("\n");
    amount = recursionWithVector(vector, aux, amount);
    printf("A soma dos valores foi: %d", amount);
}
