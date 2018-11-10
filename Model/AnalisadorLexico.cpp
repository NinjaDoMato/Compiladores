
#include <iostream>
#include <regex>
#include "AnalisadorLexico.h"
#include "Arquivo.h"

using namespace std;


// TODO: organizar melhor a leitura do proximo char, por enquanto só defini os estados do analex
// TODO: organizar melhor o switch-case. O compilador fica apontando que os states são inacesiveis.

/**
 *
 * @param c
 * @return
 */
Token AnalisadorLexico::Analex(char caracter) {
    if (this->Estado == 1) {
        if (isdigit(caracter)) {
            this->Estado = 2;
            this->Lexema.push_back(caracter);
            caracter = this->ArquivoEntrada.Prox_char();
        } else if (caracter == '+'){
            this->Estado = 10;
            this->Lexema.push_back(caracter);
            caracter = this->ArquivoEntrada.Prox_char();
        } else if (caracter == '-'){
            this->Estado = 11;
            this->Lexema.push_back(caracter);
            caracter = this->ArquivoEntrada.Prox_char();
        }
        
        else if (caracter == ' '){
            return Token("",this->Lexema, "Estado "+std::to_string(1));
        }

        else if(caracter == '\377' || caracter == '\000' || caracter == ' '){
            caracter = this->ArquivoEntrada.Prox_char();
        }
    } else if (Estado == 2) {
        if (isdigit(caracter) || caracter == '.') {
            while(isdigit(caracter)){
                this->Lexema.push_back(caracter);
                caracter = this->ArquivoEntrada.Prox_char();
            }
            if(caracter == '.'){
                this->Estado = 3;
                this->Lexema.push_back(caracter);
                caracter = this->ArquivoEntrada.Prox_char();
            } else {
                this->ArquivoEntrada.Ant_char();
                return Token("L_INT",this->Lexema, "Estado "+std::to_string(this->Estado));
            }
        } else {
            this->ArquivoEntrada.Ant_char();
            return Token("L_INT",this->Lexema, "Estado "+std::to_string(this->Estado));
        }
    } else if (Estado == 3){
        if(isdigit(caracter)) {
            this->Estado = 4;
            this->Lexema.push_back(caracter);
            caracter = this->ArquivoEntrada.Prox_char();
        }
    } else if (Estado == 4) {
        if(isdigit(caracter)) {
            while (isdigit(caracter)) {
                this->Lexema.push_back(caracter);
                caracter = this->ArquivoEntrada.Prox_char();
            }
            this->ArquivoEntrada.Ant_char();
            return Token("L_FLT",this->Lexema, "Estado "+std::to_string(this->Estado));
        } else {
            this->ArquivoEntrada.Ant_char();
            return Token("L_FLT",this->Lexema, "Estado "+std::to_string(this->Estado));
        }
    } else if(Estado == 10){
        if(caracter == '+'){
            return Token("O_INC",this->Lexema, "Estado "+std::to_string(this->Estado));
        } else if(caracter == '=') {
            return Token("O_MEQ",this->Lexema, "Estado "+std::to_string(this->Estado));
        } else {
            this->ArquivoEntrada.Ant_char();
            return Token("O_SUM",this->Lexema, "Estado "+std::to_string(this->Estado));
        }
    } else if(Estado == 11){
        if(caracter == '='){
            return Token("O_SEQ",this->Lexema, "Estado "+std::to_string(this->Estado));
        } else if(caracter == '-') {
            return Token("O_SNC",this->Lexema, "Estado "+std::to_string(this->Estado));
        } else {
            this->ArquivoEntrada.Ant_char();
            return Token("O_SUB",this->Lexema, "Estado "+std::to_string(this->Estado));
        }
    }
    return this->Analex(caracter);






//    vector<Token> tokens;
//    while (!arquivo.IsEmpty()) {
//        char c = arquivo.Prox_char();
//        int state = 0;
//        string lex = "";
//        lex.push_back(c);
//        Arquivo file("", "");
//        Token token("NOT_IMP", lex);
//        switch (state) {
//            case 0:
//                if (std::regex_match(&c, std::regex("a-zA-Z"))){
//
//                } else if (isdigit(c)) {
//                    lex += c;
//                    state = 1;
//                } else if (c == '\'') {
//                    lex += c;
//                    state = 4;
//                } else if (c == '\"') {
//                    lex += c;
//                    state = 6;
//                } else if (c == '+') {
//                    lex += c;
//                    state = 8;
//                } else if (c == '-') {
//                    lex += c;
//                    state = 9;
//                } else if (c == '/') {
//                    lex += c;
//                    state = 10;
//                } else if (c == '%') {
//                    lex += c;
//                    state = 11;
//                } else if (c == '<') {
//                    lex += c;
//                    state = 12;
//                } else if (c == '>') {
//                    lex += c;
//                    state = 13;
//                } else if (c == '=') {
//                    lex += c;
//                    state = 14;
//                } else if (c == '*') {
//                    lex += c;
//                    state = 15;
//                } else if (c == '!') {
//                    lex += c;
//                    state = 16;
//                } else if (c == '&') {
//                    lex += c;
//                    state = 17;
//                } else if (c == '|') {
//                    lex += c;
//                    state = 18;
//                }
//            case 1:
//                c = file.Prox_char();
//                while (isdigit(c)) {
//                    lex += c;
//                }
//                if (c == '.') {
//                    lex += c;
//                    state = 2;
//                } else {
//                    tokens.push_back(Token("L_INT", lex));
//                }
//            case 2:
//                c = file.Prox_char();
//                if (isdigit(c)) {
//                    lex += c;
//                    state = 3;
//                } else {
//                    // TODO: definir uma mensagem de erro, talvez uma Exception pra ficar legal
//                }
//            case 3:
//                c = file.Prox_char();
//                while (isdigit(c)) {
//                    lex += c;
//                }
//                token = Token("L_FLT", lex);
//                //return token;
//            case 4:
//                c = file.Prox_char();
//                if (c != '\'') {
//                    lex += c;
//                    state = 5;
//                } else {
//                    // TODO:  definir uma mensagem de erro, talvez uma Exception pra ficar legal
//                }
//            case 5:
//                c = file.Prox_char();
//                if (c == '\'') {
//                    lex += c;
//                    token = Token("L_CHAR", lex);
//                    tokens.push_back(Token("L_INT", lex));
//                } else {
//                    // TODO:  definir uma mensagem de erro, talvez uma Exception pra ficar legal
//                }
//            case 6:
//                c = file.Prox_char();
//                if (c != '\"') {
//                    lex += c;
//                    state = 7;
//                } else {
//                    // TODO:  definir uma mensagem de erro, talvez uma Exception pra ficar legal
//                }
//            case 8:
//                while (c != '\"') {
//                    lex += c;
//                    c = file.Prox_char();
//                }
//                lex += c;
//                token = Token("L_STR", lex);
//            case 9:
//                c = file.Prox_char();
//                if (c == '+') {
//                    lex += c;
//                    token = Token("O_INC", lex);
//                } else if (c == '=') {
//                    lex += c;
//                    token = Token("O_MEQ", lex);
//                } else {
//                    token = Token("O_SUM", lex);
//                }
//            case 10:
//                c = file.Prox_char();
//
//                if (c == '-') {
//                    lex += c;
//
//                    token = Token("O_SNC", lex);
//                } else if (c == '=') {
//                    lex += c;
//
//                    token = Token("O_SEQ", lex);
//                } else {
//                    token = Token("O_SUB", lex);
//                }
//            case 11:
//                c = file.Prox_char();
//
//                if (c == '=') {
//                    lex += c;
//
//                    token = Token("O_DEQ", lex);
//                } else if (c == '/') {
//                    lex += c;
//
//                    token = Token("T_CMT", lex);
//                } else {
//                    token = Token("O_DIV", lex);
//                }
//            case 12:
//
//                if (c == '=') {
//                    lex += c;
//
//                    token = Token("O_REQ", lex);
//                } else {
//                    token = Token("O_MOD", lex);
//                }
//            case 13:
//
//                if (c == '=') {
//                    lex += c;
//
//                    token = Token("O_MAE", lex);
//                } else {
//                    token = Token("O_SMA", lex);
//                }
//            case 14:
//
//                if (c == '=') {
//                    lex += c;
//
//                    token = Token("O_MEE", lex);
//                } else {
//                    token = Token("O_SME", lex);
//                }
//            case 15:
//
//                if (c == '=') {
//                    lex += c;
//
//                    token = Token("O_SEE", lex);
//                } else {
//                    token = Token("O_ATR", lex);
//                }
//            case 16:
//
//                if (c == '=') {
//                    lex += c;
//
//                    token = Token("O_MMQ", lex);
//                } else {
//                    token = Token("O_MUL", lex);
//                }
//            case 17:
//                if (c == '=') {
//                    lex += c;
//
//                    token = Token("O_DIF", lex);
//                } else {
//                    token = Token("O_NOT", lex);
//                }
//            case 18:
//                if (c == '$') {
//                    lex += c;
//
//                    token = Token("O_AND", lex);
//                } else {
//                    // TODO:  definir uma mensagem de erro, talvez uma Exception pra ficar legal
//                }
//            case 19:
//                if (c == '|') {
//                    lex += c;
//
//                    token = Token("O_COR", lex);
//                } else {
//                    // TODO:  definir uma mensagem de erro, talvez uma Exception pra ficar legal
//                }
//        }
//    }
}
