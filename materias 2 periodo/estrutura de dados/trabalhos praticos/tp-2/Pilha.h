#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include "Quadrado.h"
#include "Losango.h"
#include "Trapezio.h"

typedef struct listano ListaNo;
typedef struct pilha Pilha;
typedef enum identificador Identificador;

enum identificador{
	QUA,
	LOS,
	TRAP
};

Pilha* criarPilha();
void pilhaPush(Pilha *pilha, int objeto, void* cont);
int pilhaPop(Pilha *pilha);
int verificarPilha(Pilha* pilha);
void liberarPilha(Pilha* pilha);
void area(Pilha* pilha);
void* getInfoPilha(ListaNo* no);
Identificador getObjetoPilha(ListaNo* no);
ListaNo* getProxPilha(Pilha* pilha);

#endif
