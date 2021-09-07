api: 
	g++ -shared ./src/lib/systemImpl.cpp ./src/lib/flowImpl.cpp ./src/lib/modelImpl.cpp -o ./bin/libapi.so -L./bin -fPIC -Wl,-rpath,bin

test_all_func: api
	g++ ./test/funcional/*.cpp -L./bin -lapi -o ./bin/funcional_tests -Wl,-rpath,bin

test_all_unit: api
	g++ ./test/unit/*.cpp ./test/unit/utils/*.cpp -L./bin -lapi -o ./bin/unit_tests -Wl,-rpath,bin

clean:
	rm -f bin/*.o bin/*.so bin/funcional_tests bin/unit_tests

run_func_test:
	./bin/funcional_tests

run_unit_test:
	./bin/unit_tests