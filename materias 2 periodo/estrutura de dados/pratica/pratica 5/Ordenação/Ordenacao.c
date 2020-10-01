#include "Ordenacao.h"

void Buble(int *v, int tam){
  int i, j, change;
  int aux;

  for(i=0; i<tam-1; i++){
    change=0;
    for(j=1; j<tam-i; j++){
      if(v[j]<v[j-1]){
        aux=v[j];
        v[j]=v[j-1];
        v[j-1]=aux;
        change++;
      }
    }
    if(change==0){
      break;
    }
  }
}

void SelectionSort(int *v, int tam){
  int i, j, max;
  int aux;

  for(i=tam-1; i>=0; i--){
    max=i;
    for(j=0; j<i; j++){
      if(v[j]>v[max]){
        max=j;
      }
    }
    if(i!=max){
      aux=v[max];
      v[max]=v[i];
      v[i]=aux;
  }
  }
}

void MergeOrdena(int *v, int esq, int dir){
  if(esq>=dir){
    return;
  }
  int meio=((esq+dir)/2);
  MergeOrdena(v, esq, meio);
  MergeOrdena(v, meio+1, dir);
  MergeIntercala(v, esq, meio, dir);
  return;
}

void MergeIntercala(int *v, int esq, int meio, int dir){
  int i, j, k;
  int tam_a=meio-esq+1;
  int tam_b=dir-meio;

  int *a=malloc(tam_a *sizeof(int));
  int *b=malloc(tam_b *sizeof(int));

  for(i=0; i<tam_a; i++){
    a[i]=v[i+esq];
  }

  for(i=0; i<tam_b; i++){
    b[i]=v[i+meio+1];
  }

  for(i=0, j=0, k=esq; k<=dir; k++){
    if(i==tam_a){
      v[k]=b[j++];
    }
    else if(j==tam_b){
      v[k]=a[i++];
    }
    else if(a[i]<b[j]){
      v[k]=a[i++];
    }
    else
      v[k]=b[j++];
  }
  free(a);
  free(b);
}

int PesqBinaria(int *v, int pesquisado, int low, int high){
    if (high<=low){
      return (pesquisado>v[low])?  (low+1): low;
    }

    int mid = (low+high)/2;

    if(pesquisado==v[mid]){
      return mid+1;
    }

    if(pesquisado>v[mid]){
      return PesqBinaria(v, pesquisado, mid+1, high);
    }

    return PesqBinaria(v, pesquisado, low, mid-1);
}

void InsertionSort(int *v, int tam){
    int i, loc, j, selected;

    for (i=1; i<tam; i++){
        j=i-1;
        selected=v[i];

        loc=PesqBinaria(v, selected, 0, j);

        while (j>=loc){
            v[j+1]=v[j];
            j--;
        }

        v[j+1]=selected;
    }
}
