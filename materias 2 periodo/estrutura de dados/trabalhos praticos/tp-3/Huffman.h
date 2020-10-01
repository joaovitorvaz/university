#ifndef HUFFMAN_H
#define HUFFMAN_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

#define FILE_SIZE 1000

typedef unsigned char byte;

typedef struct lista Lista;
typedef struct listaNo ListaNo;
typedef struct heapNo HeapNo;

Lista* createLista();
ListaNo* createListaNo(HeapNo* no);
HeapNo* createHeapNo(int freq, byte symbol, HeapNo* esq, HeapNo* dir);
void insertNo(ListaNo* lNo, Lista* lista);
HeapNo* removeHeapMin(Lista* lista);
void getFrequenciaBytes(FILE* input, unsigned int* listaBytes);
bool getCodigo(HeapNo* hNo, byte simbolo, char* buffer, int size);
HeapNo* buildArvoreHuffman(unsigned* listaBytes);
void liberaArvoreHuffman(HeapNo* hNo);
int geraBit(FILE* input, int pos, byte* aux);
void comprimeArquivo(char* inputFile, char* outputFile);
void descomprimirFile(char* inputFile, char* outputFile);
void createArquivo_Compressao();
void createArquivo_Descompressao();

#endif
