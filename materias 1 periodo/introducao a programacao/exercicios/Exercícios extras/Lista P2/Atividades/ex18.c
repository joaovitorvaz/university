#include <stdio.h>
#define N 10
int main ()
{
  int vet1[N];
  int vet2[N];
   for (int i=0; i<N; i++){
     printf ("Insira um valor: ");
     scanf ("%d", &vet1[i]);
   }
   printf("\n");
   for (int i=N; i>0; i--){
     vet2[i]=vet1[i-1];
     printf("%d  ", vet2[i]);
   }
   printf("\n\n");
   return 0;
}
