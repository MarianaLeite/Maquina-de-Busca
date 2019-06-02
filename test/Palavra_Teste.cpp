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

TEST_SUITE("Testes sobre os métodos da classe Palavra"){
    
    Palavra a("olá");
    
    TEST_CASE("Remover acentos"){
        CHECK(Palavra_teste::removerAcento_('á') == 'a');
        CHECK(Palavra_teste::removerAcento_('Á') == 'A');
    }

    TEST_CASE("Converter"){
        CHECK(Palavra_teste::converter_("Olá") == "ola");
        CHECK(Palavra_teste::converter_("Oláé") == "olae");
    }
    
    TEST_CASE("paraString"){
        CHECK(a.paraString() == "ola");
        Palavra b("pé");
        CHECK(b.paraString() == "pe");
        Palavra c("olé");
        CHECK(c.paraString() == "ole");
        Palavra d("é");
        CHECK(d.paraString() == "e");
        Palavra e("então");
        CHECK(e.paraString() == "entao");
        Palavra f("Fundão");
        CHECK(f.paraString() == "fundao");
        Palavra g("Xumbalaié");
        CHECK(g.paraString() == "xumbalaie");
        Palavra h("Não!!!!");
        CHECK(h.paraString() == "nao");
        Palavra i("eeee~y~u~iaao");
        CHECK (i.paraString() == "eeeeyuiaao");
        Palavra j("áéíóúâêîôûàèìòù");
        CHECK (j.paraString() == "aeiouaeiouaeiou" );
        Palavra k("Não!!!!");
        CHECK(k.paraString() == "nao");
        Palavra l("Pão!PãnN!!!");
        CHECK(l.paraString() == "paopann");
        Palavra m("éê");
        CHECK(m.paraString() == "ee");
        Palavra n("ALO,HA");
        CHECK (n.paraString() == "aloha");
    }
    
    TEST_CASE("Operator=="){
        Palavra a("REI");
        Palavra b ("rei");
        Palavra c("REI");
        Palavra d("Noite");
        CHECK((a == b) == true);
        CHECK((a == c) == true);
        CHECK((a == d) == false);
    }

    TEST_CASE("Operator="){
        Palavra a("Night");
        Palavra b("KIng");
        CHECK(a.paraString() == "night");
        CHECK (b.paraString() == "king");
        a = b;
        CHECK (a.paraString() == "king");
    }

    TEST_CASE("Operator<"){
        Palavra a("Árvores");
        Palavra b("Balão");
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