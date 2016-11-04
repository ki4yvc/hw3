# Makefile for HW3
CC = g++
CFLAGS = -g -Wall

OBJS = node.o\
			 list.o\
			 bigint.o\
			 iterator.o\
			 main.o


INCS = node.h list.h bigint.h iterator.h

bigint: ${OBJS}
	@echo
	@echo Linking $@
	g++ -o $@ -Wall -g ${OBJS} -lm

${OBJS}: ${INCS} Makefile

clean:
	rm -f *.o bigint
