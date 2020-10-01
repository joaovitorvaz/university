#include "../Hpp/MaodeObra.hpp"

MaoDeObra :: MaoDeObra(string nome, double valor) : nome(nome), valor(valor){}

MaoDeObra :: ~MaoDeObra() {}

// Gets

string MaoDeObra :: getNome(){
    return nome;
}

double MaoDeObra :: getValor(){
    return valor;
}

// Sets

void MaoDeObra :: setNome(string nome) {
    this->nome = nome;
}

void MaoDeObra :: setValor(double valor) {
    this->valor = valor;
}
