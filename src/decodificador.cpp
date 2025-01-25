#include "decodificador.h"
#include <iostream>
void decoder(int instruction, int opcode, int num)
{
    instruction = num >> 12;
    int reg = 0, imed = 0;

    switch(instruction)
    {
        case 0x0:
            if(!opcode)
            {
                std::cout << "LSL";
                name_reg(num,TYPE_1);
            }
            else
            {
                std::cout << "LSR";
                name_reg(num, TYPE_1);
            }
            break;
        case 0x1:
            if(opcode==0)
            {
                std::cout << "ASR";
                name_reg(num,TYPE_1);
            }
            else if(opcode == 4)
            {
                std::cout << "ADD";
                name_reg(num,TYPE_2);
            }
            else if(opcode == 5)
            {
                std::cout << "SUB";
                name_reg(num,TYPE_2);
            }
            else if(opcode == 6)
            {
                std::cout << "ADD";
                name_reg(num,TYPE_3);
            }
            else if(opcode == 7)
            {
                std::cout << "SUB";
                name_reg(num,TYPE_3);
            }
            break;
        
        case 0x2:
            if(opcode == 0)
            {
                std::cout << "MOV";
                name_reg(num, TYPE_4);
            }
            else
            {
                std::cout << "CMP";
                name_reg(num, TYPE_4);
            }
            break;

        case 0x3:
            if(opcode == 0)
            {
                std::cout << "ADD";
                name_reg(num, TYPE_4);
            }
            else
            {
                std::cout << "SUB";
                name_reg(num, TYPE_4);
            }
            break;
        
        case 0x4:
            switch(opcode)
            {
                case 0x0:
                    std::cout << "AND";
                    name_reg(num,TYPE_5);
                    break;
                case 0x1:
                    std::cout << "EOR";
                    name_reg(num,TYPE_5);
                    break;
                case 0x2:
                    std::cout << "LSL";
                    name_reg(num, TYPE_5);
                    break;
                case 0x3:
                    std::cout << "LSR";
                    name_reg(num, TYPE_5);
                case 0x4:
                    std::cout << "ASR";
                    name_reg(num, TYPE_5);
                    break;
                case 0x5:
                    std::cout << "ADC";
                    name_reg(num, TYPE_5);
                    break;
                case 0x6:
                    std::cout << "SBC";
                    name_reg(num, TYPE_5);
                    break;
                case 0x7:
                    std::cout << "ROR";
                    name_reg(num, TYPE_5);
                    break;
                case 0x8:
                    std::cout << "TST";
                    name_reg(num, TYPE_5);
                    break;
                case 0x9:
                    std::cout << "NEG";
                    name_reg(num, TYPE_5);
                    break;
                case 0xA:
                    std::cout << "CMP";
                    name_reg(num, TYPE_5);
                    break;
                case 0xB:
                    std::cout << "CMN";
                    name_reg(num, TYPE_5);
                    break;
                case 0xC:
                    std::cout << "ORR";
                    name_reg(num, TYPE_5);
                    break;
                case 0xD:
                    std::cout << "MUL";
                    name_reg(num, TYPE_5);
                    break;
                case 0xE:
                    std::cout << "BIC";
                    name_reg(num, TYPE_5);
                    break;
                case 0xF:
                    std::cout << "MVN";
                    name_reg(num,TYPE_5);
                    break;
                case 0x11:
                    std::cout << "ADD";
                    name_reg(num,TYPE_5);
                    break;
                case 0x12:
                    std::cout << "ADD";
                    name_reg(num,TYPE_5);
                    break;
                case 0x13:
                    std::cout << "MOV";
                    name_reg(num,TYPE_5);
                case 0x15:
                    std::cout << "CMP";
                    name_reg(num,TYPE_5);
                    break;
                case 0x16:
                    std::cout << "CMP";
                    name_reg(num, TYPE_5);
                    break;
                case 0x17:
                    std::cout << "CMP";
                    name_reg(num, TYPE_5);
                    break;
                case 0x18:
                    std::cout << "CPY";
                    name_reg(num, TYPE_5);
                    break;
                case 0x19:
                    std::cout << "MOV";
                    name_reg(num, TYPE_5);
                    break;
                case 0x1A:
                    std::cout << "MOV";
                    name_reg(num, TYPE_5);
                    break;
                case 0x1B:
                    std::cout << "MOV";
                    name_reg(num,TYPE_5);
                    break;
                case 0x1C:
                    std::cout << "BX";
                    //implementar depois
                    break;
                case 0x1E:
                    std::cout << "BLX";
                    //implementar
                    break;
                case 0xFF:
                    std::cout << "LDR";
                    name_reg(num, TYPE_4_1);
                    break;
            }
            break;

        case 0x5:
            switch(opcode)
            {
                case 0x0:
                    std::cout << "STR";
                    break;
                case 0x1:
                    std::cout << "STRH";
                    break;
                case 0x2:
                    std::cout << "STRB";
                    break;
                case 0x3:
                    std::cout << "LDRSB";
                    break;
                case 0x4:
                    std::cout << "LDR";
                    break;
                case 0x5:
                    std::cout << "LDRH";
                    break;
                case 0x6:
                    std::cout << "LDRB";
                    break;
                case 0x7:
                    std::cout << "LDRSH";
                    break;
            }
            break;
    
        case 0x6:
            if(!opcode)
            {
                std::cout << "STR";
                name_reg(num, TYPE_1_1);
            }
            else
            {
                std::cout << "LDR";
                name_reg(num, TYPE_1_1);
            }
        break;

        case 0x7:
            if(!opcode)
            {
                std::cout << "STRB";
                name_reg(num, TYPE_1_1);
            }
            else
            {
                std::cout << "LDRB";
                name_reg(num, TYPE_1_1);
            }
        break;

        case 0x8:
            if(!opcode)
            {
                std::cout << "STRH";
                name_reg(num, TYPE_1_1);
            }
            else
            {
                std::cout << "LDRH";
                name_reg(num, TYPE_1_1);
            }
        break;

        case 0x9:
            if(!opcode)
            {
                std::cout << "STR";
                name_reg(num, TYPE_4_2);
            }
            else
            {
                std::cout << "LDR";
                name_reg(num, TYPE_4_2);
            }
        break;

        case 0xA:
            std::cout << "ADD";
            if(!opcode)
            {
                name_reg(num, TYPE_4_1);
            } 
            else
            {
                name_reg(num, TYPE_4_2);
            }
        break;

        case 0xB:
            switch(opcode)
            {
                case 0x0:
                    std::cout << "ADD sp,";
                    imed = num & 0x7F;
                    std::cout << imed << "\n";
                break;

                case 0x1:
                    std::cout << "SUB sp,";
                    imed = num & 0x7F;
                    std::cout << imed << "\n";
                break;

                case 0x8:
                    std::cout << "SXTH";
                    name_reg(num, TYPE_5);
                break;

                case 0x9:
                    std::cout << "SXTB";
                    name_reg(num, TYPE_5);
                break;

                case 0xA:
                    std::cout << "UTXH";
                    name_reg(num, TYPE_5);
                break;

                case 0xB:
                    std::cout << "UTXB";
                    name_reg(num, TYPE_5);
                break;

                case 0x28:
                    std::cout << "REV";
                    name_reg(num, TYPE_5);
                break;

                case 0x29:
                    std::cout << "REV16";
                    name_reg(num, TYPE_5);
                break;

                case 0x2B:
                    std::cout << "REVSH";
                    name_reg(num, TYPE_5);
                break;

                case 0x2:
                    std::cout << "PUSH";
                    name_reg(num, TYPE_6_1);
                break;

                case 0x6:
                    std::cout << "POP";
                    name_reg(num, TYPE_6_1);
                break;

                case 0x14:
                    std::cout << "SETEND LE";
                break;

                case 0x15:
                    std::cout << "SETEND BE";
                break;

                case 0xC:
                    std::cout << "CPSIE";
                break;

                case 0xF:
                    std::cout << "BKPT";
                    name_reg(num, TYPE_7);
                break;

                default:
                    std::cout << "Instrução invalida\n";
                break;
            }
            break;
        
        case 0xC:
            if(!opcode)
            {
                std::cout << "STMIA";
                name_reg(num, TYPE_6);
            }
            else
            {
                std::cout << "LDMIA";
                name_reg(num, TYPE_6);
            }
        break;

        case 0xD:
            if(opcode == 0xF)
            {
                std::cout << "SWI";
            }
            else
            {
                std::cout << "B";
                std::cout << dec_cond(num);
            }

            name_Reg(num, TYPE_7);
        break;

        case 0xE:
            if(!opcode)
            {
                std::cout << "B";
                name_reg(num, TYPE_8);
            }
            else
            {
                std::cout << "BLX";
                name_reg(num, TYPE_9);
            }
        break;

        case 0xF:
            std::cout << "BL";
            name_reg(num, TYPE_10);

        default:
            std::cout << "Instrução invalida\n";
        break;
    }
}

