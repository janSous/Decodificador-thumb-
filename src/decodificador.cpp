#include "decodificador.h"
#include <iostream>
void decoder(int opcode, int num){
    int instruction = num >> 12;
    int reg = 0, imed = 0;

    switch(instruction)
    {
        case 0x0:
            if(!opcode)
            {
                std::cout << "LSL ";
                nome_reg(num,TYPE_1);
            }
            else
            {
                std::cout << "LSR ";
                nome_reg(num, TYPE_1);
            }
            break;
        case 0x1:
            if(opcode==0)
            {
                std::cout << "ASR ";
                nome_reg(num,TYPE_1);
            }
            else if(opcode == 4)
            {
                std::cout << "ADD ";
                nome_reg(num,TYPE_2);
            }
            else if(opcode == 5)
            {
                std::cout << "SUB ";
                nome_reg(num,TYPE_2);
            }
            else if(opcode == 6)
            {
                std::cout << "ADD ";
                nome_reg(num,TYPE_3);
            }
            else if(opcode == 7)
            {
                std::cout << "SUB ";
                nome_reg(num,TYPE_3);
            }
            break;
        
        case 0x2:
            if(opcode == 0)
            {
                std::cout << "MOV ";
                nome_reg(num, TYPE_4);
            }
            else
            {
                std::cout << "CMP ";
                nome_reg(num, TYPE_4);
            }
            break;

        case 0x3:
            if(opcode == 0)
            {
                std::cout << "ADD ";
                nome_reg(num, TYPE_4);
            }
            else
            {
                std::cout << "SUB ";
                nome_reg(num, TYPE_4);
            }
            break;
        
        case 0x4:
            switch(opcode)
            {
                case 0x0:
                    std::cout << "AND ";
                    nome_reg(num,TYPE_5);
                    break;
                case 0x1:
                    std::cout << "EOR ";
                    nome_reg(num,TYPE_5);
                    break;
                case 0x2:
                    std::cout << "LSL ";
                    nome_reg(num, TYPE_5);
                    break;
                case 0x3:
                    std::cout << "LSR ";
                    nome_reg(num, TYPE_5);
                case 0x4:
                    std::cout << "ASR ";
                    nome_reg(num, TYPE_5);
                    break;
                case 0x5:
                    std::cout << "ADC ";
                    nome_reg(num, TYPE_5);
                    break;
                case 0x6:
                    std::cout << "SBC ";
                    nome_reg(num, TYPE_5);
                    break;
                case 0x7:
                    std::cout << "ROR ";
                    nome_reg(num, TYPE_5);
                    break;
                case 0x8:
                    std::cout << "TST ";
                    nome_reg(num, TYPE_5);
                    break;
                case 0x9:
                    std::cout << "NEG ";
                    nome_reg(num, TYPE_5);
                    break;
                case 0xA:
                    std::cout << "CMP ";
                    nome_reg(num, TYPE_5);
                    break;
                case 0xB:
                    std::cout << "CMN ";
                    nome_reg(num, TYPE_5);
                    break;
                case 0xC:
                    std::cout << "ORR ";
                    nome_reg(num, TYPE_5);
                    break;
                case 0xD:
                    std::cout << "MUL ";
                    nome_reg(num, TYPE_5);
                    break;
                case 0xE:
                    std::cout << "BIC ";
                    nome_reg(num, TYPE_5);
                    break;
                case 0xF:
                    std::cout << "MVN ";
                    nome_reg(num,TYPE_5);
                    break;
                case 0x11:
                    std::cout << "ADD ";
                    nome_reg(num,TYPE_5);
                    break;
                case 0x12:
                    std::cout << "ADD ";
                    nome_reg(num,TYPE_5);
                    break;
                case 0x13:
                    std::cout << "MOV ";
                    nome_reg(num,TYPE_5);
                case 0x15:
                    std::cout << "CMP ";
                    nome_reg(num,TYPE_5);
                    break;
                case 0x16:
                    std::cout << "CMP ";
                    nome_reg(num, TYPE_5);
                    break;
                case 0x17:
                    std::cout << "CMP ";
                    nome_reg(num, TYPE_5);
                    break;
                case 0x18:
                    std::cout << "CPY ";
                    nome_reg(num, TYPE_5);
                    break;
                case 0x19:
                    std::cout << "MOV ";
                    nome_reg(num, TYPE_5);
                    break;
                case 0x1A:
                    std::cout << "MOV ";
                    nome_reg(num, TYPE_5);
                    break;
                case 0x1B:
                    std::cout << "MOV ";
                    nome_reg(num,TYPE_5);
                    break;
                case 0x1C:
                    std::cout << "BX ";
                    //implementar depois
                    break;
                case 0x1E:
                    std::cout << "BLX ";
                    //implementar
                    break;
                case 0xFF:
                    std::cout << "LDR ";
                    nome_reg(num, TYPE_4_1);
                    break;
            }
            break;

        case 0x5:
            switch(opcode)
            {
                case 0x0:
                    std::cout << "STR ";
                    break;
                case 0x1:
                    std::cout << "STRH ";
                    break;
                case 0x2:
                    std::cout << "STRB ";
                    break;
                case 0x3:
                    std::cout << "LDRSB ";
                    break;
                case 0x4:
                    std::cout << "LDR ";
                    break;
                case 0x5:
                    std::cout << "LDRH ";
                    break;
                case 0x6:
                    std::cout << "LDRB ";
                    break;
                case 0x7:
                    std::cout << "LDRSH ";
                    break;
            }
            break;
    
        case 0x6:
            if(!opcode)
            {
                std::cout << "STR ";
                nome_reg(num, TYPE_1_1);
            }
            else
            {
                std::cout << "LDR ";
                nome_reg(num, TYPE_1_1);
            }
        break;

        case 0x7:
            if(!opcode)
            {
                std::cout << "STRB ";
                nome_reg(num, TYPE_1_1);
            }
            else
            {
                std::cout << "LDRB ";
                nome_reg(num, TYPE_1_1);
            }
        break;

        case 0x8:
            if(!opcode)
            {
                std::cout << "STRH ";
                nome_reg(num, TYPE_1_1);
            }
            else
            {
                std::cout << "LDRH ";
                nome_reg(num, TYPE_1_1);
            }
        break;

        case 0x9:
            if(!opcode)
            {
                std::cout << "STR ";
                nome_reg(num, TYPE_4_2);
            }
            else
            {
                std::cout << "LDR ";
                nome_reg(num, TYPE_4_2);
            }
        break;

        case 0xA:
            std::cout << "ADD ";
            if(!opcode)
            {
                nome_reg(num, TYPE_4_1);
            } 
            else
            {
                nome_reg(num, TYPE_4_2);
            }
        break;

        case 0xB:
            switch(opcode)
            {
                case 0x0:
                    std::cout << "ADD sp, ";
                    imed = num & 0x7F;
                    std::cout << imed << "\n";
                break;

                case 0x1:
                    std::cout << "SUB sp, ";
                    imed = num & 0x7F;
                    std::cout << imed << "\n";
                break;

                case 0x8:
                    std::cout << "SXTH ";
                    nome_reg(num, TYPE_5);
                break;

                case 0x9:
                    std::cout << "SXTB ";
                    nome_reg(num, TYPE_5);
                break;

                case 0xA:
                    std::cout << "UTXH ";
                    nome_reg(num, TYPE_5);
                break;

                case 0xB:
                    std::cout << "UTXB ";
                    nome_reg(num, TYPE_5);
                break;

                case 0x28:
                    std::cout << "REV ";
                    nome_reg(num, TYPE_5);
                break;

                case 0x29:
                    std::cout << "REV16 ";
                    nome_reg(num, TYPE_5);
                break;

                case 0x2B:
                    std::cout << "REVSH ";
                    nome_reg(num, TYPE_5);
                break;

                case 0x2:
                    std::cout << "PUSH ";
                    nome_reg(num, TYPE_6_1);
                break;

                case 0x6:
                    std::cout << "POP ";
                    nome_reg(num, TYPE_6_1);
                break;

                case 0x14:
                    std::cout << "SETEND LE ";
                break;

                case 0x15:
                    std::cout << "SETEND BE ";
                break;

                case 0xC:
                    std::cout << "CPSIE ";
                break;
                
                case 0xE:
                    std::cout << "CPSID";
                break;

                case 0xF:
                    std::cout << "BKPT ";
                    nome_reg(num, TYPE_7);
                break;

                default:
                    std::cout << "Instrução invalida\n";
                break;
            }
            break;
        
        case 0xC:
            if(!opcode)
            {
                std::cout << "STMIA ";
                nome_reg(num, TYPE_6);
            }
            else
            {
                std::cout << "LDMIA ";
                nome_reg(num, TYPE_6);
            }
        break;

        case 0xD:
            if(opcode == 0xE)
            {
                std::cout << "Undefined Instruction";
            }
            else if(opcode == 0xF)
            {
                std::cout << "SWI ";
                decodificador_cond(num);
            }
            else
            {
                std::cout << "B";
                decodificador_cond(num);
                nome_reg(num, TYPE_7);
            }

        break;

        case 0xE:
            if(!opcode)
            {
                std::cout << "B ";
                nome_reg(num, TYPE_8);
            }
            else
            {
                std::cout << "BLX ";
                nome_reg(num, TYPE_9);
            }
        break;

        case 0xF:
            std::cout << "BL ";
            nome_reg(num, TYPE_10);
            break;

        default:
            std::cout << "Instrução invalida\n";
        break;
    }
}

