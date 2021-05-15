#ifndef ARVOREBESTRELA_H
#define ARVOREBESTRELA_H

#define M 2
#define MM M*2
#define MM2 M*2

#include "tp1.h"

//Estruturas
typedef struct TipoPaginaE* TipoApontadorE;

typedef enum {Interna, Externa} TipoIntExt;

typedef struct TipoPaginaE{
    TipoIntExt Pt;
    union {
        struct { //Pagina interna
            int ni;
            int ri[MM];
            TipoApontadorE pi[MM + 1];
        } U0;
        struct { //Pagina externa (folha)
            int ne;
            Registro re[MM2];
        } U1;
    } UU;
}TipoPaginaE;

//Protótipos de funções
int pesquisa4(Registro* x, TipoApontadorE Ap, Analise* a);
void criaArvoreBEstrela(FILE* arq, TipoApontadorE* Ap, Analise* a);
void insereEstrela(Registro Reg, TipoApontadorE* Ap, Analise* a);
void insEstrela(Registro Reg, TipoApontadorE Ap, short* cresceu, Registro* RegRetorno, TipoApontadorE* ApRetorno, Analise* a);
void insereNaPaginaEstrela(TipoApontadorE Ap, Registro Reg, TipoApontadorE ApDir, Analise* a);

#endif