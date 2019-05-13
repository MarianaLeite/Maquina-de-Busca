#ifndef DOCUMENTO_H
#define DOCUMENTO_H

#include <map>
#include <string>
#include "Palavra.h"

using namespace std;

/**
 * @brief Classe de implementação do objeto Documento
 * 
 */
class Documento{
    
    private:

    /**
     * @brief 
     * 
     */
    string nome_;

    /**
     * @brief Conjunto de chave valor em que chave é a palavra existente no documento
     * e, valor, o termo frequencia desta no documento
     * 
     */
    map<Palavra,int> frequencia_;
    
    public:

    /**
     * @brief Construtor do objeto Documento
     * 
     * @param x Nome do documento
     */
    Documento(const string &x);

    /**
     * @brief Método que insere {@x} no conjunto de palavras do documento
     * 
     * @param x 
     */
    void inserirPalavra(const string &x);

    /**
     * @brief Método que retorna a frequência do termo {@x} no documento
     * 
     * @param x 
     * @return int Quantidade de vezes que {@x} aparece no documento
     */
    int frequencia(const Palavra &x);

    /**
     * @brief 
     * 
     * @param x 
     * @return true 
     * @return false 
     */
    bool operator==(const Documento &x);

    /**
     * @brief 
     * 
     * @param x 
     */
    void operator=(const Documento &x);

};

#endif