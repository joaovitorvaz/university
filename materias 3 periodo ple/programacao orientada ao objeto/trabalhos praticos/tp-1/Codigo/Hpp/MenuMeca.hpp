#ifndef MENUMECA_HPP
#define MENUMECA_HPP

#include<iostream>
#include<list>
#include"./Mecanico.hpp"
#include"./Vendedor.hpp"
#include"./Item.hpp"
#include"./MaodeObra.hpp"
#include"./Servico.hpp"
#include"./Ordem.hpp"

using namespace std;


void menuMeca(Mecanico* mecani);
void viewOrdems(Mecanico* mecani, Vendedor vend);
void adicionaServico(Mecanico* mecani, Vendedor vendi);
void cadastraServico(Mecanico* mecani, Vendedor vendi);

#endif