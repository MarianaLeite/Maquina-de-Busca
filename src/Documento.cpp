# include "../include/Documento.h"
# include <string>
#include <iostream>
#include <fstream>
using namespace std;

    int tamanho_;
    string* elementos_;
    int* ocorrencias_;
    int tamanhoVetor_;

Documento::Documento(){
    this->elementos_ = new string[1];
    this->ocorrencias_ = new int[1];
    this->tamanho_ = 0;
    this->tamanhoVetor_ = 1;
}

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

bool Documento::pertence(string _palavra){
    for(int i=0;i<this->tamanho_;i++){
        if(this->elementos_[i] == _palavra) return true;
    }
    return false;
}

void Documento::insereElemento(string _insert){
    if(this->pertence(_insert)){
        for(int i=0;i<this->tamanho_;i++){
        if(this->elementos_[i] == _insert) ocorrencias_[i]++;
        }
    }else{
        if(tamanho_==tamanhoVetor_){
            tamanhoVetor_ = tamanhoVetor_*2;
            string* ptrs;
            ptrs = new string[tamanhoVetor_];
            int* ptro;
            ptro = new int[tamanhoVetor_];
            for(int i = 0; i < tamanho_; i++){
                ptrs[i]=this->elementos_[i];
                ptro[i]=this->ocorrencias_[i];
            }
            delete [] elementos_;
            delete [] ocorrencias_;
            elementos_ = ptrs;
            ocorrencias_ = ptro;
        }
        elementos_[tamanho_] = _insert;
        ocorrencias_[tamanho_] = 1;
        tamanho_ ++;        
    }
}
    
int Documento::ocorrencias(string _elemento){
    for (int i=0;i < this->tamanho_;i++){
        if (elementos_[i] == _elemento){
            return ocorrencias_[i];
        }
    }
    return 0;
}

string Documento::palavra(int _indice){
    if(_indice <= this->tamanho_){
        return this->elementos_[_indice];
    }
    return "";
}

void Documento::leArquivo(string nomeArquivo){    
    bool ignoraQuebraLinha = false;
    char rd;
    string palavra("");
    ifstream arquivo;
    arquivo.open(nomeArquivo);
    if(arquivo.is_open()){
        while(!arquivo.eof()){
            while(1){
                arquivo.get(rd);
                if(rd == ' ' || (rd =='\n'&& !ignoraQuebraLinha) || arquivo.eof()) break;//encerra palavra em espaco, fim de linha ou fim do arquivo
                ignoraQuebraLinha = false;   
                removeAccented(&rd);//remove acentuacao
                if(rd >= 65 && rd<= 90) rd = rd + 32;   //maiuscula para minuscula.
                if((rd >= 97 && rd <= 122)||(rd >= 48 && rd <= 57)){    // so permite entrar na palavra letras e numeros.
                    palavra = palavra + rd;
                }else if(rd == '-'){
                    ignoraQuebraLinha = true;   //permite palavras separadas por hifem ao fim da linha.
                }else if(rd != '\n') break;    //encerra palavra para qualquer caracter diferente de - ou caracter valido.               
            }
            if(palavra != "") this->insereElemento(palavra);
            palavra = "";
            
        }
        arquivo.close();
    }else cout<<"Nao abriu o arquivo "<<nomeArquivo<<endl;
}

int Documento::tamanho(){
    return this->tamanho_;
}

Documento::~Documento(){
    delete [] elementos_;
    delete [] ocorrencias_; 
}