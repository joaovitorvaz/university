#include <iostream>
#include <string>

#include "../Hpp/Administrador.hpp"

Administrador :: Administrador(string nome, string cpf, string rg, string endereco, string telefone, string email, string user, string senha, int id) : Funcionario(nome, cpf, rg, endereco, telefone, email, user, senha, id) {}

Administrador :: ~Administrador() {}

// Identificador
int Administrador :: idFunc = 1;

Vendedor Administrador :: criaVendedor() {
    // Forçamos o construtor para escrita dos campos desejados
    string user, senha;
    Pessoa newPessoa;
    cin >> newPessoa;
    cout << "User: ";
    getline(cin, user);
    cout << "Senha: ";
    getline(cin, senha);
    Vendedor newVendedor(newPessoa.getNome(), newPessoa.getCpf(), newPessoa.getRg(), newPessoa.getEndereco(), newPessoa.getTelefone(), newPessoa.getEmail(), user, senha);
    newVendedor.setId(idFunc);
    idFunc++;
    return newVendedor;
}

void Administrador :: addVendedor(Vendedor vendedor) {
    // Inserindo no fim da lista de vendedores
    this->vendedores.push_back(vendedor);
}

void Administrador :: removeVendedor(Vendedor vendedor) {
    // Removendo um vendedor de acordo com o id percorrido
    list<Vendedor>::iterator i = this->vendedores.begin();
    
    do {
        if(i->getId() == vendedor.getId())
            break;
        
        advance(i, 1);
    } while(i->getId() != vendedor.getId());

    this->vendedores.erase(i);
}

Vendedor Administrador :: getVendedorUser(string user) {
    // Obtendo um vendedor atraves do user passado.
    for(list<Vendedor>::iterator i = this->vendedores.begin(); i != this->vendedores.end(); i++) {
        if(user.compare(i->getUser()) == 0)
            return *i;
    } 
}

Vendedor Administrador :: getVendedorId(int id) {
    // Obtendo um vendedor atraves do id passado.
    for(list<Vendedor>::iterator i = this->vendedores.begin(); i != this->vendedores.end(); i++) {
        if(i->getId() == id)
            return *i;
    }
}

void Administrador :: setVendedor(Vendedor vendedor, int id) {
    for(list<Vendedor>::iterator i = this->vendedores.begin(); i != this->vendedores.end(); i++) {
        if(i->getId() == id){
            *i = vendedor;
            return;
        }
    }
}

Mecanico Administrador :: criaMecanico() {
    // Forçamos o construtor para escrita dos campos desejados
    string user, senha;
    Pessoa newPessoa;
    cin >> newPessoa;
    cout << "User: ";
    getline(cin, user);
    cout << "Senha: ";
    getline(cin, senha);
    Mecanico newMecanico(newPessoa.getNome(), newPessoa.getCpf(), newPessoa.getRg(), newPessoa.getEndereco(), newPessoa.getTelefone(), newPessoa.getEmail(), user, senha);
    newMecanico.setId(idFunc);
    idFunc++;
    return newMecanico;
}

void Administrador :: addMecanico(Mecanico mecanico) {
    // Inserindo no fim da lista de mecanicos
    this->mecanicos.push_back(mecanico);
}

void Administrador :: removeMecanico(Mecanico mecanico) {
    // Removendo um mecanico de acordo com o id percorrido
    list<Mecanico>::iterator i = this->mecanicos.begin();
    
    do {
        if(i->getId() == mecanico.getId())
            break;
        
        advance(i, 1);
    } while(i->getId() != mecanico.getId());

    this->mecanicos.erase(i);
}

Mecanico Administrador :: getMecanicoUser(string user) {
        // Obtendo um mecanico atraves do user passado.
    for(list<Mecanico>::iterator i = this->mecanicos.begin(); i != this->mecanicos.end(); i++) {
        if(user.compare(i->getUser()) == 0)
            return *i;
    } 
}

Mecanico Administrador :: getMecanicoId(int id) {
    // Obtendo um mecanico atraves do id passado.
    for(list<Mecanico>::iterator i = this->mecanicos.begin(); i != this->mecanicos.end(); i++) {
        if(i->getId() == id)
            return *i;
    }
}

