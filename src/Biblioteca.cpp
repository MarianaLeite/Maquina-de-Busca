#include "../include/Biblioteca.h"
#include "../include/Documento.h"
#include <cmath>
#include<set>
#include <iostream>//remover
Biblioteca::Biblioteca(const string &x){
    inserirDocumento("teste1.txt");
    inserirDocumento("teste2.txt");
    inserirDocumento("teste3.txt");
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
    //teste impressao do indice invertido
    for(map<Palavra,vector<int>>::iterator i = indiceInvertido_.begin(); i != indiceInvertido_.end();++i ){
        cout<< i->first.paraString()<<" ";
        for (int j:i->second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    //fim do teste impressao do indice invertido
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
    return produtoEscalar/(moduloBusca * moduloX);
}

vector<string> Biblioteca::busca(const string argumentos){
    vector<string> saida;
    Documento buscar;
    buscar.configurarComoBusca(argumentos);
    //teste impressao busca
    cout<<"palavras da busca: "<<endl;
    for (Palavra& p: buscar.palavras()){
        cout<<p.paraString()<<" ";
    }
    cout<<endl;
    //fim teste impressao busca
    map<float,string> cossenos;
    for (Documento d : documentos_){
        cossenos[similaridade(d,buscar)]=d.nome();
        cout<<"similaridade de "<<d.nome()<<" = "<<similaridade(d,buscar)<<endl;
    }
    for(map<float,string>::iterator i=cossenos.begin();i!= cossenos.end();++i){
        saida.push_back(i->second);
    }
    return saida;
}

