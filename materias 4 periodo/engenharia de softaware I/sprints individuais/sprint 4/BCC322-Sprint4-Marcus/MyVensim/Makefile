all_unit: ./test/unit/main.cpp mem_usage.dll unit_tests.dll unit_model.dll unit_flow.dll unit_system.dll modelImpl.dll flowImpl.dll systemImpl.dll model.dll flow.dll system.dll 
	g++ ./test/unit/main.cpp -o ./bin/unit_tests ./bin/mem_usage.dll ./bin/unit_tests.dll ./bin/modelImpl.dll ./bin/flowImpl.dll ./bin/systemImpl.dll ./bin/unit_model.dll ./bin/unit_flow.dll ./bin/unit_system.dll

all_funcional: ./test/funcional/main.cpp funcional_tests.dll model.dll flow.dll system.dll modelImpl.dll flowImpl.dll systemImpl.dll 
	g++ ./test/funcional/main.cpp -o ./bin/funcional_tests ./bin/modelImpl.dll ./bin/flowImpl.dll ./bin/systemImpl.dll ./bin/funcional_tests.dll

system.dll: ./src/system.h 
	g++ -Wall -g -c ./src/system.h -o ./bin/system.dll

systemImpl.dll: ./src/systemImpl.cpp ./src/systemImpl.h system.dll
	g++ -Wall -g -c ./src/systemImpl.cpp -o ./bin/systemImpl.dll

flow.dll: ./src/flow.h system.dll
	g++ -Wall -g -c ./src/flow.h -o ./bin/flow.dll

flowImpl.dll: ./src/flowImpl.cpp ./src/flowImpl.h system.dll
	g++ -Wall -g -c ./src/flowImpl.cpp -o ./bin/flowImpl.dll

model.dll: ./src/model.h flow.dll system.dll
	g++ -Wall -g -c ./src/model.h -o ./bin/model.dll

modelImpl.dll: ./src/modelImpl.cpp ./src/modelImpl.h model.dll flow.dll system.dll
	g++ -Wall -g -c ./src/modelImpl.cpp -o ./bin/modelImpl.dll

funcional_tests.dll: ./test/funcional/funcional_tests.cpp ./test/funcional/funcional_tests.h model.dll flow.dll system.dll
	g++ -Wall -g -c ./test/funcional/funcional_tests.cpp -o ./bin/funcional_tests.dll

mem_usage.dll: ./test/unit/utils/mem_usage.cpp ./test/unit/utils/mem_usage.h
	g++ -Wall -g -c ./test/unit/utils/mem_usage.cpp -o ./bin/mem_usage.dll

unit_system.dll: ./test/unit/unit_system.cpp ./test/unit/unit_system.h  mem_usage.dll system.dll
	g++ -Wall -g -c ./test/unit/unit_system.cpp -o ./bin/unit_system.dll

unit_flow.dll: ./test/unit/unit_flow.cpp ./test/unit/unit_flow.h  mem_usage.dll flow.dll system.dll
	g++ -Wall -g -c ./test/unit/unit_flow.cpp -o ./bin/unit_flow.dll

unit_model.dll: ./test/unit/unit_model.cpp ./test/unit/unit_model.h  mem_usage.dll unit_flow.dll model.dll flow.dll system.dll
	g++ -Wall -g -c ./test/unit/unit_model.cpp -o ./bin/unit_model.dll

unit_tests.dll: ./test/unit/unit_tests.cpp ./test/unit/unit_tests.h system.dll
	g++ -Wall -g -c ./test/unit/unit_tests.cpp -o ./bin/unit_tests.dll

run_unit:
	./bin/unit_tests

run_funcional:
	./bin/funcional_tests

clean:
	rm -f ./bin/*
