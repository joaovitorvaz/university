all: ./O/Pessoa.o ./O/Administrador.o ./O/Vendedor.o ./O/Carro.o ./O/Cliente.o ./O/Funcionario.o ./O/Item.o ./O/MaoDeObra.o ./O/Mecanico.o ./O/Ordem.o ./O/Servico.o ./O/MenuAdmin.o ./O/MenuMeca.o ./O/MenuVend.o main.cpp
	g++ -o ./O/main main.cpp ./O/Pessoa.o ./O/Administrador.o ./O/Vendedor.o ./O/Carro.o ./O/Cliente.o ./O/Funcionario.o ./O/Item.o ./O/MaoDeObra.o ./O/Mecanico.o ./O/Ordem.o ./O/Servico.o ./O/MenuAdmin.o ./O/MenuMeca.o ./O/MenuVend.o -Wall

./O/Pessoa.o: ./Cpp/Pessoa.cpp
	g++ -o ./O/Pessoa.o -c ./Cpp/Pessoa.cpp

./O/Ordem.o: ./Cpp/Ordem.cpp
	g++ -o ./O/Ordem.o -c ./Cpp/Ordem.cpp

./O/Administrador.o: ./Cpp/Administrador.cpp
	g++ -o ./O/Administrador.o -c ./Cpp/Administrador.cpp

./O/Vendedor.o: ./Cpp/Vendedor.cpp
	g++ -o ./O/Vendedor.o -c ./Cpp/Vendedor.cpp

./O/Carro.o: ./Cpp/Carro.cpp
	g++ -o ./O/Carro.o -c ./Cpp/Carro.cpp

./O/Cliente.o: ./Cpp/Cliente.cpp
	g++ -o ./O/Cliente.o -c ./Cpp/Cliente.cpp

./O/Funcionario.o: ./Cpp/Funcionario.cpp
	g++ -o ./O/Funcionario.o -c ./Cpp/Funcionario.cpp

./O/Item.o: ./Cpp/Item.cpp
	g++ -o ./O/Item.o -c ./Cpp/Item.cpp

./O/MaoDeObra.o: ./Cpp/MaoDeObra.cpp
	g++ -o ./O/MaoDeObra.o -c ./Cpp/MaoDeObra.cpp

./O/Mecanico.o: ./Cpp/Mecanico.cpp
	g++ -o ./O/Mecanico.o -c ./Cpp/Mecanico.cpp

./O/Servico.o: ./Cpp/Servico.cpp
	g++ -o ./O/Servico.o -c ./Cpp/Servico.cpp

./O/MenuAdmin.o: ./Cpp/MenuAdmin.cpp
	g++ -o ./O/MenuAdmin.o -c ./Cpp/MenuAdmin.cpp

./O/MenuMeca.o: ./Cpp/MenuMeca.cpp
	g++ -o ./O/MenuMeca.o -c ./Cpp/MenuMeca.cpp

./O/MenuVend.o: ./Cpp/MenuVend.cpp
	g++ -o ./O/MenuVend.o -c ./Cpp/MenuVend.cpp

clean:
	rm -f ./O/*.o ./O/main

run:
	./O/main
