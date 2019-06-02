#include "../include/Biblioteca.h"
#include "../include/Documento.h"
#include "../include/Palavra.h"
#include <iostream>
int main(){
    vector<string> resultado;
    string argBusca;
    Biblioteca a("dirBusca");
    cout<<"Entre com os argumentos da busca:"<<endl;
    getline(cin,argBusca);
    resultado = a.busca(argBusca);
    for (string s:resultado){
        cout << s << endl;
    }

}