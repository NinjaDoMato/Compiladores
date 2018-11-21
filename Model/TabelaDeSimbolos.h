#ifndef COMPILADORES_TABELADESIMBOLOS_H
#define COMPILADORES_TABELADESIMBOLOS_H

#include<string>
#include"Tipo.h"

using namespace std;

// TODO: Usei os nomes dos métodos que estão na apostila, podemos mudar isso
// TODO: Podemos fazer um esquema igual ao Enum do Lexico para substitur as strings passadas por parametros e representar o tipo

class TabelaDeSimbolos
{
public:

    // Inclui o primeiro parâmetro na tabela de simbolos com o tipo indicado no egundo parametro
    void Insere(string id, string tipo);

    // Retorna se o identificador está ou não na TS
    bool Consulta(string id);

    // Retorna o tipo de um identificador na TS (que será representado pelo Enum a ser desenvolvido)
    string Tipo(string id);

    void Remove(string id);

private:

};



#endif