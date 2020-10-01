#include "No.h"

struct no{
  float temp;
  char identificador[20];
  char descricao[100];
  No *prox;
};

No* CriaNo(int n){
  No* no=malloc(sizeof(No));
  char identificador[20], descricao[50];
  clock_t t=clock();
  scanf("%s", identificador);
  scanf("%s", descricao);
  loop(n);
  t=clock()-t;
  no->temp=((float)t)/CLOCKS_PER_SEC;
  strcpy(no->identificador, identificador);
  strcpy(no->descricao, descricao);
  setProxNo(no, NULL);
  return no;
}

void loop(int n){
  int x;
  for(int i=0; i<n; i++){
    x+=i+n;
  }
}

No* LiberaNo(No* no){
  free(no);
}

void setTemp(No *no, float temp){
  no->temp=temp;
}

void setIdentificadorNo(No *no, char *identificador){
    strcpy(no->identificador, identificador);
}

void setDescricaoNo(No *no, char *descricao){
    strcpy(no->descricao, descricao);
}

void setProxNo(No* no, No* prox){
  no->prox=prox;
}

float getTempNo(No *no){
    return no->temp;
}

char* getIdentificadorNo(No *no){
    return no->identificador;
}

char* getDescricaoNo(No *no){
    return no->descricao;
}

No* getProxNo(No* no){
  return no->prox;
}
