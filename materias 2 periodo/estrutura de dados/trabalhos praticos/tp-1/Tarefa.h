#ifndef TAREFA_H
#define TAREFA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tarefa Tarefa;

Tarefa *criarTarefa(char *nome, int prioridade, int preechida);
void apagarTarefa(Tarefa *tarefa);
void setNomeTarefa(Tarefa *tarefa, char *nome);
void setPrioridadeTarefa(Tarefa *tarefa, int prioridade);
void setPreenchimentoTarefa(Tarefa *tarefa, int preechida);
char *getNomeTarefa(Tarefa *tarefa);
double getPrioridadeTarefa(Tarefa *tarefa);
double getPreenchimentoTarefa(Tarefa *tarefa);
void imprimeTarefa(Tarefa* tarefa);
int pesquisaBinaria(Tarefa **tarefa, int buscado, int esq, int dir);
void MergeSort(Tarefa **tarefa, int esq, int dir);
void Merge(Tarefa **tarefa, int esq, int mid, int dir);

#endif
