#ifndef DECODIFICADOR_COND_H
#define DECODIFICADOR_COND_H

char *decod_cond(int num);

enum cond{EQ,NE,CS_HS,CC_LO,MI,PL,VS,VC, 
          HI, LS, GE, LT, GT, LE}cond;
        
#endif