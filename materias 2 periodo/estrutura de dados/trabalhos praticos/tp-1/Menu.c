#include"Menu.h"

/*Metódo ideal seria criar um tipo varias funções para cada função do menu,
de forma a evitar um alto volume de parametros para a função main menu*/

void mainMenu(){

  int indice, indiceAdd, indiceDel, indiceEdit, indiceShow;
  int nMoradores=0, nTarefas=0, nAfazeres=0;
  int m=0, t=0, a=0;
  char NomeRep[R];

  Morador** auxMorador=malloc(5*sizeof(Morador*));
  for(int i=0; i<5; i++){
    auxMorador[i]=criarMorador("Lala", "01/11/20", 0);
  }
  Tarefa** auxTarefa=malloc(5*sizeof(Tarefa*));
  for(int i=0; i<5; i++){
    auxTarefa[i]=criarTarefa("varrer", 1, 0);
  }
  Afazer** auxAfazer=malloc(5*sizeof(Afazer*));
  for(int i=0; i<5; i++){
    auxAfazer[i]=CriaAfazer(auxMorador[i], auxTarefa[i]);
  }

  scanf("%s", NomeRep);
  printf("Republica: %s\n", NomeRep);

  Republica* rep=criaRep(NomeRep);

  do{
    scanf("%d", &indice);

    switch(indice){
        case 1:
            scanf("%d", &indiceAdd);
            menuAdd(indiceAdd, auxMorador, auxTarefa, auxAfazer, rep, &nMoradores, &nTarefas, &nAfazeres);
            break;

        case 2:
            scanf("%d", &indiceShow);
            menuShow(indiceShow, auxTarefa, rep, &m, &t, &a);
            break;

        case 3:
            scanf("%d", &indiceEdit);
            menuEdit(indiceEdit, auxMorador, auxTarefa, auxAfazer, rep);
            break;

        case 4:
            scanf("%d", &indiceDel);
            menuDel(indiceDel, auxMorador, auxTarefa, auxAfazer);
            break;

        case 5:
          for(int i=0; i<5; i++){
              apagarMorador(auxMorador[i]);
          }
          free(auxMorador);
          for(int i=0; i<5; i++){
              apagarTarefa(auxTarefa[i]);
          }
          free(auxTarefa);
          for(int i=0; i<5; i++){
              LiberaAfazer(auxAfazer[i]);
          }
          free(auxAfazer);
          free(rep);
          break;
      }
  }while(indice!=5);
}

void menuAdd(int indiceAdd, Morador **auxMorador, Tarefa **auxTarefa, Afazer **auxAfazer, Republica *rep, int* nMoradores, int* nTarefas, int* nAfazeres){
    char nome[R], dtIngresso[12], tarefa[R];
    int condicao, prioridade, preenchida;
    int posicaoM, posicaoT;

    switch(indiceAdd){
        case 1:
           scanf("%s", nome);
           scanf("%s", dtIngresso);
           scanf("%d", &condicao);
           setNomeMorador(auxMorador[*nMoradores], nome);
           setDtIngressoMorador(auxMorador[*nMoradores], dtIngresso);
           setCondMorador(auxMorador[*nMoradores], condicao);
           setMoradorR(rep, auxMorador[*nMoradores], *nMoradores);
           *nMoradores+=1;
        break;

        case 2:
            scanf("%s", tarefa);
            scanf("%d", &prioridade);
            scanf("%d", &preenchida);
            setPreenchimentoTarefa(auxTarefa[*nTarefas], preenchida);
            setPrioridadeTarefa(auxTarefa[*nTarefas], prioridade);
            setNomeTarefa(auxTarefa[*nTarefas], tarefa);
            setTarefaR(rep, auxTarefa[*nTarefas], *nTarefas);
            *nTarefas+=1;
            if(*nTarefas==5){
              MergeSort(auxTarefa, 0, 4);
            }
        break;

        case 3:
            scanf("%d", &posicaoM);
            scanf("%d", &posicaoT);
            setMoradorR(rep, auxMorador[posicaoM], posicaoM);
            setTarefaR(rep, auxTarefa[posicaoT], posicaoT);
            setAfazeresR(rep, auxAfazer[*nAfazeres], *nAfazeres);
            *nAfazeres+=1;
        break;
    }
}

void menuShow(int indiceAdd, Tarefa** auxTarefa, Republica* rep, int* m, int* t, int* a){
  int pos, busca;
    switch(indiceAdd){
        case 1:
            scanf("%d", &pos);
            if(*m==0){
              printf("\nOs moradores da republica são: \n\n");
            }
            ImprimeNomeMorador(rep, pos);
            *m+=1;
        break;

        case 2:
            if(*t==0){
              printf("\nAs tarefas da republica são: \n\n");
            }
            scanf("%d", &busca);
            pos=pesquisaBinaria(auxTarefa, busca, 0, 4);
            ImprimeDescTarefa(rep, pos);
            *t+=1;
        break;

        case 3:
            if(*a==0){
              printf("\nAfazeres: \n\n");
            }
            scanf("%d", &pos);
            ImprimeAfazerR(rep, pos);
            *a+=1;
        break;
    }
}

void menuEdit(int indiceEdit, Morador **auxMorador, Tarefa **auxTarefa, Afazer **auxAfazer, Republica* rep){
    char nome[R], dtIngresso[12], tarefa[R];
    int condicao, prioridade, preenchida;
    int posicao;
    int posA;
    int posD;

    switch(indiceEdit){
        case 1:
            scanf("%d", &posicao);
            scanf("%s", nome);
            setNomeMorador(auxMorador[posicao], nome);
            scanf("%s", dtIngresso);
            setDtIngressoMorador(auxMorador[posicao], dtIngresso);
            scanf("%d", &condicao);
            setCondMorador(auxMorador[posicao], condicao);
            setMoradorR(rep, auxMorador[posicao], posicao);
        break;
        case 2:
            scanf("%d", &posicao);
            scanf("%s", tarefa);
            setNomeTarefa(auxTarefa[posicao], tarefa);
            scanf("%d", &prioridade);
            setPrioridadeTarefa(auxTarefa[posicao], prioridade);
            scanf("%d", &preenchida);
            setPreenchimentoTarefa(auxTarefa[posicao], preenchida);
            setTarefaR(rep, auxTarefa[posicao], posicao);
        break;
        case 3:
            scanf("%d", &posA);
            scanf("%d", &posD);
            setMorador(auxAfazer[posA], auxMorador[posD]);
            scanf("%d", &posD);
            setTarefa(auxAfazer[posA], auxTarefa[posD]);
            setAfazeresR(rep, auxAfazer[posA], posA);
        break;
    }
}

void menuDel(int indiceDel, Morador **auxMorador, Tarefa **auxTarefa, Afazer **auxAfazer){
    int posicao;
    switch(indiceDel){
        case 1:
            scanf("%d", &posicao);
            apagarMorador(auxMorador[posicao]);
        break;

        case 2:
            scanf("%d", &posicao);
            apagarTarefa(auxTarefa[posicao]);
        break;

        case 3:
            scanf("%d", &posicao);
            LiberaAfazer(auxAfazer[posicao]);
        break;
    }
}
