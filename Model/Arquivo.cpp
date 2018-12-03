
#include <iostream>
#include <string>
#include "Arquivo.h"
using namespace std;

/**
 *
 * @param inputFile
 * @param outputFile
 */
Arquivo::Arquivo(string inputFile, string outputFile)
{
    //this->Log = ofstream(outputFile, ios_base::app);
    this->File = ifstream(inputFile);
    vector<char> auxiliar;

    if (this->File.is_open())
    {
        while (!this->File.eof())
        {
            auxiliar.push_back((char) (this->File.get()));
        }
        this->File.close();
    }

    for(int i=auxiliar.size(); i>=0;i--){
        this->Buffer.push_back(auxiliar[i]);
    }
}

/**
 *
 * @return
 */
char Arquivo::Prox_char()
{
    char prox = this->Buffer.back();
    this->Buffer.pop_back();
    // Guarda o ultimo elemento que foi removido
    UltimaLeitura = prox;
    return prox;
}

/**
 *
 * @return
 */
void Arquivo::Ant_char(){
    this->Buffer.push_back(this->UltimaLeitura);
}

/**
 *
 * @param estado
 * @param token
 */
void Arquivo::Grava_token(string estado, Token token)
{
    //this->Log.open("saida.txt", ios::app);

    ofstream arquivo("saida", ios_base::trunc);

    if (arquivo.is_open())
    {
        std::cout << "Arquivo de texto aberto com sucesso!" << std::endl;
    }
    else
        std::cout << "Erro ao abrir arquivo de texto.";

    arquivo.close();
}

void GravaToken(std::vector<Token> tokens){
    ofstream arquivo("saida", ios_base::trunc);

    if (arquivo.is_open())
    {
        for(int i=0; i<tokens.size();i++) {

            string linha = "|"+tokens[i].GetLog()+"|"+tokens[i].GetTokenId()+"|"+tokens[i].GetLexema()+"|";
            arquivo << linha;
        }

    }
    else
        std::cout << "Erro ao abrir arquivo de texto.";

    arquivo.close();
}

/**
 *
 * @return
 */
bool Arquivo::IsEmpty() {
    return this->Buffer.size() == 0;
}
