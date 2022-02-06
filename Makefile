CC	= gcc
OBJ	= obj/
#DEBUG=-O0 -Wextra -g
#CFLAGS = $(DEBUG) -pedantic -Wall -std=c99 -lm -I$(OBJ)
CFLAGS = -Wall -Wextra -Wdouble-promotion -Wconversion -Wsign-conversion  -O0 -g -D_GNU_SOURCE
SRC	= src/
INCLUDE = include/
LIBS	= -lm

allprog: ctackm main Stack Parser Expressoes
	$(CC) $(CFLAGS) $(OBJ)/*.o -o ctackm $(LIBS)

ctackm: Stack Parser Expressoes

Stack: $(SRC)stack.c $(INCLUDE)stack.h
	$(CC) $(CFLAGS) -o $(OBJ)stack.o -c $(SRC)stack.c

Parser: $(SRC)parser.c $(INCLUDE)parser.h
	$(CC) $(CFLAGS) -o $(OBJ)parser.o -c $(SRC)parser.c

Expressoes: $(SRC)expressoes.c $(INCLUDE)expressoes.h
	$(CC) $(CFLAGS) -o $(OBJ)expressoes.o -c $(SRC)expressoes.c


main: $(SRC)main.c
	$(CC) $(CFLAGS) -o $(OBJ)main.o -c $(SRC)main.c


clean:
	@echo -n "Cleaning...\n"
	@rm -rf $(OBJ)
	@rm ctackm

