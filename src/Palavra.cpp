#include "../include/Palavra.h"
#include <ctype.h>
#include <iostream>
#include <string>


Palavra::Palavra(string x){
    this->palavra_ = converter(x);
}

string Palavra::converter(const string &x){
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

char Palavra::removerAcento(char x) {
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

string Palavra::paraString()const{
    return this->palavra_;
}

bool Palavra::operator==(const Palavra &x) const {
    return (this->palavra_ == x.palavra_);
}

void Palavra::operator=(const Palavra &x){
    this->palavra_ = x.palavra_;
}

bool Palavra::operator<(const Palavra &x) const {
    return (this->palavra_ < x.palavra_);
}