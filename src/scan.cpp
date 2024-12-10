#include <iostream>
using std::cerr;
using std::endl;
using std::cin;
using std::cout;
using std::ios;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;

int main()
{
    ifstream inputFile("entrada.in",ios::in);
    ofstream outputFile("saida.out",ios::out);

    string num_hex;

    if(!inputFile)
    {
        cout << "Erro. Arquivo de entrada não foi aberto." << endl;
        return 1;
    }

    if(!outputFile)
    {
        cout << "Erro. Arquivo de saida não foi aberto." << endl;
        return 1;
    }


    while(inputFile >> num_hex)
    {
        outputFile << num_hex << endl;;
    }

    return 0;
}