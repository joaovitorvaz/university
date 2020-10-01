#include "Cases.h"

void case1Buble(int *v, int tam){
  printf("---BUBLESORT---");

  printf("\n\nValores aleatorios.");
  TempoAtualInicial();
  Aleatorio(v, tam);
  Buble(v, tam);
  TempoAtualFinal();

  printf("\n\nValores crescentes.");
  TempoAtualInicial();
  OrdenadoCresc(v, tam);
  Buble(v, tam);
  TempoAtualFinal();

  printf("\n\nValores decrescentes.");
  TempoAtualInicial();
  OrdenadoDescre(v, tam);
  Buble(v, tam);
  TempoAtualFinal();
}

void case2Selection(int *v, int tam){
  printf("\n\n\n---SELECTIONSORT---");

  printf("\n\nValores aleatorios.");
  TempoAtualInicial();
  Aleatorio(v, tam);
  SelectionSort(v, tam);
  TempoAtualFinal();

  printf("\n\nValores crescentes.");
  TempoAtualInicial();
  OrdenadoCresc(v, tam);
  SelectionSort(v, tam);
  TempoAtualFinal();

  printf("\n\nValores decrescentes.");
  TempoAtualInicial();
  OrdenadoDescre(v, tam);
  SelectionSort(v, tam);
  TempoAtualFinal();
}

void case3Merge(int *v, int tam){
  printf("\n\n\n---MERGESORT---");

  printf("\n\nValores aleatorios.");
  TempoAtualInicial();
  Aleatorio(v, tam);
  MergeOrdena(v, 0, tam-1);
  TempoAtualFinal();

  printf("\n\nValores crescentes.");
  TempoAtualInicial();
  OrdenadoCresc(v, tam);
  MergeOrdena(v, 0, tam-1);
  TempoAtualFinal();

  printf("\n\nValores decrescentes.");
  TempoAtualInicial();
  OrdenadoDescre(v, tam);
  MergeOrdena(v, 0, tam-1);
  TempoAtualFinal();
}

void case4Insertion(int *v, int tam){
  printf("\n\n\n---INSERTIONSORT---");

  printf("\n\nValores aleatorios.");
  TempoAtualInicial();
  Aleatorio(v, tam);
  InsertionSort(v, tam);
  TempoAtualFinal();

  printf("\n\nValores crescentes.");
  TempoAtualInicial();
  OrdenadoCresc(v, tam);
  InsertionSort(v, tam);
  TempoAtualFinal();

  printf("\n\nValores decrescentes.");
  TempoAtualInicial();
  OrdenadoDescre(v, tam);
  InsertionSort(v, tam);
  TempoAtualFinal();
}