int opcode(int num)
{
    int opcode = 0;
    int instruction = num >> 12;

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
            if(((num >> 11) & 0x1) == 0)
            {
                if(((num & 0xF00) >> 8) == 0x7)
                {
                    opcode = ((num & 0xF8) >> 7);
                }
                else if(((num & 0xF00) >> 8) < 0x7)
                {
                    opcode = ((num & 0xFC0) >> 6);
                }
            }
            else
            {
                opcode = 0xFF;
            }
           
        break;

        case 0x5:
            opcode = (num >> 9) & 0x3;
        break;

        case 0x6 ... 0xA:
            opcode = (num >> 11) & 0x1;
        break; 

        //avaliar e testar depois
        case 0xB:

            if(((num >> 8) & 0xF) == 0xE)
            {
                opcode = 0xF;
            }
            //Verifica bits 10-9
            else if(((num >> 9) & 0x3) == 0x0)
            {
                opcode = ((num >> 7) & 0x1F);
            }
            else if(((num >> 9) & 0x3) == 0x1)
            {
                opcode = ((num >> 6) & 0x3F);
            }
            else if(((num >> 9) & 0x3) == 0x2)
            {
                opcode = ((num >> 9) & 0x7);
            }
            else
            {
                if(((num >> 5) & 0x1) == 0)
                {
                    opcode = ((num >> 2) & 0x1F);
                }
                else if(((num >> 5) & 0x1) == 1)
                {
                    opcode = ((num >> 4) & 0xF);
                }
            }
            
        break;
        

        case 0xC:
            opcode = (num >> 11) & 0x1;
        break;

        case 0xD:
            opcode = ((num >> 8) & 0xF);
        break;

        case 0xE:
            opcode = (num>>11) & 0x1;
        break;

        case 0xF:
            opcode = (num>>11) & 0x1;
        
        default:
            opcode = 0;   
    }

    return opcode;
}
