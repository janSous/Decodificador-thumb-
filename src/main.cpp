#include <iostream>
#include "decodificador.h"
#include "string_to_hexa.h"
using namespace std;

int main()
{
    std::cout << "============ DECODIFICADOR THUMB =============" << std::endl;
    int choice;

    menu:
    cout << "Digite uma opção: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            validar();
            goto menu;
        default:
            cout << "saindo..." << endl;
    }

}