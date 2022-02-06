/**
 * @file expressoes.c
 * Este ficheiro contem as funções auxiliares do parse que fazem várias operações sobre o conteúdo da stack.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "../include/stack.h"
#include "../include/expressoes.h"


double conv(DATA n) {
    switch(n.type) {
        case LONG: return n.LONG;
        case CHAR: return n.CHAR;
        case DOUBLE: return n.DOUBLE;
        default: assert (0 && "ERRO! conv invocado com algo que não é um número");
   }
}
/**
 * \brief Função que devolve o valor guardado numa posição da stack como sendo um long.
 * @param n Elemento da stack que contém o valor que se quer converter para double.
 * @returns Parte relevante do elemento da stack como sendo um long.
 */
long conv_i(DATA n) {
    switch(n.type) {
        case LONG: return n.LONG;
        case CHAR: return n.CHAR;
        case DOUBLE: return n.DOUBLE;
        default: assert (0 && "ERRO! conv invocado com algo que não é um número");
   }
}
/**
 * \brief Função que soma o valor do elemento no topo da stack com aquele uma posição abaixo do mesmo.
 * @param s Stack sobre a qual a operação vai ser efetuada.
 */
void soma(STACK *s){
    DATA x,y;
        x=pop(s);
        y=pop(s);

    if(has_type(x, LONG) && has_type(y, LONG)){
        long r = conv(y) + conv(x);
        push_LONG(s, r);
    }
    else if ((has_type(x, LONG) || has_type(x, DOUBLE)) &&
    (has_type(y, LONG) || has_type(y, DOUBLE))){
        double r =conv(y) + conv(x);
        push_DOUBLE(s, r);
    }
}
/**
 * \brief Função que subtrai o valor do elemento uma posição abaixo do topo da stack pelo topo.
 * @param s Stack sobre a qual a operação vai ser efetuada.
 */
void subtracao(STACK *s){
    DATA x,y;
        x=pop(s);
        y=pop(s);

    if(has_type(x, LONG) && has_type(y, LONG)){
        long r = conv(y) - conv(x);
        push_LONG(s, r);
    }
    else if ((has_type(x, LONG) || has_type(x, DOUBLE)) &&
    (has_type(y, LONG) || has_type(y, DOUBLE))){
        double r =conv(y) - conv(x);
        push_DOUBLE(s, r);
    }
}
/**
 * \brief Função que multiplica o valor do elemento uma posição abaixo do topo da stack pelo topo.
 * @param s Stack sobre a qual a operação vai ser efetuada.
 */
void multiplicacao(STACK *s){
    DATA x,y;
        x=pop(s);
        y=pop(s);

    if(has_type(x, LONG) && has_type(y, LONG)){
        long r = conv(y) * conv(x);
        push_LONG(s, r);
    }
    else if ((has_type(x, LONG) || has_type(x, DOUBLE)) &&
    (has_type(y, LONG) || has_type(y, DOUBLE))){
        double r =conv(y) * conv(x);
        push_DOUBLE(s, r);
    }
}
/**
 * \brief Função que divide o valor do elemento uma posição abaixo do topo da stack pelo topo.
 * @param s Stack sobre a qual a operação vai ser efetuada.
 */
void divisao(STACK *s){
    DATA x,y;
        x=pop(s);
        y=pop(s);

    if(has_type(x, LONG) && has_type(y, LONG)){
        long r = conv(y) / conv(x);
        push_LONG(s, r);
    }
    else if ((has_type(x, LONG) || has_type(x, DOUBLE)) &&
    (has_type(y, LONG) || has_type(y, DOUBLE))){
        double r =conv(y) / conv(x);
        push_DOUBLE(s, r);
    }
}
/**
 * \brief Função que decrementa o valor do elemento no topo da stack.
 * @param s Stack sobre a qual a operação vai ser efetuada.
 */
