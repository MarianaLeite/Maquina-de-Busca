#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/Palavra.h"
#include <string>
#include <ctype.h>
#include <locale>


using namespace std;


class Palavra_teste {
    public:
        static string palavra_(const Palavra &c) {
            return  c.palavra_;
        }

        static string converter(const string &x){
              string y;
            for (char i : x){   
            i = removerAcento(i);
            i = tolower(i);
            if (islower(i)){
                if (iswdigit(i) || iswalnum(i)) y += i;
                }
            }
            return y;
        }

        static char removerAcento (char x){
             char *p = &x;
            while ((*p) != 0) {    
            const char* tr = "AAAAAAECEEEEIIIIDNOOOOOx0UUUUYPsaaaaaaeceeeeiiiiOnooooo/0uuuuypy";
            unsigned char ch = (*p);
            if (ch >= 192){
                (*p) = tr[ch-192];
            }
            ++p;
            }
        return x;
        }
};



TEST_SUITE("Testa a remo??o de caracteres especiais da palavra"){
    Palavra a("ol·");
    
    TEST_CASE("Remover acentos"){
        char a = '·';
        char b = '¡';
        
        a = Palavra_teste::removerAcento(a);
        CHECK(a == 'a');
        b = Palavra_teste::removerAcento(b);
        CHECK(b == 'A');
    }

    TEST_CASE("Converter"){
        string  a = "Ola";
        string b = "Ùl· ";
        a = Palavra_teste::converter(a);
        CHECK(a == "ola");
        b = Palavra_teste::converter(b);
        CHECK(b == "olae");
    }
    
    TEST_CASE("paraString"){
        CHECK(a.paraString() == "ola");
        Palavra b("pÈ");
        CHECK(b.paraString() == "pe");
        Palavra c("olÈ");
        CHECK(c.paraString() == "ole");
        Palavra d("È");
        CHECK(d.paraString() == "e");
        Palavra e("ent„o");
        CHECK(e.paraString() == "entao");
        Palavra f("Fund„o");
        CHECK(f.paraString() == "fundao");
        Palavra g("XumbalaiÍ");
        CHECK(g.paraString() == "xumbalaie");
        Palavra h("N√o!!!!");
        CHECK(h.paraString() == "nao");
        Palavra i("   Í~y~u~i„„ı");
        CHECK (i.paraString() == "eeeeyuiaao");
        Palavra j("·ÈÌÛ˙‚ÍÓÙ˚‰ÎÔˆ¸");
        CHECK (j.paraString() == "aeiouaeiouaeiou" );
        Palavra k("N„o!!!!");
        CHECK(k.paraString() == "nao");
        Palavra l("P„o!P¬nN!!!");
        CHECK(l.paraString() == "paopann");
        Palavra m("»…");
        CHECK(m.paraString() == "ee");
        Palavra n("AL‘,HA");
        CHECK (n.paraString() == "aloha");
    }
    
    TEST_CASE("Operator == "){
        Palavra a("REI");
        Palavra b ("rei");
        Palavra c("REI");
        Palavra d("Noite");
        CHECK((a == b) == true);
        CHECK((a == c) == true);
        CHECK((a == d) == false);
    }

    TEST_CASE("Operator ="){
        Palavra a("Night");
        Palavra b("KIng");
        CHECK(a.paraString() == "night");
        CHECK (b.paraString() == "king");
        a = b;
        CHECK (a.paraString() == "king");
    }

    TEST_CASE("Operator <"){
        Palavra a("¿rvores");
        Palavra b("Bal„o");
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

