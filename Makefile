
BIN=gcc
CFLAGS=-g -Wall

all: base_32

base_32.o: base32.c
	$(BIN) $(CFLAGS) -c $^

base32_utils.o: base32_utils.c base32_utils.h
	$(BIN) $(CFLAGS) -c $^

base_32: base_32.o base32_utils.o
	$(BIN) $(CFLAGS) $^ -o $@

clean:
	rm *.o base_32 2>/dev/null