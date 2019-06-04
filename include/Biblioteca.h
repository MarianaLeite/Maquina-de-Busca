#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "../include/Documento.h"
#include "../include/Palavra.h"

using namespace std;

/**
 * @brief Classe de implementa��o do objeto Biblioteca
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
     * @brief Para cada palavra, armazena a lista de frequ�ncia dessa por
     * documento
     * 
     */
    map<Palavra,vector<int>> indiceInvertido_;
    
    /**
     * @brief M�todo que insere o documento de nome {@x} ao conjunto de documentos
     * da biblioteca
     * 
     * @param x Nome e extens�o do documento
     */
    void inserirDocumento(const string &x);

    /**
     * @brief M�todo que retorna a import�ncia da palavra {@x} na biblioteca
     * dada pela equa��o idf
     * 
     * @param x Objeto Palavra
     * @return double idf
     */
    double frequenciaInversa(const Palavra &x);

    /**
     * @brief M�todo que retorna a coordenada de {@x} no eixo {@y} dada pela
     * equa��o tf*idf
     * 
     * @param x Objeto Documento
     * @param y Objeto Palavra
     * @return double Coordenada
     */
    double coordenada( Documento &x, const Palavra &y);

    /**
     * @brief M�todo que retorna, numa escala de 0 at� 1, a similaridade entre
     * o documento {@x} e a busca, dada por cosseno entre os vetores de representa��o
     * dos par�metros
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
     * @param x Diret�rio completo da biblioteca
     */
    Biblioteca(const string &x);
    
    /**
     * @brief Construtor do objeto Biblioteca, constoi uma biblioteca vazia
     * 
     */
    Biblioteca();
    
    /**
     * @brief M�todo que retorna o ranking de documentos relacionados � busca
     * 
     * @param x String com todas as palavras da busca
     * 
     * @return Vetor ordenado com os arquivos que correspondem a busca
     */
    vector<string>busca(const string);

    friend class Biblioteca_teste;
};

#endif