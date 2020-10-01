#include <stdio.h>
#include <string.h>
#define R 10
#define T 3
int main ()
{
  char sex;
  char resp[R];
  float sm=0, sf=0, nm=0, nf=0;
  int st, nt;
  float pfs, pmn;

  for (int num=0; num<T; num++) {

    printf ("Entrevistado %d insira seu sexo. |m| para masculino e |f| para feminino: ", num+1);
    scanf ("%s", &sex);
    printf ("Insira sua resposta: ");
    scanf ("%s", resp);
    printf ("\n");

    if (sex == 'f'){
      if ((strcmp (resp, "sim")) == 0) {
        sf+=1;
      }
      else
        nf+=1;

    }
    else if (sex == 'm') {
      if ((strcmp (resp, "sim")) == 0) {
        sm+=1;
      }
      else
        nm+=1;
   }
  }

  st=sf+sm;
  nt=nf+nm;
  pfs=((sf/(sf+nf)*100));
  pmn=((nm/(sm+nm)*100));

  printf ("\n");
  printf ("%d pessoas responderam sim.", st);
  printf ("\n%d pessoas responderam nao.", nt);
  printf ("\nA porcentagem das mulheres que responderam sim e de: %.2f", pfs);
  printf ("\nA porcentagem dos homens que responderam nao e de: %.2f", pmn);
  printf ("\n");

  return 0;
}
