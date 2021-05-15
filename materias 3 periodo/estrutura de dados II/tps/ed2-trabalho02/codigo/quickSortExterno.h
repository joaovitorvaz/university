#ifndef QUICKSORTEXTERNO_H
#define QUICKSORTEXTERNO_H

#include "tp2.h"

//Macros
#define TAMAREA 20
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define FALSE 0
#define TRUE 1

//Prototipos de Funcoes
void QuicksortExterno(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir, Analise *a);

void LeSup(FILE ** ArqLEs, Aluno *UltLido, int *Ls, short *OndeLer, Analise *a);
void LeInf(FILE **ArqLi, Aluno *UltLido, int *Li, short *OndeLer, Analise *a);
void InserirArea(Aluno *Area, Aluno *UltLido, int *NRArea, Analise *a); 
void EscreveMax(FILE **ArqLEs, Aluno R, int *Es, Analise *a);
void EscreveMin(FILE **ArqEi, Aluno R, int *Ei, Analise *a);
void RetiraMax(Aluno *Area, Aluno *R, int *NRArea, Analise *a);
void RetiraMin(Aluno *Area, Aluno *R, int *NRArea, Analise *a);

void Particao(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, Aluno *Area, int Esq, int Dir, int *i, int *j, Analise *a);

void FAVazia(Aluno *Area, Analise *a);
void InsereItem(Aluno UltLido, Aluno *Area, Analise *a);
int ObterNumCelOcupadas(Aluno *Area, Analise *a);
void RetiraUltimo(Aluno *Area, Aluno *R, Analise *a);
void RetiraPrimeiro(Aluno *Area, Aluno *R, Analise *a);

void imprimirArea(Aluno *Area);

#endif