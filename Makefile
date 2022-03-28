
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
	del *.o base_64.exe *.gch 
else
	rm *.o base_64 *.gch
endif