#include <iostream>
#include "decodificador.h"
#include "string_to_hexa.h"
#include "lerarq.h"

using namespace std;

int main()
{
    std::cout << "============ DECODIFICADOR THUMB =============" << std::endl;
    int choice;

    menu:
    cout << "Digite uma opção: ";
    cout << "\n [1] para decodificar uma instrucao: \n [2] para ler um arquivo de instrucoes;\n [3] para sair; \n \n";
    cout << "Insira:"; 
    cin >> choice;

    switch(choice)
    {
        case 1:
            validar();
            goto menu;
        case 2:
            lerarq();
            goto menu;
        case 3:
            cout << "saindo..." << endl;
            system("clear");
            exit(0);

       

    }

}