int opcode(int instruction, int num)
{
    int opcode = 0;
    instruction = num >> 12;

    switch(instruction)
    {
        case 0x0:
            opcode = (num >> 11) & 0b1;
        break;

        case 0x1:
            if(((num>>11) & 0b1) == 0)
            {
                opcode = 0;
            }
            else if((num >> 11 & 0b1) && (num >> 10) & 0b1)
            {
                opcode = ((num >> 9 & 0b111));
            }
            else
            {
                opcode = ((num >> 9 & 0b111));
            }

        break;

        case 0x2:
            opcode = (num >> 11) & 0b1;
        break;

        case 0x3:
            opcode = (num >> 11) & 0b1;
        break;

        case 0x4:
            if((num >> 11) & 0x1)
            {
                if(((num >>8) & 0x7) == 0x7)
                    opcode = ((num>>7) & 0xF);
                else 
                    opcode = (num >> 6) & 0x1F;
            }
            else   
                opcode = 0x1;
        break;

        case 0x5:
            opcode = (num >> 9) & 0x3;
        break;

        case 0x6 ... 0xA:
            opcode = (num >> 11) & 0x1;
        break; 

        //avaliar e testar depois
        case 0xB:
            //Verifica bits 11-8
            if(((num >> 8) & 0xF) == 0)
                opcode = (num >> 7 & 0x1);
            //Verifica bits 10 e 9   
            if(((num >> 9) & 0x3) == 0x1)
                opcode = (num >> 6) & 0x3;
            if(((num >> 9) & 0x3) == 0x2)
                opcode = (num >> 11) & 0x1;
            if(((num >> 9) & 0x3) == 0x3)
            {
                if(((num >> 5) & 0xF) == 0x2)
                    opcode = (num>>3) & 0x1;
                if(((num >> 5) & 0xF) == 0x3)
                    opcode = (num>>4) & 0x1;
            }
        break;

        case 0xC:
            opcode = (num >> 11) & 0x1;
        break;

        case 0xD:
            opcode = 0;
        break;

        case 0xE:
            opcode = (num>>11) & 0x1;
        break;

        case 0xF:
            opcode = (num>>11) & 0x1;
        
        default:
            opcode = 0;   
    }
}
