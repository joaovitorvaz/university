#include <stdio.h>
#define T 10

int pesquisaBinaria(int *v, int chave, int esq, int dir);

int main(){

  int v[T];
  int chave, esq, dir, retorno;

  for(int i=0; i<T; i++){
    v[i]=i;
  }

  esq=0;
  dir=9;

  scanf("%d", &chave);
  retorno=pesquisaBinaria(v, chave, esq, dir);
  printf("\nPosicao = %d\n", retorno+1);

  return 0;
}

int pesquisaBinaria(int *v, int chave, int esq, int dir){

  if(esq>dir){
    return -1;
  }

  int aux=(esq+dir)/2;

  if(chave==v[aux]){
    return aux;
  }

  else if(chave<v[aux]){
    return pesquisaBinaria(v, chave, esq, aux-1);
  }

  else
    return pesquisaBinaria(v, chave, aux+1, dir);
}
