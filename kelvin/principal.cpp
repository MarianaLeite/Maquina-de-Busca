#include "Biblioteca.h"
#include<iostream>

int main(){
    Biblioteca colecao;
    colecao.leArquivo("teste.txt");
    colecao.leArquivo("arquivo_teste.txt");
    cout<<"num docs: "<<colecao.numDocumentos()<<endl;
    cout<<"num palavras: "<<colecao.numPalavras()<<endl;
    
}