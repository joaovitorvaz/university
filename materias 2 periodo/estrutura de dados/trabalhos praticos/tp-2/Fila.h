#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"No.h"

typedef struct fila Fila;

Fila* CriaFila();
void LiberaFila(Fila *fila);
void fila_inserefinal(Fila* fila, int n);
void fila_retiraprim(Fila* fila);
void fila_imprime(Fila* fila);
void setPrim(Fila *fila, No *prim);
void setUlt(Fila *fila, No *ult);
No* getPrimFila(Fila* fila);
No* getUltFila(Fila* fila);

#endif
