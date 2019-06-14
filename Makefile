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

src/biblioteca.o: src/biblioteca.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

src/documento.o: src/documento.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

src/palavra.o: src/palavra.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

test/bin/palavra_test: src/palavra.o test/palavra_test.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

test/bin/documento_test: src/documento.o src/palavra.o test/documento_test.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

test/bin/biblioteca_test: src/biblioteca.o src/palavra.o src/documento.o test/biblioteca_test.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

main: src/palavra.o src/documento.o src/biblioteca.o src/main.cpp  
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@