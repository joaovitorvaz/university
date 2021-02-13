#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int *inverso(int *v, int n);

int main()
{
  setlocale (LC_ALL,"");
  int n, *v, *vem;
  printf("Insira um valor de n: ");
  scanf("%d", &n);
  printf("\n");
  v = malloc(n * sizeof(int));
  vem = malloc(n * sizeof(int));

  for(int i=0; i<n; i++){
    printf("Insira o digito %d: ", i+1);
    scanf("%d", &v[i]);
  }

  vem = inverso(v, n);
  free(v);

  for(int i=0; i<n; i++){
    printf("\nO inverso e: %d", vem[i]);
  }

  printf("\n");

  free(vem);
  return 0;
}

int *inverso(int*v, int n) {

  int *nw=NULL;
  nw = malloc(n * sizeof(int));

  for(int i=0; i<n; i++){
    nw[i]=v[n-i-1];
  }

  return nw;
}
