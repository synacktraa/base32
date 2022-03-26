
BIN=gcc
CFLAGS=-g -Wall

all: base_32

base32.o: base32.c
	$(BIN) $(CFLAGS) -c $^

base32_utils.o: base32_utils.c base32_utils.h
	$(BIN) $(CFLAGS) -c $^

base_32: base32.o base32_utils.o
	$(BIN) $(CFLAGS) $^ -o $@

clean:

ifeq ($(OS),Windows_NT)
	del *.o base_32.exe *.gch 
else
	CHECK := $(shell uname)
	ifeq ($(CHECK), Linux)
		rm *.o base_32 *.gch
	endif
endif