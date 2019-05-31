#ifndef DOCUMENTO_H
#define DOCUMENTO_H

#include <map>
#include <vector>
#include <string>
#include "../include/Palavra.h"

using namespace std;

/**
 * @brief Classe de implementação do objeto Documento
 * 
 */
class Documento{
    
    private:

    /**
     * @brief Nome do documento e sua extensão
     * 
     */
    string nome_;

    /**
     * @brief Conjunto de chave valor em que chave é a palavra existente no documento
     * e, valor, o termo frequencia desta no documento
     * 
     */
    map<Palavra,int> frequencia_;
    
    /**
     * @brief Coordenadas do documento na biblioteca, onde cada posição i do vetor
     * é sua coordenada na palavra i 
     * 
     */
    map<Palavra,double> coordenadas_;
    
    public:

    /**
     * @brief Construtor do objeto Documento
     * 
     * @param x Nome do documento e sua extensão
     */
    Documento(const string &x);

    /**
     * @brief Método que armazena {@x} no conjunto de palavras do documento
     * 
     * @param x Objeto Palavra
     */
    void inserirPalavra(const Palavra &x);

    /**
     * @brief Método que retorna a frequência do termo {@x} no documento
     * 
     * @param x Palavra a ser buscada no documento
     * @return int Quantidade de vezes que {@x} aparece no documento
     */
    int frequencia(const Palavra &x);
    
    /**
     * @brief Método que retorna um vector com todas as palavras do arquivo sem repetição
     * 
     * 
     * @return vector<Palavra> todas as palavras do documento
     */    
    set<Palavra> palavras() const;

    /**
     * @brief Método que retorna o nome do documento
     * 
     * 
     * @return string nome do documento
     */
    string nome() const;
    
    /**
     * @brief Verifica se o nome do documento {@x} é igual ao nome do documento corrente,
     * o que determina que se trata do mesmo documento
     * 
     * @param x Objeto Documento
     * @return true Se o nome dos documentos são iguais
     * @return false Se o nome dos documentos são diferentes
     */
    bool operator==(const Documento &x)const;
};

#endif