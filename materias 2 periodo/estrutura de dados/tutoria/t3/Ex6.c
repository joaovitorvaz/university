#include <stdio.h>

void retornoBin(int num);

int main(){
  int num;

  scanf("%d", &num);
  retornoBin(num);
  printf("\n");
  return 0;
}

void retornoBin(int num){
  if(num/2!=0){
    retornoBin(num/2);
  }
  printf("%d", num%2);
}
