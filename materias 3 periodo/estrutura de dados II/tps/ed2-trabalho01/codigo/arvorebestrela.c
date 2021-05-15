#include "arvorebestrela.h"

//O metodo de pesquisa ira retornar 0 caso nao encontre o item, e 1 caso encontre
int pesquisa4(Registro* x, TipoApontadorE Ap, Analise* a){
    long i;

    if(Ap == NULL)
        return 0;

    //Pesquisa sequencial na pagina interna
    if(Ap->Pt == Interna){
        i = 1;

        contComparacao(a);
        while(i < Ap->UU.U0.ni && x->chave > Ap->UU.U0.ri[i-1]){
            contComparacao(a);
            i++;
        }

        contComparacao(a);
        if(x->chave < Ap->UU.U0.ri[i-1])
            return pesquisa4(x, Ap->UU.U0.pi[i-1], a);
        else
            return pesquisa4(x, Ap->UU.U0.pi[i], a);
    }

    //Pesquisa sequencial na pagina folha
    i = 1;
    contComparacao(a);
    while(i < Ap->UU.U1.ne && x->chave > Ap->UU.U1.re[i-1].chave){
        contComparacao(a);
        i++;
    }

    contComparacao(a);
    if(x->chave == Ap->UU.U1.re[i-1].chave){
        *x = Ap->UU.U1.re[i-1];
        return 1;
    }
    else
        return 0;
}

//O metodo criaArvoreBEstrela eh responsavel por criar a arvore B* em memoria principal, tendo Ap como o ponteiro 
//para a raiz dessa arvore B*
void criaArvoreBEstrela(FILE* arq, TipoApontadorE* Ap, Analise* a){
    Registro r;

    contTransferencia(a);
    while(fread(&r, sizeof(Registro), 1, arq) == 1){
        contTransferencia(a);
        insereEstrela(r,Ap,a);
    }
}

void insereEstrela(Registro Reg, TipoApontadorE* Ap, Analise* a){
    short cresceu;
    Registro RegRetorno;
    TipoPaginaE *ApRetorno, *ApTemp;
    
    //Insercao do primeiro item em uma arvore B* vazia
    if(*Ap == NULL){
        ApTemp = (TipoPaginaE*) malloc(sizeof(TipoPaginaE));
        ApTemp->Pt = Externa;
        ApTemp->UU.U1.ne = 1;
        ApTemp->UU.U1.re[0] = Reg;
        *Ap = ApTemp;
        return;
    }
    //Insercao dos demais itens
    else{
        insEstrela(Reg, *Ap, &cresceu, &RegRetorno, &ApRetorno, a);
        //Arvore cresceu na altura pela raiz
        if (cresceu){
            ApTemp = (TipoPaginaE*) malloc(sizeof(TipoPaginaE));
            ApTemp->Pt = Interna;
            ApTemp->UU.U0.ni = 1;
            ApTemp->UU.U0.ri[0] = RegRetorno.chave;
            ApTemp->UU.U0.pi[1] = ApRetorno;
            ApTemp->UU.U0.pi[0] = *Ap;
            *Ap = ApTemp;
        }
    }
}

