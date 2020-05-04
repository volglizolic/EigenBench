//
// Created by Volglizolic on 5/2/20.
//

#ifndef EIGENBENCH_HELPER_H
#define EIGENBENCH_HELPER_H

#include "creators.h"

int rand_action(random_array_t *t){
    return get_next_char_rand(t);
}


int rand_index(int tid, random_array_t *indexes, int subarray_size){
    //if reading from A1 set tid to 0 or subarray_size to 0
    return get_next_char_rand(indexes) + (tid * subarray_size);
}

#endif //EIGENBENCH_HELPER_H
