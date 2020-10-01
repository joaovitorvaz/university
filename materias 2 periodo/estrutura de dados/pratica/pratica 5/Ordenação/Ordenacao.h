#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdio.h>
#include <stdlib.h>

#include "Valores.h"

void Buble(int *v, int tam);
void SelectionSort(int *v, int tam);
void MergeOrdena(int *v, int esq, int dir);
void MergeIntercala(int *v, int esq, int meio, int dir);
int PesqBinaria(int *v, int pesquisado, int low, int high);
void InsertionSort(int *v, int tam);

#endif
