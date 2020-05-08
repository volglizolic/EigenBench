//
// Created by Volglizolic on 5/2/20.
//

#ifndef EIGENBENCH_UTILS_H
#define EIGENBENCH_UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    bool time;
    int A1; int A2; int A3; int no_threads;
    int loops; bool persistent; int R1; int W1; int R2; int W2;
    int R3_i; int W3_i; int Nop_i; int k_i;
    int R3_o; int W3_o; int Nop_o; int k_o;
    float lct;
}data_t;

enum {
    TIME,
    A1, A2, A3, THREADS,
    LOOPS, PERSIST, R1, W1, R2, W2,
    R3I, W3I, NOPI, KI,
    R3O, W3O, NOPO, KO,
    LCT
};

void *x_malloc(size_t size);
void parse_args(int argc, char **args, data_t* data);

#endif //EIGENBENCH_UTILS_H
