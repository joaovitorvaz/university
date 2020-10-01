#include <stdio.h>
#include "Funcoes.h"

#define T 5

int main(){

    int vetor[T], resultado, x, y;

    printf("Bem vindo aos exercicios.\n\n\n");

    for(int i=0; i<T; i++){
        scanf("%d", &vetor[i]);
    }

    resultado=SomadeValores(vetor, T);

    printf("Questão 1) Resultado = %d  \n\n", resultado);

    printf("Questão 2) Resultado = ");
    InverteArray(vetor, T);

    for(int i=0; i<T; i++){
        printf("%d  ", vetor[i]);
    }

    scanf("%d %d", &x, &y);

    resultado=MOD(x, y);

    printf("\n\nQuestão 3) Resultado = %d  \n\n", resultado);

    resultado=Somatorio(T);
    printf("Questão 4) Resultado = %d\n\n", resultado);

    return 0;
}