void insEstrela(Registro Reg, TipoApontadorE Ap, short* cresceu, Registro* RegRetorno, TipoApontadorE* ApRetorno, Analise* a){
    long i = 1;
    long j;
    TipoApontadorE ApTemp;

    //Caso a pagina seja externa (folha)
    if(Ap->Pt == Externa){
        contComparacao(a);
        while(i < Ap->UU.U1.ne && Reg.chave > Ap->UU.U1.re[i-1].chave){
            contComparacao(a);
            i++;
        }

        contComparacao(a);
        if(Reg.chave == Ap->UU.U1.re[i-1].chave){
            printf("Registro ja esta presente\n");
            *cresceu = 0;
            return;
        }

        contComparacao(a);
        if(Reg.chave < Ap->UU.U1.re[i-1].chave){
            i--;
        }

        //Página tem espaço
        if(Ap->UU.U1.ne < MM2){
            *RegRetorno = Reg;
            insereNaPaginaEstrela(Ap, *RegRetorno, *ApRetorno, a);
            *cresceu = 0;
            return;
        }
        //Página tem que ser dividida
        ApTemp = (TipoPaginaE*) malloc(sizeof(TipoPaginaE));
        ApTemp->Pt = Externa;
        ApTemp->UU.U1.ne = 0;

        *RegRetorno = Reg; //retorno recebe o item
        *ApRetorno = NULL; //apontador recebe NULL
        
        //Emprestimo
        if(i < M + 1){
            insereNaPaginaEstrela(ApTemp, Ap->UU.U1.re[MM2-1], *ApRetorno, a);
            Ap->UU.U1.ne--;
            insereNaPaginaEstrela(Ap, *RegRetorno, *ApRetorno, a);
        }
        //Insercao direta
        else{
            insereNaPaginaEstrela(ApTemp, *RegRetorno, *ApRetorno, a);
        }

        //Inserindo a segunda metade dos registros na pagina criada
        for (j = 1; j<=M; j++){
            insereNaPaginaEstrela(ApTemp, Ap->UU.U1.re[MM2 - j], *ApRetorno, a);
        }
        
        Ap->UU.U1.ne = M;
        *RegRetorno = Ap->UU.U1.re[M];
        *ApRetorno = ApTemp;
        *cresceu = 1;
        return;
    }
    //Caso a pagina seja interna
    else{
        contComparacao(a);
        while(i < Ap->UU.U0.ni && Reg.chave > Ap->UU.U0.ri[i-1]){
            contComparacao(a);
            i++;
        }

        contComparacao(a);
        if(Reg.chave == Ap->UU.U0.ri[i-1]){
            printf("Registro ja esta presente\n");
            *cresceu = 0;
            return;
        }

        contComparacao(a);
        if(Reg.chave < Ap->UU.U0.ri[i-1]){
            i--;
        }
        
        insEstrela(Reg, Ap->UU.U0.pi[i], cresceu, RegRetorno, ApRetorno, a);
        if(!*cresceu)
            return;
        //Página tem espaço
        if(Ap->UU.U0.ni < MM){
            insereNaPaginaEstrela(Ap, *RegRetorno, *ApRetorno, a);
            *cresceu = 0;
            return;
        }
        //Página tem que ser dividida
        ApTemp = (TipoPaginaE*) malloc(sizeof(TipoPaginaE));
        ApTemp->Pt = Interna;
        ApTemp->UU.U0.ni = 0;
        ApTemp->UU.U0.pi[0] = NULL;

        Registro RegAux;

        //Emprestimo
        if(i < M + 1){
            RegAux.chave = Ap->UU.U0.ri[MM-1];
            insereNaPaginaEstrela(ApTemp, RegAux, Ap->UU.U0.pi[MM], a);
            Ap->UU.U0.ni--;
            insereNaPaginaEstrela(Ap, *RegRetorno, *ApRetorno, a);
        }
        //Insercao direta
        else{
            insereNaPaginaEstrela(ApTemp, *RegRetorno, *ApRetorno, a);
        }

        for (j = M+2;j <=MM; j++){
            RegAux.chave = Ap->UU.U0.ri[j - 1];
            insereNaPaginaEstrela(ApTemp, RegAux, Ap->UU.U0.pi[j], a);
        }

        Ap->UU.U0.ni = M;
        ApTemp->UU.U0.pi[0] = Ap->UU.U0.pi[M+1];
        RegRetorno->chave = Ap->UU.U0.ri[M];
        *ApRetorno = ApTemp;

        return;
    }
}

void insereNaPaginaEstrela(TipoApontadorE Ap, Registro Reg, TipoApontadorE ApDir, Analise* a){
    short naoAchouPosicao = 0;
    int k;

    //Caso a pagina seja externa (folha)
    if(Ap->Pt == Externa){
        k = Ap->UU.U1.ne;
        if(k > 0)
            naoAchouPosicao = 1;

        while(naoAchouPosicao){
            contComparacao(a);
            if (Reg.chave >= Ap->UU.U1.re[k-1].chave){
                naoAchouPosicao = 0;
                break;
            }
            Ap->UU.U1.re[k] = Ap->UU.U1.re[k-1];
            k--;
            if(k < 1)
                naoAchouPosicao = 0;
        }
        Ap->UU.U1.re[k] = Reg;
        Ap->UU.U1.ne++;
    }
    //Caso a pagina seja interna
    else{
        k = Ap->UU.U0.ni;
        if(k > 0)
            naoAchouPosicao = 1;

        while(naoAchouPosicao){
            contComparacao(a);
            if (Reg.chave >= Ap->UU.U0.ri[k-1]){
                naoAchouPosicao = 0;
                break;
            }
            Ap->UU.U0.ri[k] = Ap->UU.U0.ri[k-1];
            Ap->UU.U0.pi[k+1] = Ap->UU.U0.pi[k];
            k--;
            if(k < 1)
                naoAchouPosicao = 0;
        }

        Ap->UU.U0.ri[k] = Reg.chave;
        Ap->UU.U0.pi[k+1] = ApDir;
        Ap->UU.U0.ni++;
    }

    return;
}