void decremento(STACK *s){
 DATA x = pop(s);
  if(has_type(x, LONG)){
  push_LONG(s,conv_i(x)-1);
  }
  else if(has_type(x, DOUBLE)){
   push_DOUBLE(s,conv(x)-1);
  }
 DATA y = pop(s);
  push(s,y);
}
/**
 * \brief Função que incrementa o valor do elemento no topo da stack.
 * @param s Stack sobre a qual a operação vai ser efetuada.
 */
void incremento(STACK *s){
 DATA x = pop(s);
 if(has_type(x, LONG)){
  push_LONG(s,conv_i(x)+1);
 }
 else if(has_type(x,DOUBLE)){
  push_DOUBLE(s,conv(x)+1);
 }
 DATA y = pop(s);
  push(s,y);
}
/**
 * \brief Função que calcula o valor do elemento uma posição abaixo do topo elevado ao valor do elemento no topo da stack.
 * @param s Stack sobre a qual a operação vai ser efetuada.
 */
void expoente(STACK *s){
  DATA x,y;
        x=pop(s);
        y=pop(s);

    if(has_type(x, LONG) && has_type(y, LONG)){
        long r = pow(conv(y), conv(x));
        push_LONG(s, r);
    }
    else if ((has_type(x, LONG) || has_type(x, DOUBLE)) &&
    (has_type(y, LONG) || has_type(y, DOUBLE))){
        double r = pow(conv(y), conv(x));
        push_DOUBLE(s, r);
    }
}
/**
 * \brief Função que calcula o valor da operação lógica OR (|) entre o valor do elemento no topo da stack com o do elemento uma posição abaixo.
 * @param s Stack sobre a qual a operação vai ser efetuada.
 */
void orr(STACK *s){
  DATA x,y;
        x=pop(s);
        y=pop(s);
    long r = conv_i(x) | conv_i(y);
    push_LONG(s, r);
}
/**
 * \brief Função que calcula o resto da divisão entre o valor do elemento uma posição a baixo do topo da stack e do elemento no topo.
 * @param s Stack sobre a qual a operação vai ser efetuada.
 */
void modulo(STACK *s){
    DATA x,y;
    if((has_type(top(s), LONG))||(has_type(top(s), DOUBLE)))
        x=pop(s);
    if((has_type(top(s), LONG))||(has_type(top(s), DOUBLE)))
        y=pop(s);

    long r = conv_i(y) % conv_i(x);
    push_LONG(s, r);
}
/**
 * \brief Função que calcula o valor da operação lógica XOR (^) entre o valor do elemento no topo da stack com o do elemento uma posição abaixo.
 * @param s Stack sobre a qual a operação vai ser efetuada.
 */
void xorr(STACK *s){
    DATA x,y;
        x=pop(s);
        y=pop(s);

   long r = conv_i(x) ^ conv_i(y);
   push_LONG(s, r);
}
/**
 * \brief Função que calcula o valor da operação lógica NOT (~) do elemento no topo da stack.
 * @param s Stack sobre a qual a operação vai ser efetuada.
 */
void nott(STACK *s){
    DATA x;
        x=pop(s);
    long r= (~conv_i(x));
    push_LONG(s,r);
}
/**
 * \brief Função que calcula o valor da operação lógica AND (&) entre o valor do elemento no topo da stack com o do elemento uma posição abaixo.
 * @param s Stack sobre a qual a operação vai ser efetuada.
 */
void andd(STACK *s){
    DATA x,y;
        x=pop(s);
        y=pop(s);
   long r = conv_i(x) & conv_i(y);
   push_LONG(s, r);
}
/**
 * \brief Função que manipula a stack de modo a trocar a posição entre elemento no topo com o elemento na posição abaixo.
 * @param s Stack que vai ser manipulada.
 */
void altera(STACK *s){
  DATA x,y;
  x=pop(s);
  y=top(s);
  pop(s);
  push(s,x);
  push(s,y);
}
/**
 * \brief Função que lê o valor no topo da stack como sendo um inteiro e depois adiciona à stack uma cópia do elemento
 *        que estiver na posição dada pelo inteiro, considerando o topo como sendo a posição 0.
 * @param s Stack que vai ser alterada.
 */
