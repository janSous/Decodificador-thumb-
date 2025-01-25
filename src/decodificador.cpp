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
                name_Reg(num, TYPE_4);
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
        

    }
}