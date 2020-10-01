#include "Aluno.h"
#include "Disciplina.h"
#include "Atestado.h"

struct atestado {
  Aluno *aluno;
  Disciplina** disc;
  int hmax;
};

Atestado *criarAtestado (Aluno *aluno, Disciplina **disc, int hmax){
  Atestado *atestado = malloc(sizeof(Atestado));
  atestado->aluno = aluno;
  atestado->disc = disc;
  atestado->hmax = hmax;
  return atestado;
}

void apagaAtestado (Atestado *atestado, int hmax){
apagarAluno(atestado->aluno);
  for (int i = 0; i < hmax; i+=4){
    free(atestado->disc[i/4]);
  }
  free(atestado->disc);
  free(atestado);
}

void setAlunoAtestado (Atestado *atestado, Aluno *aluno){
  atestado->aluno = aluno;
}

void setDisciplinaAtestado (Atestado *atestado, Disciplina *disc, int opcao){
  atestado->disc[opcao] = disc;
}

void setCargaAtestado (Atestado *atestado , int hmax){
  atestado->hmax = hmax;
}

void getAlunoAtestado (Atestado *atestado, Aluno *aluno){
  aluno = atestado->aluno;
}

void getDisciplinaAtestado (Atestado *atestado, Disciplina *disc, int opcao){
  disc = getDisciplina(atestado->disc, opcao);
}

void getCargaAtestado (Atestado *atestado, int *hmax){
  *hmax = atestado->hmax;
}

void imprimeAtestado(Atestado * atestado){
  imprimealuno(atestado->aluno);
    for(int i=0; i<4; i++){
      imprimeDisc(atestado->disc[i]);
    }
}
