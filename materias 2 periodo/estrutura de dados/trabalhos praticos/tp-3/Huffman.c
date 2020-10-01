#include "Huffman.h"

struct lista{
    ListaNo* first;
    int elementos;
};

struct listaNo{
    HeapNo* no;
    ListaNo* prox;
};

struct heapNo{
    byte simbolo;
    int freq;
    HeapNo *esq,*dir;
};

Lista* createLista(){
    Lista* nova = malloc(sizeof(Lista));
    nova->first = NULL;
    nova->elementos = 0;

    return nova;
}

ListaNo* createListaNo(HeapNo* no){
    ListaNo* lNo = malloc(sizeof(ListaNo));

    lNo->no = no;
    lNo->prox = NULL;

    return lNo;
}

HeapNo* createHeapNo(int freq, byte simbolo, HeapNo* esq, HeapNo* dir){
    HeapNo* hNo = malloc(sizeof(HeapNo));

    hNo->freq = freq;
    hNo->simbolo = simbolo;
    hNo->esq = esq;
    hNo->dir = dir;

    return hNo;
}

void insertNo(ListaNo* lNo, Lista* lista){
    if(!lista->first){
        lista->first = lNo;
    }
    else if(lNo->no->freq < lista->first->no->freq){
        lNo->prox = lista->first;
        lista->first = lNo;
    }
    else{
        ListaNo* aux = lista->first->prox;
        ListaNo* aux2 = lista->first;

        while(aux && aux->no->freq <= lNo->no->freq){
            aux2 = aux;
            aux = aux2->prox;
        }
        aux2->prox = lNo;
        lNo->prox = aux;
    }
    lista->elementos++;
}

HeapNo* removeHeapMin(Lista* lista){
    ListaNo* aux = lista->first;
    HeapNo* aux2 = aux->no;

    lista->first = aux->prox;

    free(aux);
    aux = NULL;

    lista->elementos--;

    return aux2;
}

//unsigned int
void getFrequenciaBytes(FILE* input, unsigned int* listaBytes){
    byte simbolo;
    while(fread(&simbolo, 1, 1, input) >= 1)
        listaBytes[(byte)simbolo]++;
    rewind(input);
}

bool getCodigo(HeapNo* hNo, byte simbolo, char* buffer, int size){
    if((!hNo->esq || !hNo->dir) && hNo->simbolo == simbolo){
        buffer[size] = '\0';
        return true;
    }
    else{
        bool flag = false;

        if(hNo->esq){
            buffer[size] = '0';
            flag = getCodigo(hNo->esq, simbolo, buffer, size + 1);
        }
        if(!flag && hNo->esq){
            buffer[size] = '1';
            flag  = getCodigo(hNo->dir,simbolo,buffer,size + 1);
        }
        if(!flag)
            buffer[size] = '\0';
        return flag;
    }
}

//void* = unsigned*
HeapNo* buildArvoreHuffman(unsigned* listaBytes){
    Lista* lista = createLista();

    for(int i = 0; i < 256; i++)
        if(listaBytes[i])
            insertNo(createListaNo(createHeapNo(i, listaBytes[i], NULL, NULL)), lista);
    while(lista->elementos > 1){
        HeapNo* esq = removeHeapMin(lista);
        HeapNo* dir = removeHeapMin(lista);
        HeapNo* soma = createHeapNo('#', esq->freq + dir->freq, esq, dir);
        insertNo(createListaNo(soma),lista);
    }
    return removeHeapMin(lista);
}

void liberaArvoreHuffman(HeapNo* hNo){
    if(!hNo) return;
    else{
        HeapNo* esq = hNo->esq;
        HeapNo* dir = hNo->dir;
        free(hNo);
        liberaArvoreHuffman(esq);
        liberaArvoreHuffman(dir);
    }
}

int geraBit(FILE* input, int pos, byte* aux){
    (pos % 8 == 0) ? fread(aux, 1, 1, input) : NULL == NULL;
    return !!((*aux) & (1 << (pos % 8)));//<< nao sabemos pa que serve essa merda
}

