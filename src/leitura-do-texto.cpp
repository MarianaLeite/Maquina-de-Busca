



#include "../include/leitura.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
using std::string;

Documento::Documento(const string nome_arquivo){
    
    ifstream in (nome_arquivo);
    if(in.is_open()){
        //pega a quantidade de palavras
        while (in.eof() == false){
            getline (in,documento_);
            Tratar_texto(documento_);
        }
    }
    in.close();
    char a = -96;
    cout << a;

}

void Documento::Tratar_texto(string documento_){
    for (int i = 0; i < documento_.length(); i++){
        documento_[i] = tolower(documento_[i]);                
        if (documento_[i] == -29 && documento_[i+1] == -95){
            documento_[i]= 'a';
            documento_[i+1] = ' ';
        }
    }
    cout << endl <<documento_;
}