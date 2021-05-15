#include "quickSortExterno.h"
#include "arquivos.h"
#include "intercala.h"

//ordena <metodo> <quantidade> <situacao> [-P]
int main(int argc, char* argv[]) {
    //Arquivo a ser ordenado
    FILE* arq;
    //Arquivos extras utilizadas no quickSort Externo
    FILE* arqEi;
    FILE* arqLi;
    FILE* arqLEs;

    if(argc < 4 || argc > 5) {
        printf("ERRO: o formato de execucao eh: ordena <metodo> <quantidade> <situacao>\n");
        exit(1);
    }

    //Variaveis da linha de execucao
    int ordena = atoi(argv[1]);
    int quantidade = atoi(argv[2]);
    int situacao = atoi(argv[3]);

    int opcional = 0;
    if(argc == 5) {
        if(!strcmp(argv[4], "[-P]"))
            opcional = 1;
        else {
            printf("ERRO: o parametro opcional deve ser digitado como '[-P]' (sem as aspas).\n");
            exit(1);
        }
    }

    //Decidindo qual arquivo deve ser aberto para ser ordenado
    switch(situacao) {
        case 1: //Arquivo original ordenado ascendentemente
            if((arq = fopen("PROVAO - 1.TXT", "r+")) == NULL) {
                printf("ERRO: O arquivo PROVAO - 1.txt nao pode ser aberto corretamente.\n");
                exit(1);
            }
            break;
        case 2: //Arquivo original ordenado descendentemente
            if((arq = fopen("PROVAO - 2.TXT", "r+")) == NULL) {
                printf("ERRO: O arquivo PROVAO - 2.txt nao pode ser aberto corretamente.\n");
                exit(1);
            }
            break;
        case 3: //Arquivo original ordenado aleatoriamente
            if((arq = fopen("PROVAO - 3.TXT", "r+")) == NULL) {
                printf("ERRO: O arquivo PROVAO - 3.txt nao pode ser aberto corretamente.\n");
                exit(1);
            }
            break;
        default: //Situação do arquivo não existente
            printf("ERRO: O parametro de situacao do executavel deve ser de 1 a 3.\n");
            break;
    }

    //Iniciando Análise
    Analise a;
    inicializaAnalise(&a);
    FILE* resultado;
    FILE* resultadoBin;

    //Decidindo qual método de ordenação deve ser utilizado
    switch(ordena) {
        case 1: //Intercalação Balanceada + Ordenação Interna
            criarArquivos(&arqLEs, &arqLi, &arqEi, &arq, situacao, quantidade);

            if(opcional) {
                printf("Antes da Ordenacao:\n");
                imprimeArquivo(arqLi, quantidade);
                printf("\n");
            }

            iniciarTempoExecucao(&a);
            intercalaInterno(arqLi, quantidade, &a);
            finalizarTempoExecucao(&a);

            resultadoBin = fopen("resultado.bin", "r+b");
            if((resultado = fopen("resultado.txt", "w+")) == NULL) {
                printf("ERRO: O arquivo resultado.txt nao pode ser aberto corretamente.\n");
                exit(1);
            }

            if(opcional) {
                printf("Depois da Ordenacao:\n");
                imprimeArquivo(resultadoBin, quantidade);
                printf("\n");
            }

            rewind(resultadoBin);
            converterTexto(resultadoBin, resultado, quantidade);

            fclose(resultado);
            remove("resultado.bin");
            imprimirAnalise(&a);
            break;
        case 2: //Intercalação Balanceada + Seleção por Substituição 
            criarArquivos(&arqLEs, &arqLi, &arqEi, &arq, situacao, quantidade);

            if(opcional) {
                printf("Antes da Ordenacao:\n");
                imprimeArquivo(arqLi, quantidade);
                printf("\n");
            }

            iniciarTempoExecucao(&a);
            intercalaExterno(arqLi, quantidade, &a);
            finalizarTempoExecucao(&a);

            resultadoBin = fopen("resultado.bin", "r+b");
            if((resultado = fopen("resultado.txt", "w+")) == NULL) {
                printf("ERRO: O arquivo resultado.txt nao pode ser aberto corretamente.\n");
                exit(1);
            }

            if(opcional) {
                printf("Depois da Ordenacao:\n");
                imprimeArquivo(resultadoBin, quantidade);
                printf("\n");
            }

            rewind(resultadoBin);
            converterTexto(resultadoBin, resultado, quantidade);

            fclose(resultado);
            remove("resultado.bin");
            imprimirAnalise(&a);
            break;
        case 3: //QuickSort Externo
            criarArquivos(&arqLEs, &arqLi, &arqEi, &arq, situacao, quantidade);

            if(opcional) {
                printf("Antes da Ordenacao:\n");
                imprimeArquivo(arqLi, quantidade);
                printf("\n");
            }

            iniciarTempoExecucao(&a);
            QuicksortExterno(&arqLi, &arqEi, &arqLEs, 1, quantidade, &a);
            finalizarTempoExecucao(&a);

            fclose(arqEi);
            fclose(arqLEs);

            if(opcional) {
                printf("Depois da Ordenacao:\n");
                imprimeArquivo(arqLi, quantidade);
                printf("\n");
            }

            rewind(arqLi);

            if((resultado = fopen("resultado.txt", "w+")) == NULL) {
                printf("ERRO: O arquivo resultado.txt nao pode ser aberto corretamente.\n");
                exit(1);
            }
            converterTexto(arqLi, resultado, quantidade);
            fclose(resultado);

            imprimirAnalise(&a);

            break;
        default:
            printf("ERRO: O parametro de ordenacao do executavel deve ser de 1 a 3.\n");
            break;
    }

    //Fechando os arquivos
    fclose(arq);

    return 0;
}