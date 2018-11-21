//
// Created by daniel.deda on 21/11/2018.
//

#ifndef COMPILADORES_TIPO_H
#define COMPILADORES_TIPO_H

#include <string>

// TODO: Não tenho certeza se isso é esse o nome, mas é o cara que vai na tabela de simbolos

using namespace std;

class Identificador
{
public:

    inline Identificador(string nome, string tipo, int tamanho, string escopo, string valor):
    Nome(nome), Tipo(tipo), Tamanho(tamanho), Escopo(escopo), Valor(valor)
    {
        // TODO: implementar um id estatico que é incrementado a cada novo identificador
    }

    // TODO: adicionar Getters e Setters

private:

    int id;
    string Nome;
    string Tipo;
    int Tamanho;
    string Escopo;
    string Valor;
};


#endif //COMPILADORES_TIPO_H
