#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Valores.h"
#include "Ordenacao.h"
#include "Cases.h"

int main(){

  srand(time(NULL));

  int vetor[T];
  int chave;

  do{

    scanf("%d", &chave);

    switch (chave){
      case 1: //BubleSort
        case1Buble(vetor, T);
      break;

      case 2: //SelectionSort
        case2Selection(vetor, T);
      break;

      case 3: //MergeSort
        case3Merge(vetor, T);
      break;

      case 4:
        case4Insertion(vetor, T);
      break;
    }

  }while(chave!=0);

  return 0;
}
