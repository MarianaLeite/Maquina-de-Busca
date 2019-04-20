/* Esse módulo irá receber o nome do arquivo e irá manipular as strings presentes nesse arquivo tratando-os 
de forma a estarem na forma que nossa máquina de busca consiga manipular os dados ali presentes. 
*/
#ifndef LEITURA
#define LEITURA_H

#include <string>


using std::string;
using std::to_string;

class arquivo {
    private: 
        string palavras_ , arquivo_;
        int tamanho_;
    
    public: 
       /*Lê um arquivo de texto e armezana os dados em uma string 
       e trata os dados do arquivo e cria um novo arquivo com os dados tratados.*/
       arquivo(const string nome_arquivo);

     /*  //retorna quantas palavras tem no arquivo.
       int quantidade_palavras();

       //armazenar as palavras em um vetor
       void palavra(string arquivo_);

*/
};

#endif  // LEITURA_H