#include "../include/biblioteca.h"
#include "../include/documento.h"
#include "../include/palavra.h"
#include <cmath>
#include <list>
#include <string>
#include <dirent.h>
#include <vector>

#include <iostream>//remover
Biblioteca::Biblioteca(){
}

Biblioteca::Biblioteca(const string &x){
    
    DIR *diretorio;
    struct dirent *entrada;
    diretorio = opendir(x.c_str());
    if (diretorio == NULL){
        cout << "Nao foi possivel abrir o diretorio" <<x<< endl;
        exit(1);
    }
    while ((entrada = readdir (diretorio)) != NULL) {
        string nome = entrada->d_name;
        string extensao;
        for(string::reverse_iterator i= nome.rbegin();i!=nome.rend();++i ){
            if(*i=='.')break;
            extensao += *i;
        }
        if(extensao == "txt") inserirDocumento(x+'/'+entrada->d_name);
    }
    closedir(diretorio);
}

void Biblioteca::inserirDocumento(const string &x){
    Documento doc(x);
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
    if (i == indiceInvertido_.end()){
        return 0;    
    }
    else{ 
        n = 0;
        for(int d=0; d < documentos_.size(); d++){
            if(i->second[d] > 0) n++;
        }
        if(log(N/n)==0) return 0.00000000000000000000000000000001;
        return log(N/n);
    }
}

double Biblioteca::coordenada(Documento &x, const Palavra &y){
    
    return x.frequencia(y)*frequenciaInversa(y);
}

double Biblioteca::similaridade(Documento &x, Documento& busca){
    vector<double> vetorialX,vetorialBusca;
    for(map<Palavra,vector<int>>::iterator i = indiceInvertido_.begin(); i!=indiceInvertido_.end();++i){
        vetorialX.push_back(coordenada(x,i->first));
        vetorialBusca.push_back(coordenada(busca,i->first));
    }
    
    double produtoEscalar = 0;
    double moduloX = 0, moduloBusca = 0;
    for(int i = 0;i<vetorialX.size();++i){
        produtoEscalar += vetorialX[i]*vetorialBusca[i];
        moduloX += vetorialX[i] * vetorialX[i];
        moduloBusca += vetorialBusca[i] * vetorialBusca[i];
    }
    moduloX = sqrt(moduloX);
    moduloBusca = sqrt(moduloBusca);
    if(moduloBusca==0||moduloX==0)return 0;
    return produtoEscalar/(moduloBusca * moduloX);
}

vector<string> Biblioteca::busca(const string argumentos){
    vector<string> saida;
    Documento buscar;
    buscar.configurarComoBusca(argumentos);
    list<Documento> ranking;
    for (Documento& d : documentos_){
            double s = similaridade(d,buscar);
            d.similaridade(s);
            ranking.push_back(d);
    }
    ranking.sort();
    for (std::list<Documento>::reverse_iterator i=ranking.rbegin();i!=ranking.rend();++i ){
        saida.push_back(i->nome());
    }
    return saida;
}