void Administrador :: setMecanico(Mecanico mecanico, int id) {
    for(list<Mecanico>::iterator i = this->mecanicos.begin(); i != this->mecanicos.end(); i++) {
        if(i->getId() == id){
            *i = mecanico;
            return;
        }
    }
}

void Administrador :: printaVendedores() {
    // Printa em tela todos os vendedores
    cout << "\nId " << "Nome"  << "\n\n"; 
    for( list<Vendedor>::iterator i = this->vendedores.begin(); i != this->vendedores.end(); i++ ) {
        cout << i->getId() << " " << i->getNome() << "\n";
        cout << i->getUser() << " " << i->getNome() << "\n";
        cout << i->getSenha() << " " << i->getNome() << "\n";
        cout << "\n";
    }
}

void Administrador :: printaVendedor(Vendedor vendedor) {
    // Printa em tela um vendedor de acordo com o vendedor passado.
    cout << "\n";
    for( list<Vendedor>::iterator i = this->vendedores.begin(); i != this->vendedores.end(); i++ ) {
        if(i->getId() == vendedor.getId()){
            cout << "Nome      : " << i->getNome() << endl;
            cout << "Telefone  : " << i->getTelefone() << endl;
            cout << "Id        : " << i->getId() << endl;
            cout << "User      : " << i->getUser() << endl;
            cout << "Senha     : " << i->getSenha() << endl;
            cout << "\n";
            break;
        }
    }
}

void Administrador :: printaMecanicos() {
    // Printa em tela todos os mecanicos
    cout << "\nId " << "Nome"  << "\n\n"; 
    for( list<Mecanico>::iterator i = this->mecanicos.begin(); i != this->mecanicos.end(); i++ ) {
        cout << i->getId() << " " << i->getNome() << "\n";
        cout << "\n";
    }
}

void Administrador :: printaMecanico(Mecanico mecanico) {
    // Printa em tela um mecanico de acordo com o mecanico passado.
    cout << "\n";
    for( list<Mecanico>::iterator i = this->mecanicos.begin(); i != this->mecanicos.end(); i++ ) {
        if(i->getId() == mecanico.getId()){
            cout << "Nome      : " << i->getNome() << endl;
            cout << "Telefone  : " << i->getTelefone() << endl;
            cout << "Id        : " << i->getId() << endl;
            cout << "User      : " << i->getUser() << endl;
            cout << "Senha     : " << i->getSenha() << endl;
            cout << "\n";
            break;
        }
    }
}

int Administrador :: verificaUser(string user, string senha){
    // Realiza a validação de acesso comparando o padrao de entrada das categorias de funcionários, identificação e senha.
    string id;
    string userSenha;
    if(user[0] == 'v' && user[1] == 'e' && user[2] == 'n' && user[3] == 'd' && user[4] == 'e'){
        for(list<Vendedor>::iterator i = this->vendedores.begin(); i!= this->vendedores.end(); i++){
            id = i->getUser();
            if(user[5] == id[5] && user[6] == id[6] && user[7] == id[7] && user[8] == id[8]){
                userSenha = i->getSenha();                  
                if(senha == userSenha){                    
                    return 1;
                }
                else{
                    cout<<"Senha invalida"<<endl;
                    return 0;
                }
            }
        }
    }

    else if(user[0] == 'm' && user[1] == 'e' && user[2] == 'c' && user[3] == 'a' && user[4] == 'n'){
        string id;
        string userSenha;
        for(list<Mecanico> :: iterator i = this->mecanicos.begin(); i!= this->mecanicos.end(); i++){
            id = i->getUser();
            if(user[5] == id[5] && user[6] == id[6] && user[7] == id[7] && user[8] == id[8]){
                userSenha = i->getSenha();
                if(senha == userSenha){
                    return 2;
                }
                else{
                    cout<<"Senha invalida"<<endl;
                    return 0;
                }
                
            }
        }
    }
    else if(user[0] == 'a' && user[1] == 'd' && user[2] == 'm' && user[3] == 'i' && user[4] == 'n'){
        if(senha == "admin"){
            return 3; 
        }
        else{
            cout<<"Senha invalida"<<endl;
            return 0;
        }
    }
    else{
        cout<<"Usuario invalido"<<endl;
        return 0;
    }
    
}

