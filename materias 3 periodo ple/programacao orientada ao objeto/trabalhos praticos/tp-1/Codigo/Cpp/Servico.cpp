#include "../Hpp/Servico.hpp"

//Concluidos todos os metodos necessário fazer o teste
Servico :: Servico(double valorTotal, int codeServico):valorTotal(valorTotal), codeServico(codeServico) {}

Servico :: ~Servico() {}

MaoDeObra Servico :: getMaoDeObra(){
    return mao_de_obra;
};

void Servico :: setMaoDeObra(string nome, double valor){
    this->mao_de_obra.setNome(nome);
    this->mao_de_obra.setValor(valor);
};

list<Item> Servico :: getListaItem(){
    return listaItem;
};

void Servico :: setListaItem(Item item){   
    listaItem.push_front(item);
}; 

bool Servico :: removeItem(int codeItem){
    
    for (std::list<Item>::iterator i = this->listaItem.begin(); i!=this->listaItem.end(); i++){
        if(i->codeItem == codeItem){
            this->listaItem.erase(i);
        }
        else{
            continue;
        }        
    }  
};

double Servico :: getValorTotal(){
    this->valorTotal = this->mao_de_obra.getValor();
    for (std::list<Item>::iterator i = this->listaItem.begin(); i!=this->listaItem.end(); i++){
        this->valorTotal += i->getPreco();
        
    }  
    return valorTotal;
};

int Servico :: getCodeServico(){
    return codeServico;
};

void Servico :: setCodeServico(int codeServico){
    this->codeServico = codeServico;
};