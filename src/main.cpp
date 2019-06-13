#include "dirent.h"
#include <iostream>
#include <string>
#include "../include/Documento.h"
#include "../include/Palavra.h"
#include "../include/Biblioteca.h"
#include <fstream>
#include <vector>


using namespace std;

int main(){
    Biblioteca biblioteca ("../test/diretorio");
    vector<string> documentos = biblioteca.busca("A");
    cout << endl <<"Ranking dos Documentos:" << endl;
    cout << "A busca de A na Biblioteca" << endl;
    for (int i = 0; i < documentos.size(); i++){
        Documento documento = documentos[i];
        Palavra palavra("A");
        cout << endl << i + 1 << ") " <<documentos[i];
        cout <<"( " << documento.frequencia(palavra) << ")" << endl;
    }
    cout << endl;
    cout << "Para casos mais complexos iremos utilizar um par�grafo de um texto como exemplo:" << endl;
    Biblioteca bibliotecaComplexa ("../test/diretorio/textos complexos");
    vector<string> documentosComplexos = bibliotecaComplexa.busca("independentemente");
    cout << endl <<"Ranking dos Documentos:" << endl;
    for (int i = 0; i < documentosComplexos.size(); i++){
        Documento documentoComplexo = documentosComplexos[i];
        Palavra palavraComplexa("independentemente");
        cout << endl << i + 1 << ") " <<documentosComplexos[i];
        cout <<"( " << documentoComplexo.frequencia(palavraComplexa) << ")" << endl;
    }
}
    