#include "Hash.h"

struct hash{
	int n;
	int pos;
	Aluno** array;
};

Hash* criaHash(){
	Hash* hash=malloc(sizeof(Hash));
	hash->n=0;
	hash->pos=N;
	hash->array=malloc(sizeof(Aluno*[hash->pos]));
	for(int i=0; i<hash->pos; i++){
		hash->array[i]=NULL;
  }
	return hash;
}

void liberaHash(Hash* hash){
	for(int i=0; i<hash->pos; i++){
		liberaAluno(hash->array[i]);
  }
	free(hash);
}

int fhash(Hash* hash, int mat){
	return(mat % hash->pos);
}

int searchash(Hash* hash, int mat){
	int h=fhash(hash, mat);
	while(hash->array[h]!=NULL){
		if((getMatricula(hash->array[h])==mat) && getExistente(hash->array[h])){
			return h;
    }
		h=(h+1)%hash->pos;
	}
	return -1;
}

int insereHash(Hash* hash, Aluno* aluno){
	if(hash->n>0.75*hash->pos){
		redimensionar(hash);
  }
	if(searchash(hash, getMatricula(aluno)) != -1){
		return 0;
	}
	int h=fhash(hash, getMatricula(aluno));
	while(hash->array[h] != NULL){
		h = (h + 1) % hash->pos;
  }
	hash->array[h] = aluno;
	hash->n++;
	return 1;
}

void redimensionar(Hash* hash){
	int max=hash->pos;
	Aluno** ant=hash->array;
	hash->n=0;
	hash->pos*=1.947;
	hash->array=malloc(sizeof(Aluno*[hash->pos]));
	for(int i=0; i<hash->pos; i++){
		hash->array[i] = NULL;
  }
	for(int i=0; i<max; i++){
		if(ant[i]){
			insereHash(hash, ant[i]);
    }
  }
	free(ant);
}

int removeHash(Hash* hash, int mat){
	int h=searchash(hash, mat);
	if(h!=-1){
		setExiste(hash->array[h]);
  }
	return h;
}

Aluno* getAluno(Hash* hash, int h){
	return hash->array[h];
}
