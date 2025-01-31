#include <string>
#ifndef DECODIFICADOR_REG_H
#define DECODIFICADOR_REG_H

extern enum types{TYPE_1, TYPE_1_1,TYPE_2,TYPE_3,TYPE_4,TYPE_4_1,
           TYPE_4_2, TYPE_5, TYPE_6, TYPE_6_1, TYPE_6_2, 
           TYPE_7, TYPE_8, TYPE_9, TYPE_10}types;


extern enum regs{R0, R1 , R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, 
          R12, R13, R14, R15}regs;

std::string decod_reg(int reg);
void nome_reg(int num, int types);

#endif