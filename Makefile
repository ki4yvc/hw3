# Makefile for HW3
CC = g++
CFLAGS = -g -Wall

OBJS= shape.o\
      circle.o\
      rectangle.o\
      rightTriangle.o\
      main.o

INCS=shape.h rectangle.h circle.h rightTriangle.h

lab10: ${OBJS}
	@echo
	@echo Linking $@
	g++ -o $@ -Wall -g ${OBJS} -lm

${OBJS}: ${INCS} Makefile

clean:
	rm -f *.o lab10 
