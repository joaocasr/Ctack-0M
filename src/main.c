/** @file main.c
 * Este é o ficheiro que contem a função principal do programa.
 */
#include <stdio.h>

#include "../include/parser.h"
/**
 * \brief Esta é a função principal do programa.
 * 
 * @return Devolve o valor 0.
 */
int main(){
  char buf[BUFSIZ];
  parse(fgets(buf, BUFSIZ, stdin));
        return 0;
}



