#include "Funcoes.h"

int SomadeValores(int *vetor, int tam){

    if(tam==0){
        return 0;
    }
    else
        return vetor[tam-1] + SomadeValores(vetor, tam-1);
}

void InverteArray(int *vetor, int tam){

    int aux;

    if(tam==1){
        return;
    }

    aux=vetor[0];
    vetor[0]=vetor[tam-1];
    vetor[tam-1]=aux;

    return InverteArray(vetor+1, tam-2);
}


int MOD(int x, int y){
    if(x>y){
        return MOD(x-y, y);
    }
    else if(x<y){
        return x;
    }
    else
        return 0;
}

int Somatorio(int num){
    if(num==0){
        return 0;
    }
    else if(num==1){
        return 1;
    }
    else
        return num*Somatorio(num-1);
}
