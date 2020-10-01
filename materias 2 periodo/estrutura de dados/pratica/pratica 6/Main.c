#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Aleatorio.h"
#include "Ordenacao.h"

#define T 100

int main(){

  srand(time(NULL));

  int vetor[T];

  printf("Bem vindo ao nosso metodo de ordenação, utilizaremos os algoritmos Radix juntamente com o CoutingSort.");
  printf("\nAnalise o exemplo a seguir:");

  printf("\n\nVetor com conteudo aleatorio: ");
  Aleatorio(vetor, T);
  Printar(vetor, T);

  //Ordenando utilizando o RadixSort & CountingSort
  RadixSort(vetor, T);

  printf("\n\nVetor devidamente ordenado: ");
  Printar(vetor, T);

  printf("\n\n\nFINALIZANDO...");


  return 0;
}
