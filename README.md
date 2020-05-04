# EigenBench
A simple implementation of the EigenBench
Software Transactional Memory Benchmark proposed in
"EigenBench: A Simple Exploration Tool for
Orthogonal TM Characteristics" (DOI: 10.1109/IISWC.2010.5648812)
[https://stanford-ppl.github.io/website/papers/iiswc10.eigenbench.pdf].

In the current version lct and persist are not implemented yet.

## Getting started
To build run `make`.

Current configuration runs with a TL2 implementation not included.
The primitives used are exactly like STAMP. To add your own STM change
the LIB, LIBPATH and INCLUDE variables in Makefile. For main.c, there is expected
an stm.h to exist in the INCLUDE directory specified.

For different options on running the benchmark run `./eigen_bench -h`.