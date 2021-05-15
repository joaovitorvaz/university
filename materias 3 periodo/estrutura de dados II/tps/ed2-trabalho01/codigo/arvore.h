#ifndef ARVORE_H
#define ARVORE_H

#include "tp1.h"

//Estruturas
typedef struct nodo{
	long int esq; 		//Filho a esquerda.
	Registro item;	  	//Registro.
	long int dir;     	//Filho a direita.
}Nodo;

//Prototipos de Funcoes
void preencheNo(Nodo* n, Registro r);
int criaArvore(FILE* arqb, FILE* arv, long tam, Analise* a);
int pesquisa2(FILE* arv, Nodo* n, Registro *retorno, Analise* a);
void imprimeArquivoArvore(FILE* arq);

#endif

