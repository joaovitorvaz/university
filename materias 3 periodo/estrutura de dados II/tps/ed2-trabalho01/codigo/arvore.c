#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

//Preenche um nó com default -1 para os apontadores dir/esq e item é preenchido com o registro lido do arquivo.
void preencheNo(Nodo* n, Registro r){
    n->dir = -1;
    n->esq = -1;
    n->item = r;
}

int criaArvore(FILE* arqb, FILE* arv, long tam, Analise* a){
	Registro A;    //Registro lido a cada iteracao do primeiro while (linha 26)  
  	Nodo auxiliar; //Nodo usado no caminhamento da arvore
  	Nodo filho;

	//Variaveis auxiliares
	int contador = 0; //O contador serve para verificar quantos registros foram inseridos e indicar a posicao do registro dentro de arv
  	int posicaoFilho = 0; //Armazena a posicao do filho (a esquerda ou direita) do nodo sendo analisado
  	int flag = 1; //A flag eh utilizada para definir se e necessario continuar percorrendo a arvore (enquanto for 1)
  	int tamanhoArvore = 0; //Armazena a quantidade de registros iseridos na arvore

	//Lê registro a registro do arquivo em questão.
	contTransferencia(a);
	while(fread(&A, sizeof(Registro), 1, arqb) == 1 && tamanhoArvore < tam){
		contTransferencia(a);
		flag = 1;
		preencheNo(&filho, A);

		//Realiza a gravação do Nodo criado no arquivo arv.
		contTransferencia(a);
		fwrite(&filho, sizeof(Nodo), 1, arv);

		contador++;

		//A seção abaixo será executada para todos os registros exceto o primeiro (raiz).
		if(contador != 1){
			rewind(arv);
			posicaoFilho = 0;
			
			//Lendo a raiz da arvore binaria e caminhando
			contTransferencia(a);
			while(fread(&auxiliar, sizeof(Nodo), 1, arv) == 1 && flag == 1){
				contTransferencia(a);
				//Compara se a o filho é menor ou maior que o pai.
				contComparacao(a);
				if(A.chave < auxiliar.item.chave)
					//(-1) é default para "sem filho".
					if(auxiliar.esq == -1){
						auxiliar.esq = contador-1;
						fseek(arv, posicaoFilho*sizeof(Nodo), 0);
						contTransferencia(a);
						fwrite(&auxiliar, sizeof(Nodo), 1, arv);
						flag = 0;						
					}
					//Caso tenha filho realiza o salto de acordo com o indice salvo em "esq".
					else{
						fseek(arv, (auxiliar.esq)*sizeof(Nodo), 0);
						posicaoFilho = auxiliar.esq;
					}
				else{
					//(-1) é default para "sem filho". 
					if(auxiliar.dir == -1){
						auxiliar.dir = contador-1;
						fseek(arv, posicaoFilho*sizeof(Nodo), 0);
						contTransferencia(a);
						fwrite(&auxiliar, sizeof(Nodo), 1, arv);
						flag = 0;
					}
					//Caso tenha filho realiza o salto de acordo com o indice salvo em "dir".
					else{
						fseek(arv, (auxiliar.dir)*sizeof(Nodo), 0);
						posicaoFilho = auxiliar.dir;
					}
				}
			}
		}
		fseek(arv, 0, 2);

		tamanhoArvore++;
	}

  	return 1;
}

//O metodo de pesquisa ira retornar 0 caso nao encontre o item, e 1 caso encontre
int pesquisa2(FILE* arv, Nodo* n, Registro *retorno, Analise* a){
    fread(n, sizeof(Nodo), 1, arv);
	contTransferencia(a);

    //Item encontrado.
    if(n->item.chave == retorno->chave){
		contComparacao(a);
    	*retorno = n->item;
    	return 1;
    }

    else if(retorno->chave > n->item.chave && n->dir != -1){
		contComparacao(a);
    	fseek(arv, (n->dir)*sizeof(Nodo), 0);
    	return pesquisa2(arv, n, retorno, a);
    }

    else if(retorno->chave < n->item.chave && n->esq != -1){
		contComparacao(a);
    	fseek(arv, (n->esq)*sizeof(Nodo), 0);
    	return pesquisa2(arv, n, retorno, a);
    }
    
    //Item não encontrado.
    return 0;
}

//Imprime todas as chaves de pesquisa presentes em um arquivo alterado pelo método 2
void imprimeArquivoArvore(FILE* arq){
    Nodo n;
    int i = 1;
    
    rewind(arq);
    while(fread(&n,sizeof(Nodo),1,arq) == 1){
        printf("Chave #%d: %d\n",i,n.item.chave);
        i++;
    }
    rewind(arq);
}