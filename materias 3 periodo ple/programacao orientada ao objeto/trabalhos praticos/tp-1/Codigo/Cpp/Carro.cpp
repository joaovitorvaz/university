#include "../Hpp/Carro.hpp"
 
Carro :: Carro(string modelo, string placa, string cor, int id) : modelo(modelo), placa(placa), cor(cor), id(id){}

Carro :: ~Carro(){};

//Gets

string Carro :: getModelo(){
    return modelo;
}

string Carro :: getPlaca(){
    return placa;
}

string Carro :: getCor(){
    return cor;
}

Ordem Carro :: getListaHistorico(int indice){
    list<Ordem>::iterator i = this->historico.begin();

    advance(i, indice - 1);

    return *i;
}

//Sets

void Carro :: setModelo(string modelo){
    this->modelo = modelo;
}

void Carro :: setPlaca(string placa){
    this->placa = placa;
}

void Carro :: setCor(string cor){
    this->cor = cor;
}




