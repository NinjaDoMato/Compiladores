#ifndef ANALISADOR_LEXICO_H
#define ANALISADOR_LEXICO_H

#include "Token.h"
#include "Arquivo.h"
#include <vector>


class AnalisadorLexico
{
public:
    AnalisadorLexico(Arquivo &arquivo): ArquivoEntrada(arquivo), Lexema(""), Estado(1){};
    Token Analex(char caracter);
    void SetaEstadoInicial(){this->Estado = 1; this->Lexema = "";};

private:
    std::string Lexema;
    Arquivo &ArquivoEntrada;
    int Estado;

};






#endif //ANALISADOR_LEXICO_H
