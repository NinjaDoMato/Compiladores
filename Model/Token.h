#ifndef COMPILADORES_TOKEN_H
#define COMPILADORES_TOKEN_H

#include <string>

class Token
{
public:

    Token(std::string token, std::string lexema, std::string log): TokenId(token), Lexema(lexema), Log(log) {}

    inline void SetTokenId(std::string tokenId)
    {
        this->TokenId = tokenId;
    };

    inline void SetLexema(std::string lexema)
    {
        this->Lexema = lexema;
    };

    inline std::string GetTokenId()
    {
        return this->TokenId;
    };

    inline std::string GetLexema()
    {
        return this->Lexema;
    };

    inline void SetLog(std::string log)
    {
        this->Log = log;
    };

    inline std::string GetLog()
    {
        return this->Log;
    };

private:

    std::string TokenId;
    std::string Lexema;
    std::string Log;
};


#endif //COMPILADORES_TOKEN_H
