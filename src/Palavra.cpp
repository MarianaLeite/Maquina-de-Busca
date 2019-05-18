#include "../include/Palavra.h"
#include <ctype.h>
#include <string>


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

        if(iswgraph(y[i])){
            y[i] = tolower(y[i]);
            y[i] = *removerAcento(&y[i]);
        }

        else y.erase(i);

    }
    return y;
}

string Palavra::paraString(){
    return this->palavra_;


bool Palavra::operator==(const Palavra &x){
    return(this->palavra_ == x.palavra_);
}

void Palavra::operator=(const Palavra &x){

}

