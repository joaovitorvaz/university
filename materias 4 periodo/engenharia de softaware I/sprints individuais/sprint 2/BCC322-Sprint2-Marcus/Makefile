all_unit: ./test/unit/main.cpp unit_tests.dll model.dll flow.dll system.dll
	g++ ./test/unit/main.cpp -o ./bin/unit_tests ./bin/unit_tests.dll

all_funcional: ./test/funcional/main.cpp funcional_tests.dll model.dll flow.dll system.dll 
	g++ ./test/funcional/main.cpp -o ./bin/funcional_tests ./bin/funcional_tests.dll

system.dll: ./src/system.h
	g++ -Wall -g -c ./src/system.h -o ./bin/system.dll

flow.dll: ./src/flow.h system.dll
	g++ -Wall -g -c ./src/flow.h -o ./bin/flow.dll

model.dll: ./src/model.h flow.dll system.dll
	g++ -Wall -g -c ./src/model.h -o ./bin/model.dll

unit_tests.dll: ./test/unit/unit_tests.cpp ./test/unit/unit_tests.h model.dll flow.dll system.dll
	g++ -Wall -g -c ./test/unit/unit_tests.cpp -o ./bin/unit_tests.dll

funcional_tests.dll: ./test/funcional/funcional_tests.cpp ./test/funcional/funcional_tests.h model.dll flow.dll system.dll
	g++ -Wall -g -c ./test/funcional/funcional_tests.cpp -o ./bin/funcional_tests.dll

run_unit:
	./bin/unit_tests

run_funcional:
	./bin/funcional_tests

clean:
	rm -f ./bin/*
