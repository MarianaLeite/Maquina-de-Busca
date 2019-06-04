#include "dirent.h"
#include <iostream>
#include <string>
#include "../include/Documento.h"
#include "../include/Palavra.h"
#include "../include/Biblioteca.h"
#include <fstream>
#include <vector>


using namespace std;

int main(){
    Biblioteca x ("../test/diretorio");
    vector<string> a = x.busca("A");
    for (int i = 0; i < a.size(); i++){
        Documento y = a[i];
        Palavra z("A");
        cout << endl <<"Ranking dos Documentos:" << endl;
        cout << i + 1 << ") " <<a[i] << endl;
        cout <<"A frequencia da palavra A no documento: " << y.frequencia(z) << endl;
        cout << "As palavras presentes no documento: " << endl;
        for(Palavra p : y.palavras()){
            cout<<p.paraString() <<endl; 
        }
    }

}
    