#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "Biblioteca.h"
using namespace std;
 
struct Palavra
{   
    string textoPalavra;
    int ocorrenciasNaColecao;
    float pesoNaColecao; //idf(inverse document frequence) 
};

struct Documento
{
    string nomeDocumento;
    vector<float> vetorial; //representação vetorial do documento na colecao
};

char* removeAccented( char* str ) {
    char *p = str;
    while ( (*p)!=0 ) {
        const char*
        tr = "AAAAAAECEEEEIIIIDNOOOOOx0UUUUYPsaaaaaaeceeeeiiiiOnooooo/0uuuuypy";
        unsigned char ch = (*p);
        if ( ch >=192 ) {
            (*p) = tr[ ch-192 ];
        }
        ++p;
    }
    return str;
}

bool Biblioteca::palavraPertence(string _palavra)const{
    for(Palavra x :palavras_){
        if(x.textoPalavra == _palavra) return true;
    }
    return false;
}

bool Biblioteca::documentoPertence(string nomeDocumento)const{
    for(int i=0; i < documentos_.size(); i++){
        if(documentos_[i].nomeDocumento == nomeDocumento){
            return true;
        }
    }
    return false;
}

void Biblioteca::inserirDocumento(string nomeDocumento){
    
    Documento d;
    d.nomeDocumento = nomeDocumento;
    documentos_.push_back(d);
    cout<<"pushback"<<endl;
    for(int i=0;i < indiceInvertido_.size();i++){
        cout<<"aumentou iI doc para"<<documentos_.size();
        indiceInvertido_[i].resize(documentos_.size());
    }
}


void Biblioteca::inserirPalavra(string palavra){
    
    if (!palavraPertence(palavra)){
        Palavra pal;
        pal.textoPalavra = palavra;
        pal.ocorrenciasNaColecao = 0;
        palavras_.push_back(pal);
        for (int i = 0; i<documentos_.size(); i++){
            documentos_[i].vetorial.resize(palavras_.size());
        }
        indiceInvertido_.push_back(vector<int>(documentos_.size()));
        cout<<"criou palavra "<<pal.textoPalavra<<" no documento "<<indiceInvertido_[0].size()-1<<endl;
    }
    palavras_[indiceDaPalavra(palavra)].ocorrenciasNaColecao ++;
    indiceInvertido_[indiceDaPalavra(palavra)][indiceInvertido_[0].size()-1]++;
    cout<<"adicionou palavra "<<palavras_[indiceDaPalavra(palavra)].textoPalavra<<" no documento "<<indiceInvertido_[0].size()-1<<endl;
 
    

}

void Biblioteca::calculaPeso(){
    float N,n;
    N = documentos_.size();
    for(int p=0; p < palavras_.size(); p++){
        n = 0;
        for(int d=0; d < documentos_.size(); d++){
            if(indiceInvertido_[p][d] > 0) n++;
        }
        palavras_[p].pesoNaColecao = log(N/n);
    }
}

string lePalavra(ifstream& arquivo){
    bool ignoraQuebraLinha = false;
    string palavra;
    char caracter;
    
    while(1){
        arquivo.get(caracter);
        if(caracter == ' ' || (caracter =='\n'&& !ignoraQuebraLinha) || arquivo.eof()) break;//encerra palavra em espaco, fim de linha ou fim do arquivo
        ignoraQuebraLinha = false;   
        removeAccented(&caracter);//remove acentuacao
        if(caracter >= 65 && caracter<= 90) caracter = caracter + 32;   //maiuscula para minuscula.
        if((caracter >= 97 && caracter <= 122)||(caracter >= 48 && caracter <= 57)){    // so permite entrar na palavra letras e numeros.
            palavra = palavra + caracter;
        }else if(caracter == '-'){
            ignoraQuebraLinha = true;   //permite palavras separadas por hifem ao fim da linha.
        }else if(caracter != '\n') break;    //encerra palavra para qualquer caracter diferente de - ou caracter valido.               
        
    }
    return palavra;
}

void Biblioteca::leArquivo(string nomeArquivo){    
    cout<<"tamvetdocI= "<<indiceInvertido_.size()<<endl;
    
    cout<<"insere arquivo "<<nomeArquivo<<endl;
    cout<<"tamvetdoc= "<<documentos_.size()<<endl;
    char caracter;
    ifstream arquivo;
    arquivo.open(nomeArquivo);
    string palavra;
    if (arquivo.is_open()){
        inserirDocumento(nomeArquivo);
        while(!arquivo.eof()){
            palavra = lePalavra(arquivo);                          
            if(palavra != ""){
                cout<<palavra<<endl;
                inserirPalavra(palavra);
            }
        }
            
    }else cout<<"nao abriu o arquivo "<<nomeArquivo<<endl;
    arquivo.close();
    calculaPeso();
    for(Documento doc :documentos_){
        vetorial(doc.nomeDocumento);
    }
    cout<<"saiu do arquivo "<<endl;
    cout<<endl;
    cout<<"indiceInvertido :"<<endl;
    for (int p = 0 ; p< indiceInvertido_.size();p++){
        for (int d = 0 ; d<indiceInvertido_[0].size();d++){
            cout<<indiceInvertido_[p][d]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"vetorial: "<<endl;
    for(Documento doc : documentos_){
        cout<<"( ";
        for (int p=0;p<palavras_.size();p++){
            cout<<doc.vetorial[p]<<", ";
        }
        cout<<" )";
        cout<<endl;
    }
    cout<<endl;


}

int Biblioteca::numPalavras()const{
    return palavras_.size();
}

int Biblioteca::numDocumentos()const{
    return documentos_.size();
}
int Biblioteca::indiceDaPalavra(string palavra)const{
    for (int i=0; i< palavras_.size(); i++){
        if (palavras_[i].textoPalavra == palavra) return i;
    }
}
int Biblioteca::indiceDoDocumento(string documento)const{
    for (int i=0; i< documentos_.size(); i++){
        if (documentos_[i].nomeDocumento == documento) return i;
    }
}

int Biblioteca::ocorrenciaNoDoc(string palavra, string doc)const{   //tf(term frequence)
    return indiceInvertido_ [indiceDaPalavra(palavra)] [indiceDoDocumento(doc)];
}

void Biblioteca::vetorial(string arquivo){ 
    cout<<"rodando vetorial"<<endl;
    if(documentoPertence(arquivo)){
        for (int p=0; p < palavras_.size(); p++){
            cout<<"palavra "<<palavras_[p].textoPalavra<<" ocorre "<<indiceInvertido_[p] [indiceDoDocumento(arquivo)]<<"vezes em arquivo"<<indiceDoDocumento(arquivo)<<endl;
            int tf = indiceInvertido_[p] [indiceDoDocumento(arquivo)];
            float idf = palavras_[p].pesoNaColecao;
            documentos_[indiceDoDocumento(arquivo)].vetorial[indiceDaPalavra(palavras_[p].textoPalavra )] = (tf * idf);
        }
    }
}

Biblioteca::~Biblioteca(){
}