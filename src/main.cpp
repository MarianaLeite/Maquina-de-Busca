#include<iostream>
#include<string>
#include"Documento.h"
#include "Palavra.h"
using namespace std;

int main(){
    Documento colecao;
    colecao.leArquivo("arquivo_teste.txt");
    colecao.leArquivo("teste.txt");
    Palavras a (colecao);
    a.Insere_palavras(colecao);
    a.Indice_invertido();

}
    
