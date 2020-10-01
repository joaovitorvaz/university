#include "Tarefa.h"

struct tarefa{
    char nome[100];
    int prioridade;
    int preenchida;
};

Tarefa *criarTarefa(char *nome, int prioridade, int preenchida){
    Tarefa *tarefa = malloc(sizeof(Tarefa));
    strcpy(tarefa->nome, nome);
    tarefa->prioridade = prioridade;
    tarefa->preenchida = preenchida;

    return tarefa;
};

void apagarTarefa(Tarefa *tarefa){
    free(tarefa);
}

void setNomeTarefa(Tarefa *tarefa, char *nome){
    strcpy(tarefa->nome, nome);
}

void setPrioridadeTarefa(Tarefa *tarefa, int prioridade){
    tarefa->prioridade = prioridade;
}

void setPreenchimentoTarefa(Tarefa *tarefa, int preenchida){
    tarefa->preenchida = preenchida;
}

char* getNomeTarefa(Tarefa *tarefa){
    return tarefa->nome;
}

double getPrioridadeTarefa(Tarefa *tarefa){
    return tarefa->prioridade;
}

double getPreenchimentoTarefa(Tarefa *tarefa){
    return tarefa->preenchida;
}

void imprimeTarefa(Tarefa* tarefa){
    printf("%s", tarefa->nome);
    printf("%d", tarefa->prioridade);
    printf("%d", tarefa->preenchida);
}

int pesquisaBinaria(Tarefa **tarefa, int buscado, int esq, int dir){

  if(esq>dir){
    return -1;
  }

  int aux=((esq+dir)/2);

  if(buscado==tarefa[aux]->prioridade){
    return aux;
  }

  else if(buscado<tarefa[aux]->prioridade){
    return pesquisaBinaria(tarefa, buscado, esq, aux-1);
  }

  else
    return pesquisaBinaria(tarefa, buscado, aux+1, dir);
}

void MergeSort(Tarefa **tarefa, int esq, int dir){

	if(esq>=dir){
        return;
    }
	int mid=(esq+dir)/2;
	MergeSort(tarefa, esq , mid);
	MergeSort(tarefa, mid+1, dir);
	Merge(tarefa, esq, mid, dir);
}

void Merge(Tarefa **tarefa, int esq, int mid, int dir){
  int i, j, k;
  int a_tam=mid-esq+1;
  int b_tam=dir-mid;
  int sub;

  Tarefa *a=malloc(a_tam*sizeof(Tarefa));
  Tarefa *b=malloc(b_tam*sizeof(Tarefa));

  for(i=0; i<a_tam; i++){
    sub=i+esq;
    a[i].prioridade=tarefa[sub]->prioridade;
    a[i].preenchida=tarefa[sub]->preenchida;
    strcpy(a[i].nome, tarefa[sub]->nome);
  }
  for(i=0; i<b_tam; i++){
    sub=i+mid+1;
    b[i].prioridade=tarefa[sub]->prioridade;
    b[i].preenchida=tarefa[sub]->preenchida;
    strcpy(b[i].nome, tarefa[sub]->nome);
  }
  for(i=0, j=0, k=esq; k<=dir; k++){
    if(i==a_tam){
      tarefa[k]->prioridade=b[j].prioridade;
      tarefa[k]->preenchida=b[j].preenchida;
      strcpy(tarefa[k]->nome, b[j].nome);
      j++;
    }
    else if(j==b_tam){
      tarefa[k]->prioridade=a[i].prioridade;
      tarefa[k]->preenchida=a[i].preenchida;
      strcpy(tarefa[k]->nome, a[i].nome);
      i++;
    }
    else if(a[i].prioridade < b[j].prioridade){
      tarefa[k]->prioridade=a[i].prioridade;
      tarefa[k]->preenchida=a[i].preenchida;
      strcpy(tarefa[k]->nome, a[i].nome);
      i++;
    }
    else{
    tarefa[k]->prioridade=b[j].prioridade;
    tarefa[k]->preenchida=b[j].preenchida;
    strcpy(tarefa[k]->nome, b[j].nome);
    j++;
  }
}
free(a);
free(b);
}
