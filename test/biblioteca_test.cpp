#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/documento.h"
#include "../include/palavra.h"
#include "../include/biblioteca.h"
#include<vector>
#include <cmath>

class Biblioteca_teste{
    public:
    
    static vector<Documento> documentos(Biblioteca& b){
        return b.documentos_;
    }
    
    static map<Palavra,vector<int>>  indiceI(Biblioteca& b){
        return b.indiceInvertido_;
    }
    
    static void inserirDocumento(Biblioteca& b, const string& s){
        b.inserirDocumento(s);
    }
    
    static double frequenciaInversa(const Palavra& p,Biblioteca& b){
        return b.frequenciaInversa(p);
    }
    
    static double coordenada(Documento &x, const Palavra &y,Biblioteca& b){
        return b.coordenada(x,y);
    }
    
    static double similaridade(Documento &x, Documento &busca,Biblioteca& b){
        return b.similaridade(x,busca);
    }
};

TEST_SUITE("Testes sobre os métodos da classe Biblioteca"){
    
    TEST_CASE("Construtor vazio da classe Biblioteca"){
        Biblioteca b;
        CHECK(Biblioteca_teste::indiceI(b).size()==0);
        CHECK(Biblioteca_teste::documentos(b).size()==0);
    }

    TEST_CASE("Teste que verifica a insersão do Documento através do método inserirDocumento"){
        Biblioteca bib;
        Biblioteca_teste::inserirDocumento(bib,"./diretorio/teste1.txt");//A A A B
        Palavra a ("A");
        Palavra b ("B");
        Palavra c ("C");
        REQUIRE(Biblioteca_teste::indiceI(bib).size()==2);
        REQUIRE(Biblioteca_teste::indiceI(bib)[a].size()==1);
        REQUIRE(Biblioteca_teste::indiceI(bib)[b].size()==1);
        CHECK(Biblioteca_teste::indiceI(bib)[a][0]==3);
        CHECK(Biblioteca_teste::indiceI(bib)[b][0]==1);
        CHECK(Biblioteca_teste::documentos(bib).size()==1);

        Biblioteca_teste::inserirDocumento(bib,"./diretorio/teste2.txt");//B B C
        REQUIRE(Biblioteca_teste::indiceI(bib).size()==3);
        REQUIRE(Biblioteca_teste::indiceI(bib)[a].size()==2);
        REQUIRE(Biblioteca_teste::indiceI(bib)[b].size()==2);
        REQUIRE(Biblioteca_teste::indiceI(bib)[c].size()==2);
        CHECK(Biblioteca_teste::indiceI(bib)[a][1]==0);
        CHECK(Biblioteca_teste::indiceI(bib)[b][1]==2);
        CHECK(Biblioteca_teste::indiceI(bib)[c][1]==1);
        CHECK(Biblioteca_teste::documentos(bib).size()==2);
    }
    
    TEST_CASE("Construtor da Biblioteca a partir do diretorio passado como parâmetro"){
        Biblioteca bib("./diretorio");
        CHECK(Biblioteca_teste::indiceI(bib).size()==3);
        CHECK(Biblioteca_teste::documentos(bib).size()==4);
        Palavra a("A");
        Palavra b("B");
        Palavra c("C");
        REQUIRE(Biblioteca_teste::indiceI(bib)[a].size()==4);
        REQUIRE(Biblioteca_teste::indiceI(bib)[b].size()==4);
        REQUIRE(Biblioteca_teste::indiceI(bib)[c].size()==4);
    }

    TEST_CASE("Testar o inverso da frequência nos documentos através do métodoinverseFrequence"){
        Biblioteca bib("./diretorio");
        Palavra a("A");
        Palavra b("B");
        Palavra c("C");
        double N=4,n=3;
        CHECK(Biblioteca_teste::frequenciaInversa(a,bib)== log(N/n));
        CHECK(Biblioteca_teste::frequenciaInversa(b,bib) > 0);
        CHECK(Biblioteca_teste::frequenciaInversa(c,bib)== log(N/n));
    }

    TEST_CASE("Testar as coordenadas de uma palavra no documento através do método coordenada"){
        Biblioteca bib("./diretorio");
        Documento d("./diretorio/teste1.txt");
        Palavra a("A");
        Palavra b("B");
        Palavra c("C");
        double N=4,n=3;
        CHECK(Biblioteca_teste::coordenada(d,a,bib) == 3*log(N/n));
        CHECK(Biblioteca_teste::coordenada(d,b,bib) > 0);
        CHECK(Biblioteca_teste::coordenada(d,c,bib) == 0);        
    }
    
    TEST_CASE("Testar a similaridade do documento com a busca "){
        Biblioteca bib("./diretorio");
        Documento d("./diretorio/teste1.txt");
        Documento e("./diretorio/teste2.txt");
        CHECK((int)Biblioteca_teste::similaridade(d,e,bib) == 0);        
    }

    TEST_CASE("Testar se o vetor ranking retorna a similaridade de cada documento com a busca"){
        Biblioteca bib("./diretorio");
        vector<string> ranking{"./diretorio/teste1.txt","./diretorio/teste3.txt","./diretorio/teste4.txt","./diretorio/teste2.txt"};
        CHECK(bib.busca("a")==ranking);        
    }
}