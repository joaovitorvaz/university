#include "../Hpp/Item.hpp"


Item :: Item(string nome, double preco, int quantidade, int codeItem) : nome(nome), preco(preco), quantidade(quantidade), codeItem(codeItem){}

Item :: ~Item(){}

// Gets

string Item :: getNome(){
    return nome;
}

double Item :: getPreco(){
    return preco;
}

int Item :: getQuantidade(){
    return quantidade;
}

double Item :: ValorTotal(){
    return preco*quantidade;
}

// Sets

void Item :: setNome(string nome){
    this->nome = nome;
}

void Item :: setPreco(double preco){
    this->preco = preco;
}

void Item :: setQuantidade(int quantidade){
    this->quantidade = quantidade;

}
int Item :: getCodeItem(){
    return codeItem;
}
    
void Item :: setCodeItem(int codeItem){
    this->codeItem = codeItem;
}  



