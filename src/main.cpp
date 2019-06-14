#include "dirent.h"
#include <iostream>
#include <string>
#include "../include/documento.h"
#include "../include/palavra.h"
#include "../include/biblioteca.h"
#include <fstream>
#include <vector>


using namespace std;

int main(){
    string caminho;
    string busca;
    cout << "Digite o caminho completo (path) onde se encontra seus arquivos: " << endl;
    cin >> caminho;
    Biblioteca biblioteca(caminho);

    while(1){
        cout << "Digite sua busca: " << endl;
        cin >> busca;
        cout << endl <<"____________________________________________________________________________" << endl;
        vector<string> documentos = biblioteca.busca(busca);
        cout << endl <<"Ranking dos Documentos:" << endl;
        for (int i = 0; i < documentos.size(); i++){
            Documento documentoComplexo = documentos[i];
            cout << endl << i + 1 << ") " <<documentos[i];
        }
        cout << endl <<"____________________________________________________________________________" << endl;
    }
}
    