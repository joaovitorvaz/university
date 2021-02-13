#include "../Hpp/Funcionario.hpp"

Funcionario :: Funcionario(string nome, string cpf, string rg, string endereco, string telefone, string email, string user, string senha, int id) : Pessoa(nome, cpf, rg, endereco, telefone, email), user(user), senha(senha), id(id){}

Funcionario :: ~Funcionario(){};

//Gets

string Funcionario :: getUser(){
    return user;
}

string Funcionario :: getSenha(){
    return senha;
}

int Funcionario :: getId(){
    return id;
}

//Sets

void Funcionario :: setUser(string user){
    this->user = user;
}

void Funcionario :: setSenha(string senha){
    this->senha = senha;
}

void Funcionario :: setId(int id){
    this->id = id;
}