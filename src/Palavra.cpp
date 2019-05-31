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
        i = tolower(i);
        i = removerAcento(i);
        if(iswdigit(i) || iswalnum(i)) y += i;
    }
    
    return y;
}

char Palavra::removerAcento(char x) {
    char *p = &x;

    while ((*p) != 0) {    
        const char* tr = "aaaaaaeceeeeiiiiOnooooo/0uuuuypy";
        unsigned char ch = (*p);
        if (ch >= 224){
            (*p) = tr[ch-224];
        }
        ++p;
    }

    return x;
}

string Palavra::paraString(){
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