#include "../Hpp/Vendedor.hpp"

Vendedor :: Vendedor(string nome, string cpf, string rg, string endereco, string telefone, string email, string user, string senha, int id) : Funcionario(nome, cpf, rg, endereco, telefone, email, user, senha, id) {}

Vendedor :: ~Vendedor() {}

// Define os Code das ordens criadas, para criar certa originalidade e manter organizado o historico das ordens
int Vendedor :: idOrdem = 1000;

list<Ordem> Vendedor :: ordens;

list<Cliente> Vendedor :: clientes;

Cliente Vendedor :: criaCadastro() {
    string modelo, placa, cor; 
    Pessoa newPessoa;
    cin >> newPessoa;

    cout << "\nCadastro do Carro\n\nModelo: ";
    getline(cin, modelo);
    cout << "Placa: ";
    getline(cin, placa);
    cout << "Cor: ";
    getline(cin, cor);

    Cliente newCliente(newPessoa.getNome(), newPessoa.getCpf(), newPessoa.getRg(), newPessoa.getEndereco(), newPessoa.getTelefone(), newPessoa.getEmail());
    Carro newCarro = Carro(modelo, placa, cor);
    newCliente.addCarro(newCarro);

    return newCliente;
}

Ordem Vendedor :: criaOrdem() {
    system("clear || cls");
    string tipo, motivo, descricao, cpfCliente, confirmacao;
    double km;
    bool correto = true;
    do {
        cout << "Deseja orçamento? (Sim ou Nao): ";
        cin >> confirmacao;
        if(confirmacao.compare("Sim") == 0) {
            tipo = "Orçamento";
            correto = false;
        }

        else if(confirmacao.compare("Nao") == 0) {
            tipo = "Manutenção direta";
            correto = false;
        }

        else 
            cout << "Comando invalido! Tente novamente\n\n";
    } while(correto);

    getchar();
    cout << "Digite o motivo da manutenção: ";
    getline(cin, motivo);
    cout << "Digite a descrição do problema: ";
    getline(cin, descricao);
    
    correto = true;
    do {
        cout << "Digite o CPF do cliente (Apenas numeros): ";
        cin >> cpfCliente;
        for(list<Cliente>::iterator i = this->clientes.begin(); i != this->clientes.end(); i++) {
            if(cpfCliente.compare(i->getCpf()) == 0) {
                correto = false;
                break;
            }
        }

        if(correto) {
            cout << "Cliente não encontrado! Deseja cadastrar o cliente? (Sim ou Nao): ";
            cin >> confirmacao;

            if(confirmacao.compare("Sim") == 0) {
                cout << "IMPORTANTE: O CPF inserido abaixo é o que será registrado!\n";
                cout << "Cria Cliente\n\n";
                Cliente novo = this->criaCadastro();
                cpfCliente = novo.getCpf();
                this->addCliente(novo);
                correto = false;
            }
        }
    } while(correto);

    cout << "Digite a quilometragem atual do carro: ";
    cin >> km;

    Ordem newOrdem(tipo, motivo, descricao, cpfCliente, km);
    return newOrdem;
}

void Vendedor :: addOrdem(Ordem* ordem) {
    (*ordem).setCodeOrdem(idOrdem);
    idOrdem++;
    this->ordens.push_back(*ordem);
}

void Vendedor :: deleteOrdem(Ordem ordem) {
    list<Ordem>::iterator i = this->ordens.begin();

    while( i->getCodeOrdem() != ordem.getCodeOrdem() ) 
        advance(i, 1);

    this->ordens.erase(i);
}
list<Ordem> Vendedor :: getListaOrdem(){
    return ordens;
}

Ordem Vendedor :: getOrdem(int id) {    
    for(list<Ordem>::iterator i = this->ordens.begin(); i != this->ordens.end(); i++) {
        if(i->getCodeOrdem() == id)
            return *i;
    }
}

