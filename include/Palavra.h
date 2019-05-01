#ifndef PALAVRA_H
#define PALAVRA_H
#include "Documento.h"
#include "Palavra.h"
#include <string>
using namespace std;

class Palavras{
    public: 
    // cria um vetor de elementos que recebe as palavras lidos da coleção de documentos
        Palavras(Documento colecao);

    // Insere as palavras da colecao no vetor palavras
        void Insere_palavras(Documento colecao);
    
    // Retorna a quantidade de vezes que a palavra aparece no documento 
        int Ocorrencia(string palavra, string nome_arquivo);

    //índice invertido: Uma matriz cujo índice das linhas são as palavras e as colunas indicam a presença no documento 
       void Indice_invertido();
    private:
        int qnt_palavras_;
        string* palavras_;
        int* ocorrencia;
        string* indice_invertido_;
};


#endif