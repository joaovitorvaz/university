/*Segunda questão*/
bool pesquisa(TipoRegistro *x, TipoApontador ap){
    long i=1;

    if(ap==NULL){
      return false;
    }
    
    while((i<ap->n) && (x->chave >ap->r[i-1].chave)){
      i++;
    }
    
    if(x->chave==ap->r[i-1].chave){
      *x = ap->r[i-1].chave;
      return true;
    }

    if(x->chave<ap->r[i-1].chave){
      pesquisa(x, ap->p[i-1]);
    }
    else{
      pesquisa(x, ap->p[i]);
    }
}

/*Terceira questão*/
void maximo(TipoRegistro *x, TipoApontador ap){
    if(ap==NULL){
      return;
    }

    if(ap->p[ap->n]==NULL){
      *x = ap->r[ap->n-1];
    }

    else{
      maximo(x, ap->p[ap->n]);
    }

    return;
}