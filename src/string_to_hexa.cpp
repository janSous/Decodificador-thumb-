#include "string_to_hexa.h"
#include "decodificador.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <iostream>



void validar(){

int num;
int opcode_num; 
std::string hexa;
int j = 0; 
int count=0;
int valido = 0; 
int input;
int choice;


digite:
printf("Digite um valor hexa: ");
std::cin >> num;

std::string* hexa = new std::string;
std::cout << "Digite uma string: ";
    getline(std::cin, *hexa);
if(hexa.size() == 0)
{
    std::cout << "\nEntrada vazia. Insira um valor. \n";
    system("/usr/bin/clear");
    goto digite;
}


while (hexa[j] != '\0')
{
    count++;
    j++;
}


for (int i = 0; i < 4; i++){
    if (isxdigit(hexa[i] == true)){
        valido++;
    }
    
    else
    {
        std::cout << "\nNumero inválido ou incompleto\n";
        std::cout << "Digite outro numero.\n";
        goto digite;
        break;
    }

    

    if (valido == 4)
    {
        num = std::stoi(hexa);
        opcode_num = opcode(num);
        decoder(opcode_num, num);

        std::cout << "\n Decodificado. Digite 1 pra inserir um novo valor ou qualquer outro para sair: ";
        std::cin >> choice;

        if(choice == 1)
        {
            goto digite;
        }
    }
    else
    {
        std::cout << "Numero invalido.\n";
        system("usr/bin/clear");
        goto digite;
    }

    std::cout << "\nFinal da decodificação. Voltando pro menu principal..." << std::endl;
    
    
}

}