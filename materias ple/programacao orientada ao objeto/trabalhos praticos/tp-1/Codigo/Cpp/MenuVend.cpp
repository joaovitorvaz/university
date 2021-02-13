#include "../Hpp/MenuVend.hpp"

#include <unistd.h>

void menuVend(Vendedor* vendedor)
{
    int opcao;
    Ordem ordem;
    Cliente cliente;

    do {
        system("clear || cls");
        cout << "As ações possíveis para vendedores são: \n" << endl;
        cout << "1. Cadastrar cliente e veiculo" << endl;
        cout << "2. Gerar ordem de serviço" << endl;
        cout << "3. Visualizar clientes" << endl;
        cout << "4. Visualizar ordems de serviço pendetes" << endl;
        cout << "5. Visualizar ordems de serviço executadas" << endl;
        cout << "6. Logout\n\n";
        cout << "Ação desejada: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            //Cadastrar Cliente e Veiculo
            system("clear || cls");
            cout << "Cria Cliente\n\n";
            cliente = vendedor->criaCadastro();
            vendedor->addCliente(cliente);
            cout << "\nFinalizado com exito.\n";
            usleep(2000000);
            break;
        case 2:
            //Gerar Ordem de serviço
            system("clear || cls");
            getchar();
            ordem = vendedor->criaOrdem();
            vendedor->addOrdem(&ordem);
            break;

        case 3:
            //Visualizar Clientes
            system("clear || cls");
            editaCliente(vendedor);
            break;

        case 4:
            //Ordens pendentes
            system("clear || cls");
            editaOrdem(vendedor);
            break;

        case 5:
            //Ordens executadas
            system("clear || cls");
            vendedor->printaOrdens(2);
            break;

        case 6:
            //Logout
            system("clear || cls");
            cout << "Saindo...\n";
            usleep(2000000);
        break;

        default:
            cout << "\nComando invalido" << endl;
        }
    } while (opcao != 6);
}

void editaCliente(Vendedor* vendedor) {
    system("clear || cls");

    string cpf, editVend;
    int opcao;
    Cliente cliente;

    vendedor->printaClientes();
    cout << "\nDigite o CPF do Cliente que deseja alterar: ";
    cin >> cpf;
    system("clear || cls");
    cliente = vendedor->getCliente(cpf);
    bool condicao = true;
    while(condicao) {
        vendedor->printaCliente(cpf);
        cout << "\n1. Nome" << endl;
        cout << "2. Endereco" << endl;
        cout << "3. Telefone" << endl;
        cout << "4. Email" << endl;
        cout << "5. Sair" << endl;
        cout << "\nDigite a opção desejada para edição: ";
        cin >> opcao;
        switch (opcao) {
        case 1:
            system("clear || cls");
            getchar();
            cout << "Novo Nome: ";
            getline(cin, editVend);
            cliente.setNomeCliente(editVend);
            cout << "Nome editado com sucesso" << endl;
            vendedor->setCliente(cliente);
            usleep(2000000);
            break;
        
        case 2:
            system("clear || cls");
            getchar();
            cout << "Novo Endereço: ";
            getline(cin, editVend);
            cliente.setEnderecoCliente(editVend);
            cout << "Endereço editado com sucesso" << endl;
            vendedor->setCliente(cliente);
            usleep(2000000);
            break;

        case 3:
            system("clear || cls");
            getchar();
            cout << "Novo Telefone: ";
            getline(cin, editVend);
            cliente.setTelefoneCliente(editVend);
            cout << "Telefone editada com sucesso" << endl;
            vendedor->setCliente(cliente);
            usleep(2000000);
            break;

        case 4:
            system("clear || cls");
            getchar();
            cout << "Novo Email: ";
            getline(cin, editVend);
            cliente.setEmailCliente(editVend);
            cout << "Email editada com sucesso" << endl;
            vendedor->setCliente(cliente);
            usleep(2000000);
            break;

        case 5:
            system("clear || cls");
            condicao = false;
            break;
        
        default:
            system("clear || cls");
            cout << "Opção invalida!" << endl;
            break;
        }
    }
}

void editaOrdem(Vendedor* vendedor) {
    system("clear || cls");
    list<int> ordens = vendedor->printaOrdens(1);
    Ordem ordem;
    int opcao, edit;
    bool condicao = true;
    do {
        cout << "\nDigite o id da ordem desejada: ";
        cin >> opcao;

        for(list<int>::iterator i = ordens.begin(); i != ordens.end(); i++) {
            if(opcao == *i) {
                ordem = vendedor->getOrdem(opcao);
                condicao = false;
                break;
            }
        }

        if(condicao) 
            cout << "Ordem não encontrada!" << endl;
    } while(condicao); 

    string editString;
    bool editbool;
    condicao = true;
    while(condicao) {
        system("clear || cls");
        vendedor->printaOrdem(opcao);
        cout << "\n1. Tipo" << endl;
        cout << "2. Motivo" << endl;
        cout << "3. Descrição" << endl;
        cout << "4. Aprovação" << endl;
        cout << "5. Estado" << endl;
        cout << "6. Excluir ordem" << endl;
        cout << "7. Sair" << endl;
        cout << "\nDigite a opção desejada para edição: ";
        cin >> edit;
        switch (edit) {
        case 1:
            getchar();
            cout << "New tipo: ";
            getline(cin, editString);
            ordem.setTipo(editString);
            cout << "Tipo editado com sucesso" << endl;
            vendedor->setOrdem(ordem);
            usleep(2000000);
            break;
        
        case 2:
            getchar();
            cout << "New Motivo: ";
            getline(cin, editString);
            ordem.setMotivo(editString);
            cout << "Motivo editado com sucesso" << endl;
            vendedor->setOrdem(ordem);
            usleep(2000000);
            break;

        case 3:
            getchar();
            cout << "New Descrição: ";
            getline(cin, editString);
            ordem.setDescricao(editString);
            cout << "Descrição editada com sucesso" << endl;
            vendedor->setOrdem(ordem);
            usleep(2000000);
            break;

        case 4:
            editbool = ordem.getAprovacao() ? false : true;
            cout << "Aprovação editada com sucesso" << endl;
            ordem.setAprovacao(editbool);
            vendedor->setOrdem(ordem);
            usleep(2000000);
            break;

        case 5:
            editbool = ordem.getEstado() ? false : true;
            cout << "Estado editado com sucesso" << endl;
            ordem.setEstado(editbool);
            vendedor->setOrdem(ordem);
            usleep(2000000);
            break;

        case 6:
            vendedor->deleteOrdem(ordem);
            cout << "Ordem deletada com sucesso" << endl;
            condicao = false;
            usleep(2000000);
            break;

        case 7:
            condicao = false;
            break;
        
        default:
            cout << "Opção invalida!" << endl;
            break;
        }
    }
}

void ordensConcluidas(Vendedor* vendedor) {
    int opcao, id;
    bool condicao = true;
    do {
        vendedor->printaOrdem(2);
        cout << "1. Excluir ordens" << endl;
        cout << "2. Sair" << endl;
        cout << "Digite a opção desejada: ";
        cin >> opcao;

        switch(opcao) {
        case 1:
            cout << "Digite o Id da ordem que deseja excluir: ";
            cin >> id;
            vendedor->deleteOrdem(vendedor->getOrdem(id));
            cout << "Ordem excluida com sucesso" << endl;
            usleep(2000000);
            break;
        
        case 2:
            condicao = false;
            break;

        default:
            cout << "Comando invalido!" << endl;
            break;
        }
    } while(condicao);
}