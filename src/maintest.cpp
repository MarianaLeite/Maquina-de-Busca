#include "../include/Biblioteca.h"
#include "../include/Documento.h"
#include "../include/Palavra.h"
#include <iostream>
int main(){
    vector<string> resultado;
    string busca;
    Biblioteca a("./dirbusca");

    std::cin>>busca;
    resultado = a.busca(busca);
    for (string s:resultado){
        cout << s << endl;
    }
}