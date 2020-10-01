#include "Pilha.h"

struct listano{
	Identificador objeto;
	void* cont;
	ListaNo* prox;
};

struct pilha{
	ListaNo* prim;
};

Pilha* criarPilha(){
	Pilha* pilha=malloc(sizeof(Pilha));
	pilha->prim =NULL;
	return pilha;
}

void pilhaPush(Pilha *pilha, int objeto, void* cont){
	ListaNo* no=malloc(sizeof(ListaNo));
	no->cont=cont;
	switch(objeto){
		case 1:
			no->objeto=QUA;
			break;
		case 2:
			no->objeto=LOS;
			break;
		case 3:
			no->objeto=TRAP;
			break;
	}
	no->prox =pilha->prim;
	pilha->prim =no;
}

int pilhaPop(Pilha *pilha){
	if(verificarPilha(pilha)!=1){
		ListaNo* no=pilha->prim;
		pilha->prim=no->prox;
		free(no);
		return 1;
	}
	return 0;
}

int verificarPilha(Pilha* pilha){
	return(pilha->prim==NULL);
}

void liberarPilha(Pilha* pilha){
	ListaNo* no=pilha->prim;
	while(no!=NULL){
		ListaNo* aux=no->prox;
		free(no);
		no=aux;
	}
	free(pilha);
}

void area(Pilha* pilha){
	for(ListaNo* no=pilha->prim; no!=NULL; no=no->prox){
		switch(no->objeto){
			case QUA:{
				Quadrado* quad=no->cont;
				printf("Area Quadrado = %.2f\n", areaQuad(quad));
			}
				break;

			case LOS:{
				Losango* los=(Losango*) no->cont;
				printf("Area Losango = %.2f\n", areaLos(los));
			}
				break;

			case TRAP:{
				Trapezio* trap=(Trapezio*) no->cont;
				printf("Area Trapezio = %.2f\n", areaTrap(trap));
			}
				break;
		}
	}
}

void* getInfoPilha(ListaNo* no){
	return no->cont;
}

Identificador getObjetoPilha(ListaNo* no){
	return no->objeto;
}

ListaNo* getProxPilha(Pilha* pilha){
	return pilha->prim;
}
