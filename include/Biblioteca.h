#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "../include/Documento.h"
#include "../include/Palavra.h"

using namespace std;

/**
 * @brief Classe de implementação do objeto Biblioteca
 * 
 */
class Biblioteca{
    
    private:

    /**
     * @brief Lista de documentos existentes na biblioteca
     * 
     */
    vector<Documento> documentos_;

    /**
     * @brief Para cada palavra, armazena a lista de frequência dessa por
     * documento
     * 
     */
    map<Palavra,vector<int>> indiceInvertido_;
    
    /**
     * @brief Método que insere o documento de nome {@x} ao conjunto de documentos
     * da biblioteca
     * 
     * @param x Nome e extensão do documento
     */
    void inserirDocumento(const string &x);

    /**
     * @brief Método que retorna a importância da palavra {@x} na biblioteca
     * dada pela equação idf
     * 
     * @param x Objeto Palavra
     * @return double idf
     */
    double frequenciaInversa(const Palavra &x);

    /**
     * @brief Método que retorna a coordenada de {@x} no eixo {@y} dada pela
     * equação tf*idf
     * 
     * @param x Objeto Documento
     * @param y Objeto Palavra
     * @return double Coordenada
     */
    double coordenada( Documento &x, const Palavra &y);

    /**
     * @brief Método que retorna, numa escala de 0 até 1, a similaridade entre
     * o documento {@x} e a busca, dada por cosseno entre os vetores de representação
     * dos parâmetros
     * 
     * @param x Objeto Documento
     * @param busca Objeto Documento
     * @return double Similaridade
     */
    double similaridade(Documento &x, Documento &busca);

    public:

    /**
     * @brief Construtor do objeto Biblioteca
     * 
     * @param x Diretório completo da biblioteca
     */
    Biblioteca(const string &x);
    
    /**
     * @brief Construtor do objeto Biblioteca, constoi uma biblioteca vazia
     * 
     */
    Biblioteca();
    
    /**
     * @brief Método que retorna o ranking de documentos relacionados à busca
     * 
     * @param x String com todas as palavras da busca
     * 
     * @return Vetor ordenado com os arquivos que correspondem a busca
     */
    vector<string>busca(const string);

    friend class Biblioteca_teste;
};

#endif