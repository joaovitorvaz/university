#include "Aleatorio.h"

int Aleatorio(int *v, int tam){
  for(int i=0; i<tam; i++){
    v[i]=rand()%tam;
  }
}

void Printar(int *v, int tam){
    for (int i=0; i<tam; i++){
        printf("%d  ", v[i]);
    }
}
