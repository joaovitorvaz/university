#include "tp1.h"

//A funcao imprimeRegistro imprime uma mensagem de que o registro pesquisado foi encontrado, bem como todos os
//dados do registro
void imprimeRegistro(Registro r){
    printf("===== DADOS DO REGISTRO =====\n");
    printf("Chave: %d\n",r.chave);
    printf("Dado 1: %ld\n",r.dado1);
    printf("Dado 2: %s\n",r.dado2);
}

//A funcao constroiArquivo e responsavel pela construcao do arquivo binario "dados.bin" usado
//pelos metodos de pesquisa externa
int constroiArquivo(int quant, int ordenacao){
    FILE* binario;
    Registro r;

    if((binario = fopen("dados.bin", "w+b")) == NULL)
        return 0;

    //vetor utilizado para chaves aleatorias
    int* vetor = malloc(quant * sizeof(int));
    for(int i=0;i<quant;i++)
        vetor[i] = i+1;
    int aux = quant;
    int aux2;

    for(int i=0; i<quant; i++){
        //criando um arquivo com chaves ordenadas crescentemente
        if(ordenacao == 0)
            r.chave = i+1;
        
        //criando um arquivo com chaves ordenadas decrescentemente
        else if(ordenacao == 1)
            r.chave = quant-i;
        
        //criando um arquivo com chaves aleatorias (algoritmo de embaralhamento)
        else{
            aux2 = rand() % aux;        //gera um numero aleatorio entre 0 e aux-1 e guarda em aux2
            r.chave = vetor[aux2];      //chave recebe o valor da posicao aleatoria vetor[aux2]
            vetor[aux2] = vetor[aux-1]; //vetor[aux2] recebe o elemento da ultima posicao do vetor
            aux--;                      //aux e decrementado em 1 para ignorar a ultima posicao do vetor a cada iteracao
        }
        
        //dado1 tera um valor aleatorio entre 1 e 10.000.000
        r.dado1 = (rand() % 10000000)+1;
        //dado2 tera o mesmo valor para todos os registros
        strcpy(r.dado2,"Esse dado sera igual para todos os registros.");
        fwrite(&r,sizeof(Registro),1,binario);
    }

    free(vetor);
    fclose(binario);
    return 1;
}

//Imprime todas as chaves de pesquisa presentes no arquivo
void imprimeArquivo(FILE* arq){
    Registro r;
    int i = 1;
    
    rewind(arq);
    while(fread(&r,sizeof(Registro),1,arq) == 1){
        printf("Chave #%d: %d\n",i,r.chave);
        i++;
    }
    rewind(arq);
}

//Inicializa uma analise
void inicializaAnalise(Analise* a){
    a->nTransferencias = 0;
    a->nComparacoes = 0;
    a->tPreProcessamento = 0.0;
    a->tPesquisa = 0.0;
    a->tTotal = 0.0;
}

//Incrementa a contagem do numero de transferencias em 1
void contTransferencia(Analise* a){
    a->nTransferencias++;
}

//Incrementa a contagem do numero de comparacoes em 1
void contComparacao(Analise* a){
    a->nComparacoes++;
}

//Armazena o tempo do inicio do pre-processamento do metodo de pesquisa, como a
//construcao da tabela de indices ou da arvore
void iniciarTempoPreProcessamento(Analise* a){
    a->tInicioPreProcessamento = clock();
}

//Armazena o tempo do final do pre-processamento do metodo de pesquisa e chama a funcao "calcularTempoPreProcessamento"
void finalizarTempoPreProcessamento(Analise* a){
    a->tFinalPreProcessamento = clock();
    calcularTempoPreProcessamento(a);
}

//Calcula o tempo gasto no pre-processamento do metodo de pesquisa
void calcularTempoPreProcessamento(Analise* a){
    a->tPreProcessamento = (a->tFinalPreProcessamento - a->tInicioPreProcessamento)*1000.0/CLOCKS_PER_SEC;
}

//Armazena o tempo do inicio da pesquisa propriamente dita
void iniciarTempoPesquisa(Analise* a){
    a->tInicioPesquisa = clock();
}

//Armazena o tempo do final da pesquisa propriamente dita e chama a funcao "calcularTempoPesquisa"
//e "calcularTempoTotal"
void finalizarTempoPesquisa(Analise* a){
    a->tFinalPesquisa = clock();
    calcularTempoPesquisa(a);
    calcularTempoTotal(a);
}

//Calcula o tempo gasto na pesquisa propriamente dita, em milissegundos
void calcularTempoPesquisa(Analise* a){
    a->tPesquisa = (a->tFinalPesquisa - a->tInicioPesquisa)*1000.0/CLOCKS_PER_SEC;
}

//Calcula o tempo total de execucao
void calcularTempoTotal(Analise* a){
    a->tTotal = a->tPreProcessamento + a->tPesquisa;
}

//Imprime a analise apos realizar uma pesquisa bem sucedida
void imprimirAnalise(Analise* a){
    printf("===== ANALISE =====\n");
    printf("Numero de transferencias efetuadas: %d\n",a->nTransferencias);
    printf("Numero de comparacoes efetuadas: %d\n",a->nComparacoes);
    printf("Tempo gasto no pre-processamento (em milissegundos): %lf\n",a->tPreProcessamento);
    printf("Tempo gasto na pesquisa em si (em milissegundos): %lf\n",a->tPesquisa);
    printf("Tempo total de execucao (em milissegundos): %lf\n",a->tTotal);
}