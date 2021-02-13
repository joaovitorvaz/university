#include<iostream>
#include<string>

#include "./Hpp/Administrador.hpp"

#include "./Hpp/MenuAdmin.hpp"
#include "./Hpp/MenuMeca.hpp"
#include "./Hpp/MenuVend.hpp"

using namespace std;

void login(Administrador administrador){ 
    Mecanico mecanico;   
    int key, tryAgain;
    string user;
    string senha;
    Vendedor vendedor;
    
    do{
        if(tryAgain == 1){
            do{
                system("clear || cls");
                cout<< "0. Para realizar login.\n";
                cout<< "1. Para sair do programa.\n\n";
                cout<< "Ação desejada: ";
                cin>>tryAgain;
                system("clear || cls"); 
            }while(tryAgain != 0 && tryAgain!= 1);
        }
        if(tryAgain == 1){
            key = 4;
        }
        else{
            tryAgain = 1;

            cout<< "Insira seus dados de acesso:\n";
            cout<< "User  - ";
            cin>>user;    
            cout<< "Senha - ";
            cin>>senha;

            key = administrador.verificaUser(user, senha);

            if(key == 1){
                vendedor = administrador.getVendedorUser(user);
                menuVend(&vendedor);
            }
            else if(key == 2){ 
                mecanico = administrador.getMecanicoUser(user);       
                menuMeca(&mecanico);
            }    
            else if(key == 3){
                menuAdmin(&administrador);
            }

            cout<< "\n";
            key = 0;
        }                

    }while (key < 1 || key > 4);
}

int main(){

    system("clear || cls");

    Administrador administrador("Thommas Shelby", "131.365.486-81", "MG-19.413.439", "Belo Horizonte", "+55 31 99666-5825", "thommasshelby@gmail.com");

    cout<< "\nSistema ativado.\n" <<endl;

    login(administrador);

    cout<< "Sistema desligado.\n" <<endl;

    return 0;
}