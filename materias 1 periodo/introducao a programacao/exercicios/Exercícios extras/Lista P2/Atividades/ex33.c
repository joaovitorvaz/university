#include <stdio.h>
int main ()
{
  int n;
  int soma=0;

  do {
  printf("Insira o valor de n: ");
  scanf("%d", &n);
  } while (n>30);

  printf("\n");

  int mat[n][n];

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      printf("Insira um numero para |Linha - %d| - |Coluna - %d| : ", i+1, j+1);
      scanf("%d", &mat[i][j]);
    }
  }

  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if (j<i){
      soma+= mat[i][j];
      }
    }
  }
  printf("\nSoma dos elementos abaixo da diagonal principal: %d", soma);
  printf("\n");
  return 0;
}
