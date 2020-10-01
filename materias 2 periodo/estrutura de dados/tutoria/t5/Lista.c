#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "No.h"

struct lista{
  No* prim;
  No* ult;
};

Lista* lst_cria(void){
  Lista *l = malloc(sizeof(Lista));
  l->prim = NULL;
  l->ult = NULL;
  return l;
}

void lst_libera(Lista* l){
  No* p = l->prim;
  while(p != NULL){
    No* t = getProxNo(p);
    free(p);
    p = t;
  }
  free(l);
}

void lst_insere(Lista *l, int info){
  No* novo = criaNo(info);
  setProxNo(novo, l->prim);
  l->prim = novo;

  No* p = l->prim;
  while(p != NULL){
    l->ult = p;
    No* t = getProxNo(p);
    p = t;
  }

}

void lst_insere_ordenado(Lista *l, int info){
  No* p = l->prim;
  while(p != NULL){
    No* t = getProxNo(p);
    if(getInfoNo(p) <= info && getInfoNo(t) >= info){
      No* aux = criaNo(info);
      setProxNo(aux, t);
      setProxNo(p, aux);
    }
    p = t;
  }
}

void lst_retira(Lista *l, int info){
  No* p = l->prim;

  if(getInfoNo(p) == info){
    No *t = getProxNo(p);
    l->prim = t;
    liberaNo(p);
  }
  else{
    retiraNo(p, info);
  }

  p = l->prim;
  while(p != NULL){
    l->ult = p;
    No* t = getProxNo(p);
    p = t;
  }
}

void retiraNo(No *no, int info){
  No* atual = getProxNo(no);
  No* prox = getProxNo(atual);

  if(getInfoNo(atual) == info){
    setProxNo(no, prox);
    liberaNo(atual);
  }
  else{
    retiraNo(atual, info);
  }
}

int lst_vazia(Lista *l){
  if(l->prim == NULL){
    return 1;
  }
  else{
    return 0;
  }
}

int lst_pertence(Lista *l, int info){
  return pertence_rec(l->prim, info);
}

int pertence_rec(No *no, int info){
  if(no == NULL){
    return 0;
  }
  else if(getInfoNo(no) == info){
      return 1;
    }
  else{
      return pertence_rec(getProxNo(no), info);
    }
}

Lista* concatenaLista(Lista *a, Lista *b){
  Lista *c = lst_cria();
  No *p = a->prim;

  while(p != NULL){
    No* t = getProxNo(p);
    lst_insere_final(c, getInfoNo(p));
    p = t;
  }

  p = b->prim;
  while(p != NULL){
    No* t = getProxNo(p);
    lst_insere_final(c, getInfoNo(p));
    p = t;
  }
  return c;
}

void lst_insere_final(Lista *l, int info){
  No* p = criaNo(info);
  if(l->prim == NULL){
    l->prim = p;
    l->ult = p;
  }
  else{
    setProxNo(l->ult, p);
    l->ult = p;
  }
}

int lst_retira_primeiro(Lista *l){
  No* p = l->prim;
  int info = getInfoNo(p);
  No *t = getProxNo(p);
  l->prim = t;
  liberaNo(p);
  return info;
}

void inverteFila(Lista *f){
  int info;
  Lista* pilha = lst_cria();
  No* p = f->prim;

  while(p != NULL){
    No* t = getProxNo(p);
    lst_insere(pilha, getInfoNo(p));
    p = t;
  }

  p = f->prim;
  while(p != NULL){
    No* t = getProxNo(p);
    lst_retira(f, getInfoNo(p));
    p = t;
  }

  p = pilha->prim;
  while(p != NULL){
    No* t = getProxNo(p);
    info = lst_retira_primeiro(pilha);
    lst_insere_final(f, info);
    p = t;
  }
}

No* getLstUltimo(Lista *l){
  return l->ult;
}

No* getLstPrimeiro(Lista *l){
  return l->prim;
}

void lst_imprime(Lista *l){
  No* p = l->prim;
  while(p != NULL){
    No* t = getProxNo(p);
    printf("%d ", getInfoNo(p));
    p = t;
  }
}
