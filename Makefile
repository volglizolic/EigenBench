CC = gcc
RISCV_CC = riscv64-unknown-linux-gnu-gcc
CFLAGS = -O2 -g -Wall
STATIC = -static
PTHREAD = -pthread

LIB = -ltl2
LIB_PATH = ../TL2
INCLUDE = -I../TL2/

PIPINOLIB = -lPipinoSTM
PIPINOLIB_PATH = ../PipinoSTM/
PIPINOLIB_INCLUDE = -I../PipinoSTM/

PIPINOLIBv2 = -lPipinoSTMv2
PIPINOLIB_PATHv2 = ../PipinoSTMv2/
PIPINOLIB_INCLUDEv2 = -I../PipinoSTMv2/

HPC_UTILS_LIB = -lhpc_utils
HPC_UTILS_LIB_PATH = ../Counters/hpc_utils_lib/
HPC_INCLUDE = -I../Counters/hpc_utils_lib/include/

x86: pipino_eigen_bench_v2 pipino_eigen_bench eigen_bench

pipino_eigen_bench_v2: *.c *.h
	$(CC) -L$(PIPINOLIB_PATHv2) $(CFLAGS) $(PIPINOLIB_INCLUDEv2) $(PTHREAD) *.c -o $@ $(PIPINOLIBv2)

pipino_eigen_bench: *.c *.h
	$(CC) -L$(PIPINOLIB_PATH) $(CFLAGS) $(PIPINOLIB_INCLUDE) $(PTHREAD) *.c -o $@ $(PIPINOLIB)

eigen_bench_riscv: *.c *.h
	$(RISCV_CC) -L$(LIB_PATH) -L$(HPC_UTILS_LIB_PATH) $(CFLAGS) $(INCLUDE) $(HPC_INCLUDE) $(PTHREAD) $(STATIC) *.c -o $@ $(LIB) $(HPC_UTILS_LIB)

eigen_bench: *.c *.h
	$(CC) -L$(LIB_PATH) $(CFLAGS) $(INCLUDE) $(PTHREAD) *.c -o $@ $(LIB)

run: eigen_bench
	./eigen_bench

clean:
	rm -f eigen_bench pipino_eigen_bench pipino_eigen_bench_v2

.PHONY: clean