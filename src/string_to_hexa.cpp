#include "string_to_hexa.h"
#include "decodificador.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



void validar(){
digite:
int instruction=0;
int opcode_num; 
int num; 
char *hexa;
int j = 0; 
int count=0;
int valido = 0; 



hexa = (char *)calloc(100, sizeof(char));

if(hexa == NULL)
{
    printf("falha de alocaçao.");
    exit(0);
}

printf("Digite um valor hexa:\n");
scanf("%s", hexa);

while (hexa[j] != '\0'){
    
    count++;
    j++;
}


if (count > 4)
{
    printf("Numero invalido:\n");
    system("/usr/bin/clear");
    free(hexa);
    goto digite;
}

for (int i = 0; i < 4; i++){
    if (isxdigit(hexa[i] == true)){
        valido++;
    }
    
    else{
        printf("Numero inválido ou imcompleto\n");
        printf("Digite outro numero.\n");
        free(hexa);
        system("usr/bin/clear");
        goto digite;
    }

    if (valido == 4){
        printf("Numero valido.\n");
    }

    else{
        printf("Numero invalido.\n");
        system("usr/bin/clear");
        free(hexa);
        goto digite;
    }


 
    
}


sscanf(hexa, "%x%*c", &num);
opcode_num = opcode(instruction, num);
printf("Decoded instruction:\n");
decoder(instruction, opcode_num, num);





}