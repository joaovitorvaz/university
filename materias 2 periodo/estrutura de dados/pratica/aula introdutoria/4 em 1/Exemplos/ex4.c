#include<stdio.h>
#include<stdlib.h>

int main()
{
  int quest, alunos, *gabarito, **provas, *notas;
  scanf("%d %d", &quest, &alunos);

  notas=malloc(alunos *sizeof(int));
  gabarito=malloc(quest * sizeof(int));
  for(int i=0; i< quest; i++){
    scanf("%d", &gabarito[i]);
  }

  provas=malloc(alunos *sizeof(int));
  for(int i=0; i< alunos; i++){
    provas[i]=malloc((quest+1) *sizeof(int));
    notas[i]=0;
    for(int j=0; j< quest+1; j++){
      scanf("%d", &provas[i][j]);
      if(provas[i][j]==gabarito[j]){
        notas[i]++;
      }
    }
    printf("%d  %d\n\n", provas[i][quest], notas[i]);
  }

    return 0;
}
