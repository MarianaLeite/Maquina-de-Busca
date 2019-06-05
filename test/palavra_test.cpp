#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/Palavra.h"
#include <string>

using namespace std;

class Palavra_teste {
    
    public:
        
        static string palavra_(const Palavra &c) {
            return  c.palavra_;
        }

        static string converter_(const string &x){
            Palavra a("");
            return a.converter(x);
        }

        static char removerAcento_(char x){
            Palavra a("");
            return a.removerAcento(x);
        }
};

TEST_SUITE("Testes sobre os m�todos da classe Palavra"){
    
    Palavra a("ol�");
    
    TEST_CASE("Remover acentos"){
        CHECK(Palavra_teste::removerAcento_('�') == 'a');
        CHECK(Palavra_teste::removerAcento_('�') == 'A');
    }

    TEST_CASE("Verifica se o met�do converter trata a string removendo os acentos e transformando as mesmas em min�sculas"){
        CHECK(Palavra_teste::converter_("Ol�") == "ola");
        CHECK(Palavra_teste::converter_("Ol��") == "olae");
    }
    
    TEST_CASE("Verificar se o m�todo paraString retorna a string que representa a Palavra"){
        CHECK(a.paraString() == "ola");
        Palavra b("p�");
        CHECK(b.paraString() == "pe");
        Palavra c("ol�");
        CHECK(c.paraString() == "ole");
        Palavra d("�");
        CHECK(d.paraString() == "e");
        Palavra e("ent�o");
        CHECK(e.paraString() == "entao");
        Palavra f("Fund�o");
        CHECK(f.paraString() == "fundao");
        Palavra g("Xumbalai�");
        CHECK(g.paraString() == "xumbalaie");
        Palavra h("N�o!!!!");
        CHECK(h.paraString() == "nao");
        Palavra i("eeee~y~u~iaao");
        CHECK (i.paraString() == "eeeeyuiaao");
        Palavra j("���������������");
        CHECK (j.paraString() == "aeiouaeiouaeiou" );
        Palavra k("N�o!!!!");
        CHECK(k.paraString() == "nao");
        Palavra l("P�o!P�nN!!!");
        CHECK(l.paraString() == "paopann");
        Palavra m("��");
        CHECK(m.paraString() == "ee");
        Palavra n("ALO,HA");
        CHECK (n.paraString() == "aloha");
    }
    
    TEST_CASE("Verifica se as Palavras (escritas com acento ou ma�sculas e min�sculas) s�o iguais"){
        Palavra a("REI");
        Palavra b ("rei");
        Palavra c("REI");
        Palavra d("Noite");
        CHECK((a == b) == true);
        CHECK((a == c) == true);
        CHECK((a == d) == false);
    }

    TEST_CASE("Verifica a atritui��o de uma palavra � outra"){
        Palavra a("Night");
        Palavra b("KIng");
        CHECK(a.paraString() == "night");
        CHECK (b.paraString() == "king");
        a = b;
        CHECK (a.paraString() == "king");
    }

    TEST_CASE("Verifica se uma Palavra � menor do que a outra (pelo contexto l�xico"){
        Palavra a("�rvores");
        Palavra b("Bal�o");
        string x = "arvores";
        string y = "balao";
        CHECK((x < y) == true);
        CHECK((y < x) == false);
        CHECK ((x < x) == false);
        CHECK ((y < y) == false);
        CHECK ((a < b == true));
        CHECK ((b < a == false));
        a = b;
        CHECK ((a < b) == false);
    }
}