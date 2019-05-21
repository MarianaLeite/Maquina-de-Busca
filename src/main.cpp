#include <dirent.h>
#include <iostream>
#include <string>
#include "../include/Palavra.h"
#include <fstream>
#include <vector>

using namespace std;

int main(){
  /*  ifstream arquivo;
    string palavra;
    vector <string> nome_dos_arquivos = lista_arquivo("C:/UFMG/Maquina-de-Busca/src");
    arquivo.open("C:/UFMG/Maquina-de-Busca/src/" + nome_dos_arquivos[3]);
    if (arquivo.is_open()){
        cout<<"deu bao " <<endl;
        while(!arquivo.eof()){
            getline(arquivo,palavra);
            cout << palavra<<endl;
            }
        arquivo.close();
    }
        else {
            cout<<"deu ruim";
        }
}

vector<string> lista_arquivo(string nome_diretorio){
    DIR *diretorio;
    int i = 0;
    vector <string> nome_arquivos;
    struct dirent *entrada;
    
    diretorio = opendir(nome_diretorio.c_str());

    if (diretorio == NULL){
        cout << "Nao foi possivel abrir o arquivo" << endl;
        exit(1);

    }

    while ((*readdir(diretorio)) != NULL){
        string auxiliar;
       // cout << entrada -> d_name<<endl;
        for (int x = 0; x < entrada -> d_namlen; x++){
            auxiliar.push_back(entrada -> d_name[x]);
        }
        //cout <<auxiliar<<endl;
        nome_arquivos.push_back(auxiliar);
        i++;
    }
    closedir(diretorio);
    return nome_arquivos;*/

    Palavra a ("xaaáááó olá, ººº éÊÊiÕ marilene. arco-íris!!!, opaòÓáêêÜü~~--¶	µ	³®	¯	¬	ÿ÷	ö	");
    std::cout << a.paraString();
}
    
    
