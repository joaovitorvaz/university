#include "../Hpp/Ordem.hpp"
#include<iostream>


//Implementar get e set Cliente
Ordem :: Ordem(string tipo, string motivo, string descricao, string cpfCliente,double km, bool aprovacao, double valorFinal, bool estado, int codeOrdem):tipo(tipo), motivo(motivo), descricao(descricao), cpfCliente(cpfCliente), km(km), aprovacao(aprovacao), valorFinal(valorFinal), estado(estado), codeOrdem(codeOrdem){}
Ordem :: ~Ordem() {}

//Get e Set para o Tipo da ordem
string Ordem :: getTipo(){
    return tipo;
}

void Ordem :: setTipo(string tipo){
   this->tipo = tipo;
}

//Get e Set para o Motivo da ordem
string Ordem :: getMotivo(){
    return motivo;
}

void Ordem :: setMotivo(string motivo){
    this->motivo = motivo;
}

//Get e Set para a Descricao da ordem
string Ordem :: getDescricao(){
    return descricao;
}

void Ordem :: setDescricao(string descricao){
    this->descricao = descricao;
}

//Get e Set para a km do veiculo
double Ordem :: getKm(){
    return km;
}

void Ordem :: setKm(double km){
    this->km = km;
}

//Get e Set para a aprovacao
bool Ordem :: getAprovacao(){
    return aprovacao;
}

void Ordem :: setAprovacao(bool aprovacao){
    this->aprovacao = aprovacao;
}

//Metodos relacionados ao gerenciamento da lista de serviços
list<Servico> Ordem :: getListaServico(){
    return listaServico;
}

void Ordem :: setListaServico(Servico servico){
    listaServico.push_front(servico);
}

bool Ordem :: removeServico(int codeServico){
    
    for (std::list<Servico>::iterator i = this->listaServico.begin(); i!=this->listaServico.end(); i++){
        if(i->codeServico == codeServico){
            this->listaServico.erase(i);
        }
        else{
            continue;
        }
        
    }     
}

double Ordem :: getValorFinal(){   
    for (std::list<Servico>::iterator i = this->listaServico.begin(); i!=this->listaServico.end(); i++){
        this->valorFinal += i->getValorTotal();
        
    }  
    return valorFinal;
}

//Get e Set para o estado da Ordem(finalizada ou em andamento)
bool Ordem :: getEstado(){
    return estado;
}

void Ordem :: setEstado(bool estado){
    this->estado = estado;
}

int Ordem :: getCodeOrdem(){
    return codeOrdem;
}

void Ordem :: setCodeOrdem(int codeOrdem){
    this->codeOrdem = codeOrdem;
}

string Ordem :: getCpfCliente() {
    return cpfCliente;
}

void Ordem :: setCpfCliente(string cpfCliente) {
    this->cpfCliente = cpfCliente;
}
