all: Biblioteca

Biblioteca: Biblioteca.o 
	g++ -o all Biblioteca.o Documento.o Palavra.o main.o -L/home/john/Documentos/Maquina-de-Busca/include

Biblioteca.o: 
	g++ -c Biblioteca.cpp Documento.cpp  Palavra.cpp main.cpp -I/../include 


clean:
	-rm -f *.o all *~