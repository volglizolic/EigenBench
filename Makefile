CC = gcc
CFLAGS = -O2 -g -Wall
STATIC = -static
PTHREAD = -pthread

LIB = -ltl2
LIB_PATH = ../TL2
INCLUDE = -I../TL2/

eigen_bench: *.c *.h
	$(CC) -L$(LIB_PATH) $(CFLAGS) $(INCLUDE) $(PTHREAD) *.c -o $@ $(LIB)

run: eigen_bench
	./eigen_bench

clean:
	rm -f eigen_bench

.PHONY: clean