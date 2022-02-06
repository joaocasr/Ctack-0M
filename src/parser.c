#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/parser.h"
#include "../include/stack.h"
#include "../include/expressoes.h"

#define LINESIZE 1 << 14

void converte_INT(STACK *s){
   char *sobra;
   DATA X= pop(s);
   switch(X.type){
    case CHAR: X.LONG=X.CHAR;
        X.type=LONG;
        push(s,X);
        break;
    case STRING: X.LONG=strtol(X.STRING,&sobra,10);
        X.type=DOUBLE;
        push(s,X);
        break;
    case LONG: X.LONG=X.LONG;
        X.type=LONG;
        push(s,X);
        break;
    case DOUBLE : X.LONG=X.DOUBLE;
        X.type=LONG;
        push(s,X);
        break;
   }
}
/**
 * \brief Função que converte o valor do elemento no topo da stack para double.
 * @param s Stack sobre a qual a função vai atuar.
 */
void converte_double(STACK *s){
    char *sobra;
    DATA X= pop(s);
    switch(X.type){
    case CHAR: X.DOUBLE=X.CHAR;
        X.type=DOUBLE;
        push(s,X);
        break;
    case STRING: X.DOUBLE=strtod(X.STRING,&sobra);
        X.type=DOUBLE;
        push(s,X);
        break;
    case LONG: X.DOUBLE=X.LONG;
        X.type=DOUBLE;
        push(s,X);
        break;
    case DOUBLE : X.DOUBLE=X.DOUBLE;
        X.type=DOUBLE;
        push(s,X);
        break;
   }
}
/**
 * \brief Função que converte o valor do elemento no topo da stack para char.
 * @param s Stack sobre a qual a função vai atuar.
 */
void converte_ascii(STACK *s){
 DATA X=pop(s);
 switch(X.type){
  case LONG: X.CHAR=X.LONG;
             X.type=CHAR;
             push(s,X);
             break;
  default: assert (0 && "Não é possivel a conversão para ascii");
 }
}


void parse(char *line){
	char *delims= " \t\n";
	STACK *s = new_stack();
	init_arr(s);
	
   for(char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)){
        char *sobra1;
        char *sobra2;
        char linha[LINESIZE];


        long val_long = strtol(token,&sobra1,10);
        double val_double= strtod(token, &sobra2);

if(strlen(sobra1) == 0)
            push_LONG(s, val_long);
        else if(strlen(sobra2) == 0)
            push_DOUBLE(s, val_double);

        else if(token[0] == 'l'){
           assert(fgets(linha,LINESIZE, stdin) != NULL);
           assert(linha[strlen(linha) -1] == '\n');
           push_STRING(s,linha);
        }
        else if(token[0] == 'i'){
           converte_INT(s);
        }
        else if(token[0] == 'f'){
           converte_double(s);
        }
        else if(token[0] == 'c'){
           converte_ascii(s);
        }
        else if (strcmp(token, "@") == 0)
                roda(s);

        else if (strcmp(token, "_") == 0)
                duplica(s);

        else if (strcmp(token, ";") == 0)
                f_pop(s);
	
	else if (strcmp(token, "$") == 0)
                replace_v(s);

	else if (strcmp(token, "?")==0)
                if_else(s);

        else if (token[0] =='\\')
                altera(s);

        else if (strcmp(token, "=")==0)
                eq_num(s);

        else if (strcmp(token, "e&")==0)
                anddsh(s);

        else if (strcmp(token, "e|")==0)
                orrsh(s);

        else if (strcmp(token, "!")==0)
                notequal(s);

        else if (strcmp(token, "<")==0)
                menor_v(s);

        else if (strcmp(token, ">")==0)
                maior_v(s);

        else if (strcmp(token, "e>")==0)
                get_maior(s);

        else if (strcmp(token, "e<")==0)
                get_menor(s);   

	else if(isupper(token[0]))
            push(s,VAR(s,token[0]));

	else if(token[0]==':' && isupper(token[1]))
            VAR(s,token[1])=top(s);

	else{
            switch (*token){
                case '+':
                    soma(s);
                    break;
                case '-':
                    subtracao(s);
                    break;
                case '*':
                    multiplicacao(s);
                    break;
                case '/':
                    divisao(s);
                    break;
                case '|':
                    orr(s);
                    break;
                case '^':
                    xorr(s);
                    break;
                case '(':      
                    decremento(s);
                    break;
                case ')':     
                    incremento(s);
                    break;
                case '%':
                    modulo(s);
                    break;
                case '&':
                    andd(s);
                    break;
                case '#':
                    expoente(s);
                    break;
            }
        }
    }
    print_stack(s);
}
