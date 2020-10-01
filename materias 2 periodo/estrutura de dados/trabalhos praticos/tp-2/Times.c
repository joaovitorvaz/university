#include "Times.h"

struct time{
  int pos;
  char nome[15];
  int pontos;
  float jogos;
  float vitorias;
  int golsm;
  int golss;
  int sg;
  float aprov;
  int ptotal;
};

Time* CriaTimes(int clubes){
  Time* time=malloc(clubes *sizeof(Time));
  char nome[15];
  for(int i=0; i<clubes; i++){
    time[i].pos = 0;
    scanf("%s", nome);
    strcpy(time[i].nome, nome);
    time[i].pontos = 0;
    time[i].jogos = 0;
    time[i].vitorias = 0;
    time[i].golsm = 0;
    time[i].golss = 0;
    time[i].sg = 0;
    time[i].aprov = 0;
    time[i].ptotal = 0;
  }
  return time;
}

void Jogos(Time *time, int clubes, int njogos){

  int golsm, golss;
  char lixo, nome[15];

  for (int i=0; i<njogos; i++){
    scanf("%s", nome);
    for (int j=0; j<clubes; j++){
      if(strcmp(nome, time[j].nome)==0){
        scanf("%d", &golsm);
        scanf("%c", &lixo);
        scanf("%c", &lixo);
        scanf("%c", &lixo);
        scanf("%d", &golss);
        setJogosTime(time, 1, j);
        setGolsmTime(time, golsm, j);
        setGolssTime(time, golss, j);
        if(golsm>golss){
          setPontosTime(time, 3, j);
          setVitoriasTime(time, 1, j);
        }
        else if(golsm==golss){
          setPontosTime(time, 1, j);
        }
      }
    }
    scanf("%s", nome);
    for (int j=0; j<clubes; j++) {
      if(strcmp(nome, time[j].nome)==0){
        setJogosTime(time, 1, j);
        setGolsmTime(time, golss, j);
        setGolssTime(time, golsm, j);
        if(golsm<golss){
          setPontosTime(time, 3, j);
          setVitoriasTime(time, 1, j);
        }
        else if(golsm==golss){
          setPontosTime(time, 1, j);
        }
      }
    }
  }
}

void AtualizarCampos(Time* time, int clubes){
  for (int i=0; i<clubes; i++){
    setSgTime(time, i);
    setAprovTime(time, i);
    setPtotalTime(time, i);
  }
}

void PrintarTime(Time* time, int clubes){
  for (int i=clubes-1; i>=0; i--){
    if(time[i+1].ptotal==time[i].ptotal){
      printf("\n   ");
    }
    else{
      printf("\n%d  ", clubes-i);
    }
    printf("\t\t%s\t", time[i].nome);
    printf(" %d\t", time[i].pontos);
    printf(" %.0f\t", time[i].jogos);
    printf(" %d\t", time[i].golsm);
    printf(" %d\t", time[i].golss);
    if(time[i].sg<0){
      printf("%d\t", time[i].sg);
    }
    else{
      printf(" %d\t", time[i].sg);
    }
    if(time[i].jogos==0){
      printf("N/A\t");
    }
    else{
      printf("%.1f\t", time[i].aprov);
    }
  }
  printf("\n");
}

void MergeOrdena(Time* time, int esq, int dir){
  if(esq>=dir){
    return;
  }
  int meio=((esq+dir)/2);
  MergeOrdena(time, esq, meio);
  MergeOrdena(time, meio+1, dir);
  MergeIntercala(time, esq, meio, dir);
  return;
}

void MergeIntercala(Time* time, int esq, int meio, int dir){
  int i, j, k;
  int tam_a=meio-esq+1;
  int tam_b=dir-meio;

  Time *a=malloc(tam_a *sizeof(Time));
  Time *b=malloc(tam_b *sizeof(Time));

  for(i=0; i<tam_a; i++){
    a[i]=time[i+esq];
  }

  for(i=0; i<tam_b; i++){
    b[i]=time[i+meio+1];
  }

  for(i=0, j=0, k=esq; k<=dir; k++){
    if(i==tam_a){
      time[k]=b[j++];
    }
    else if(j==tam_b){
      time[k]=a[i++];
    }
    else if(a[i].ptotal<b[j].ptotal){
      time[k]=a[i++];
    }
    else if(a[i].ptotal==b[j].ptotal){
      if(strcmp(a[i].nome, a[j].nome)<0){
        time[k]=a[i++];
      }
      else{
        time[k]=b[j++];
      }
    }
    else
      time[k]=b[j++];
  }
  free(a);
  free(b);
}
Time* LiberaTimes(Time* time){
  free(time);
}

void setNomeTime(Time* time, char *nome, int pos){
  strcpy(time[pos].nome, nome);
}

void setPontosTime(Time* time, int pontos, int pos){
  time[pos].pontos+=pontos;
}

void setVitoriasTime(Time* time, float vitorias, int pos){
  time[pos].vitorias+=vitorias;
}

void setJogosTime(Time* time, float jogos, int pos){
  time[pos].jogos+=jogos;
}

void setGolsmTime(Time* time, int golsm, int pos){
  time[pos].golsm+=golsm;
}

void setGolssTime(Time* time, int golss, int pos){
  time[pos].golss+=golss;
}

void setSgTime(Time* time, int pos){
  time[pos].sg=time[pos].golsm-time[pos].golss;
}

void setAprovTime(Time* time, int pos){
  time[pos].aprov=(time[pos].pontos/(time[pos].jogos*3))*100;
}

void setPtotalTime(Time* time, int pos){
  time[pos].ptotal=(time[pos].pontos*1000)+(time[pos].sg*100)+(time[pos].golsm*1);
}

char* getNomeTime(Time *time, int pos){
    return time[pos].nome;
}

int getPontosTime(Time* time, int pos){
  return time[pos].pontos;
}

float getVitoriasTime(Time* time, int pos){
  return time[pos].vitorias;
}

float getJogosTime(Time* time, int pos){
  return time[pos].jogos;
}

int getGolsmTime(Time* time, int pos){
  return time[pos].golsm;
}

int getGolssTime(Time* time, int pos){
  return time[pos].golss;
}

int getSgTime(Time* time, int pos){
  return time[pos].sg;
}

float getAprovTime(Time* time, int pos){
  return time[pos].aprov;
}

int getPtotalTime(Time* time, int pos){
  return time[pos].ptotal;
}
