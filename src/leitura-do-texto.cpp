/**
 * @file leitura-do-texto.cpp
 * 
 * @authors João Victor de Castro Alves (joaovictorcastroa@gmail.com)
 *          Mariana da Silva Leite (marianaleite785@gmail.com)
 * 
 * @brief 
 * 
 * @version 0.1
 * 
 * @date 2019-04-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../include/leitura.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using std::string;

Documento::Documento(const string nome_documento){
    
    //TODO: Ler cada linha do documento, retirar maiúsculas e símbolos e adicionar as palavras à lista

    ifstream in (nome_documento);
    if(in.is_open()){
        
        while (in.eof() == false){
            getline (in,documento_);
            cout << documento_ << endl;
        }
    }
    in.close();

}
