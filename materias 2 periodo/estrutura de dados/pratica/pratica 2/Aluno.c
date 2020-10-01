#include "Aluno.h"

struct aluno{
    char nome [72];
    double cpf;
    int nMatricula;
    char curso [100];
    char dtIngresso[11];
};

Aluno *criarAluno(char *nome, double cpf, int nMatricula, char *curso, char *dtIngresso){
    Aluno * aluno = malloc(sizeof(Aluno));
    strcpy(aluno->nome, nome);
    aluno->cpf = cpf;
    aluno->nMatricula = nMatricula;
    strcpy(aluno->curso, curso);
    strcpy(aluno->dtIngresso, dtIngresso);
    return aluno;
}

void apagarAluno(Aluno *aluno){
    free(aluno);
}

void setNomeAluno(Aluno *aluno, char *nome){
    strcpy(aluno->nome, nome);
}

void setCpfAluno(Aluno *aluno, double cpf){
    aluno->cpf = cpf;
}

void setMatriculaAluno(Aluno *aluno, int nMatricula){
    aluno->nMatricula = nMatricula;
}

void setCursoAluno(Aluno *aluno, char *curso){
    strcpy(aluno->curso, curso);
}

void setDtIngressoAluno(Aluno *aluno, char *dtIngresso){
    strcpy(aluno->dtIngresso, dtIngresso);
}

char* getNomeAluno(Aluno *aluno){
    return aluno->nome;
}

double getCpfAluno(Aluno *aluno){
    return aluno->cpf;
}

int getMatriculaAluno(Aluno *aluno){
    return aluno->nMatricula;
}

char* getCursoAluno(Aluno *aluno){
    return aluno->curso;
}

char* getDtIngressoAluno(Aluno *aluno){
    return aluno->dtIngresso;
}

void imprimealuno(Aluno * aluno){
  printf("%s\n%.0lf\n%d\n%s\n%s\n\n", getNomeAluno(aluno), getCpfAluno(aluno), getMatriculaAluno(aluno), getCursoAluno(aluno), getDtIngressoAluno(aluno));
}
