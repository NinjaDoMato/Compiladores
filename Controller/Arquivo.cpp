#include "../Model/Arquivo.h"

Arquivo::Arquivo(string inputFile, string outputFile)
{
    this->Log = ofstream(outputFile);
    this->File = ifstream(inputFile);

    if (this->File.is_open())
    {
        while (!this->File.eof())
        {
            this->Buffer.push_back((char) (this->File.get()));
        }
        this->File.close();
    }
}

char Arquivo::Prox_char()
{
    char prox = this->Buffer.back();
    this->Buffer.pop_back();

    return prox;
}

void Arquivo::Grava_token(string estado, Token token)
{
    if (this->Log.is_open())
    {
        this->Log << estado << "    " << token.GetTokenId() << "    " << token.GetLexema() << endl;
    }
    this->Log.close();
}

