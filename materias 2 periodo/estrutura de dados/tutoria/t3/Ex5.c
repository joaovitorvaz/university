#include <stdio.h>
#include <stdlib.h>

int Fibonacci(int num, int *cont);

int main(){
  int num, fib;
  int *cont=malloc(sizeof(int));
  *cont=0;

  scanf("%d", &num);
  fib=Fibonacci(num, cont);
  printf("fib(%d) = %d, chamadas = %d\n", num, fib, *cont);
  free(cont);
  return 0;
}

int Fibonacci(int num, int *cont){
  if(num==0){
    *cont+=1;
    return 0;
  }
  else if(num==1){
    *cont+=1;
    return 1;
  }
  else{
    *cont+=1;
    return Fibonacci(num-1, cont) + Fibonacci(num-2, cont);
  }
}
