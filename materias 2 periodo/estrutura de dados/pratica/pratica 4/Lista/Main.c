#include "Lista.h"

int main(){
  Lista* lista = CriaLista();
  int n, v;

  scanf("%d", &n);
  lst_insere_comeco(lista, n);
  scanf("%d", &n);
  lst_insere_comeco(lista, n);
  scanf("%d", &n);
  lst_insere_comeco(lista, n);

  scanf("%d", &n);
  lst_inserefinal(lista, n);

  printf("Lista encadeada: ");
  lst_imprime(lista);

  lst_retiraprim(lista);

  printf("\nLista encadeada: ");
  lst_imprime(lista);

  scanf("%d",&n);
  int p = pertence(lista, n);
  if(p == 1){
    printf("\n\nO numero %d pertence a lista!\n", n);
  }
  else
    printf("\n\nO numero %d nao pertence a lista!\n", n);

    v=lst_vazia(lista);
    if(v==0){
      printf("\nA lista esta vazia.");
    }
    else
      printf("\nA lista nao esta vazia.");

  LiberaLista(lista);

  return 0;
}
