
#include "../Model/Compilador.h"
#include "../Model/Arquivo.h"

// TODO: organizar melhor a leitura do proximo char, por enquanto só defini os estados do analex
// TODO: organizar melhor o switch-case. O compilador fica apontando que os states são inacesiveis.

Token Compilador::Analex(char c)
{
    int state = 0;
    string lex = " ";
    Arquivo file("", "");

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
                Token token("L_INT", lex);
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

            Token token ("L_FLT", lex);
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

                Token token("L_CHAR", lex);
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

            if(c == '\"')
            {
                lex += c;
                Token token("L_STR", lex);
                return token;
            }
            else
            {
                // TODO:  definir uma mensagem de erro, talvez uma Exception pra ficar legal
            }

        case 8:

            c = file.Prox_char();

            if(c == '+')
            {
                lex += c;

                Token token("O_INC", lex);
                return token;
            }
            else if(c == '=')
            {
                lex += c;

                Token token("O_MEQ", lex);
                return token;
            }
            else
            {
                Token token("O_SUM", lex);
                return token;
            }

        break;

        case 9:

            c = file.Prox_char();

            if(c == '-')
            {
                lex += c;

                Token token("O_SNC", lex);
                return token;
            }
            else if(c == '=')
            {
                lex += c;

                Token token("O_SEQ", lex);
                return token;
            }
            else
            {
                Token token("O_SUB", lex);
                return token;
            }

        break;

        case 10:

        break;
    }
}
