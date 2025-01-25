#include <iostream>
#include "decodificador_reg.h"
using std::cout;

std::string decoder_reg(int reg)
{
    switch(reg)
    {
        case 0:
            cout << "R0";
        break;

        case 1:
            cout << "R1";
        break;

        case 2:
            cout << "R2";
        break;

        case 3:
            cout << "R3";
        break;

        case 4:
            cout << "R4";
        break;

        case 5:
            cout << "R5";
        break;
        
        case 6:
            cout << "R6";
        break;

        case 7:
            cout << "R7";
        break;

        case 8:
            cout << "R8";
        break;

        case 9:
            cout << "R9";
        break;

        case 10:
            cout << "R10";
        break;

        case 11:
            cout << "R11";
        break;

        case 12:
            cout << "R12";
        break;

        case 13:
            cout << "SP";
        break;

        case 14:
            cout << "LR";
        break;

        case 15:
            cout << "PC";
        break;
    }
}

void nome_reg(int num, int type)
{
    int reg = 0;
    int imed = 0;

    switch(type)
    {
        case TYPE_1: // Ld = #imediato << Lm| Ld = Lm >> #imediato
            reg = num & 0x7; //Bits 2-0(Ld)
            cout << decoder_reg(reg) << ", ";
            reg = num & 0x78; //Pega os bits 5-3(Lm)
            cout << decoder_reg(reg) << ", ";
            imed = num & 0x7C0; // Bits 10-6(immed5)
            cout << '#' << imed;
        break;

        case TYPE_1_1: // Ld, [Lm, #immed]
            reg = num & 0x7; //Bits 2-0(Ld)
            cout << decoder_reg(reg) << ", ";
            reg = num & 0x78; // Bits 5-3(Lm)
            cout << "[ " << decoder_reg(reg);
            imed = num & 0x7C0; //Bits 10-6(immed5)
            cout << ", #" << imed << "]";
        break;

        case TYPE_2: // Ld, Lm, Ln
            reg = num & 0x7; //Ld(bits 2-0)
            cout << decoder_reg(reg) << ", ";
            reg = num & 0x78; //Ln(bits 5-3)
            cout << decoder_reg(reg) << ", ";
            reg = num & 0x1C0; // Lm(bits 8-5)
            cout << decoder_reg(reg);
        break;

        case TYPE_3: // Ld, Ln, immed
            reg = num & 0x7; //Ld(bits 2-0)
            cout << decoder_reg(reg) << ", ";
            reg = num & 0x78;// Ln(bits 5-3)
            cout << decoder_reg(reg) << ", #";
            imed = num & 0x1C0; // immed3(bits 8-6)
            cout << imed;
        break;

        case TYPE_4: // Ln, #immed/ Ld,#immed
            reg = num & 0x700; // Ld/Ln(bits 10-8)
            cout << decoder_reg(reg) << ", #";
            imed = num & 0xFF; // immed8(bits 7-0)
            cout << imed;
        break;

        case TYPE_5: // Ld|Ln|Hd & 7|Hn & 7, Lm|Ls|Hm & 7
            reg = num & 0x7; //Ld|Ln|Hd & 7
            cout << decoder_reg(reg) << ", "



        

    }
}