#ifndef DOCUMENTO_H
#define DOCUMENTO_H

#include <map>
#include <vector>
#include <string>
#include "../include/Palavra.h"

using namespace std;

/**
 * @brief Classe de implementa��o do objeto Documento
 * 
 */
class Documento{
    
    private:

    double similaridade_;

    /**
     * @brief Nome do documento e sua extens�o
     * 
     */
    string nome_;

    /**
     * @brief Conjunto de chave valor em que chave � a palavra existente no documento
     * e, valor, o termo frequencia desta no documento
     * 
     */
    map<Palavra,int> frequencia_;
    
    /**
     * @brief Coordenadas do documento na biblioteca, onde cada posi��o i do vetor
     * � sua coordenada na palavra i 
     * 
     */
    map<Palavra,double> coordenadas_;

    /**
     * @brief M�todo que armazena {@x} no conjunto de palavras do documento
     * 
     * @param x Objeto Palavra
     */
    void inserirPalavra(const Palavra &x);

    /**
     * @brief M�todo que abre documento .txt de nome {@x} e converte em objeto 
     * Documento
     * 
     * @param x Diret�rio e nome do documento e.g.: C:/Jao/Documentos/Jao.txt
     */
    void lerDocumento(string x);

    public:

    /**
     * @brief Construtor do objeto Documento
     * 
     */
    Documento();

    /**
     * @brief Construtor do objeto Documento
     * 
     * @param x Nome do documento e sua extens�o
     */
    Documento(const string &x);

    /**
     * @brief M�todo que retorna a frequ�ncia do termo {@x} no documento
     * 
     * @param x Palavra a ser buscada no documento
     * @return int Quantidade de vezes que {@x} aparece no documento
     */
    int frequencia(const Palavra &x);
    
    /**
     * @brief M�todo que retorna um vector com todas as palavras do arquivo sem repeti��o
     * 
     * 
     * @return vector<Palavra> todas as palavras do documento
     */    
    vector<Palavra> palavras() const;

    /**
     * @brief M�todo que retorna o nome do documento
     * 
     * 
     * @return string nome do documento
     */
    string nome() const;

    /**
     * @brief M�todo que configura documento com o texto {@busca} de busca somente
     * se o documento estiver vazio (ou n�o inicializado com o nome do arquivo 
     * correspondente)
     * 
     * @param busca Texto de busca
     */
    void configurarComoBusca(string busca);

    /**
     * @brief Metodo que salva a similaridade do documento com a busca, parametro utilizado
     * para compara��o de menor
     * 
     * @param valor de importancia
     */
    void similaridade(double x);
    /**
     * @brief Comparador para ordena��o baseada em similaridade
     * 
     * @param Documento a ser comparado
     */
    bool operator <(Documento &d)const;
    
    /**
     * @brief Verifica se o nome do documento {@x} � igual ao nome do documento corrente,
     * o que determina que se trata do mesmo documento
     * 
     * @param x Objeto Documento
     * @return true Se o nome dos documentos s�o iguais
     * @return false Se o nome dos documentos s�o diferentes
     */
    bool operator==(const Documento &x)const;

    friend class Documento_teste;
};

#endif