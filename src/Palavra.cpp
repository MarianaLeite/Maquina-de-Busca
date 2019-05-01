#include "../include/Palavra.h"
#include "../include/Documento.h"
# include <string>
#include <iostream>
using namespace std;

Palavras::Palavras(Documento colecao){

    this -> qnt_palavras_ = colecao.tamanho();
    this -> palavras_ = new string[qnt_palavras_];
    this -> ocorrencia = new int[1];
    this -> indice_invertido_ = new string[qnt_palavras_];
    
}

int Palavras::Ocorrencia(string palavra, string nome_arquivo){
    Documento x;
    x.leArquivo(nome_arquivo);
    return x.ocorrencias(palavra);
    
}
void Palavras::Insere_palavras(Documento colecao){

    for(int i = 0; i < qnt_palavras_; i++){
        palavras_[i] = colecao.palavra(i);
        cout<<palavras_[i]<<" - "<<colecao.ocorrencias(palavras_[i])<<endl;
    }

}
void Palavras::Indice_invertido(){ 
    string arquivos[2];
    arquivos[0] = "arquivo_teste.txt";
    arquivos[1] = "teste.txt";
    if (qnt_palavras_ != 0){
        for (int palavra = 0; palavra < this -> qnt_palavras_ ; palavra++){
        //cout<<palavras[palavra]<<" ";
        for (int arquivo = 0; arquivo < 2; arquivo++){   
            cout<<this -> Ocorrencia(palavras_[palavra], arquivos[arquivo])<<" ";
            this -> indice_invertido_[palavra][arquivo] = this -> Ocorrencia(palavras_[palavra],arquivos[arquivo]);
           /* if(indiceInvertido[palavra][arquivo]>0){
                alguma coisa ++;
            }*/
        }
        cout<<endl;
    } 
    } 
}

