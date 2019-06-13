#include "dirent.h"
#include <iostream>
#include <string>
#include "../include/documento.h"
#include "../include/palavra.h"
#include "../include/biblioteca.h"
#include <fstream>
#include <vector>


using namespace std;

int main(){
    Biblioteca biblioteca ("../test/diretorio");
    vector<string> documentos = biblioteca.busca("A");
    cout << endl <<"____________________________________________________________________________" << endl;
    cout << endl <<"Ranking dos Documentos:" << endl;
    cout << endl << "A busca de A na Biblioteca" << endl;
    for (int i = 0; i < documentos.size(); i++){
        Documento documento = documentos[i];
        Palavra palavra("A");
        cout << endl << i + 1 << ") " <<documentos[i];
        cout <<"( " << documento.frequencia(palavra) << ")" << endl;
    }
    cout << endl <<"____________________________________________________________________________" << endl;
    cout << endl << "Para casos mais complexos iremos utilizar um paragrafo de um texto como exemplo:" << endl;
    Biblioteca bibliotecaComplexa ("../test/diretorio/textos complexos");
    vector<string> documentosComplexos = bibliotecaComplexa.busca("o");
    cout << endl <<"Ranking dos Documentos:" << endl;
    for (int i = 0; i < documentosComplexos.size(); i++){
        Documento documentoComplexo = documentosComplexos[i];
        Palavra palavraComplexa("o");
        cout << endl << i + 1 << ") " <<documentosComplexos[i];
        cout <<"( " << documentoComplexo.frequencia(palavraComplexa) << ")" << endl;
    }
    cout << endl <<"____________________________________________________________________________" << endl;
    Documento doc ("../test/diretorio/textos complexos/exemplo0.txt");
    for (int i = 0; i < doc.palavras().size(); i++){
        vector <Palavra> x = doc.palavras();
        cout  << x[i].paraString() << endl;
    }
    cout << doc.palavras().size();

}
    