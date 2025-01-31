#include "string_to_hexa.h"
#include "decodificador.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <iostream>

void validar() {
    int num;
    int opcode_num;
    int choice;

digite:
    
    std::string* hexa = new std::string;
    std::cout << "Digite uma string hexadecimal (4 caracteres): ";
    std::getline(std::cin, *hexa);


    if (hexa->empty()) {
        std::cout << "\nEntrada vazia. Insira um valor.\n";
        system("clear");
        delete hexa;
        goto digite;
    }

    bool valido = true;

    
    if (hexa->size() != 4) {
        valido = false;
        std::cout << "Número inválido. Digite outro número.\n";
    } else {
        for (char c : *hexa) {
            if (!isxdigit(c)) {
                valido = false;
                break;
            }
        }
    }

    if (valido) {
        if (sscanf(hexa->c_str(), "%x", &num) == 1) {
            opcode_num = opcode(num); 
            decoder(opcode_num, num);  

            std::cout << "\nDecodificado. Digite 1 para inserir um novo valor ou qualquer outro para sair: ";
            std::cin >> choice;

            
            if (choice == 1) {
                goto digite;
            }
        } else {
            std::cout << "Erro: A string não contém um número hexadecimal válido.\n";
        }
    } else {
        std::cout << "Número inválido. Digite outro número.\n";
        system("clear");
        delete hexa;
        goto digite;
    }

    std::cout << "\nFinal da decodificação. Voltando para o menu principal...\n";

    delete hexa;
}