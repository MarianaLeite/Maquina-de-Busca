#include "../include/Documento.h"
#include <string>
#include <set>

usign namespace std;

Documento::Documento(const string &x){
    this->nome_ = x;
}

void Documento::inserirPalavra(const Palavra &x){
    this->frequencia_[x]++;
}

int Documento::frequencia(const Palavra& x) {
    return frequencia_[x];
}

set<Palavra> Documento::palavras() const {
    set<Palavra> palavras;
    map<Palavra,int>::iterator i;
    
    for(i = frequencia_.begin(); i != frequencia_.end(); ++i){
        palavras.insert(i->first);
    }

    return palavras;
}

string Documento::nome() const {
    return this->nome_;
}