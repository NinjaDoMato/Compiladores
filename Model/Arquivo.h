#ifndef COMPILADORES_ARQUIVO_H
#define COMPILADORES_ARQUIVO_H

#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Token.h"
#include "../Controller/Arquivo.cpp"

using namespace std;

class Arquivo
{
public:

    // Inicializa o controlador do arquivo
    Arquivo(string inputFile, string outputFile);


    // Retorna o proximo caractér do buffer de entrada
    char Prox_char();

    // Faz a gravação do LOG, do token e do seu lexema no arquivo de saída
    void Grava_token(string estado, Token token);


private:

    ifstream File;
    ofstream Log;

    vector<char> Buffer;
};























#endif //COMPILADORES_ARQUIVO_H
