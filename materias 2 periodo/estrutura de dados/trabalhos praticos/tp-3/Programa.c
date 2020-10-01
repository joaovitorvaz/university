#include"Programa.h"

void atv1(){
	int opcao;

	do{
    scanf("%d", &opcao);

		if(opcao==1){
			createArquivo_Compressao();
      comprimeArquivo("input.ttf", "output.hx");
			printf("\n");
    }
    else if(opcao==2){
    	createArquivo_Descompressao();
      descomprimirFile("input.hx", "output.ttf");
			printf("\n");
    }
	}while(opcao!=0);
}

void atv2(){
	int n, mat;
	char nome[100];
	int cpf;

	Hash* hash=criaHash();

//   (DIGITE 0) SAIR
//   (DIGITE 1) INSERIR ALUNO
//   (DIGITE 2) VERIFICAR LOCALIDADE DAS FICHAS
//    DO ALUNO NO ESCANINHO
//   (DIGITE 3) IMPRIMIR ALUNO
//   (DIGITE 4) REMOVER ALUNO

	do{
    scanf("%d", &n);

		if(n==1){
      scanf("%s %d %d", nome, &cpf, &mat);

			Aluno* aluno=criaAluno(nome, cpf, mat);
			int i=insereHash(hash, aluno);

			if(i==1){
        printf("Estudante adicionado.\n");
      }
			else
        printf("Estudante ja existe.\n");
		}
    else if(n==2){
      scanf("%d", &mat);

			if(searchash(hash, mat)!=-1){
        printf("Documentos estao no escaninho: %d\n", searchash(hash, mat));
      }
			else
      printf("Documentos nao encontrado.\n");
		}
    else if(n==3){

      scanf("%d", &mat);

			if(searchash(hash, mat)!=-1){
				imprimeAluno(getAluno(hash, searchash(hash, mat)));
      }
			else
      printf("Estudante nao encontrado.\n");
		}
    else if(n==4){

      scanf("%d", &mat);

			if(searchash(hash, mat)!=-1){
				removeHash(hash, mat);
        printf("Estudante removido.\n");
			}
      else
        printf("Estudante nao encontrado.\n");
		}
	}while(n != 0);

	liberaHash(hash);
}
