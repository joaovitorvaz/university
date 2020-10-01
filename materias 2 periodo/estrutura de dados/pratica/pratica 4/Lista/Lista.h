#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

#include"No.h"

typedef struct lista Lista;

Lista* CriaLista();
void LiberaLista(Lista *lista);
void lst_insere_comeco(Lista* lista, int v);
void lst_inserefinal(Lista* lista, int v);
void lst_retira(Lista* lista, int v);
void lstRetiraNo(No* no, int v);
int lst_retiraprim(Lista* lista);
int lst_vazia(Lista* lista);
int lst_pertence(No* no, int v);
int pertence(Lista* lista, int v);
void lst_imprime(Lista* lista);
void setPrim(Lista *lista, No *prim);
void setUlt(Lista *lista, No *ult);
No* getPrimLista(Lista* lista);
No* getUltLista(Lista* lista);

#endif
