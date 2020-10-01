#include "Valores.h"

void Aleatorio(int *vetor, int tam){
  for(int i=0; i<tam; i++){
    vetor[i]=rand()%tam;
  }
}

void OrdenadoCresc(int *vetor, int tam){
  for(int i=0; i<tam; i++){
    vetor[i]=i;
  }
}

void OrdenadoDescre(int *vetor, int tam){
  for(int i=tam; i>0; i--){
    vetor[tam-i]=i;
  }
}

void Printar(int *vetor, int tam){
  for(int i=0; i<tam; i++){
    printf("%d  ", vetor[i]);
  }
  printf("\n");
}

void TempoAtualInicial(){
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo=localtime( &rawtime );
  printf("\n\nIniciando:   %s", asctime(timeinfo));
}

void TempoAtualFinal(){
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo=localtime( &rawtime );
  printf("Finalizado:  %s", asctime(timeinfo));
}
