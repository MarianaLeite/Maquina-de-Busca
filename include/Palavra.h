#ifndef PALAVRA_H
#define PALAVRA_H

#include <string>

using namespace std;

/**
 * @brief 
 * 
 */
class Palavra{

    private:

    /**
     * @brief Conjunto de caracteres não especiais de representação de Palavra
     * 
     */
    string palavra_;

    /**
     * 
     * @brief Método que converte caracteres especiais
     * 
     * 
     * @param x String com caracteres especiais
     */
    void converter(const string &x);
    
    public:

    /**
     * @brief Construtor do objeto Palavra
     * 
     * @param x String com caracteres expeciais
     */
    Palavra(const string &x);

    /**
     * @brief Método que retorna o conjunto de caracteres de representação de Palavra
     * 
     * @return string
     */
    string paraString();

    /**
     * @brief Método que verifica a igualdade entre o objeto corrente e {@x}
     * 
     * @param x Objeto Palavra
     * @return true Se os objetos são iguais
     * @return false Se os objetos são diferentes
     */
    bool operator==(const Palavra &x);

    /**
     * @brief Método que atribui {@x} ao objeto corrente 
     * 
     * @param x Objeto Palavra
     */
    void operator=(const Palavra &x);
};

#endif