#include "../include/Palavra.h"
#include <ctype.h>
#include <string>

//ISO 8859-1
char* removerAcento( char* str ) {
    char *p = str;
    while ( (*p)!=0 ) {
        const char*
        tr = "aaaaaaeceeeeiiiiOnooooo/0uuuuypy";
        unsigned char ch = (*p);
        if ( ch >=224 ) {
            (*p) = tr[ ch-224 ];
        }
        ++p;
    }
    return str;
}

Palavra::Palavra(string x){
    this->palavra_ = converter(x);
}

string Palavra::converter(const string &x){
    string y = x;
    for (int i = 0; i < y.length(); i++){
        if (y[i] >= 128 && y[i] <= 159){
            y.erase(i);
        }
        if (y[i] >= 161 && y[i] <= 191){
            y.erase(i);
        }
        if (y[i] >= 247 && y[i] <= 248){
            y.erase(i);
        }
        if (y[i] >= 253 && y[i] <= 255){
            y.erase(i);
        }
        if (y[i] >= 58 && y[i] <= 64){
            y.erase(i);
        }
        if (y[i] >= 91 && y[i] <= 96){
            y.erase(i);
        }
        if (y[i] >= 123 && y[i] <= 126){
            y.erase(i);
        }

        y[i] = tolower(y[i]);
        y[i] = *removerAcento(&y[i]);
    }
    return y;
}

string Palavra::paraString(){
    return this->palavra_;
}

bool Palavra::operator==(const Palavra &x){
    if (this -> palavra_ == x.palavra_){
        return true;
    }else {
        return false;
    }
    
}

void Palavra::operator=(const Palavra &x){

}

