//
// Created by Volglizolic on 5/2/20.
//

#include "creators.h"
#include "utils.h"
#include <stdio.h>

static unsigned long x=123456789, y=362436069, z=521288629;

unsigned long xorshf96(void) {          //period 2^96-1
    unsigned long t;
    x ^= x << 16u;
    x ^= x >> 5u;
    x ^= x << 1u;
    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    return z;
}

unsigned int get_next_int_rand(random_array_t *array_struct){
    if(array_struct->index < array_struct->size) return array_struct->array[array_struct->index++];
    //Wrap around
    array_struct->index = 0;
    return array_struct->array[array_struct->index++];
}

unsigned int get_next_char_rand(random_array_t *array_struct){
    if(array_struct->index < array_struct->size) return array_struct->carray[array_struct->index++];
    //Wrap around
    array_struct->index = 0;
    return array_struct->carray[array_struct->index++];
}

bool get_next_bool_rand(random_array_t *array_struct){
    if(array_struct->index < array_struct->size) return array_struct->barray[array_struct->index++];
    //Wrap around
    array_struct->index = 0;
    return array_struct->barray[array_struct->index++];
}

void save_index(random_array_t *t){t->snapshot = t->index;}
void restore_index(random_array_t *t){t->index = t->snapshot;}

void print_array(random_array_t *array_struct){
    if(array_struct->type==INT)
        for (int i = 0; i < array_struct->size; ++i) {
            printf("%ud\t", array_struct->array[i]);
        }
    else
        for (int i = 0; i < array_struct->size; ++i) {
            printf("%c\t", array_struct->carray[i]);
        }
    printf("\n");
}


/* ===================== *
 ***** General array *****
 * ===================== */

random_array_t *create_random_array(unsigned int size, unsigned int max){
    random_array_t *res = x_malloc(sizeof(random_array_t));
    res->array = x_malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        res->array[i] = (unsigned int) xorshf96() % max;
    }
    res->size = size;
    res->index = 0;
    res->type = INT;
    return res;
}


/* ==================== *
 ***** Action array *****
 * ==================== */

random_array_t *create_random_action_array(int times, unsigned int R1, unsigned int R2, unsigned int W1, unsigned int W2){
    random_array_t *res = x_malloc(sizeof(random_array_t));
    unsigned int total = W1 + W2 + R1 + R2;
    res->carray = x_malloc(times * total * sizeof(unsigned char));
    for (int j = 0; j < times; ++j) {
        unsigned int r1 = R1, r2 = R2, w1 = W1, w2 = W2;
        for (int i = 0; i < total; ++i) {
            unsigned int seed = (xorshf96() % (r1 + r2 + w1 + w2)) + 1;
            if (seed <= r1 ){ res->carray[i + j * total] = READ1; r1--; continue;}
            if (seed <= r1 + r2 ){ res->carray[i + j * total] = READ2; r2--; continue;}
            if (seed <= r1 + r2 + w1 ){ res->carray[i + j * total] = WRITE1; w1--; continue;}
            if (seed <= r1 + r2 + w1 + w2){ res->carray[i + j * total] = WRITE2; w2--; continue;}
        }
    }
    res->size = times * (W1 + W2 + R1 + R2);
    res->index = 0;
    res->type = CHAR;
    return res;
}

/* =================== *
 ***** Index array *****
 * =================== */
random_array_t *create_index_array(int size, unsigned int max){
    return create_random_array(size, max);
}


/* ================== *
 ***** Bool array *****
 * ================== */
random_array_t *create_bool_array(int size, float lct){
    random_array_t *res = x_malloc(sizeof(random_array_t));
    res->barray = x_malloc(size * sizeof(bool));
    for (int i = 0; i < size; ++i) {
        float x = (float)rand()/(float)(RAND_MAX);
        res->barray[i] = (x < lct) ? true : false;
    }
    res->size = size;
    res->index = 0;
    res->type = BOOL;
    return res;
}
