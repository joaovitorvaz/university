#include "tp2.h"

//Imprime até (cont) alunos presentes no arquivo
void imprimeArquivo(FILE* arq, int quant){
    Aluno a;
    int i = 1;
    
    rewind(arq);
    while(i <= quant && fread(&a,sizeof(Aluno),1,arq) == 1){
        imprimeAluno(a);
        i++;
    }
    rewind(arq);
}

//Imprime os dados de um aluno
void imprimeAluno(Aluno a){
    completaInscricao(a.inscricao);
    completaNota(a.nota);
    printf("%-2s ",a.estado);
    printf("%-30s ",a.cidade);
    printf("%-50s\n",a.curso);
}

//Inicializa uma analise
void inicializaAnalise(Analise* a){
    a->nTransferenciasLeitura = 0;
    a->nTransferenciasEscrita = 0;
    a->nComparacoes = 0;
    a->tExecucao = 0.0;
}

//Incrementa a contagem do numero de transferencias de leitura em 1
void contTransferenciaLeitura(Analise* a){
    a->nTransferenciasLeitura++;
}

//Incrementa a contagem do numero de transferencias de escrita em 1
void contTransferenciaEscrita(Analise* a){
    a->nTransferenciasEscrita++;
}

//Incrementa a contagem do numero de comparacoes em 1
void contComparacao(Analise* a){
    a->nComparacoes++;
}

//Armazena o tempo do inicio da execução do metodo de ordenação, como a
void iniciarTempoExecucao(Analise* a){
    a->tInicioExecucao = clock();
}

//Armazena o tempo do final do pre-processamento do metodo de pesquisa e chama a funcao "calcularTempoPreProcessamento"
void finalizarTempoExecucao(Analise* a){
    a->tFinalExecucao = clock();
    a->tExecucao = (a->tFinalExecucao - a->tInicioExecucao)*1000.0/CLOCKS_PER_SEC;
}

//Imprime a analise apos realizar uma ordenação
void imprimirAnalise(Analise* a){
    printf("===== ANALISE =====\n");
    printf("Numero de transferencias (leitura) efetuadas: %d\n",a->nTransferenciasLeitura);
    printf("Numero de transferencias (escrita) efetuadas: %d\n",a->nTransferenciasEscrita);
    printf("Numero de comparacoes efetuadas: %d\n",a->nComparacoes);
    printf("Tempo de execucao (em milissegundos): %lf\n",a->tExecucao);
}

//Retorna a quantidade de dígitos de um long int n
int contaDigitosLong(long int n, int cont){
    if(n > 0)
        return contaDigitosLong(n/10, ++cont);  
    else  
        return cont;  
}

//Completa a inscrição com 0 adicionados à esquerda do número e imprime na tela
void completaInscricao(long int n){
    int aux = 8 - contaDigitosLong(n,0);

    //Serão impressos aux vezes o dígito 0 no arquivo arq para completar a inscrição
    for(int i=0; i<aux; i++)
        printf("0");
    
    printf("%ld ",n);
}

//Completa a inscrição com 0 adicionados à esquerda do número e imprime no arquivo arq
void completaInscricaoArq(FILE* arq, long int n){
    int aux = 8 - contaDigitosLong(n,0);

    //Serão impressos aux vezes o dígito 0 no arquivo arq para completar a inscrição
    for(int i=0; i<aux; i++)
        fprintf(arq,"0");
    
    fprintf(arq,"%ld ",n);
}

//Retorna a quantidade de dígitos de um double n antes do ponto (ou vírgula)
int contaDigitosDouble(double n, int cont){
    if(n >= 1.0)
        return contaDigitosDouble(n/10.0, ++cont);  
    else  
        return cont;  
}

//Completa a nota com 0 adicionados à esquerda do número e imprime na tela
void completaNota(double n){
    int aux = 3 - contaDigitosLong(n,0);

    //Se o número n estiver entre 0 e 1
    if(n>=0.0 && n<=1.0)
        //Será impresso 2 vezes o dígito 0 no arquivo arq para completar a nota
        printf("00");
    //Se o número for maior que 1
    else
        //Serão impressos aux vezes o dígito 0 no arquivo arq para completar a nota
        for(int i=0; i<aux; i++)
            printf("0");

    printf("%.1lf ",n);
}

//Completa a nota com 0 adicionados à esquerda do número e imprime no arquivo arq
void completaNotaArq(FILE* arq, double n){
    int aux = 3 - contaDigitosLong(n,0);

    //Se o número n estiver entre 0 e 1
    if(n>=0.0 && n<=1.0)
        //Será impresso 2 vezes o dígito 0 no arquivo arq para completar a nota
        fprintf(arq,"00");
    //Se o número for maior que 1
    else
        //Serão impressos aux vezes o dígito 0 no arquivo arq para completar a nota
        for(int i=0; i<aux; i++)
            fprintf(arq,"0");

    fprintf(arq,"%.1lf ",n);
}