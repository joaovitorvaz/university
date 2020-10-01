#include "Lista.h"

struct lista{
  No* prim;
  No* ult;
};

Lista* CriaLista(){
  Lista* lista=malloc(sizeof(Lista));
  lista->prim=NULL;
  lista->ult=NULL;
  return lista;
}

void LiberaLista(Lista *lista){
  No* p= lista->prim;
  while(p!=NULL){
    No* t=getProxNo(p);
    free(p);
    p=t;
  }
  free(lista);
}

void lst_insere_comeco(Lista* lista, int v){
 No* aux=CriaNo();
 setContNo(aux, v);
 if(lista->prim == NULL){
   setPrim(lista, aux);
   setUlt(lista, aux);
 }
 else
  setProxNo(aux, lista->prim);
  lista->prim=aux;
}

void lst_inserefinal(Lista* lista, int v){
	No* aux = lista->ult;
	No* new = CriaNo();
	setContNo(new, v);

	if(aux == NULL){
		lista->prim = new;
		lista->ult = new;
		setProxNo(new, NULL);
	}

	else{
		setProxNo(aux, new);
		lista->ult = new;
		setProxNo(new, NULL);
	}
}

void lst_retira(Lista* lista, int v){

  No* aux = lista->prim;

  if(getContNo(aux) == v){
    No* aux1 = getProxNo(aux);
    lista->prim = aux1;
    LiberaNo(aux);
  }

  else
    lstRetiraNo(lista->prim, v);

  aux = lista->prim;
  No* ant = NULL;

  while(aux != NULL){
    ant = aux;
    aux = getProxNo(aux);
  }

  lista->ult = ant;
}

void lstRetiraNo(No* no, int v){
	No* atu = getProxNo(no);
	No* pro = getProxNo(atu);

	if(getContNo(atu) == v){
		setProxNo(no, pro);
		LiberaNo(atu);
	}
	else
		lstRetiraNo(atu, v);
}

int lst_retiraprim(Lista* lista){
	No* no = lista->prim;
	int aux = getContNo(no);

	if(getContNo(no) == 0){
		LiberaNo(no);
		lista->prim = NULL;
		lista->ult = NULL;
	}

	else{
		No* newno = getProxNo(no);
		lista->prim = newno;
	}

	return aux;
}

int lst_vazia(Lista* lista){
  	if(lista->prim == NULL){
  		return 0;
    }
  	return 1;
}

int pertence(Lista* lista, int v){
	if(lst_pertence(lista->prim, v)){
		return 1;
  }
	else
		return 0;
}

int lst_pertence(No* no, int v){
  	if(getContNo(no)==v)
  		return 1;

  	else{
  		if(getProxNo(no) != NULL){
  			return lst_pertence(getProxNo(no), v);
      }
  		else
  			return 0;
  	}
}

void lst_imprime(Lista* lista){
  	No* aux = lista->prim;
  	int dado;

  	while(aux != NULL){
  		dado=getContNo(aux);
      if(dado==0){}
      else
  		  printf("%d ", dado);
  		aux=getProxNo(aux);
  	}
}

void setPrim(Lista *lista, No *prim){
  lista->prim=prim;
}

void setUlt(Lista *lista, No *ult){
  lista->ult=ult;
}

No* getPrimLista(Lista* lista){
  return lista->prim;
}

No* getUltLista(Lista* lista){
  return lista->ult;
}