void Vendedor :: setOrdem(Ordem ordem) {
    for(list<Ordem>::iterator i = this->ordens.begin(); i != this->ordens.end(); i++) {
        if(i->getCodeOrdem() == ordem.getCodeOrdem()) {
            *i = ordem;
            return;
        }
    }
}

void Vendedor :: addCliente(Cliente cliente) {
    this->clientes.push_back(cliente);
}

Cliente Vendedor :: getCliente(string cpf) {
    for(list<Cliente>::iterator i = this->clientes.begin(); i != this->clientes.end(); i++) {
        if(cpf.compare(i->getCpf()) == 0) 
            return *i;
    }
}

void Vendedor :: setCliente(Cliente cliente) {
    for(list<Cliente>::iterator i = this->clientes.begin(); i != this->clientes.end(); i++) {
        if(i->getCpf() == cliente.getCpf()) {
            *i = cliente;
            return;
        }
    }
}

bool Vendedor :: confirmaOrdem(Ordem ordem) {
    ordem.setAprovacao(true);
    return true;
}

list<int> Vendedor :: printaOrdens(int opcao) {
    list<int> ordem;
    for(list<Ordem>::iterator i = this->ordens.begin(); i != this->ordens.end(); i++) {
        //Printar funcoes que ainda nao foram finalizadas
        if(opcao == 1 && !i->getEstado() ) {
            cout << i->getCodeOrdem() << " " << i->getMotivo() << " " << i->getCpfCliente() << endl;
            ordem.push_back(i->getCodeOrdem());
        }
        //Funcao que ja estao prontas
        else if(opcao == 2 && i->getEstado()) {
            cout << i->getCodeOrdem() << " " << i->getMotivo() << " " << i->getCpfCliente() << endl;
            ordem.push_back(i->getCodeOrdem());
        }
       
        else {
            cout << i->getCodeOrdem() << " " << i->getMotivo() << " " << i->getCpfCliente() << endl;
            ordem.push_back(i->getCodeOrdem());
        }
    }

    return ordem;
}

void Vendedor :: printaOrdem(int indice) {
    Ordem ordem;
    for(list<Ordem>::iterator i = this->ordens.begin(); i != this->ordens.end(); i++) {
        if(i->getCodeOrdem() == indice) {
            ordem = *i;
            break;
        }
    }

    string aprovacao = ordem.getAprovacao() ? "Aprovado" : "Em analise";
    string estado = ordem.getEstado() ? "Finalizado" : "Em andamento";
    cout << "Tipo: " << ordem.getTipo() << endl;
    cout << "Motivo: " << ordem.getMotivo() << endl;
    cout << "Descrição: " << ordem.getDescricao() << endl;
    cout << "Code Ordem: " << ordem.getCodeOrdem() << endl;
    cout << "CPF cliente: " << ordem.getCpfCliente() << endl;
    cout << "Valor: " << ordem.getValorFinal() << endl;
    cout << "Aprovação: " << aprovacao << endl;
    cout << "Estado: " << estado << endl;
} 

void Vendedor :: printaClientes() {
    for(list<Cliente>::iterator i = this->clientes.begin(); i != this->clientes.end(); i++) {
        cout << i->getNome() << " " << i->getCpf() << endl;
    }
}

void Vendedor :: printaCliente(string cpf) {
    Cliente cliente;
    for(list<Cliente>::iterator i = this->clientes.begin(); i != this->clientes.end(); i++) {
        if(cpf.compare(i->getCpf()) == 0) {
            cliente = *i;
            break;
        }
    }

    cout << "Nome: " << cliente.getNome() << endl;
    cout << "CPF: " << cliente.getCpf() << endl;
    cout << "RG: " << cliente.getRg() << endl;
    cout << "Endereço: " << cliente.getEndereco() << endl;
    cout << "Telefone: " << cliente.getTelefone() << endl;
    cout << "Email: " << cliente.getEmail() << endl;
}
