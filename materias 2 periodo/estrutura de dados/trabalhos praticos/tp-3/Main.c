#include "Huffman.h"
#include "Hash.h"
#include "Programa.h"

int main(){
	int opcao;

	do{
    scanf("%d", &opcao);

		if(opcao == 1){
			atv1();
    }

		else if(opcao==2){
			printf("Possuimos 10 escaninhos.\n\n");
			atv2();
    }

	}while(opcao!=0);

	printf("\nFim de programa...\n");

	return 0;
}
