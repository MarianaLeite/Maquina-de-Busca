#include<iostream>
#include<string>
#include"Arquivo.h"
using namespace std;

int ocor(string palavra,string arquivo){ //retorna a quantidade de ocorrencias da palavra no arquivo
    Arquivo x;
    x.leArquivo(arquivo);
    return x.ocorrencias(palavra);
}


void imprimeArquivo(Arquivo* _print){//teste
    for(int i=0;i < _print->tamanho();i++){
    cout<<_print->palavra(i)<<" - "<< _print->ocorrencias(_print->palavra(i))<<endl;
    }
}
int main(){
    Arquivo colecao;
    colecao.leArquivo("arquivo_teste.txt");
    colecao.leArquivo("teste.txt");

    imprimeArquivo(&colecao);
    string palavras[colecao.tamanho()];    
    string arquivos[2];
    arquivos[0]= "arquivo_teste.txt";
    arquivos[1]= "teste.txt";
    float peso[colecao.tamanho()];
    for (int i=0;i<colecao.tamanho();i++){
        palavras[i] = colecao.palavra(i);
    }
    int indiceInvertido[colecao.tamanho()][2];
    for (int palavra = 0;palavra < colecao.tamanho() ; palavra++){
        //cout<<palavras[palavra]<<" ";
        for (int arquivo = 0;arquivo < 2; arquivo++){   
            cout<<ocor(palavras[palavra],arquivos[arquivo])<<" ";
            indiceInvertido[palavra][arquivo] = ocor(palavras[palavra],arquivos[arquivo]);
            if(indiceInvertido[palavra][arquivo]>0){
                alguma coisa ++;
            }
        }
        cout<<endl;
    }
    
}
