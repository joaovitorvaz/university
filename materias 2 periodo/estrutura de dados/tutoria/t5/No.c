#include <stdio.h>
#include <stdlib.h>
#include "no.h"

struct no{
  int info;
  No* prox;
};

No* criaNo(int info){
  No* no = malloc(sizeof(No));
  no->info = info;
  no->prox = NULL;
  return no;
}

void liberaNo(No *no){
  free(no);
}

int getInfoNo(No* no){
  return no->info;
}

No* getProxNo(No* no){
  return no->prox;
}

void setInfoNo(No* no, int info){
  no->info = info;
}

void setProxNo(No* no, No* noProx){
  no->prox = noProx;
}

void imprimeNo(No *no){
  printf("info: %d\n", no->info);
}
