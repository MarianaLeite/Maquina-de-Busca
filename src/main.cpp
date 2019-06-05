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
    for (int i = 0; i < documentos.size(); i++){
        Documento documento = documentos[i];
        Palavra palavra("A");
        cout << endl <<"Ranking dos Documentos:" << endl;
        cout << i + 1 << ") " <<documentos[i] << endl;
        cout <<"A frequencia da palavra A no documento: " << documento.frequencia(palavra) << endl;
        cout << "As palavras presentes no documento: " << endl;
        for(Palavra p : documento.palavras()){
            cout<<p.paraString() <<endl; 
        }
    }

}
    