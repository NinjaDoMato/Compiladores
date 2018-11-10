#ifndef COMPILADORES_ARQUIVO_H
#define COMPILADORES_ARQUIVO_H

#include <fstream>
#include <string>
#include <vector>
#include "Token.h"

class Arquivo {

public:


    // Inicializa o controlador do arquivo
    Arquivo();
    Arquivo(std::string inputFile, std::string outputFile);

    // Retorna o proximo caractér do buffer de entrada
    char Prox_char();

    // Insere o ultimo elemento removido do buffer
    void Ant_char();

    // Faz a gravação do LOG, do token e do seu lexema no arquivo de saída
    void Grava_token(std::string estado, Token token);

    // TODO: Implementar
    // Gravar token no arquivo
    void GravaToken(Token token);
    void GravaToken(std::vector<Token> tokens);

    bool IsEmpty();

    std::vector<char> getBuffer(){
        return this->Buffer;
    }


private:

    std::ifstream File;
    std::ofstream Log;
    std::vector<char> Buffer;
    char UltimaLeitura;
};


#endif //COMPILADORES_ARQUIVO_H
