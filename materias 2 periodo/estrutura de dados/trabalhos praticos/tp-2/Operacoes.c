#include "Operacoes.h"

void insereObj(Pilha* pilha){
	int tipo;
	scanf("%d", &tipo);

	switch(tipo){
		case 1: {
			float lado;
			scanf("%f", &lado);
			Quadrado* quad=criarQuad(lado);
			pilhaPush(pilha, tipo, quad);
		}
			break;

		case 2: {
			float dma, dme;
			scanf("%f", &dma);
			scanf("%f", &dme);
			Losango* los=criarLos(dma, dme);
			pilhaPush(pilha, tipo, los);
		}
			break;
		case 3: {
			float bma, bme, height;
			scanf("%f", &bma);
			scanf("%f", &bme);
			scanf("%f", &height);
			Trapezio* trap=criarTrap(bma, bme, height);
			pilhaPush(pilha, tipo, trap);
		}
			break;
	}
}
