#include "Aluno.h"

struct aluno{
	char nome[100];
	int cpf;
	int matricula;
	bool flag;
};

Aluno* criaAluno(char* nome, int cpf, int matricula){
	Aluno* aluno=malloc(sizeof(Aluno));
	strcpy(aluno->nome, nome);
	aluno->cpf=cpf;
	aluno->matricula=matricula;
	aluno->flag=true;
	return aluno;
}

void liberaAluno(Aluno* aluno){
	free(aluno);
}

void imprimeAluno(Aluno* aluno){
  printf("Nome: %s | CPF: %d | Matricula: %d \n", aluno->nome, aluno->cpf, aluno->matricula);
}

char* getNome(Aluno* aluno){
	return aluno->nome;
}

int getCPF(Aluno* aluno){
	return aluno->cpf;
}

int getMatricula(Aluno* aluno){
	return aluno->matricula;
}

bool getExistente(Aluno* aluno){
	return aluno->flag;
}

void setNome(Aluno* aluno, char* nome){
	strcpy(aluno->nome, nome);
}

void setCPF(Aluno* aluno, int cpf){
	aluno->cpf=cpf;
}

void setMatricula(Aluno* aluno, int matricula){
	aluno->matricula=matricula;
}

void setExiste(Aluno* aluno){
	aluno->flag=false;
}