void replace_v(STACK * s){
   int i,n;
   i= conv_i(pop(s));
   n= s->n_elems - i -1;
 DATA x;
  x = s->stack[n];
  push(s,x);
}
/**
 * \brief Função que manipula a stack de modo a mover o elemento no topo e o abaixo do topo uma posição para baixo, e o 2 posições abaixo do topo para o topo.
 * @param s Stack que vai ser manipulada.
 */
void roda(STACK *s){
  DATA x,y,z;
  x=pop(s);
  y=pop(s);
  z=pop(s);

  push(s,y);
  push(s,x);
  push(s,z);

}
/**
 * \brief Função que adiciona um elemento à stack igual ao seu topo.
 * @param s Stack que irá ser alterada.
 */
void duplica(STACK *s){
DATA x;
 x=top(s);
 push(s,x);
}
/**
 * \brief Função que retira o elemento do topo da stack.
 * @param s Stack que irá ser alterada.
 */
void f_pop(STACK *s){
 pop(s);
}
/**
 * \brief Função que devolve falso se n é diferente de zero, e verdadeiro se n é igual a zero.
 * @param n é um DATA
 */
int cond(DATA n){
 if(conv_i(n)!=0){
    return 1;
 }else{
    return 0;
 }
}
/**
 * \brief Função que realiza o comando if_then_else entre elementos, de acordo com o primeiro da sequência
 * @param s Stack que irá ser alterada.
 */
void if_else(STACK *s){
 DATA Z = pop(s);
 DATA Y = pop(s);
 DATA X = pop(s);
 DATA R = cond(X) ? Y : Z;
push(s, R);
}
/**
 * \brief Função que verifica a igualdade de dois elementos.
 * @param s Stack que irá ser alterada.
 */
void eq_num(STACK *s){
 DATA X= pop(s);
 DATA Y= pop(s);
 double r = (conv(X)==conv(Y)) ? 1 : 0;
push_DOUBLE(s,r);
}
/**
 * \brief Função que realiza o comando E  (com shortcut).
 * @param s Stack que irá ser alterada.
 */
void anddsh(STACK *s){
 DATA Y=pop(s);
 DATA X=pop(s);
 DATA r= cond(X) ? Y : X;
push(s,r);
}
/**
 * \brief Função que realiza o comando Ou  (com shortcut).
 * @param s Stack que irá ser alterada.
 */
void orrsh(STACK *s){
 DATA Y=pop(s);
 DATA X=pop(s);
 DATA r= cond(X) ? X : Y;
push(s,r);
}
/**
 * \brief Função que nega a valoração.
 * @param s Stack que irá ser alterada.
 */
void notequal(STACK *s){
 DATA X=pop(s);
double r=(conv(X)!=0) ? 0 : 1;
push_DOUBLE(s,r);
}
/**
 * \brief Função que verifica se o primeiro elemento é maior do que o segundo.
 * @param s Stack que irá ser alterada.
 */
void maior_v(STACK *s){
  DATA Y=pop(s);
  DATA X=pop(s);
  double r = (conv(X)>conv(Y)) ? 1 : 0;
 push_DOUBLE(s,r);
}
/**
 * \brief Função que verifica se o segundo elemento é maior do que o primeiro.
 * @param s Stack que irá ser alterada.
 */
void menor_v(STACK *s){
  DATA Y=pop(s);
  DATA X=pop(s);
  double r = (conv(X)<conv(Y)) ? 1 : 0;
 push_DOUBLE(s,r);
}
/**
 * \brief Função que coloca o menor dos 2 valores na stack.
 * @param s Stack que irá ser alterada.
 */
void get_maior(STACK *s){
  DATA Y= pop(s);
  DATA X= pop(s);
  DATA r = (conv(X)>conv(Y)) ? X : Y;
 push(s,r);
}
/**
 * \brief Função que coloca o maior dos 2 valores na stack.
 * @param s Stack que irá ser alterada.
 */
void get_menor(STACK *s){
  DATA Y= pop(s);
  DATA X= pop(s);
  DATA r = (conv(X)<conv(Y)) ? X : Y;
 push(s,r);
}
