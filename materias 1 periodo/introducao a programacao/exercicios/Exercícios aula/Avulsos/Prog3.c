/*Marcus vinícius Souza Fernandes  -  19.1.40.46 -  BCC201-61P*/
#include <stdio.h>
void duracaodogame(int hi, int mi, int hf, int mf);
int main()
{
  int hi, mi, hf, mf;
  printf("Insira a hora inicial: ");
  scanf("%d", &hi);
  printf("\nInsira os minutos iniciais: ");
  scanf("%d", &mi);
  printf("\nInsira a hora final: ");
  scanf("%d", &hf);
  printf("\nInsira os minutos finais: ");
  scanf("%d", &mf);
  duracaodogame(hi,mi, hf, mf);

  return 0;
}
void duracaodogame(int hi, int mi, int hf, int mf)
{
  int temptotal, hti, htf;
  hti=((hi*60)+mi);
  htf=((hf*60)+mf);
  if (htf<hti){
    htf=((24*60)+htf);
  }
  temptotal=(htf-hti);
  printf ("\nA duração total em minutosfoi de: %.2d minutos.\n", temptotal);
}
