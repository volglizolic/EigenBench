#define _GNU_SOURCE

#include <stdio.h>
#include <stdbool.h>
#include <sched.h>
#include <pthread.h>
#include "creators.h"
#include "utils.h"

#include "stm.h"

static long *Array1, *Array2, *Array3;
random_array_t **random_action_arrays;
random_array_t **random_index_A1_arrays;
random_array_t **random_index_A2_arrays;
random_array_t **random_index_A3_arrays;

void test_core(int t_id, int loops, bool persist, int R1, int W1, int R2, int W2,
               int R3_i, int W3_i, int Nop_i, int k_i,
               int R3_o, int W3_o, int Nop_o, int k_o);

void* pre_test_core(void *);



typedef struct {
    int t_id;
    data_t *data;
}for_thread_t;

int main(int argc, char **argv) {
    data_t data;
    parse_args(argc, argv, &data);

    int A1 = data.A1, A2 = data.A2, A3 = data.A3;
    int no_threads = data.no_threads;

    int times = (data.loops > 10)? 7 : data.loops;

    Array1 = x_malloc(A1 * sizeof(long)); for (int i = 0; i < A1; ++i) Array1[i] = i;
    Array2 = x_malloc(A2 * no_threads * sizeof(long)); for (int i = 0; i < A2 * no_threads; ++i) Array2[i] = i;
    Array3 = x_malloc(A3 * no_threads * sizeof(long)); for (int i = 0; i < A3 * no_threads; ++i) Array3[i] = i;

    random_action_arrays = x_malloc(sizeof(random_array_t*) * no_threads);
    random_index_A1_arrays = x_malloc(sizeof(random_array_t*) * no_threads);
    random_index_A2_arrays = x_malloc(sizeof(random_array_t*) * no_threads);
    random_index_A3_arrays = x_malloc(sizeof(random_array_t*) * no_threads);
    for (int i = 0; i < no_threads; ++i) {
        random_action_arrays[i] = create_random_action_array(times, data.R1, data.R2, data.W1, data.W2);
        random_index_A1_arrays[i] = create_index_array(A1 * times, A1);
        random_index_A2_arrays[i] = create_index_array(A2 * times, A2);
        random_index_A3_arrays[i] = create_index_array(A3 * times, A3);
    }

    clock_t begin = 0, end;
    if(data.time)
        begin = clock();
    STM_STARTUP();
    for_thread_t for_thread[no_threads];
    pthread_t threads[no_threads];
    pthread_attr_t thread_attr[no_threads];
    cpu_set_t cpu_set[no_threads];
    for (int i = 0; i < no_threads; ++i) {
        for_thread[i].data = &data;
        for_thread[i].t_id = i;
        CPU_ZERO(&cpu_set[i]);
        CPU_SET(i, &cpu_set[i]);
        pthread_attr_init(&thread_attr[i]);
        pthread_attr_setaffinity_np(&thread_attr[i], sizeof(cpu_set_t), &cpu_set[i]);
        pthread_create(&threads[i], &thread_attr[i], pre_test_core, &for_thread[i]);
    }
    for(int i = 0; i < no_threads; i++) pthread_join(threads[i], NULL);
    STM_SHUTDOWN();
    if(data.time){
        end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Main execution time: %f\n", time_spent);
    }
    return 0;
}

void save_random_seed(int t_id){
    save_index(random_action_arrays[t_id]);
    save_index(random_index_A2_arrays[t_id]);
    save_index(random_index_A3_arrays[t_id]);
}
void restore_random_seed(int t_id){
    restore_index(random_action_arrays[t_id]);
    restore_index(random_index_A2_arrays[t_id]);
    restore_index(random_index_A3_arrays[t_id]);
}

void* pre_test_core(void *arg){
    for_thread_t *t = (for_thread_t *) arg;
#define T t->data->
    test_core(t->t_id, T loops, T persistent,
            T R1, T W1, T R2, T W2, T R3_i, T W3_i, T Nop_i, T k_i,
            T R3_o, T W3_o, T Nop_o, T k_o);
#undef T
    return NULL;
}

void
test_core(int t_id, int loops, bool persist, int R1, int W1, int R2, int W2, int R3_i, int W3_i, int Nop_i, int k_i,
          int R3_o, int W3_o, int Nop_o, int k_o) {
    STM_THREAD_T *STM_SELF = STM_NEW_THREAD();
    STM_INIT_THREAD(STM_SELF, t_id);
    long val = 0;
    int total = R1 + R2 + W1 + W2;
    for (int i = 0; i < loops; ++i) {
//        save_random_seed(t_id);
        STM_BEGIN_WR();
//        if(persistent)
//            restore_random_seed(t_id);
        // TODO History buffers and lct support
        for (int j = 0; j < total; ++j) {
            unsigned char action = get_next_char_rand(random_action_arrays[t_id]);
            if(action == READ1){
                val += STM_READ(Array1[0]);//get_next_int_rand(random_index_A1_arrays[t_id])]);
            } else if (action == WRITE1){
                STM_WRITE(Array1[0], val);//get_next_int_rand(random_index_A1_arrays[t_id])], val);
            }else if (action == READ2){
                val += STM_READ(Array2[t_id * A2 + get_next_int_rand(random_index_A2_arrays[t_id])]);
            }else if (action == WRITE2){
                STM_WRITE(Array2[t_id * A2 + get_next_int_rand(random_index_A2_arrays[t_id])], val);
            }
            if((j % k_i) == 0)
                for (int k = 0; k < R3_i + W3_i + Nop_i; ++k) {
                    int temp = (int) rand() % 2, r3 = R3_i, w3 = W3_i;
                    if(temp == 0 && w3 > 0) {
                        STM_WRITE(Array3[t_id * A3 + get_next_int_rand(random_index_A3_arrays[t_id])], val);
                        w3--;
                    } else if (temp == 1 && r3 > 0){
                        val += STM_READ(Array3[t_id * A3 + get_next_int_rand(random_index_A3_arrays[t_id])]);
                        r3--;
                    } else {
                        asm("nop");
                    }
                }
        }
        STM_END();
        if((i % k_o) == 0)
            for (int k = 0; k < R3_o + W3_o + Nop_o; ++k) {
                int temp = (int) rand() % 2, r3 = R3_o, w3 = W3_o;
                if(temp == 0 && w3 > 0) {
                    val = Array3[t_id * A3 + get_next_int_rand(random_index_A3_arrays[t_id])];
                    w3--;
                } else if (temp == 1 && r3 > 0){
                    val += Array3[t_id * A3 + get_next_int_rand(random_index_A3_arrays[t_id])];
                    r3--;
                } else {
                    asm("nop");
                }
            }
    }
    STM_FREE_THREAD(STM_SELF);
}
