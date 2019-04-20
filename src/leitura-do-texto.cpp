



#include "../include/leitura.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
using std::string;

arquivo::arquivo(const string nome_arquivo){
    
    ifstream in (nome_arquivo);
    if(in.is_open()){
        //pega a quantidade de palavras
        while (in.eof() == false){
            getline (in,arquivo_);
            cout << arquivo_ << endl;
        }
    }
    in.close();

}
