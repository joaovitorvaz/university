#include <stdio.h>

int MultiSom(int num1, int num2);

int main(){
  int num1, num2, result;

  scanf("%d", &num1);
  scanf("%d", &num2);
  result=MultiSom(num1, num2);
  printf("\nResultado = %d\n", result);
  return 0;
}

int MultiSom(int num1, int num2){
  if(num1==0){
    return 0;
  }
  else
    return num2 + MultiSom(num1-1, num2);
}
