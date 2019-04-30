#ifndef arquivo_h
#define arquivo_h
#include "Arquivo.h"
#include <string>
using namespace std;

/*Tipo abstrato de dados destinado a representar um arquivo para mecanismo de busca, armazenando
  todas as palavras contidas e o numero de aocorrencias de cada uma normalizando as palavras em 
  letras minusculas e removendo pontuacao. Letras acentuadas serao descartadas*/



class Arquivo{
    public:
    
    //cria um arquivo vazio
    Arquivo();
    //testa se uma palavra está presente no arquivo.
    bool pertence( string _palavra);
    
    //insere uma ocorrencia da palavra no arquivo.
    void insereElemento(string _insert);
    
    //retorna numero de ocorrencias de _elemento.
    int ocorrencias(string _elemento);
    
    //retorna o elemento correspondente a indice.
    string palavra(int indice);

    //Cria a representacao de um arquivo a partir do seu nome.
    void leArquivo(string nomeArquivo);

    //retorna quantidade de elementos.
    int tamanho();

    ~Arquivo();
    
    private:
    int tamanhoVetor_;
    int tamanho_;
    string* elementos_;
    int* ocorrencias_;




};




#endif