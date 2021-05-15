//Fiz junto do Cadu
#include <stdio.h>

#define M 2
#define MM 2*M
#define MM2 5

typedef long TipoChave;

typedef struct TipoRegistro {
    TipoChave Chave;
} TipoRegistro;

typedef enum {Interna, Externa} TipoIntExt;

typedef struct TipoPagina* TipoApontador;

typedef struct TipoPagina {
    TipoIntExt Pt;
    union {
        struct {
            int ni;
            TipoChave ri[MM];
            TipoApontador pi[MM + 1];
        } U0;

        struct {
            int ne;
            TipoRegistro re[MM2];
        } U1;

    } UU;
} TipoPagina;

void Maximo(TipoRegistro *x, TipoApontador Ap){
    if (Ap == NULL){
        return;
    }

    if (Ap->Pt == Interna){
        maximo(x, Ap->UU.U0.pi[Ap->UU.U0.ni]);
    }

    else{
        *x = Ap->UU.U1.re[Ap->UU.U1.ne - 1];
    }
}