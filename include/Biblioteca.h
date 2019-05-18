#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <set>
#include "Documento.h"
#include "Palavra.h"

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
    set<Documento> documentos_;

    /**
     * @brief Para cada palavra, armazena a lista de frequência dessa por
     * documento
     * 
     */
    map<Palavra,vector<int>> indiceInvertido_;

    /**
     * @brief Lista ordenada de documentos similares com a busca
     * 
     */
    set<double,const Documento&> ranking_;
    
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
    double coordenada(const Documento &x, const Palavra &y);

    /**
     * @brief Método que retorna, numa escala de 0 até 1, a similaridade entre
     * o documento {@x} e a busca, dada por cosseno entre os vetores de representação
     * dos parâmetros
     * 
     * @param x Objeto Documento
     * @param busca Objeto Documento
     * @return double Similaridade
     */
    double similaridade(const Documento &x, const Documento busca);

    /**
     * @brief Método que insere os documentos no ranking de similaridade com
     * a busca
     * 
     */
    void ranquear();

    public:

    /**
     * @brief Construtor do objeto Biblioteca
     * 
     * @param x Diretório completo da biblioteca
     */
    Biblioteca(const string &x);

};

#endif