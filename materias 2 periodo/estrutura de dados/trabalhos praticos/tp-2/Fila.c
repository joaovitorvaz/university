#include "Fila.h"

struct fila{
  No* prim;
  No* ult;
};

Fila* CriaFila(){
  Fila* fila=malloc(sizeof(Fila));
  fila->prim=NULL;
  fila->ult=NULL;
  return fila;
}

void LiberaFila(Fila *fila){
  No* p= fila->prim;
  while(p!=NULL){
    No* t=getProxNo(p);
    free(p);
    p=t;
  }
  free(fila);
}

void fila_inserefinal(Fila* fila, int n){
	No* aux = fila->ult;
	No* new = CriaNo(n);

	if(aux == NULL){
		fila->prim = new;
		fila->ult = new;
		setProxNo(new, NULL);
	}

	else{
		setProxNo(aux, new);
		fila->ult = new;
		setProxNo(new, NULL);
	}
}

void fila_retiraprim(Fila* fila){
	No* no=fila->prim;
  fila->prim=getProxNo(no);
  if(fila->prim==NULL){
    fila->ult==NULL;
  }
  free(no);
}

void fila_imprime(Fila* fila){
  	No* aux=fila->prim;
  	float time;
    char identificador[20], descricao[50];

  	while(aux != NULL){
  		time=getTempNo(aux);
      strcpy(identificador, getIdentificadorNo(aux));
      strcpy(descricao, getDescricaoNo(aux));

  		printf("%f\n", time);
      printf("%s\n", identificador);
      printf("%s\n\n", descricao);

  		aux=getProxNo(aux);
  	}
}

void setPrim(Fila *fila, No *prim){
  fila->prim=prim;
}

void setUlt(Fila *fila, No *ult){
  fila->ult=ult;
}

No* getPrimFila(Fila* fila){
  return fila->prim;
}

No* getUltFila(Fila* fila){
  return fila->ult;
}
