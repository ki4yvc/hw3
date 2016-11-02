# Makefile for HW3
CC = g++
CFLAGS = -g -Wall

SRC = main.cpp list.cpp bigint.cpp

TARGET = bigint

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f *.o bigint