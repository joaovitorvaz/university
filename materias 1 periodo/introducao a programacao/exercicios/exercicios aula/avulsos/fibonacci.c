#include <stdio.h>

int main()
{
  int num, f1, f2, f3;

  do {
    printf("Digite um numero: ");
    scanf("%d", &num);
        if(num<=0) {
          printf("\nDigite um numero positivo!");
        }
  } while (num<=0);

    printf("\n0 - 1 - ");
    f1=0;
    f2=1;
    num=num-2;

    for(int cont=0; cont<=num; cont++) {
      f3=f2+f1;
      printf("%i - ",f3);
      f1=f2;
      f2=f3;
    }

    printf ("\n");

  return 0;
}
