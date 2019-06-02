#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/Documento.h"
#include "../include/Palavra.h"
#include <string>
#include <ctype.h>
#include <locale>

using namespace std;

class Documento_teste {
    public: 
    
        static double similaridade (Documento &x, int y){
            x.similaridade(y);
            return x.similaridade_;
        }

        static string nome (Documento &x){
            return x.nome_;
        }

        static map <Palavra, int> frequencia_(Documento &x){
            return x.frequencia_;
        }

        static map <Palavra, double> coordenadas_(Documento &x){
            return x.coordenadas_;
        }

        static void inserirPalavras (const Palavra &x, Documento &y){
            y.inserirPalavra(x);
        }

        
};