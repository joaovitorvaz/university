#include "tp1.h"
#include "asi.h"

//Pre-processamento: criacao do indice de paginas
int* criarIndiceDePaginas(FILE* arq, int ordenacao, Analise* a){
    int* tabela = malloc(MAXTABELA * sizeof(int));
    Registro r;
    int i=0;

    contTransferencia(a);
	while(fread(&r,sizeof(Registro),1,arq) == 1){
        contTransferencia(a);
		tabela[i] = r.chave;
		i++;
		fseek(arq,(ITENSPAGINA-1)*sizeof(Registro),SEEK_CUR);
	}
	fseek(arq,0,SEEK_SET);

    //Completando o resto do indice de paginas (e impedindo que contenha lixo)
    if(ordenacao == 0)
        while(i < MAXTABELA){
            tabela[i] = 2147483647;
            i++;
        }
    else
        while(i < MAXTABELA){
            tabela[i] = -2147483646;
            i++;
        }

    return tabela;
}

//O metodo de pesquisa ira retornar 0 caso nao encontre o item, e 1 caso encontre
int pesquisa1(int tab[], int tam, Registro* item, FILE* arq, int ordenacao, Analise* a){
    Registro pagina[ITENSPAGINA];

    int i, quantitens;
    long desloc;
    // procura pela página onde o item pode se encontrar
    i = 0;

    //Como o Acesso Sequencial Indexado necessita de um arquivo ordenado pela chave de pesquisa,
    //nenhuma chave sera encontrada, caso a ordenacao do arquivo seja aleatoria
    contComparacao(a); //Primeira comparacao dos whiles presentes nas linhas 35 e 40
    if(ordenacao != 1)
        while (i < tam && tab[i] <= item->chave){
            contComparacao(a);
            i++;
        }
    else
        while (i < tam && tab[i] >= item->chave){
            contComparacao(a);
            i++;
        }

    // caso a chave desejada seja menor que a 1a chave, o item nao existe no arquivo
    if (i == 0)
        return 0;
    else {
        if (i < tam)
            quantitens = ITENSPAGINA;
        //a ultima página pode nao estar completa
        else {
            fseek (arq, 0, SEEK_END);
            quantitens = (ftell(arq)/sizeof(Registro))%ITENSPAGINA;

			//Permite a pesquisa de um item na ultima pagina do arquivo caso ela esteja completa
			if(quantitens == 0)
				quantitens = ITENSPAGINA;
        }

        // le a pagina desejada do arquivo
        desloc = (i-1)*ITENSPAGINA*sizeof(Registro);
        fseek (arq, desloc, SEEK_SET);
        fread (&pagina, sizeof(Registro), quantitens, arq);
        contTransferencia(a);

        // pesquisa sequencial na pagina lida
        for (i=0; i < quantitens; i++){
            contComparacao(a);
            if (pagina[i].chave == item->chave) {
                *item = pagina[i];
                return 1;
            }
        }

        return 0;
    }
}