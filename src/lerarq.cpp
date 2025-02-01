#include "lerarq.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib> 
#include <cctype>  

using namespace std;

int lerarq() {

    int num;
    int opcode_num;
    bool valido = true;

    ifstream file("../entrada.in"); 
    if (!file) {
        cerr << "Erro ao abrir o arquivo!\n";
        exit(1);
    }

    int cont = 0;
    string line;

    ofstream outfile("../saida.out");
    if (!outfile) {
        cerr << "Erro ao abrir o arquivo para escrita!" << endl;
        exit(1);
    }

    streambuf* orig_buf = cout.rdbuf();    
    cout.rdbuf(outfile.rdbuf());             

    while (getline(file, line)) {

        valido = true;  

        for (char c : line) {
            if (!isxdigit(c)) {
                valido = false;
                break;
            }
        }

        if (valido) {
            if (line.size() == 4 && !line.empty()) {
                cont++;

                if (sscanf(line.c_str(), "%x", &num) == 1) {
                   opcode_num = opcode(num); 
                   decoder(opcode_num, num);
                   cout << "\n";
                }
            }
        } else {
            
            cout << "Valor nao hexadecimal ou linha inválida: " << line << endl;
            cout << "Entrada invalida ou vazia\n," << cont << "\n";
        }

    }
    
    cout.rdbuf(orig_buf);
    
    outfile.close();
    file.close();

    return 0;
}

