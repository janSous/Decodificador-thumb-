
#include <iostream>
#include "decodificador_cond.h"
using std::string;
using std::cout;

void decodificador_cond(int num)
{
   int cond = num & 0xF00; // pega os bits 11-8 (cond)

   switch(cond)
   {
        case 0x0:
            cout << "EQ";
        break;
        
        case 0x1:
            cout << "NE";
        break;

        case 0x2:
            cout << "CS_HS";
        break;

        case 0x3:
            cout << "CC_LO";
        break;

        case 0x4:
            cout << "MI";
        break;

        case 0x5:
            cout << "PL";
        break;

        case 0x6:
            cout << "VS";
        break;

        case 0x7:
            cout << "VC";
        break;

        case 0x8:
            cout << "HI";
        break;

        case 0x9:
            cout << "LS";
        break;

        case 0xA:
            cout << "GE";
        break;

        case 0xB:
            cout << "LT";
        break; 

        case 0xC:
            cout << "GT";
        break;

        case 0xD:
            cout << "LE";
        case 0xE:
            cout << "Undefined";
        case 0xF:
            cout << "SWI, ";
            int immed = num & 0x00FF;
            cout << std::hex << immed;
        break;
   }  
}
