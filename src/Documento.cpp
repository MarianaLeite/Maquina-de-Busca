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

int Documento::frequencia(const Palavra &x) {
    return frequencia_[x];
}

bool Documento::operator==(const Documento &x){
    return (this->nome_ == x.nome_);
}

TEST_CASE("Inserir palavra no documento"){
    
}