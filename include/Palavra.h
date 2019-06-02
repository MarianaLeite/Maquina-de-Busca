#ifndef PALAVRA_H
#define PALAVRA_H

#include <string>

using namespace std;

/**
 * @brief Classe de implementa��o do objeto Palavra
 * 
 */
class Palavra{

    private:

    /**
     * @brief Conjunto de caracteres n�o especiais de representa��o de Palavra
     * 
     */
    string palavra_;

    /**
     * 
     * @brief M�todo que converte caracteres especiais para n�o-especiais
     * 
     * @param x String com caracteres especiais
     */
    string converter(const string &x);

    /**
     * @brief M�todo que remove o acento de {@x}
     * 
     * @param x Caracter acentuado
     * @return char Caracter sem acento
     */
    char removerAcento(char x);

    friend class Palavra_teste;
    
    public:

    /**
     * @brief Construtor do objeto Palavra
     * 
     * @param x String a ser convertida para caracteres n�o-especiais
     */
    Palavra(string x);

    /**
     * @brief M�todo que retorna o conjunto de caracteres de representa��o de Palavra
     * 
     * @return string
     */
    string paraString() const;

    /**
     * @brief M�todo que verifica a igualdade entre o objeto corrente e {@x}
     * 
     * @param x Objeto Palavra
     * @return true Se os objetos s�o iguais
     * @return false Se os objetos s�o diferentes
     */
    bool operator==(const Palavra &x)const;

    /**
     * @brief M�todo que atribui {@x} ao objeto corrente 
     * 
     * @param x Objeto Palavra
     */
    void operator=(const Palavra &x);

    /**
     * @brief M�todo que verifica se o objeto corrente � menor que {@x}
     * 
     * @param x Objeto Palavra
     * @return true Se o objeto corrente � menor
     * @return false Se o objeto corrente � maior
     */
    bool operator<(const Palavra &x)const;
};

#endif