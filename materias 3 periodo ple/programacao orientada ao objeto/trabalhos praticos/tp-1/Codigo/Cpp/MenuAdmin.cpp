#include "../Hpp/MenuAdmin.hpp"

void menuAdmin(Administrador* administrador){
    
    int opcao, resposta;

    do{
        system("clear || cls");
        cout<<"As ações possíveis para o Administrador são: \n\n"<<endl;
        cout<<"1.  Cadastrar um Vendedor"<<endl;
        cout<<"2.  Alterar dados de um Vendedor"<<endl; 
        cout<<"3.  Selecionar um Vendedor"<<endl;
        cout<<"4.  Deletar um Vendedor"<<endl;
        cout<<"5.  Cadastrar um Mecanico"<<endl;
        cout<<"6.  Alterar dados de um Mecanico"<<endl;
        cout<<"7.  Selecionar um Mecanico"<<endl;
        cout<<"8.  Deletar um Mecanico"<<endl;
        cout<<"9.  Listar Vendedores"<<endl;
        cout<<"10. Listar Mecanicos"<<endl;
        cout<<"11. Logout\n\n";

        cout<<"Ação desejada: ";

        cin>>opcao;

        switch(opcao){
            case 1:
                //Cadastrar Vendedor
                system("clear || cls");
                cout << "Criando um vendedor\n" << endl;
                administrador->addVendedor(administrador->criaVendedor());
                cout << "\nCadastrado com sucesso!\n";
                usleep(2000000);
            break;

            case 2:
                //Editar Vendedor
                system("clear || cls");
                administrador->printaVendedores();
                cout << "Insira o ID do vendedor que deseja editar: ";
                cin >> resposta;
                system("clear || cls");
                cout << "Editando um vendedor\n" << endl;
                administrador->setVendedor(administrador->criaVendedor(), resposta);
                cout << "\nEditado com sucesso!\n";
                usleep(2000000);
            break;

            case 3:
                //Visualizar Vendedor
                system("clear || cls");
                cout << "Insira o ID do vendedor que deseja visualizar: ";
                cin >> resposta;
                administrador->printaVendedor(administrador->getVendedorId(resposta));
                usleep(3000000);
            break;

            case 4:
                //Excluir Vendedor
                system("clear || cls");
                administrador->printaVendedores();
                cout << "Insira o ID do vendedor que deseja apagar: ";
                cin >> resposta;
                system("clear || cls");
                cout << "Apagando um vendedor\n" << endl;
                administrador->removeVendedor(administrador->getVendedorId(resposta));
                cout << "\nExcluido com sucesso!\n";
                usleep(2000000);
            break;

            case 5:
                //Cadastrar Mecanico
                system("clear || cls");
                administrador->addMecanico(administrador->criaMecanico());
                cout << "\nCadastrado com sucesso!\n";
                usleep(2000000);
            break;

            case 6:
                //Editar Mecanico
                system("clear || cls");
                administrador->printaMecanicos();
                cout << "Insira o ID do mecanico que deseja editar: ";
                cin >> resposta;
                system("clear || cls");
                cout << "Editando um mecanico\n" << endl;
                administrador->setMecanico(administrador->criaMecanico(), resposta);
                cout << "\nEditado com sucesso!\n";
                usleep(2000000);
            break;

            case 7:
                //Visualizar Mecanico
                system("clear || cls");
                cout << "Insira o ID do mecanico que deseja visualizar: ";
                cin >> resposta;
                administrador->printaMecanico(administrador->getMecanicoId(resposta));
                usleep(3000000);
            break;

            case 8:
                //Excluir Mecanico
                system("clear || cls");
                administrador->printaMecanicos();
                cout << "Insira o ID do mecanico que deseja apagar: ";
                cin >> resposta;
                system("clear || cls");
                cout << "Apagando um mecanico\n" << endl;
                administrador->removeMecanico(administrador->getMecanicoId(resposta));
                cout << "\nExcluido com sucesso!\n";
                usleep(2000000);
            break;

            case 9:
                //Mostrar todos os Vendedores
                system("clear || cls");
                administrador->printaVendedores();
                usleep(4000000);
            break;

            case 10:
                //Mostrar todos os Mecanicos
                system("clear || cls");
                administrador->printaMecanicos();
                usleep(4000000);
            break;

            case 11:
                //Logout
                system("clear || cls");
                cout << "Saindo...\n";
                usleep(2000000);             
            break;

            default:
            
            cout<<"Comando invalido"<<endl;
        }
    }while(opcao!=11);
}