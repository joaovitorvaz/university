#include "arquivos.h"
#include "tp2.h"

//Gera os arquivos binários necéssarios na ordenação externa
void criarArquivos(FILE** ArqLEs, FILE** ArqLi, FILE** ArqEi, FILE** ArqTexto, int situacao, int quantidade){
	FILE *arqBin;

	switch(situacao){
		case 1:
		{ //ARQUIVO ORDENADO
			if((arqBin = fopen("PROVAO_ORDENADO.bin", "wb")) == NULL){
				printf("ERRO: O arquivo PROVAO_ORDENADO.bin nao pode ser criado corretamente.\n");
				exit(1);
			}

			converterBin(*ArqTexto, arqBin, quantidade);

			fclose(arqBin);

			if((*ArqLi = fopen("PROVAO_ORDENADO.bin", "r+b")) == NULL){
				printf("ERRO: O arquivo PROVAO_ORDENADO.bin nao pode ser criado corretamente.\n");
				exit(1);
			}

			if((*ArqEi = fopen("PROVAO_ORDENADO.bin", "r+b")) == NULL){
				printf("ERRO: O arquivo PROVAO_ORDENADO.bin nao pode ser criado corretamente.\n");
				exit(1);
			}

			if((*ArqLEs = fopen("PROVAO_ORDENADO.bin", "r+b")) == NULL){
				printf("ERRO: O arquivo PROVAO_ORDENADO.bin nao pode ser criado corretamente.\n");
				exit(1);
			}

			break;
		}

		case 2:
		{ //ARQUIVO INVERSAMENTE ORDENADO
			if((arqBin = fopen("PROVAO_INVERSAMENTE.bin", "wb")) == NULL){
				printf("ERRO: O arquivo PROVAO_INVERSAMENTE.bin nao pode ser criado corretamente.\n");
				exit(1);
			}

			converterBin(*ArqTexto, arqBin, quantidade);

			fclose(arqBin);

			if((*ArqLi = fopen("PROVAO_INVERSAMENTE.bin", "r+b")) == NULL){
				printf("ERRO: O arquivo PROVAO_INVERSAMENTE.bin nao pode ser criado corretamente.\n");
				exit(1);
			}

			if((*ArqEi = fopen("PROVAO_INVERSAMENTE.bin", "r+b")) == NULL){
				printf("ERRO: O arquivo PROVAO_INVERSAMENTE.bin nao pode ser criado corretamente.\n");
				exit(1);
			}

			if((*ArqLEs = fopen("PROVAO_INVERSAMENTE.bin", "r+b")) == NULL){
				printf("ERRO: O arquivo PROVAO_INVERSAMENTE.bin nao pode ser criado corretamente.\n");
				exit(1);
			}

			break;
		}

		case 3:
		{ //ARQUIVO DESORDENADO ALEATORIAMENTE
			if((arqBin = fopen("PROVAO.bin", "wb")) == NULL){
				printf("ERRO: O arquivo PROVAO.bin nao pode ser criado corretamente.\n");
				exit(1);
			}

			converterBin(*ArqTexto, arqBin, quantidade);

			fclose(arqBin);

			if((*ArqLi = fopen("PROVAO.bin", "r+b")) == NULL){
				printf("ERRO: O arquivo PROVAO.bin nao pode ser criado corretamente.\n");
				exit(1);
			}

			if((*ArqEi = fopen("PROVAO.bin", "r+b")) == NULL){
				printf("ERRO: O arquivo PROVAO.bin nao pode ser criado corretamente.\n");
				exit(1);
			}

			if((*ArqLEs = fopen("PROVAO.bin", "r+b")) == NULL){
				printf("ERRO: O arquivo PROVAO.bin nao pode ser criado corretamente.\n");
				exit(1);
			}

			break;
		}
	}
}

//Lendo os dados de arqOriginal (arquivo texto) e escrevendo em arqBin (arquivo binário)
void converterBin(FILE* arqOriginal, FILE* arqBin, int quantidade){
	long int nroInscricao;
	double nota;
	char estado[3];
	char cidade[51];
	char curso[31];

	int i = 0;

	while(i < quantidade)
	{
		fscanf(arqOriginal, "%ld", &nroInscricao);
		fscanf(arqOriginal, "%lf", &nota);
		fgets(estado, 2, arqOriginal);
		fgets(cidade, 50, arqOriginal);
		fgets(curso, 30, arqOriginal);

		Aluno* aluno = malloc(sizeof(Aluno));
		aluno->inscricao = nroInscricao;
		aluno->nota = nota;
		strcpy(aluno->estado, estado);
		strcpy(aluno->cidade, cidade);
		strcpy(aluno->curso, curso);

		fwrite(aluno, sizeof(Aluno), 1, arqBin);
		free(aluno);

		i++;
	}
}

//Lendo os dados de arqOriginal (arquivo binário) e escrevendo em arqTexto (arquivo texto)
void converterTexto(FILE* arqOriginal, FILE* arqTexto, int quantidade){
	long int nroInscricao;
	double nota;
	char estado[3];
	char cidade[51];
	char curso[31];

	int i = 0;

	while(i < quantidade)
	{
		Aluno* aluno = malloc(sizeof(Aluno));

		fread(aluno, sizeof(Aluno), 1, arqOriginal);

		nroInscricao = aluno->inscricao;
		nota = aluno->nota;
		strcpy(estado, aluno->estado);
		strcpy(cidade, aluno->cidade);
		strcpy(curso, aluno->curso);

		completaInscricaoArq(arqTexto, nroInscricao);
		completaNotaArq(arqTexto, nota);
		fprintf(arqTexto, "%-s %-s %-s\n", estado, cidade, curso);
		
		free(aluno);

		i++;
	}
	fclose(arqOriginal);

	//Deletando os arquivos intermediários
	remove("PROVAO.bin");
	remove("PROVAO_ORDENADO.bin");
	remove("PROVAO_INVERSAMENTE.bin");
}