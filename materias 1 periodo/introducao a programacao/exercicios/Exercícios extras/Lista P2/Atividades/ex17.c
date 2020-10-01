#include <stdio.h>
#define T 365
int main ()
{
  float vetort[T];
  float tp=0, md;
   for (int i=0; i<T; i++){
     printf ("Insira a temperatura: ");
     scanf("%f", & vetort[i]);
     tp+=vetort[i];
   }
  md=tp/T;
  printf("\n\n");

  for (int i=0; i<T; i++){
    if (vetort[i]<md){
      printf ("%.2f", vetort[i]);
      printf ("\n");
    }
  }

  return 0;
}
