/** @file stack.c
 * Este é o ficheiro cujas funções dizem respeito à implementação da stack.
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/stack.h"

int has_type(DATA elem, int mask){
        return (elem.type & mask) != 0;
}

STACK *new_stack(){
        STACK *s = (STACK *) calloc(1, sizeof(STACK));
        s->size = 100;
        s->stack = (DATA *) calloc(s->size, sizeof(DATA));
        return s;
}

void push(STACK *s, DATA elem){
        if(s->size == s->n_elems){
                s->size += 100;
                s->stack = (DATA *) realloc(s->stack, s->size * sizeof(DATA));
        }
        s->stack[s->n_elems] = elem;
        s->n_elems++;
}

DATA pop(STACK *s){
        s->n_elems--;
        return s->stack[s->n_elems];
}

DATA top(STACK *s){
        return s->stack[s->n_elems -1];
}

int is_empty(STACK *s){
        return s->n_elems = 0;
}

DATA conv_long(long x){
DATA p;
p.type=LONG;        
p.LONG=x;
return p;
}

DATA conv_char(char x){
DATA p;
p.type=CHAR;
p.CHAR=x;
return p;
}

void init_arr(STACK *s){
int n;
char v;
char v1= ' ';
char v2= '\n';
for(v = 'A', n = 10; v <= 'F'; v++, n++){
      VAR(s,v)=conv_long(n);
}
for(v = 'X', n = 0; v <= 'Z'; v++, n++){
      VAR(s,v)=conv_long(n);
}
 for(v='G',n=0;v<='M';v++){
      VAR(s,v)=conv_long(n);
}
for(v='O',n=0;v<='R';v++){
      VAR(s,v)=conv_long(n);
}
for(v='T',n=0;v<='W';v++){
      VAR(s,v)=conv_long(n);
}       
      VAR(s,'S')=conv_char(v1);
      VAR(s,'N')=conv_char(v2);
}


void print_stack(STACK *s){
        for(int i = 0; i <s->n_elems; i++){
                DATA elem = s->stack[i];
                TYPE type = elem.type;
                switch(type){
                        case LONG: printf("%ld", elem.LONG);
                                break;
                        case DOUBLE: printf("%g", elem.DOUBLE);
                                break;
                        case CHAR: printf("%c", elem.CHAR);
                                break;
                        case STRING: printf("%s", elem.STRING);
                                break;
                }
        }
        printf("\n");
}


#define STACK_OPERATION(_type, _name)                   \
        void push_##_name(STACK *s, _type val){         \
                DATA elem;                              \
                elem.type = _name;                      \
                elem._name = val;                       \
                push(s, elem);                          \
        }                                               \
        _type pop_##_name(STACK *s){                    \
                DATA elem = pop(s);                     \
                assert(elem.type == _name);             \
                return elem._name;                      \
        }

STACK_OPERATION(long, LONG)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)
