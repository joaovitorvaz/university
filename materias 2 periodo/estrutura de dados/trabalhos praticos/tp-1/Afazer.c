#include "Afazer.h"

struct afazer{
  Morador *morador;
  Tarefa *tarefa;
};

Afazer* CriaAfazer(Morador *morador, Tarefa *tarefa){
  Afazer* afazer=malloc(sizeof(Afazer));
  afazer->morador=morador;
  afazer->tarefa=tarefa;
  return afazer;
};

void LiberaAfazer(Afazer *afazer){
  free(afazer);
}

void setMorador(Afazer *afazer, Morador *morador){
  afazer->morador=morador;
}

void setTarefa(Afazer *afazer, Tarefa *tarefa){
  afazer->tarefa=tarefa;
}

Morador *getMorador(Afazer *afazer){
    return afazer->morador;
}

Tarefa *getTarefa(Afazer *afazer){
    return afazer->tarefa;
}

void imprimeAfazer(Afazer* afazer){
    printf("A tarefa de %s é", getNomeMorador(afazer->morador));
    printf(" %s.\n", getNomeTarefa(afazer->tarefa));
}
