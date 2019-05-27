
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/Documento.h"
#include "../include/Palavra.h"
#include <string>

Documento::Documento(const string &x){
    this->nome_ = x;
}

void Documento::inserirPalavra(const Palavra &x){
    this->frequencia_[x]++;
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