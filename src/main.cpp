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
    Biblioteca biblioteca ("test/diretorio");
    vector<string> documentos = biblioteca.busca("A");
    cout << endl <<"____________________________________________________________________________" << endl;
    cout << endl <<"Ranking dos Documentos:" << endl;
    cout << endl << "A busca de A na Biblioteca" << endl;
    for (int i = 0; i < documentos.size(); i++){
        Documento documento = documentos[i];
        cout << endl << i + 1 << ") " <<documentos[i];
    }
    cout << endl <<"____________________________________________________________________________" << endl;
    cout << endl << "Para casos mais complexos iremos utilizar um paragrafo de um texto como exemplo:" << endl;
    Biblioteca bibliotecaComplexa ("documentosExemplo");
    vector<string> documentosComplexos = bibliotecaComplexa.busca("pensando");
    cout << endl <<"Ranking dos Documentos:" << endl;
    for (int i = 0; i < documentosComplexos.size(); i++){
        Documento documentoComplexo = documentosComplexos[i];
        cout << endl << i + 1 << ") " <<documentosComplexos[i];
    }
    cout << endl <<"____________________________________________________________________________" << endl;
    

}
    