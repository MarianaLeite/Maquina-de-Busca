CXX		  := g++
# CXX_FLAGS := -Wall -Wextra -std=c++14 -ggdb

all: test/bin/palavra_test test/bin/documento_test test/bin/biblioteca_test main 

clean:
	rm -rf bin/* .vscode/ipch

# run: bin/main
# 	clear
# 	./bin/main

# teste: bin/teste_multiconjunto
# 	clear
# 	./bin/teste_multiconjunto

bin/biblioteca.o: src/biblioteca.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/documento.o: src/documento.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/palavra.o: src/palavra.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

test/bin/palavra_test: bin/palavra.o test/palavra_test.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

test/bin/documento_test: bin/documento.o bin/palavra.o test/documento_test.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

test/bin/biblioteca_test: bin/biblioteca.o bin/palavra.o bin/documento.o test/biblioteca_test.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

main: bin/palavra.o bin/documento.o bin/biblioteca.o src/main.cpp  
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@