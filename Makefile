CC = gcc
RISCV_CC = riscv64-unknown-linux-gnu-gcc
CFLAGS = -O2 -g -Wall
STATIC = -static
PTHREAD = -pthread

LIB = -ltl2
LIB_PATH = ../TL2
INCLUDE = -I../TL2/

HPC_UTILS_LIB = -lhpc_utils
HPC_UTILS_LIB_PATH = ../Counters/hpc_utils_lib/
HPC_INCLUDE = -I../Counters/hpc_utils_lib/include/

eigen_bench_riscv: *.c *.h
	$(RISCV_CC) -L$(LIB_PATH) -L$(HPC_UTILS_LIB_PATH) $(CFLAGS) $(INCLUDE) $(HPC_INCLUDE) $(PTHREAD) $(STATIC) *.c -o $@ $(LIB) $(HPC_UTILS_LIB)

eigen_bench: *.c *.h
	$(CC) -L$(LIB_PATH) $(CFLAGS) $(INCLUDE) $(PTHREAD) *.c -o $@ $(LIB)

run: eigen_bench
	./eigen_bench

clean:
	rm -f eigen_bench

.PHONY: clean