#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/Palavra.h"

TEST_SUITE("Testa a remoção de caracteres especiais da palavra"){
    Palavra a("áéíóú");
    string x = a.paraString();
    TEST_CASE("Remove acentos"){
        CHECK(x == "aeiou");
    }
}

