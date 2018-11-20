
#include <iostream>
#include <regex>
#include "AnalisadorLexico.h"
#include "Arquivo.h"
#include "../Enuns/EstadoEnum.h"

using namespace std;


/**
 * 
 * @param c
 * @return Token
 */
 
 //TODO: Verificar se estrutura de verificação dos estados não fica mais clara 
 //      utilizando Switch-Case (considerando a estrutura inicial do professor)
 
Token AnalisadorLexico::Analex(char caracter) {

    if (this->Estado == static_cast<int>(EstadoEnum::INICIAL)) 
    {
        if (isdigit(caracter)) 
        {
            this->Estado = static_cast<int>(EstadoEnum::ESTADO_NUM_1);
            this->Lexema.push_back(caracter);
        }
        else if (caracter == '+') 
        {
            this->Estado = static_cast<int>(EstadoEnum::ESTADO_SOMA);
            this->Lexema.push_back(caracter);
        }
        else if (caracter == '-') 
        {
            this->Estado = static_cast<int>(EstadoEnum::ESTADO_SUBTRACAO);
            this->Lexema.push_back(caracter);
        }
        else if (caracter == '<') 
        {
            this->Estado = static_cast<int>(EstadoEnum::ESTADO_MENOR);
            this->Lexema.push_back(caracter);
        }
        else if (caracter == '>') 
        {
            this->Estado = static_cast<int>(EstadoEnum::ESTADO_MAIOR);
            this->Lexema.push_back(caracter);
        }
        else if (caracter == '=') 
        {
            this->Estado = static_cast<int>(EstadoEnum::ESTADO_IGUAL);
            this->Lexema.push_back(caracter);
        }
        else if (caracter == '*') 
        {
            this->Estado = static_cast<int>(EstadoEnum::ESTADO_MULTIPLICACAO);
            this->Lexema.push_back(caracter);
        }
        else if (caracter == '%') 
        {
            this->Estado = static_cast<int>(EstadoEnum::ESTADO_PORCENTAGEM);
            this->Lexema.push_back(caracter);
        }
        else if (caracter == '/') 
        {
            this->Estado = static_cast<int>(EstadoEnum::ESTADO_DIVISAO);
            this->Lexema.push_back(caracter);
        } 
        else if (caracter == '!') 
        {
            this->Estado = static_cast<int>(EstadoEnum::ESTADO_DIFERENTE);
            this->Lexema.push_back(caracter);
        }
        else if (caracter == '&') 
        {
            this->Estado = static_cast<int>(EstadoEnum::ESTADO_E);
            this->Lexema.push_back(caracter);
        }
        else if (caracter == '|') 
        {
            this->Estado = static_cast<int>(EstadoEnum::ESTADO_OU);
            this->Lexema.push_back(caracter);
        }
        else if (caracter == '\'')
        {
            this->Estado = static_cast<int>(EstadoEnum::ESTADO_CHAR_1);
            this->Lexema.push_back(caracter);
            caracter = this->ArquivoEntrada.Prox_char();

        }
        else if (caracter == '\"') 
        {
            this->Estado = static_cast<int>(EstadoEnum::ESTADO_STR_1);
            this->Lexema.push_back(caracter);
            caracter = this->ArquivoEntrada.Prox_char();
        }
        
        
        // Exceções
        else if (caracter == ' ') 
        {
            return Token("", this->Lexema, "Estado " + std::to_string(1));
        }

        // Recebe o proximo caracter
        caracter = this->ArquivoEntrada.Prox_char();

    }
    else if (Estado == static_cast<int>(EstadoEnum::ESTADO_NUM_1)) 
    {
        if (isdigit(caracter) || caracter == '.') 
        {
            while (isdigit(caracter)) 
            {
                this->Lexema.push_back(caracter);
                caracter = this->ArquivoEntrada.Prox_char();
            }
            if (caracter == '.') 
            {
                this->Estado = static_cast<int>(EstadoEnum::ESTADO_NUM_2);
                this->Lexema.push_back(caracter);
                caracter = this->ArquivoEntrada.Prox_char();
            } 
            else 
            {
                this->ArquivoEntrada.Ant_char();
                return Token("L_INT", this->Lexema, "Estado " + std::to_string(this->Estado));
            }
            
        }
        else 
        {
            this->ArquivoEntrada.Ant_char();
            return Token("L_INT", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
        
    } 
    else if (Estado == static_cast<int>(EstadoEnum::ESTADO_NUM_2)) 
    {
        if (isdigit(caracter)) 
        {
            this->Estado = static_cast<int>(EstadoEnum::ESTADO_NUM_3);
            this->Lexema.push_back(caracter);
            caracter = this->ArquivoEntrada.Prox_char();
        }
    } 
    else if (Estado == static_cast<int>(EstadoEnum::ESTADO_NUM_3)) 
    {
        if (isdigit(caracter)) 
        {
            while (isdigit(caracter)) 
            {
                this->Lexema.push_back(caracter);
                caracter = this->ArquivoEntrada.Prox_char();
            }
            this->ArquivoEntrada.Ant_char();
            return Token("L_FLT", this->Lexema, "Estado " + std::to_string(this->Estado));
        } 
        else 
        {
            this->ArquivoEntrada.Ant_char();
            return Token("L_FLT", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
    } 
    else if (Estado == static_cast<int>(EstadoEnum::ESTADO_SOMA)) 
    {
        if (caracter == '+') 
        {
            this->Lexema.push_back(caracter);
            return Token("O_INC", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
        else if (caracter == '=') 
        {
            this->Lexema.push_back(caracter);
            return Token("O_MEQ", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
        else
        {
            this->ArquivoEntrada.Ant_char();
            return Token("O_SUM", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
    } 
    else if (Estado == static_cast<int>(EstadoEnum::ESTADO_SUBTRACAO)) 
    {
        if (caracter == '=') 
        {
            this->Lexema.push_back(caracter);
            return Token("O_SEQ", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
        else if (caracter == '-') 
        {
            this->Lexema.push_back(caracter);
            return Token("O_SNC", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
        else 
        {
            this->ArquivoEntrada.Ant_char();
            return Token("O_SUB", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
    }
    else if (Estado == static_cast<int>(EstadoEnum::ESTADO_MENOR)) 
    {
        if (caracter == '=') 
        {
            this->Lexema.push_back(caracter);
            return Token("O_MAE", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
        else 
        {
            this->ArquivoEntrada.Ant_char();
            return Token("O_SMA", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
    } 
    else if (Estado == static_cast<int>(EstadoEnum::ESTADO_MAIOR)) 
    {
        if (caracter == '=') 
        {
            this->Lexema.push_back(caracter);
            return Token("O_MEE", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
        else 
        {
            this->ArquivoEntrada.Ant_char();
            return Token("O_SME", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
    }
    else if (Estado == static_cast<int>(EstadoEnum::ESTADO_IGUAL)) 
    {
        if (caracter == '=') 
        {
            this->Lexema.push_back(caracter);
            return Token("O_SEE", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
        else 
        {
            this->ArquivoEntrada.Ant_char();
            return Token("O_ATR", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
    } 
    else if (Estado == static_cast<int>(EstadoEnum::ESTADO_MULTIPLICACAO)) 
    {
        if (caracter == '=') 
        {
            this->Lexema.push_back(caracter);
            return Token("O_MMQ", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
        else 
        {
            this->ArquivoEntrada.Ant_char();
            return Token("O_MUL", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
    } 
    // TODO: Este estado esta duplicado? - Comentei e mudei para o que achei correto
    // else if (Estado == static_cast<int>(EstadoEnum::ESTADO_DIVISAO)) 
    else if (Estado == static_cast<int>(EstadoEnum::ESTADO_RESTO)) // <-- era isso? 
    {
        if (caracter == '=') 
        {
            this->Lexema.push_back(caracter);
            return Token("O_REQ", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
        else 
        {
            this->ArquivoEntrada.Ant_char();
            return Token("O_MOD", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
    } 
    else if (Estado == static_cast<int>(EstadoEnum::ESTADO_DIVISAO)) 
    {
        if (caracter == '=')
        {
            this->Lexema.push_back(caracter);
            return Token("O_DEQ", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
        else if (caracter == '/') 
        {
            this->Lexema.push_back(caracter);
            return Token("O_CMT", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
        else 
        {
            this->ArquivoEntrada.Ant_char();
            return Token("O_DIV", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
    } 
    else if (Estado == static_cast<int>(EstadoEnum::ESTADO_DIFERENTE)) 
    {
        if (caracter == '=') 
        {
            this->Lexema.push_back(caracter);
            return Token("O_DIF", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
        else 
        {
            this->ArquivoEntrada.Ant_char();
            return Token("O_NOT", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
    } 
    else if (Estado == static_cast<int>(EstadoEnum::ESTADO_E)) 
    {
        if (caracter == '&') 
        {
            this->Lexema.push_back(caracter);
            return Token("O_AND", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
    } 
    else if (Estado == static_cast<int>(EstadoEnum::ESTADO_OU)) 
    {
        if (caracter == '|') 
        {
            this->Lexema.push_back(caracter);
            return Token("O_COR", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
    }
    else if (Estado == static_cast<int>(EstadoEnum::ESTADO_CHAR_1))
    {
        if(caracter != '\'')
        {
            this->Lexema.push_back(caracter);
            this->Estado = static_cast<int>(EstadoEnum::ESTADO_CHAR_2);
            caracter = this->ArquivoEntrada.Prox_char();
        }
    }
    else if (Estado == static_cast<int>(EstadoEnum::ESTADO_CHAR_2))
    {
        if(caracter == '\')
        {
            this->Lexema.push_back(caracter);
            return Token("L_CHR", this->Lexema, "Estado " + std::to_string(this->Estado));
        }
        else
        {
            // TODO: Verificar com o Winderson o que fazer com os erros.
        }
    }
    else if (Estado == static_cast<int>(EstadoEnum::ESTADO_STR_1))
    {
        if(caracter != '\"')
        {
            this->Lexema.push_back(caracter);
            this->Estado = static_cast<int>(EstadoEnum::ESTADO_STR_2);
            caracter = this->ArquivoEntrada.Prox_char();
        }
    }
    else if(Estado == static_cast<int>(EstadoEnum::ESTADO_STR_2))
    {
        while(caracter != '\"')
        {
            this->Lexema.push_back(caracter);
            caracter = this->ArquivoEntrada.Prox_char();
        }
        
        this->Lexema.push_back(caracter);
        return Token("L_STR", this->Lexema, "Estado " + std::to_string(this->Estado));
    }
           
    return this->Analex(caracter);
}
