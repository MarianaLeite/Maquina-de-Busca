#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <set>
#include "Documento.h"
#include "Palavra.h"

using namespace std;

/**
 * @brief 
 * 
 */
class Biblioteca{
    
    private:

    /**
     * @brief 
     * 
     */
    set<Documento> documentos_;

    /**
     * @brief 
     * 
     */
    map<Palavra,set<const Documento&>> indiceInvertido_;

    /**
     * @brief Método que insere o documento de nome {@x} ao conjunto de documentos
     * da biblioteca
     * 
     * @param x 
     */
    void inserirDocumento(const string &x);

    /**
     * @brief Método que retorna a importância da palavra {@x} na biblioteca
     * 
     * @param x 
     * @return double 
     */
    double frequenciaInversa(const Palavra &x);

    /**
     * @brief Método que retorna a coordenada de {@x} no eixo {@y}
     * 
     * @param x 
     * @param y 
     * @return double 
     */
    double coordenada(const Documento &x, const Palavra &y);

    //TODO: Métodos para calculo de similaridade

    //TODO: Método para organização da lista de documentos de forma ranqueada

    public:

    /**
     * @brief Construtor do objeto Biblioteca
     * 
     * @param x Diretório completo da biblioteca
     */
    Biblioteca(const string &x);

};

#endif