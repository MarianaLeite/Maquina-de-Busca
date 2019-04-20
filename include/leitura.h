/**
 * @file leitura.h
 * 
 * @authors João Victor de Castro Alves (joaovictorcastroa@gmail.com)
 *          Mariana da Silva Leite (marianaleite785@gmail.com)
 * 
 * @brief Esse módulo irá receber o nome do arquivo e irá manipular as strings presentes nesse arquivo tratando-os 
 *        de forma a estarem na forma que nossa máquina de busca consiga manipular os dados ali presentes
 * 
 * @version 0.1
 * 
 * @date 2019-04-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LEITURA
#define LEITURA_H

#include <string>

using std::string;
using std::to_string;

/**
 * @brief 
 * 
 */
class Documento {
    
    public: 
       
       /**
        * @brief Construtor do objeto Documento
        * 
        * @param nome_documento Nome e extensão do documento e.g. "doc.txt"
        */
       Documento(const string nome_documento);

       /**
        * @brief Verifica se a palavra existe no documento
        * 
        * @param palavra
        * @return true Se a palavra existe no documento
        * @return false Se a palavra não existe no documento
        */
       bool pertence(string palavra);

       void Tratar_texto(string n);

    private: 

        /**
         * @brief 
         * 
         */
        struct Palavra{
            Palavra* anterior;
            string palavra;
            int quantidade;
            Palavra* proxima;
        };

        /**
         * @brief Ponteiro para a lista de palavras contidas no documento
         * 
         */
        Palavra* palavra_;
        
        /**
         * @brief Número de palavras não-repetidas contidas no documento
         * 
         */
        int num_palavras_;
        
        /**
         * @brief Nome e extensão do documento e.g. "doc.txt"
         * 
         */
        string documento_ , n;

        /**
        * @brief Insere a palavra na lista de palavras
        * 
        * @param palavra 
        */
       void inserir(string palavra);

       /**
        * @brief Incrementa a quantidade de uma mesma palavra existente na lista
        * 
        */
       void incrementa(string);

};

#endif  //LEITURA_H