//
// Created by Volglizolic on 5/2/20.
//

#ifndef EIGENBENCH_CREATORS_H
#define EIGENBENCH_CREATORS_H

#include <glob.h>
#include <stdbool.h>

enum {
    READ1,
    READ2,
    WRITE1,
    WRITE2
};

enum {
    CHAR,
    INT,
    BOOL
};

typedef struct {
    unsigned int size;
    unsigned int index;
    unsigned int snapshot;
    union {
        unsigned int *array;
        unsigned char *carray;
        bool *barray;
    };
    char type;
}random_array_t;

unsigned long xorshf96(void);

unsigned int get_next_int_rand(random_array_t *array_struct);
unsigned int get_next_char_rand(random_array_t *array_struct);
bool get_next_bool_rand(random_array_t *array_struct);


void save_index(random_array_t *t);
void restore_index(random_array_t *t);

random_array_t *create_random_array(unsigned int size, unsigned int max);
random_array_t *create_random_action_array(int times, unsigned int R1, unsigned int R2, unsigned int W1, unsigned int W2);
random_array_t *create_index_array(int size, unsigned int max);
random_array_t *create_bool_array(int size, float lct);

void print_array(random_array_t *array_struct);

#endif //EIGENBENCH_CREATORS_H
