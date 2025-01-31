#include <string>
#ifndef DECODIFICADOR_COND_H
#define DECODIFICADOR_COND_H


void decodificador_cond(int num);

extern enum cond{EQ,NE,CS_HS,CC_LO,MI,PL,VS,VC, 
          HI, LS, GE, LT, GT, LE}cond;
        
#endif