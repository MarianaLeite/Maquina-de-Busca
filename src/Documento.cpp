#include "../include/Documento.h"
#include <string>

Documento::Documento(const string &x){

}

void Documento::inserirPalavra(const string &x){
    
}

int Documento::frequencia(const Palavra& x) {
    return frequencia_[x];
}
vector<Palavra> Documento::palavras() const{

}

string Documento::nome()const{
    return this->nome_;
}

bool Documento::operator==(const Documento &x)const{

}
bool Documento::operator<(const Documento &x)const{
    return (this->nome_<x.nome_);
}