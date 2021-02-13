//Marcus Vinícius Souza Fernandes  -  19.1.4046  -  BCC201-61P
#include <stdio.h>
#include <string.h>
#define M 70

int main()
{
  char n[M];
  int cd=0;
  int cu=0;
  int ci=0;
  int contse=0;

  printf("Digite o seu nome completo: ");
  fgets(n, M, stdin);
  printf("\n");

  ci = strlen(n)-1;

  for(int i = 0; i < ci; i++){
    if(n[i] != ' '){
      contse++;
    }
  }

  for(int i = ci-1; i >= 0 && n[i] != ' '; i--){
    if(n[i] != ' ') {
      cu++;
    }
  }

  cd=ci-cu-1;

  for(int i = cd +1; i <= ci -1;i++){
    printf("%c", n[i]);
  }

  printf(", ");

  for(int i =0; i < cd; i++){
    printf("%c", n[i]);
  }

  printf("\nTotal de letras: %d", contse);
  printf("\nTotal de letras do ultimo sobrenome: %d\n", cu);

  return 0;
}
