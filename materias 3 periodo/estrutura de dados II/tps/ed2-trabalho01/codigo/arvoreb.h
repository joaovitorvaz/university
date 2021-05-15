#ifndef ARVOREB_H
#define ARVOREB_H

#define M 2
#define MM M*2

#include "tp1.h"

//Estruturas
typedef struct TipoPagina* TipoApontador;

typedef struct TipoPagina{
    short n;
    Registro r[MM];
    TipoApontador p[MM + 1];
}TipoPagina;

//Protótipos de funções
int pesquisa3(Registro* x, TipoApontador Ap, Analise* a);
void criaArvoreB(FILE* arq, TipoApontador* Ap, Analise* a);
void insere(Registro Reg, TipoApontador* Ap, Analise* a);
void ins(Registro Reg, TipoApontador Ap, short* cresceu, Registro* RegRetorno, TipoApontador* ApRetorno, Analise* a);
void insereNaPagina(TipoApontador Ap, Registro Reg, TipoApontador ApDir, Analise* a);

#endif