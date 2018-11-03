
#include "../Model/Compilador.h"
#include "../Model/Arquivo.h"

// TODO: organizar melhor a leitura do proximo char, por enquanto só defini os estados do analex
// TODO: organizar melhor o switch-case. O compilador fica apontando que os states são inacesiveis.

Token Compilador::Analex(char c)
{
    int state = 0;
    string lex = " ";
    Arquivo file("", "");

    Token token("NOT_IMP", lex);

    switch (state)
    {
        case 0:

            if(isdigit(c))
            {
                lex += c;
                state = 1;
            }
            else if(c == '\'')
            {
                lex += c;
                state = 4;
            }
            else if(c == '\"')
            {
                lex += c;
                state = 6;
            }
            else if(c == '+')
            {
                lex += c;
                state = 8;
            }
            else if(c == '-')
            {
                lex += c;
                state = 9;
            }
            else if(c == '/')
            {
                lex += c;
                state = 10;
            }
            else if(c == '%')
            {
                lex += c;
                state = 11;
            }
            else if(c == '<')
            {
                lex += c;
                state = 12;
            }
            else if(c == '>')
            {
                lex += c;
                state = 13;
            }
            else if(c == '=')
            {
                lex += c;
                state = 14;
            }
            else if(c == '*')
            {
                lex += c;
                state = 15;
            }
            else if(c == '!')
            {
                lex += c;
                state = 16;
            }
            else if(c == '&')
            {
                lex += c;
                state = 17;
            }
            else if(c == '|')
            {
                lex += c;
                state = 18;
            }

        //break;

        case 1:

            c = file.Prox_char();

            while(isdigit(c))
            {
                lex += c;
            }

            if(c == '.')
            {
                lex += c;
                state = 2;
            }
            else
            {
                token = Token("L_INT", lex);
                return token;
            }

        case 2:

            c = file.Prox_char();

            if(isdigit(c))
            {
                lex += c;
                state = 3;
            }
            else
            {
                // TODO: definir uma mensagem de erro, talvez uma Exception pra ficar legal
            }

        case 3:

            c = file.Prox_char();

            while(isdigit(c))
            {
                lex += c;
            }

            token = Token("L_FLT", lex);
            //return token;

        case 4:

            c = file.Prox_char();

            if(c != '\'')
            {
                lex += c;
                state = 5;
            }
            else
            {
                // TODO:  definir uma mensagem de erro, talvez uma Exception pra ficar legal
            }

        case 5:

            c = file.Prox_char();

            if(c == '\'')
            {
                lex += c;

                token = Token("L_CHAR", lex);
                return token;
            }
            else
            {
                // TODO:  definir uma mensagem de erro, talvez uma Exception pra ficar legal
            }

        case 6:

            c = file.Prox_char();

            if(c != '\"')
            {
                lex += c;
                state = 7;
            }
            else
            {
                // TODO:  definir uma mensagem de erro, talvez uma Exception pra ficar legal
            }

        case 7:

            while(c != '\"')
            {
                lex += c;
                c = file.Prox_char();
            }

            lex += c;
            token = Token("L_STR", lex);

        case 8:

            c = file.Prox_char();

            if(c == '+')
            {
                lex += c;

                token = Token("O_INC", lex);
            }
            else if(c == '=')
            {
                lex += c;

                token = Token("O_MEQ", lex);
            }
            else
            {
                token = Token("O_SUM", lex);
            }

        case 9:

            c = file.Prox_char();

            if(c == '-')
            {
                lex += c;

                token = Token("O_SNC", lex);
            }
            else if(c == '=')
            {
                lex += c;

                token = Token("O_SEQ", lex);
            }
            else
            {
                token = Token("O_SUB", lex);
            }

        case 10:

            c = file.Prox_char();

            if(c == '=')
            {
                lex += c;

                token = Token("O_DEQ", lex);
            }
            else if(c == '/')
            {
                lex += c;

                token = Token("T_CMT", lex);
            }
            else
            {
                token = Token("O_DIV", lex);
            }

        case 11:

            if(c == '=')
            {
                lex += c;

                token = Token("O_REQ", lex);
            }
            else
            {
                token = Token("O_MOD", lex);
            }

        case 12:

            if(c == '=')
            {
                lex += c;

                token = Token("O_MAE", lex);
            }
            else
            {
                token = Token("O_SMA", lex);
            }

        case 13:

            if(c == '=')
            {
                lex += c;

                token = Token("O_MEE", lex);
            }
            else
            {
                token = Token("O_SME", lex);
            }

        case 14:

            if(c == '=')
            {
                lex += c;

                token = Token("O_SEE", lex);
            }
            else
            {
                token = Token("O_ATR", lex);
            }

        case 15:

            if(c == '=')
            {
                lex += c;

                token = Token("O_MMQ", lex);
            }
            else
            {
                token = Token("O_MUL", lex);
            }

        case 16:

            if(c == '=')
            {
                lex += c;

                token = Token("O_DIF", lex);
            }
            else
            {
                token = Token("O_NOT", lex);
            }

        case 17:

            if(c == '$')
            {
                lex += c;

                token = Token("O_AND", lex);
            }
            else
            {
                // TODO:  definir uma mensagem de erro, talvez uma Exception pra ficar legal
            }

        case 18:

            if(c == '|')
            {
                lex += c;

                token = Token("O_COR", lex);
            }
            else
            {
                // TODO:  definir uma mensagem de erro, talvez uma Exception pra ficar legal
            }
    }

    return token;
}
