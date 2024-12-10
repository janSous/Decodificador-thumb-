#ifndef DECODICADOR_H
#define DECODIFICADOR_H

int opcode(int instrucao, int num);
void dec_instrucao(int instrucao, int opcode, int num);
void scan();
void verifica_hexa();

#endif 