#include "asi.h"
#include "arvore.h"
#include "arvoreb.h"
#include "arvorebestrela.h"

//pesquisa <metodo> <quantidade> <situacao> <chave> [-P]
int main(int argc, char* argv[]){
    FILE* arq;
    FILE* arq2;
    Registro r;
    srand(time(NULL));

    if(argc < 5 || argc > 6){
        printf("ERRO: o formato de execucao eh: pesquisa <metodo> <quantidade> <situacao> <chave>\n");
        exit(1);
    }

    //Variaveis da linha de execucao
    int pesquisa = atoi(argv[1]);
    int quantidade = atoi(argv[2]);
    int situacao = atoi(argv[3]);
    int chave = atoi(argv[4]);
    int opcional = 0;
    if(argc == 6){
        if(!strcmp(argv[5],"[-P]"))
            opcional = 1;
        else
            printf("ERRO: o parametro opcional deve ser digitado como '[-P]' (sem as aspas)\n.");
    }
        

    //A funcao constroiArquivo retorna 0 caso o arquivo nao tenha sido criado corretamente
    if(!constroiArquivo(quantidade,situacao)){
        printf("ERRO: O arquivo binario nao pode ser construido.\n");
        exit(1);
    }

    if((arq = fopen("dados.bin", "rb")) == NULL){
        printf("ERRO: O arquivo dados.bin nao pode ser aberto corretamente.\n");
        exit(1);
    }
    r.chave = chave;
    Analise a;                  
    inicializaAnalise(&a);

    //Variáveis auxiliares
    int* tabela;                //Índice de páginas do ASI
    Nodo raiz;                  //Nodo raiz de um árvore binária
    long quantidadeLong = (long) quantidade;
    TipoApontador Ap = NULL;    //Apontador da página raiz de uma árvore B
    TipoApontadorE ApE = NULL;  //Apontador da página raiz de uma árvore B*
    
    switch(pesquisa){
        case 1: // Acesso Sequencial Indexado
            //Pre-processamento: construção do índice de páginas
            iniciarTempoPreProcessamento(&a);
            tabela = criarIndiceDePaginas(arq, situacao, &a);
            finalizarTempoPreProcessamento(&a);

            //Pesquisa propriamente dita
            iniciarTempoPesquisa(&a);
            if(pesquisa1(tabela,MAXTABELA,&r,arq,situacao,&a)){
                finalizarTempoPesquisa(&a);
                if(opcional)
                    imprimeArquivo(arq);
                printf("Registro encontrado.\n");
                imprimeRegistro(r);
                imprimirAnalise(&a);
            }
            else{
                finalizarTempoPesquisa(&a);
                if(opcional)
                    imprimeArquivo(arq);
                printf("Nao existe um registro com essa chave.\n");
                imprimirAnalise(&a);
            }
            break;
        case 2: //Arvore binaria adequada a memoria externa
            if((arq2 = fopen("temp.bin", "w+b")) == NULL){
                printf("ERRO: O arquivo temp.bin nao pode ser aberto corretamente.\n");
                exit(1);
            }
            //Pre-processamento: construção da árvore binária
            iniciarTempoPreProcessamento(&a);
            criaArvore(arq, arq2, quantidadeLong, &a);
            finalizarTempoPreProcessamento(&a);

            //Removendo o arquivo binario antigo e renomeando o arquivo binario novo
            fclose(arq);
            fclose(arq2);
            if(remove("dados.bin") != 0)
                printf("Erro ao deletar dados.bin antigo.\n");
            if(rename("temp.bin","dados.bin") != 0)
                printf("Erro ao renomear temp.bin.\n");
            if((arq = fopen("dados.bin", "rb")) == NULL){
                printf("ERRO: O arquivo dados.bin nao pode ser aberto corretamente.\n");
                exit(1);
            }

            //Pesquisa propriamente dita
            iniciarTempoPesquisa(&a);
            if(pesquisa2(arq,&raiz,&r,&a)){
                finalizarTempoPesquisa(&a);
                if(opcional)
                    imprimeArquivoArvore(arq);
                printf("Registro encontrado.\n");
                imprimeRegistro(r);
                imprimirAnalise(&a);
            }
            else{
                finalizarTempoPesquisa(&a);
                if(opcional)
                    imprimeArquivoArvore(arq);
                printf("Nao existe um registro com essa chave.\n");
                imprimirAnalise(&a);
            }
            break;
        case 3: //Árvore B
            //Pre-processamento: construção da árvore B
            iniciarTempoPreProcessamento(&a);
            criaArvoreB(arq,&Ap,&a);
            finalizarTempoPreProcessamento(&a);

            //Pesquisa propriamente dita
            iniciarTempoPesquisa(&a);
            if(pesquisa3(&r,Ap,&a)){
                finalizarTempoPesquisa(&a);
                if(opcional)
                    imprimeArquivo(arq);
                printf("Registro encontrado.\n");
                imprimeRegistro(r);
                imprimirAnalise(&a);
            }
            else{
                finalizarTempoPesquisa(&a);
                if(opcional)
                    imprimeArquivo(arq);
                printf("Nao existe um registro com essa chave.\n");
                imprimirAnalise(&a);
            }
            break;
        case 4: //Árvore B*
            //Pre-processamento: construção da árvore B*
            iniciarTempoPreProcessamento(&a);
            criaArvoreBEstrela(arq,&ApE,&a);
            finalizarTempoPreProcessamento(&a);

            //Pesquisa propriamente dita
            iniciarTempoPesquisa(&a);
            if(pesquisa4(&r,ApE,&a)){
                finalizarTempoPesquisa(&a);
                if(opcional)
                    imprimeArquivo(arq);
                printf("Registro encontrado.\n");
                imprimeRegistro(r);
                imprimirAnalise(&a);
            }
            else{
                finalizarTempoPesquisa(&a);
                if(opcional)
                    imprimeArquivo(arq);
                printf("Nao existe um registro com essa chave.\n");
                imprimirAnalise(&a);
            }
            break;
        default:
            printf("ERRO: O parametro de pesquisa do executavel deve ser de 1 a 4.\n");
            break;
    }
        
    fclose(arq);
    return 0;
}