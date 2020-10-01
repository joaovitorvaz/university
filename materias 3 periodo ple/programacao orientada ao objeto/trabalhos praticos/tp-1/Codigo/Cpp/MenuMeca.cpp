#include"../Hpp/MenuMeca.hpp"
#include <unistd.h>

//Menu inicial
void menuMeca(Mecanico* mecani){   
    Vendedor vend;
    Ordem ordem("planejada", "Barulhos estranhos", "Barulhos esquisito", "122.270.936.84",40.4, true, 0.0, true, 80),ordem1("planejada", "Barulhos estranhos", "Barulhos esquisito", "122.270.936.84",40.4, true, 0.0, false, 40),ordem2("planejada", "Barulhos estranhos", "Barulhos esquisito", "122.270.936.84",40.4, false, 0.0, false, 10);
    
    list<Ordem> listaOrdem{ordem,ordem1,ordem2};    
    int opcao;
    do{
        system("clear || cls");
        cout<<"As ações possíveis para mecanicos são: \n"<<endl;
        cout<<"1.Visualizar Ordems de servico abertas e aceita-las"<<endl;
        cout<<"2.Cadastrar Servicos executados e pecas utilizadas"<<endl;    
        cout<<"3.Logout\n\n";
        cout<<"Ação desejada: ";
        cin>>opcao;

        switch(opcao){
            case 1:    
                //Visualizar ordens disponíveis
                system("clear || cls");          
                viewOrdems(mecani,vend);
            break;
                
            case 2: 
                //Cadastrar servições cadastrados
                system("clear || cls");       
                adicionaServico(mecani,vend);
            break;
            case 3:
                //Logout
                system("clear || cls");
                cout << "Saindo...\n";
                usleep(2000000);
            break;
            default:
            
            cout<<"Comando invalido"<<endl;
            break;
        }
   }while(opcao != 3);

}

//Funcao para visualizar Ordems e seleciona-las
void viewOrdems(Mecanico* mecan, Vendedor vend){   
    system("clear || cls");
    int codeOrdem;    
    int aprovacao; 
    vend.printaOrdens(1);
    cout<<"\nSelecione uma ordem:";    
    cin>>codeOrdem;
    mecan->setOrdem(vend.getOrdem(codeOrdem));
}

//Adiciona um numero x de servicos a Ordem
void adicionaServico(Mecanico* mecani, Vendedor vendi){
    system("clear || cls");
    //Definindo quantos servicos foram realizados no mesmo carro
    int servico;
    cout<<"Numero de servicos realizados no veiculo:";
    cin>>servico;
    //Armazenando multiplos servicos na ordem
    for(int i = 0; i<servico; i++){
        cadastraServico(mecani, vendi);
    }   
}

void cadastraServico(Mecanico* mecani,Vendedor vendi){
    
    //Variaveis para criação de uma mao de obra
    string nomeMao;
    double valor;

    //Variaveis para criação de um item
    string nomeItem;
    double preco;
    int quantidade;
    int codeItem;
    int tipos;
    //Criação do Item
    Item item;
    //Criacao servico           
    Servico servico;


    cout<<"Mao de obra realizada: ";
    cin>>nomeMao;
    cout<<"Custo da mao de obra: ";
    cin>>valor;
    servico.setMaoDeObra(nomeMao,valor);

    cout<<"Variedade de items utilizados: ";
    cin>>tipos;

    for(int i = 0; i<tipos; i++){
        cout<<"Item utilizado: ";
        cin>>nomeItem;
        cout<<"Quantidade: ";
        cin>>quantidade;
        cout<<"Valor do Item: ";
        cin>>preco;
        cout<<"Codigo do Item: ";
        cin>>codeItem;       
       
        item.setNome(nomeItem);
        item.setQuantidade(quantidade);
        item.setPreco(preco);
        item.setCodeItem(codeItem);
        servico.setListaItem(item);    
        mecani->setServicoOrdem(servico);
        vendi.setOrdem(mecani->getOrdem());
    }
}


