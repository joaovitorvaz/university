#ifndef SERVICO_HPP
#define SERVICO_HPP

#include "./Item.hpp"
#include "./MaodeObra.hpp"
#include<list>

//Adicionar metodo para retornar um dos nós da listas
class Servico{
    private:
        MaoDeObra mao_de_obra;       
        list<Item> listaItem;        
        double valorTotal;
        

    public:
        int codeServico;
        Servico(double valorTotal = 0.0, int codeServico = 000000);
        ~Servico();

        MaoDeObra getMaoDeObra();       
        void setMaoDeObra(string nome, double valor);

        list<Item> getListaItem();
        void setListaItem(Item item);
        bool removeItem(int codeItem);

        double getValorTotal();

        int getCodeServico();
        void setCodeServico(int codeServico);         
};

#endif