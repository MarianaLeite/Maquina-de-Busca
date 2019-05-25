#ifndef PALAVRA_H
#define PALAVRA_H

#include <string>

using namespace std;

/**
 * @brief Classe de implementação do objeto Palavra
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
     * @brief Método que converte caracteres especiais para não-especiais
     * 
     * @param x String com caracteres especiais
     */
    string converter(const string &x);

    /**
     * @brief Método que remove o acento de {@x}
     * 
     * @param x Caracter acentuado
     * @return char Caracter sem acento
     */
    char removerAcento(char x);
    
    public:

    /**
     * @brief Construtor do objeto Palavra
     * 
     * @param x String a ser convertida para caracteres não-especiais
     */
    Palavra(string x);

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

    /**
     * @brief Método que verifica se o objeto corrente é menor que {@x}
     * 
     * @param x Objeto Palavra
     * @return true Se o objeto corrente é menor
     * @return false Se o objeto corrente é maior
     */
    bool operator<(const Palavra &x);
};

#endif