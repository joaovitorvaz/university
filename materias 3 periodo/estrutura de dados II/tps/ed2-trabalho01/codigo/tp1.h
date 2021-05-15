#ifndef TP1_H
#define TP1_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Estruturas
typedef struct registro{
    int chave;
    long int dado1;
    char dado2[501];
}Registro;

typedef struct analise{
    int nTransferencias;
    int nComparacoes;
    clock_t tInicioPreProcessamento;
    clock_t tFinalPreProcessamento;
    clock_t tInicioPesquisa;
    clock_t tFinalPesquisa;
    double tPreProcessamento;
    double tPesquisa;
    double tTotal;
}Analise;

//Prototipos de Funcoes
void imprimeRegistro(Registro r);
int constroiArquivo(int quant, int ordenacao);
void imprimeArquivo(FILE* arq);

void inicializaAnalise(Analise* a);

void contTransferencia(Analise* a);
void contComparacao(Analise* a);

void iniciarTempoPreProcessamento(Analise* a);
void finalizarTempoPreProcessamento(Analise* a);
void calcularTempoPreProcessamento(Analise* a);

void iniciarTempoPesquisa(Analise* a);
void finalizarTempoPesquisa(Analise* a);
void calcularTempoPesquisa(Analise* a);

void calcularTempoTotal(Analise* a);
void imprimirAnalise(Analise* a);

#endif