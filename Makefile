CC = riscv64-unknown-linux-gnu-gcc
CFLAGS = -O3 -g -Wall
STATIC = -static
PTHREAD = -pthread

LIB = -lTL2_riscv
LIB_PATH = ../TL2
INCLUDE = -I../TL2/

PIPINOLIB = -lPipinoSTM_riscv
PIPINOLIB_PATH = ../PipinoSTM/
PIPINOLIB_INCLUDE = -I../PipinoSTM/

PIPINOLIBv2 = -lPipinoSTMv2_riscv
PIPINOLIB_PATHv2 = ../PipinoSTMv2/
PIPINOLIB_INCLUDEv2 = -I../PipinoSTMv2/

PIPINOLIBv3 = -lPipinoSTMv3_riscv
PIPINOLIB_PATHv3 = ../PipinoSTMv3/
PIPINOLIB_INCLUDEv3 = -I../PipinoSTMv3/

HPC_UTILS_LIB = -lhpc_utils
HPC_UTILS_LIB_PATH = ../Counters/hpc_utils_lib/
HPC_INCLUDE = -I../Counters/hpc_utils_lib/include/

default: pipino_eigen_bench_v3 tl2_eigen_bench

pipino_eigen_bench_v3: *.c *.h
	$(CC) -L$(PIPINOLIB_PATHv3) -L$(HPC_UTILS_LIB_PATH) $(CFLAGS) $(PIPINOLIB_INCLUDEv3) $(HPC_INCLUDE) $(PTHREAD) $(STATIC) *.c -o $@ $(PIPINOLIBv3) $(HPC_UTILS_LIB)

pipino_eigen_bench_v2: *.c *.h
	$(CC) -L$(PIPINOLIB_PATHv2) -L$(HPC_UTILS_LIB_PATH) $(CFLAGS) $(PIPINOLIB_INCLUDEv2) $(HPC_INCLUDE) $(PTHREAD) $(STATIC) *.c -o $@ $(PIPINOLIBv2) $(HPC_UTILS_LIB)

pipino_eigen_bench: *.c *.h
	$(CC) -L$(PIPINOLIB_PATH) -L$(HPC_UTILS_LIB_PATH) $(CFLAGS) $(PIPINOLIB_INCLUDE) $(HPC_INCLUDE) $(PTHREAD) $(STATIC) *.c -o $@ $(PIPINOLIB) $(HPC_UTILS_LIB)

tl2_eigen_bench: *.c *.h
	$(CC) -L$(LIB_PATH) -L$(HPC_UTILS_LIB_PATH) $(CFLAGS) $(INCLUDE) $(HPC_INCLUDE) $(PTHREAD) $(STATIC) *.c -o $@ $(LIB) $(HPC_UTILS_LIB)

clean:
	rm -f eigen_bench pipino_eigen_bench pipino_eigen_bench_v2

.PHONY: clean pipino_eigen_bench_v3 tl2_eigen_bench