//
// Created by winderson on 11/11/18.
//

#ifndef COMPILADORES_CARACTERENUM_H
#define COMPILADORES_CARACTERENUM_H


enum class EstadoEnum {

    // Estado inicial
    INICIAL = 1,

    // Estados dos números
    ESTADO_NUM_1 = 2, // inteiro
    ESTADO_NUM_2 = 3, // real
    ESTADO_NUM_3 = 4, // real

    // Estado operadores
    ESTADO_SOMA = 10, // soma
    ESTADO_SUBTRACAO = 11, // subtracao
    ESTADO_MENOR = 12, // menor
    ESTADO_MAIOR = 13, // maior
    ESTADO_IGUAL = 14, // igual
    ESTADO_MULTIPLICACAO = 15, // multplicacao
    ESTADO_PORCENTAGEM = 16, // porcentagem
    ESTADO_DIVISAO = 17, // divisao
    ESTADO_DIFERENTE = 18, // diferente
    ESTADO_E = 19, // and
    ESTADO_OU = 20, // or

    // Estado identificador
    ESTADO_IDENTIFICADOR_1 = 21,
    ESTADO_IDENTIFICADOR_2 = 22





};


#endif //COMPILADORES_CARACTERENUM_H
