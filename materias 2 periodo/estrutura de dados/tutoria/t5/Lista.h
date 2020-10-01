#ifndef LISTA_H
#define LISTA_H

#include "No.h"

typedef struct lista Lista;

Lista* lst_cria(void);
void lst_libera(Lista* l);
void lst_insere(Lista *l, int info);
void lst_insere_ordenado(Lista *l, int info);
void lst_retira(Lista *l, int info);
void retiraNo(No* no, int info);
int lst_vazia(Lista* l);
int lst_pertence(Lista* l, int info);
int pertence_rec(No *no, int info);
void lst_imprime(Lista *l);
Lista* concatenaLista(Lista *a, Lista *b);
void lst_insere_final(Lista *l, int info);
int lst_retira_primeiro(Lista *l);
void inverteFila(Lista *f);
No* getLstUltimo(Lista *l);
No* getLstPrimeiro(Lista *l);

#endif
