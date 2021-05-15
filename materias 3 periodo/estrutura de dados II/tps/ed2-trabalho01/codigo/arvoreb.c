#include "arvoreb.h"

//O metodo de pesquisa ira retornar 0 caso nao encontre o item, e 1 caso encontre
int pesquisa3(Registro *x, TipoApontador Ap, Analise* a){
    long i = 1;

    if(Ap == NULL)
        return 0;
    
    contComparacao(a);
    while((i < Ap->n) && (x->chave > Ap->r[i-1].chave)){
        contComparacao(a);
        i++;
    }
    
    contComparacao(a);
    if(x->chave == Ap->r[i-1].chave){
        contComparacao(a);
        *x = Ap->r[i-1];
        return 1;
    }

    contComparacao(a);
    if(x->chave < Ap->r[i-1].chave)
        return pesquisa3(x, Ap->p[i-1], a);
    else
        return pesquisa3(x, Ap->p[i], a);
}

//O metodo criaArvoreB eh responsavel por criar a arvore B em memoria principal, tendo Ap como o ponteiro para
//a raiz dessa arvore B
void criaArvoreB(FILE* arq, TipoApontador* Ap, Analise* a){
    Registro r;

    contTransferencia(a);
    while(fread(&r, sizeof(Registro), 1, arq) == 1){
        contTransferencia(a);
        insere(r,Ap,a);
    }
}

void insere(Registro Reg, TipoApontador* Ap, Analise* a){
    short cresceu;
    Registro RegRetorno;
    TipoPagina *ApRetorno, *ApTemp;
    
    ins(Reg, *Ap, &cresceu, &RegRetorno, &ApRetorno, a);
    //Arvore cresceu na altura pela raiz
    if (cresceu){
        ApTemp = (TipoPagina*)malloc(sizeof(TipoPagina));
        ApTemp->r[0] = RegRetorno;
        ApTemp->n = 1;
        ApTemp->p[1] = ApRetorno;
        ApTemp->p[0] = *Ap;
        *Ap = ApTemp;
    }
}

void ins(Registro Reg, TipoApontador Ap, short* cresceu, Registro* RegRetorno, TipoApontador* ApRetorno, Analise* a){
    long i = 1;
    long j;
    TipoApontador ApTemp;

    if(Ap == NULL){
        *cresceu = 1;
        (*RegRetorno) = Reg;
        (*ApRetorno) = NULL;
        return;
    }

    contComparacao(a);
    while(i < Ap->n && Reg.chave > Ap->r[i-1].chave){
        contComparacao(a);
        i++;
    }

    contComparacao(a);
    if(Reg.chave == Ap->r[i-1].chave){
        printf("Registro ja esta presente\n");
        *cresceu = 0;
        return;
    }

    contComparacao(a);
    if(Reg.chave < Ap->r[i-1].chave){
        i--;
    }
    
    ins(Reg, Ap->p[i], cresceu, RegRetorno, ApRetorno, a);
    if(!*cresceu)
        return;
    //Página tem espaço
    if(Ap->n < MM){
        insereNaPagina(Ap, *RegRetorno, *ApRetorno, a);
        *cresceu = 0;
        return;
    }
    //Página tem que ser dividida
    ApTemp = (TipoPagina*)malloc(sizeof(TipoPagina));
    ApTemp->n = 0;
    ApTemp->p[0] = NULL;
    
    if(i < M + 1){
        insereNaPagina(ApTemp, Ap->r[MM-1], Ap->p[MM], a);
        Ap->n--;
        insereNaPagina(Ap, *RegRetorno, *ApRetorno, a);
    }
    else{
        insereNaPagina(ApTemp, *RegRetorno, *ApRetorno, a);
    }
    for (j = M+2;j <=MM; j++){
        insereNaPagina(ApTemp, Ap->r[j-1], Ap->p[j], a);
    }
    Ap->n = M;
    ApTemp->p[0] = Ap->p[M+1];
    *RegRetorno = Ap->r[M];
    *ApRetorno = ApTemp;
}

void insereNaPagina(TipoApontador Ap, Registro Reg, TipoApontador ApDir, Analise* a){
    short naoAchouPosicao = 0;
    int k;
    k = Ap->n;
    if(k > 0)
        naoAchouPosicao = 1;

    while(naoAchouPosicao){
        contComparacao(a);
        if (Reg.chave >= Ap->r[k-1].chave){
            naoAchouPosicao = 0;
            break;
        }
        Ap->r[k] = Ap->r[k-1];
        Ap->p[k+1] = Ap->p[k];
        k--;
        if(k < 1)
            naoAchouPosicao = 0;
    }
    Ap->r[k] = Reg;
    Ap->p[k+1] = ApDir;
    Ap->n++;
}