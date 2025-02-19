#include <iostream>
#include "decodificador_reg.h"
using std::cout;

//Função auxiliar
void aux(int cont)
{
    if(cont != 0)
        cout << ", ";
}

std::string decoder_reg(int reg)
{
    std::string s;
    switch(reg)
    {
        case 0:
            s = "R0";

        break;

        case 1:
            s = "R1";
        break;

        case 2:
            s = "R2";
        break;

        case 3:
            s = "R3";
        break;

        case 4:
            s = "R4";
        break;

        case 5:
            s = "R5";
        break;
        
        case 6:
            s = "R6";
        break;

        case 7:
            s = "R7";
        break;

        case 8:
            s = "R8";
        break;

        case 9:
            s = "R9";
        break;

        case 10:
            s = "R10";
        break;

        case 11:
            s = "R11";
        break;

        case 12:
            s = "R12";
        break;

        case 13:
            s = "SP";
        break;

        case 14:
            s = "LR";
        break;

        case 15:
            s = "PC";
        break;
    }

    return s;

}

void nome_reg(int num, int types)
{
    int reg = 0;
    int imed = 0;
    int cont = 0;

    switch(types)
    {
        case TYPE_1: // Ld = #imediato << Lm| Ld = Lm >> #imediato
            reg = num & 0x7; //Bits 2-0(Ld)
            cout << decoder_reg(reg) << ", ";
            reg = ((num & 0x38) >> 3); //Pega os bits 5-3(Lm)
            cout << decoder_reg(reg) << ", ";
            imed = ((num & 0x7C0) >> 6); // Bits 10-6(immed5)
            cout << '#' << imed;
        break;

        case TYPE_1_1: // Ld, [Lm, #immed]
            reg = num & 0x7; //Bits 2-0(Ld)
            cout << decoder_reg(reg) << ", ";
            reg = ((num & 0x38) >> 3); // Bits 5-3(Lm)
            cout << "[ " << decoder_reg(reg);
            imed = ((num & 0x7C0) >> 6); //Bits 10-6(immed5)
            cout << ", #" << imed << "]";
        break;

        case TYPE_2: // Ld, Lm, Ln
            reg = num & 0x7; //Ld(bits 2-0)
            cout << decoder_reg(reg) << ", ";
            reg = ((num & 0x38) >> 3); //Ln(bits 5-3)
            cout << decoder_reg(reg) << ", ";
            reg = ((num & 0x1C0) >> 6); // Lm(bits 8-6)
            cout << decoder_reg(reg);
        break;

        case TYPE_3: // Ld, Ln, immed
            reg = num & 0x7; //Ld(bits 2-0)
            cout << decoder_reg(reg) << ", ";
            reg = ((num & 0x38) >> 3);// Ln(bits 5-3)
            cout << decoder_reg(reg) << ", #";
            imed = ((num & 0x1C0) >> 6); // immed3(bits 8-6)
            cout << imed;
        break;

        case TYPE_4: // Ln, #immed/ Ld,#immed
            reg = ((num & 0x0700) >> 8); // Ld/Ln(bits 10-8)
            cout << decoder_reg(reg) << ", #";
            imed = num & 0xFF; // immed8(bits 7-0)
            cout << imed;
        break;

        case TYPE_4_1: //Ld, [pc, #immed*4]
            reg = ((num & 0x700) >> 8); //Ld(bits 10-8)
            cout << decoder_reg(reg) << ", [" << 
            decoder_reg(15) << ", #";
            imed = num & 0xFF; //immed8(bits 7-0)
            cout << imed << "]";
        break;

        case TYPE_4_2: //Ld, [sp, #immed*4]
            reg = ((num & 0x700) >> 8); //Ld(bits 10-8)
            cout << decoder_reg(reg) << ", [" <<
            decoder_reg(14) << ", #";
            imed = num & 0xFF; //immed8(bits 7-0)
            cout << imed << "]";

        case TYPE_5: // Ld|Ln|Hd & 7|Hn & 7, Lm|Ls|Hm & 7
            reg = num & 0x7; //Ld|Ln|Hd&7 (bits 2-0)
            cout << decoder_reg(reg) << ", ";
            reg = ((num & 0x38) >> 3); // Lm|Ls|Hm&7 (bits 5-3)
            cout << decoder_reg(reg);
        break;

        case TYPE_6_1: // PUSH|POP
            reg = num & 0x1FF; //Conj. de registradores + pc/lr (bits 8-0)

             cout << " {";

            if(reg & 0x1 == 1)
            {
                cout << decoder_reg(0);
                cont ++;
            }

            if(((reg >> 1) & 0x1) == 0x1)
            {
                aux(cont);
                cout << decoder_reg(1);
                cont++;
            }

            if(((reg >> 2) & 0x1) == 0x1)
            {
                aux(cont);
                cout << decoder_reg(2);
                cont++;
            }
               
            if(((reg >> 3) & 0x1) == 0x1)
            {
                aux(cont);
                cout << decoder_reg(3);
                cont++;
            }
                
            if(((reg >> 4) & 0x1) == 0x1)
            {
                aux(cont);
                cout << decoder_reg(4);
                cont++;
            }
               
            if(((reg >> 5) & 0x1) == 0x1)
            {
                aux(cont);
                cout << decoder_reg(5);
                cont++;
            }
                
            if(((reg >> 6) & 0x1) == 0x1)
            {
                aux(cont);
                cout << decoder_reg(6);
                cont++;
            }
                
            if(((reg >> 7) & 0x1) == 0x1)
            {
                aux(cont);
                cout << decoder_reg(7);
                cont++;
            }
                
            if(((reg >> 8) & 0x1) == 0x1)
            {
                if(((num >> 8) & 0x1) == 0x1)
                {
                    aux(cont);
                    cout << decoder_reg(14);
                }
                else
                {
                    aux(cont);
                    cout << decoder_reg(15);
                }
                
            }
                 
            cout << "}";
        break;

        case TYPE_7: // BKPT #immed8
            imed = num & 0xFF; // immed8(bits 7-0)
            cout << " #" << imed*2 + 4;
        break;
        
        case TYPE_8: //B #adress
            imed = num & 0x7FF; //offset com sinal(10-0)
            imed = imed*2 + 4;
            cout << " #" << imed;
        break;
         case TYPE_9: //BlX #adress32
            imed = ((num & 0x7FE) >> 1); //Imed10(bits 11-1)
            imed = imed*4;
            imed = (imed << 12);
            imed = imed+4;
            imed = imed & ~0x3; //((instruction+4+(poff<<12)+offset*4) &~ 3)
            cout << " #" << imed;
        break;

        case TYPE_10: //BL #adress
            imed = num & 0x7FF; //offset com ou sem sinal (bits 11-0)
            imed = imed*2 + 4;
            cout << " #" << imed;
        break;
    }
}



