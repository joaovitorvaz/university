#include"../Hpp/Cliente.hpp"

Cliente :: Cliente(string nome, string cpf, string rg, string endereco, string telefone, string email) : Pessoa(nome, cpf, rg, endereco, telefone, email) {}

Cliente :: ~Cliente(){};

// Sets para edição dos campos do cliente de acordo com os dados de pessoa

void Cliente :: setNomeCliente(string nome) {
    this->setNome(nome);
}

void Cliente :: setTelefoneCliente(string telefone) {
    this->setTelefone(telefone);
}

void Cliente :: setEmailCliente(string email) {
    this->setEmail(email);
}

void Cliente :: setEnderecoCliente(string endereco) {
    this->setEndereco(endereco);
}

// Interações com a lista de carro(s)

void Cliente :: addCarro(Carro carro){  
    carros.push_back(carro);
}

void Cliente :: popCarro(int id){    

    for (std::list<Carro>::iterator i = this->carros.begin(); i!=this->carros.end(); i++){
        if(i->id == id){
            this->carros.erase(i);
        }
        else{
            continue;
        }        
    }  
}

void Cliente :: printaCarro() {
    for(list<Carro>::iterator i = this->carros.begin(); i != this->carros.end(); i++ ) {
        cout << i->getModelo() << endl;
        cout << i->getPlaca() << endl;
        cout << i->getCor() << endl;
    }
}