void comprimeArquivo(char* inputFile, char* outputFile){
    unsigned listaBytes[256] = {0};

    FILE* input = fopen(inputFile, "rb");
    FILE* output = fopen(outputFile, "wb");

    getFrequenciaBytes(input, listaBytes);

    HeapNo* raiz = buildArvoreHuffman(listaBytes);

    fwrite(listaBytes, 256, sizeof(listaBytes[0]), output);

    fseek(output, sizeof(int), SEEK_CUR);

    byte simbolo, aux = 0;
    unsigned size = 0;

    while(fread(&simbolo, 1, 1, input) >= 1){
        char buffer[1024] = {0};
        getCodigo(raiz, simbolo, buffer, 0);
        for(char* i = buffer; *i; i++){
            if(*i = '1')
                aux = aux + pow(2, size % 8);
            size++;

            if(size % 8 == 0){
                fwrite(&aux, 1, 1, output);
                aux = 0;
            }
        }
    }
    fwrite(&aux, 1, 1, output);
    fseek(output, 256*sizeof(int),SEEK_SET);
    fwrite(&size, 1, sizeof(void*), output);

    fseek(input, 0L, SEEK_END);
    double tamanhoInput = ftell(input);

    fseek(output, 0l, SEEK_END);
    double tamanhoOutput = ftell(output);

    liberaArvoreHuffman(raiz);

    printf("Input File: %s\n", inputFile);
    printf("(%lf bytes)\n",tamanhoInput/1000);

    printf("Output File: %s\n",outputFile);
    printf("%lf bytes\n",tamanhoOutput/1000);

    printf("Frequencia de descompressao: %f\n",(tamanhoOutput*100)/tamanhoInput);

    fclose(output);
    fclose(input);
}

void descomprimirFile(char* inputFile, char* outputFile){
    unsigned listaBytes[256] = {0};

    FILE* input = fopen(inputFile, "rb");
    FILE* output = fopen(outputFile, "wb");

    fread(listaBytes, 256, sizeof(listaBytes[0]),input);

    HeapNo* raiz = buildArvoreHuffman(listaBytes);

    unsigned size;
    fread(&size, 1, sizeof(size),input);

    int pos = 0;
    byte aux = 0;

    while(pos < size){
        HeapNo* hNo_Atual = raiz;

        while(hNo_Atual->esq || hNo_Atual->dir)
            hNo_Atual = geraBit(input, pos++, &aux) ? hNo_Atual->dir : hNo_Atual->esq;
        fwrite(&(hNo_Atual->simbolo), 1, 1, output);
    }

    liberaArvoreHuffman(raiz);

    fseek(input, 0L, SEEK_END);
    double tamanhoInput = ftell(input);

    fseek(output, 0L, SEEK_END);
    double tamanhoOutput = ftell(output);

    printf("Input File: %s\n", inputFile);
    printf("(%lf bytes)\n",tamanhoInput/1000);

    printf("Output File: %s\n",outputFile);
    printf("%lf bytes\n",tamanhoOutput/1000);

    printf("Frequencia de descompressao: %f\n",(tamanhoOutput*100)/tamanhoInput);

    fclose(output);
    fclose(input);

}

void createArquivo_Compressao(){
    int* words = malloc(100*sizeof(int));
    FILE* aux = fopen("input.ttf","w+b");

    for(int i = 0; i < 100; i++){
        words[i] = (char)(rand() % 176);
        fwrite(&words[i], sizeof(int),1, aux);
    }
    fclose(aux);
    free(words);
}

void createArquivo_Descompressao(){
    int* words  = malloc(FILE_SIZE*sizeof(int));
    FILE* aux = fopen("input.hx", "w+b");

    for(int i = 0; i<FILE_SIZE;i++){
        words[i]  = (char)(rand()%176);
        fwrite(&words[i],sizeof(int), 1,aux);
    }
    fclose(aux);
    free(words);
}
