#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"
#include "../include/Documento.h"
#include "../include/Palavra.h"
#include <string>
#include <ctype.h>
#include <locale>

using namespace std;

class Documento_teste {
    public: 
    
        static double similaridade (Documento &x){
            return x.similaridade_;
        }

        static string nome (Documento &x){
            return x.nome_;
        }

        static map <Palavra, int> frequencia_(Documento &x){
            return x.frequencia_;
        }

        static map <Palavra, double> coordenadas_(Documento &x){
            return x.coordenadas_;
        }

        static void inserirPalavras (const Palavra &x, Documento &y){
            y.inserirPalavra(x);
        }

        
};

TEST_SUITE("Classe Documento"){
    
    TEST_CASE("Construtor vazio da classe Documento"){
        Documento x;
        CHECK(Documento_teste::nome(x).empty());
    }

    TEST_CASE("Contrutor com  o nome do documento como parâmetro"){
        Documento x("doctext.txt");
        Palavra y("teste");
        CHECK(Documento_teste::nome(x) == "doctext.txt");
        Documento_teste::inserirPalavras(y,x);
        CHECK(x.Documento::frequencia(y) == 1);
    }

    TEST_CASE("método que retorna a frequencia da palavra no documento"){
        Documento x("doctext.txt");
        Palavra y("Olá");
        CHECK(x.Documento::frequencia(y) == 1);
    }

    TEST_CASE("método que retorna o vetor de palavras Palavras"){
        Documento x("doctext.txt");
        vector <Palavra> auxiliar = x.Documento::palavras();
        CHECK (auxiliar.size() == x.Documento::palavras().size());
        CHECK(auxiliar[0] == x.Documento::palavras()[0]);
        CHECK(auxiliar[1] == x.Documento::palavras()[1]);
        CHECK(auxiliar[0].paraString() == x.Documento::palavras()[0].paraString());
        CHECK(auxiliar[1].paraString() == x.Documento::palavras()[1].paraString());
    }

    TEST_CASE("metódo que retorna o nome do documento"){
        Documento x("doctext.txt");
        CHECK(Documento_teste::nome(x) == "doctext.txt");
    }

    TEST_CASE("configurar um documento com um texto"){
        Documento x;
        CHECK(x.Documento::palavras().size() == 0);
        x.configurarComoBusca("Dark side");
        CHECK(x.Documento::palavras().size() == 2);
        CHECK(x.Documento::palavras()[0].paraString() == "dark");
        CHECK(x.Documento::palavras()[1].paraString() == "side");
    }

    TEST_CASE("inserir palavra"){
        Documento x("doctext.txt");
        Palavra y("vinho");
        Documento_teste::inserirPalavras(y,x);
        CHECK(x.Documento::frequencia(y) == 1);
        CHECK(x.Documento::palavras().size() == 3);
    }

    TEST_CASE("frequencia"){
        Documento x("doctext.txt");
        Palavra y("Olá");
        Palavra z("Não");
        CHECK(x.Documento::frequencia(y) == 1);
        Documento_teste::inserirPalavras(y,x);
        CHECK(x.Documento::frequencia(y) == 2);
        CHECK(x.Documento::frequencia(z) == 0);
    }

    TEST_CASE("método Palavras que retorna um vetor de palavras do documento"){
        Palavra x("Amanhã");
        Documento y("doctext.txt");
        CHECK(y.Documento::palavras().size() == 2);
        Documento_teste::inserirPalavras(x,y);
        CHECK(y.Documento::palavras().size() == 3);
        CHECK(y.Documento::palavras()[0].paraString() == "amanha");
        CHECK(y.Documento::palavras()[1].paraString() == "marilene");
        CHECK(y.Documento::palavras()[2].paraString() == "ola");
    }

    TEST_CASE("Similaridade"){
        Documento x("doctext.txt");
        x.Documento::similaridade(1);
        CHECK(Documento_teste::similaridade(x) == 1);
    }

    TEST_CASE("nome do documento"){
        Documento x("doctext.txt");
        CHECK(Documento_teste::nome(x) == "doctext.txt");
    }

    TEST_CASE("operator <"){
        Documento x("doctext.txt");
        x.Documento::similaridade(1);
        Documento y("../teste1.txt");
        y.Documento::similaridade(0.5);
        CHECK((y < x));
    }

}
