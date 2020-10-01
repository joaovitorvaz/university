int Maximo(int *v, int tam){
    int max=v[0];

    for (int i=1; i<tam; i++){
        if (v[i]>max){
            max=v[i];
        }
    }
    return max;
}


void CountingSort(int *v, int tam, int expo){
    int aux[n];
    int i;
    int count[10]={0};

    for (i=0; i < n; i++){
        count[(v[i]/expo)%10]++;
    }

    for (i=1; i<10; i++){
        count[i]+=count[i-1];
    }

    for (i=n-1; i>=0; i--){
        aux[count[(v[i]/expo)%10]-1]=v[i];
        count[(v[i]/expo)%10]--;
    }

    for (i=0; i<n; i++){
        v[i] = aux[i];
    }
}

void RadixSort(int *v, int tam){
    int max=Maximo(v, tam);

    for (int expo=1; max/expo>0; expo*=10){
        CountingSort(v, tam, expo);
    }
}

void Printar(int *v, int tam){
    for (int i=0; i<tam; i++){
        printf("%d ", v[i]);
    }
}

int main(){
    int *vetor;
    RadixSort(v, T);
    Printar(v, T);
    return 0;
}
