#ifndef ___STACK_H___
#define ___STACK_H___

#include <assert.h>

/**< @struct enum
* \brief Assignação de nomes a números do tipo 2^n que simbolizam os tipos de dados que cada elemento da stack contém.
* @var enum::lONG
* @var enum::DOUBLE
* @var enum::CHAR
* @var enum::STRING
*/
typedef enum {LONG = 2   ///< member 'LONG' is equal to 2.
            , DOUBLE = 4 ///< member 'DOUBLE' is equal to 4.
            , CHAR = 1   ///< member 'CHAR' is equal to 1.
            , STRING = 8 ///< member 'STRING' is equal to 8.
} TYPE;
/*
#define INTEGER(LONG | CHAR)
#define NUMBER (INTEGER | DOUBLE)
*/

/**< @struct DATA
 * \brief representa cada elemento da nossa stack.
 */
typedef struct data { 
        TYPE type;     ///< 'type' armazena dado do tipo TYPE.
        long LONG;     ///< 'LONG' armazena dado do tipo long.
        double DOUBLE; ///< 'DOUBLE' armazena dado do tipo double.
        char CHAR;     ///< 'CHAR' armazena dado do tipo char.
        char *STRING;  ///< 'STRING' armazena dado do tipo char*.
} DATA;

/**< @struct STACK da nossa stack.*/
typedef struct stack{ 
        DATA *stack; /**< Array com os elementos da nossa stack.*/
        int size; /**< Indica o tamanho da stack.*/
        DATA arr_val[26];/**<Array que armazena as as variáveis dadas pelas letras do alfabeto.*/
        int n_elems; /**< Indica a posição do próximo elemento a ser adicionado.*/
} STACK;

#define VAR(s,v) s->arr_val[v-'A'] 

/**< Função has_type presente em stack.c .*/
int has_type(DATA elem, int mask);
STACK *new_stack();
void push(STACK *s, DATA elem);
DATA pop(STACK *s);
DATA top(STACK *s);
int is_empty(STACK *s);
void print_stack(STACK *s);
DATA conv_long(long x);
DATA conv_char(char x);
void init_arr(STACK *s);

/**< Função macro que realiza comandos pop e push de um determinado valor da e na stack.*/
#define STACK_OPERATION_PROTO(_type, _name)             \
        void push_##_name(STACK *s, _type val);         \
        _type pop_##_name(STACK *s);

STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)
// STACK_OPERATION_PROTO(DATA, data)

#endif
