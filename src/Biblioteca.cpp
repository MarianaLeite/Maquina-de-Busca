#include "../include/Biblioteca.h"
#include "../include/Documento.h"
#include <cmath>
#include<set>
Biblioteca::Biblioteca(const string &x){
    inserirDocumento(x);
}

void Biblioteca::inserirDocumento(const string &x){
    
    Documento doc(x);
    ifstream arquivo;
    arquivo.open(x);
    string palavras_documento;
    if (arquivo.is_open()){
        while (!arquivo.eof()){
            getline(arquivo,palavras_documento);
        }
        arquivo.close();
    }else {
        cout << "Deu ruim";
    }
    for (int i = 0; i < palavras_documento.size(); i++){
        string auxiliar;
        if (palavras_documento[i] != ' '){
            auxilar.push_back(palavras_documento[i]);
        }else if(palavras_documento[i] == ' '){
            Palavra x(auxiliar);
            auxiliar = ' ';
        }

    }
    for(Palavra& p : doc.palavras()){
        indiceInvertido_.insert(std::pair<Palavra,vector<int>>(p,vector<int>(documentos_.size())));
        indiceInvertido_[p].push_back(doc.frequencia(p));
    }
    documentos_.push_back(doc);
    for(map<Palavra,vector<int>>::iterator i = indiceInvertido_.begin(); i != indiceInvertido_.end();++i ){
        i->second.resize(documentos_.size());
    }
}

double Biblioteca::frequenciaInversa(const Palavra &x){
    double N,n;
    N = documentos_.size();
    map<Palavra,vector<int>>::iterator i = indiceInvertido_.find(x);
    if (i == indiceInvertido_.end())return 0;
    else{ 
        n = 0;
        for(int d=0; d < documentos_.size(); d++){
            if(i->second[d] > 0) n++;
        }
    return log(N/n);
    }
}

double Biblioteca::coordenada(Documento &x, const Palavra &y){
    return x.frequencia(y)*frequenciaInversa(y);
}

double Biblioteca::similaridade( Documento &x, Documento& busca){
    map<Documento,vector<double>> vetorial;
    for(map<Palavra,vector<int>>::iterator i = indiceInvertido_.begin(); i!=indiceInvertido_.end();++i){
        vetorial[x].push_back(coordenada(x,i->first));
        vetorial[busca].push_back(coordenada(busca,i->first));
    }
    double produtoEscalar = 0;
    double moduloX = 0, moduloBusca = 0;
    for(int i = 0;i<vetorial[x].size();++i){
        produtoEscalar += vetorial[x][i]*vetorial[busca][i];
        moduloX += vetorial[x][i] * vetorial[x][i];
        moduloBusca += vetorial[busca][i] * vetorial[busca][i];
    }
    moduloX = sqrt(moduloX);
    moduloBusca = sqrt(moduloBusca);
    return produtoEscalar/(moduloBusca * moduloX);
}

vector<string> Biblioteca::busca(const string argumentos){
    vector<string> saida;
    Documento buscar(argumentos);
    map<float,string> cossenos;
    for (Documento d : documentos_){
        cossenos[similaridade(d,buscar)]=d.nome();
    }
    for(map<float,string>::iterator i=cossenos.begin();i!= cossenos.end();++i){
        saida.push_back(i->second);
    }
    return saida;
}

