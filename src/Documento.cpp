#include "../include/Documento.h"
#include <dirent.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Documento::Documento(){
    this->nome_.clear();
}

Documento::Documento(const string &x){
    this->nome_ = x;
    this->lerDocumento(x);
}

void Documento::configurarComoBusca(string busca){
    if(this->nome_.empty()){

        string aux;

        for(int i = 0; i <= busca.size(); i++){
            
            if(busca[i] == '\0'){
                Palavra palavra(aux);
                this->inserirPalavra(palavra);
                break;
            } else if(busca[i] == ' '){
                Palavra palavra(aux);
                this->inserirPalavra(palavra);
                aux.clear();
            } else {
                aux += busca[i];
            }
        }
    }
}

void Documento::lerDocumento(string x){
    ifstream doc;
    string aux;
    char caracter;
    
    doc.open(x);
    if (doc.is_open()){
        
        while(1){
            
            doc.get(caracter);
            
            if(doc.eof()){
                Palavra palavra(aux);
                this->inserirPalavra(palavra);
                break;
            } else if(caracter == ' '){
                Palavra palavra(aux);
                this->inserirPalavra(palavra);
                aux.clear();
            } else {
                aux += caracter;
            }
        }
    }
    doc.close();
}

void Documento::inserirPalavra(const Palavra &x){
    this->frequencia_[x]++;
}

int Documento::frequencia(const Palavra& x) {
    return frequencia_[x];
}

vector<Palavra> Documento::palavras() const {
    vector<Palavra> palavras;
    map<const Palavra,int>::const_iterator i;
    
    for(i = frequencia_.begin(); i != frequencia_.end(); ++i){
        palavras.push_back(i->first);
    }

    return palavras;
}

string Documento::nome() const {
    return this->nome_;
}