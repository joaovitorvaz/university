#ifndef ITEM_HPP
#define ITEM_HPP

#include<string>


using namespace std;

class Item {
//Foi utilizado a classe Pessoa para atribuir as permissoes de acesso
private:
    string nome;
    double preco;
    int quantidade;
    
   

public:
    int codeItem;
    Item(string nome = "", double preco = 0.0, int quantidade = 0, int codeItem = 0000);
    ~Item();
    string getNome();
    void setNome(string);
    double getPreco();
    void setPreco(double);
    int getQuantidade();
    void setQuantidade(int);   
    double ValorTotal();
    int getCodeItem();
    void setCodeItem(int codeItem);     
};

#endif