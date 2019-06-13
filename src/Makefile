CXX:= g++
CXX_FLAGS := -Wall -Wextra -std=c++14 -ggdb

all: main biblioteca documento palavra ../test/biblioteca_test ../test/documento_test ../test/palavra_test

clean:
	rm -rf * .vscode/ipch

run: main
	clear
	.main

biblioteca.o: biblioteca.cpp biblioteca.o documento.cpp documento.o palavra.cpp palavra.o
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

documento.o: documento.cpp documento.o palavra.cpp palavra.o
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

palavra.o: palavra.cpp palavra.o
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

main: main.cpp biblioteca.o documento.o palavra.o
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

../test/biblioteca_test: ../src/biblioteca.o ../src/documento.o ../src/palavra.o
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

../test/documento_test: ../src/documento.o ../src/palavra.o
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

../test/palavra_test: ../src/palavra.o
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@