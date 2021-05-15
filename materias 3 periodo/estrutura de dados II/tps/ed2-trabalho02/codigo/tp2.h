#ifndef TP2_H
#define TP2_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Estruturas
typedef struct aluno{
    long int inscricao;
    double nota;
    char estado[3];
    char cidade[51];
    char curso[31];
}Aluno;

typedef struct analise{
    int nTransferenciasLeitura;
    int nTransferenciasEscrita;
    int nComparacoes;
    clock_t tInicioExecucao;
    clock_t tFinalExecucao;
    double tExecucao;
}Analise;

//Prototipos de Funcoes
void imprimeArquivo(FILE* arq, int quant);
void imprimeAluno(Aluno a);

void inicializaAnalise(Analise* a);

void contTransferenciaLeitura(Analise* a);
void contTransferenciaEscrita(Analise* a);
void contComparacao(Analise* a);

void iniciarTempoExecucao(Analise* a);
void finalizarTempoExecucao(Analise* a);

void imprimirAnalise(Analise* a);

int contaDigitosLong(long int n, int cont);
void completaInscricao(long int n);
void completaInscricaoArq(FILE* arq, long int n);

int contaDigitosDouble(double n, int cont);
void completaNota(double n);
void completaNotaArq(FILE* arq, double n);

#endif