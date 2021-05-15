#ifndef INTERCALA_H
#define INTERCALA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tp2.h"

#define REG 20
#define FITAS 20

typedef struct fita Fita;
typedef struct heap Heap;

void intercalaInterno(FILE*, int, Analise*);
void intercalaExterno(FILE*, int, Analise*);

void criaBlocosInterno(FILE*, Fita*, Aluno*, int, Analise*);
void criaBlocosExterno(FILE*, Fita*, int, Analise*);

int iniciaInterlacao(Fita*, Fita*, Aluno*, int, Analise*);
int intercala(Fita*, Fita*, Aluno*, int, Analise*);
void quickSort(Aluno*, int, int, Analise*);
void heapSort(Heap*, int, Analise*);

// Funções para facilitar o código
void inicializaFitas(Fita*, Fita*);
int getFitasDisponiveis(Fita*);
int isContinua(int*, int);
bool isTudoMarcado(Heap*, int, int);
void desmarcaTudo(Heap*, int, int);

#endif