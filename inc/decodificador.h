#include "decodificador_cond.h"
#include "decodificador_reg.h"
#include "string_to_hexa.h"

#ifndef DECODICADOR_H
#define DECODIFICADOR_H


int opcode(int num);
void decoder(int opcode, int num);
void validar();


#endif 