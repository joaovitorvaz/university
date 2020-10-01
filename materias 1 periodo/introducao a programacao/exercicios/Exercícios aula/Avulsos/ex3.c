// Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC201-61P
// Murilo de Paula Vieira Neto - 19.1.4011 - BCC201-62P

#include <stdio.h>
int main()
{
  int x, y, cont, ax;

  do {
    printf("Digite os valores de x e y: ");
    scanf("%d %d", &x, &y);
      if (x>y) {
        printf("\nx deve ser menor que y.\n\n");
      }
      else if ((x%2!=0) || (y%2!=0)) {
        printf("\nApenas numeros pares sao aceitos.\n\n");
      }
  } while ((x>y) || (x%2!=0) || (y%2!=0));

  printf("\n");

  int linha= (((y-x)/2)+1);
  int espac= ((y-x)/2);

  for (int i=0; i<linha; i++){
    for (cont=0; cont<espac; cont++) {
      printf(" ");
    }
    for (ax=0; ax<x; ax++){
      printf("*");
    }
    printf("\n");
    espac-=1;
    x+=2;
  }
  printf("\n");
  return 0;
}
