//
// Created by winderson on 11/5/18.
//

#include <iostream>
#include <string>
#include "CompiladorController.h"
#include "../Model/AnalisadorLexico.h"
#include "../Model/Arquivo.h"
#include "../Model/Lexico.h"

using namespace std;

/**
 *
 */
void CompiladorController::executar() {

    //AnalisadorLexico analisadorLexico;
    Arquivo arquivo("../entrada.txt", "../saida.txt");
    AnalisadorLexico analisadorLexico(arquivo);

    while (!arquivo.getBuffer().empty()) {
        char c = arquivo.Prox_char();
        analisadorLexico.SetaEstadoInicial();
        Token token = analisadorLexico.Analex(c);
        cout << "ANALISADOR LOG --> " << token.GetLog() << endl;
        cout << "TOKEN ID --> " << token.GetTokenId() << endl;
        cout << "LEXEMA --> " << token.GetLexema() << endl;
    }
}

void CompiladorController::analisar(Arquivo arquivo) {

//    AnalisadorLexico analisadorLexico;
//    while(!arquivo.IsEmpty()){
//        char caracter = arquivo.Prox_char();
//        Token token = analisadorLexico.Analex(caracter);
//        arquivo.GravaToken(token);
//    }
}