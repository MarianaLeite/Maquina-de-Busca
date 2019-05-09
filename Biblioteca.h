#ifndef DOCUMENTO_H
#define DOCUMENTO_H
#include <string>
#include <vector>
using namespace std;
class VetorBuscaRn;
/*Tipo abstrato de dados destinado a representar uma biblioteca de busca, armazenando
  todas as palavras contidas e o numero de ocorrencias de cada uma normalizando as palavras em 
  letras minusculas e removendo pontuacao; todos os arquivos e sua quantidade; e capaz de representar
  um arquivo como um vetor no espaco Rn composto pelas palavras contidas na biblioteca.
 */

    struct Palavra;
    struct Documento;

    class Biblioteca{
    public:
    
    //Cria biblioteca com base num vetor de nomes dos arquivos
    Biblioteca();

    //retorna quantidade de palavras na colecao.
    int numPalavras()const;

    //retorna quantidade de documentos na colecao.
    int numDocumentos()const;

    //retorna a representacao vetorial de arquivo dentro da biblioteca
    void vetorial(string arquivo);

    void leArquivo(string nomeArquivo);

    ~Biblioteca();
    
    private:
    // calcula o quao importante uma palavra é na biblioteca para representar um qrquivo
    void calculaPeso();

    //insere uma palavra no vocabulario da biblioteca relacionada ao ultimo arquivo lido
    //precondicao: a biblioteca tem pelo menos um arquivo
    void inserirPalavra(string palavra);

    void inserirDocumento(string nomeDocumento);

    

    //Insere documento na biblioteca
    bool palavraPertence (string palavra)const;
    bool documentoPertence (string documento)const;
    int ocorrenciaNoDoc (string palavra, string documento)const;
    int indiceDaPalavra (string palavra)const;
    int indiceDoDocumento (string documento)const;

    vector <Palavra> palavras_;
    vector <Documento> documentos_;
    vector <vector<int>> indiceInvertido_;


};
#endif