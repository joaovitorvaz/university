#include "../Hpp/Pessoa.hpp"
#include <iostream>

Pessoa :: Pessoa(string nome, string cpf, string rg, string endereco, string telefone, string email) : nome(nome), cpf(cpf), rg(rg), endereco(endereco), telefone(telefone), email(email) {}

Pessoa :: ~Pessoa() {}

// Gets

string Pessoa :: getNome() {
    return nome;
}

string Pessoa :: getCpf() {
    return cpf;
}

string Pessoa :: getRg() {
    return rg;
}

string Pessoa :: getEndereco() {
    return endereco;
}

string Pessoa :: getTelefone() {
    return telefone;
}

string Pessoa :: getEmail() {
    return email;
}

// Sets

void Pessoa :: setNome(string nome) {
    this->nome = nome;
}

void Pessoa :: setCpf(string cpf) {
    this->cpf = cpf;
}

void Pessoa :: setRg(string rg) {
    this->cpf = cpf;
}

void Pessoa :: setEndereco(string endereco) {
    this->endereco = endereco;
}

void Pessoa :: setTelefone(string telefone) {
    this->telefone = telefone;
}

void Pessoa :: setEmail(string email) {
    this->email = email;
}

// Sobrecarga

istream& operator>>(istream& in, Pessoa& pessoa) {
    getchar();
    cout << "Nome: ";
    getline(in, pessoa.nome);
    cout << "CPF: ";
    getline(in, pessoa.cpf);
    cout << "RG: ";
    getline(in, pessoa.rg);
    cout << "Endereço: ";
    getline(in, pessoa.endereco);
    cout << "Telefone: ";
    getline(in, pessoa.telefone);
    cout << "Email: ";
    getline(in, pessoa.email);
    return in;
}