#include "No.h"

struct no{
  int cont;
  No *prox;
};

No* CriaNo(){
  No* no=malloc(sizeof(No));
  setProxNo(no, NULL);
  return no;
}

No* LiberaNo(No* no){
  free(no);
}

void setContNo(No* no, int cont){
  no->cont=cont;
}

void setProxNo(No* no, No* prox){
  no->prox=prox;
}

int getContNo(No* no){
  return no->cont;
}

No* getProxNo(No* no){
  return no->prox;
}
