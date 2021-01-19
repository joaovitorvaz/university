#include "../Hpp/Mecanico.hpp"

Mecanico :: Mecanico(string nome, string cpf, string rg, string endereco, string telefone, string email, string user, string senha, int id) : Funcionario(nome, cpf, rg, endereco, telefone, email, user, senha, id) {}

Mecanico :: ~Mecanico(){}


void Mecanico :: setOrdem(Ordem ordem){  
    this->ordem = ordem;
}

Ordem Mecanico :: getOrdem(){
    return ordem;
}

void Mecanico :: setServicoOrdem(Servico servico){    
    this->ordem.setListaServico(servico);
}

