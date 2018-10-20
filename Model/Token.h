#ifndef COMPILADORES_TOKEN_H
#define COMPILADORES_TOKEN_H

#include <string>

using namespace std;

class Token
{
public:

    inline Token(string token, string lexema): TokenId(token), Lexema(lexema) {}

    inline string GetTokenId()
    {
        return this->TokenId;
    };

    inline string GetLexema()
    {
        return this->Lexema;
    };

private:

    string TokenId;
    string Lexema;
};


#endif //COMPILADORES_TOKEN_H
