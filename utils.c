//
// Created by Volglizolic on 5/2/20.
//

#include <getopt.h>
#include <string.h>
#include "utils.h"


static const int values[] = {
        [TIME] = false,
        [A1] = 0, [A2] = 32768, [A3] = 0, [THREADS] = 4,
        [LOOPS] = 10000, [PERSIST] = false, [LCT] = 0,
        [R1] = 0, [W1] = 0,  [R2] = 90,  [W2] = 10,
        [R3I] = 0,  [W3I] = 0,  [NOPI] = 0,  [KI] = 20,
        [R3O] = 0,  [W3O] = 0,  [NOPO] = 0,  [KO] = 20
};

//static char * const token[] = {
//        [A1] = "a1", [A2] = "a2", [A3] = "a3",
//        [LOOPS] = "loops", [PERSIST] = "persistent",
//        [R1] = "R1", [W1] = "W1",  [R2] = "R2",  [W2] = "W2",
//        [R3I] = "R3_i",  [W3I] = "W3_i",  [NOPI] = "Nop_i",  [KI] = "k_i",
//        [R3O] = "R3_o",  [W3O] = "W3_o",  [NOPO] = "Nop_o",  [KO] = "k_o",
//        NULL
//};

static struct option long_options[] = {
        {"a1", required_argument, 0,  A1 },
        {"a2", required_argument, 0,  A2 },
        {"a3", required_argument, 0,  A3 },
        {"loops", required_argument, 0,  'l' },
        {"persistent", required_argument, 0,  'p' },
        {"lct", required_argument, 0,  LCT },
        {"r1", required_argument, 0,  R1 },
        {"w1", required_argument, 0,  W1 },
        {"r2", required_argument, 0,  R2 },
        {"w2", required_argument, 0,  W2 },
        {"r3i", required_argument, 0,  R3I },
        {"w3i", required_argument, 0,  W3I },
        {"nopi", required_argument, 0,  NOPI },
        {"ki", required_argument, 0,  KI },
        {"r3o", required_argument, 0,  R3O },
        {"w3o", required_argument, 0,  W3O },
        {"nopo", required_argument, 0,  NOPO },
        {"ko", required_argument, 0,  KO },
        {0, 0, 0, 0}
};

//#define SPACES(x) "                                   "x
//#define SSPACES(x) "                                     "x
//#define SSSPACES(x) "                                       "x
//#define NSPACES(x) x

#define PRINT_OPT_NO_DEF(arg, opt, desc) printf("%2s%-3s%-30s%-20s\n", " ", arg, opt, desc)
#define PRINT_OPT(arg, opt, desc, def) printf("%2s%-3s%-30s%-20s%d\n", " ", arg, opt, desc, def)
//#define PRINT_SUBOPT(opt, desc)  printf("%7s%-30s%-20s\n", " ", opt, desc)

void print_help(char *name){
    printf("Usage: %s [OPTIONS]\n", name);
    printf("Runs the EigenBench STM Benchmark\n"
           "For more information on EigenBench check the paper\n"
           "  EigenBench: A Simple Exploration Tool for Orthogonal TM Characteristics\n"
           "  https://stanford-ppl.github.io/website/papers/iiswc10.eigenbench.pdf\n\n");
    printf("Specifying EigenBench parameters:\n");
    PRINT_OPT("", "--a1=A1_SIZE", "Size of Array1 (Hot array), default ", values[A1]);
    PRINT_OPT("", "--a2=A2_SIZE", "Size of Array2 (Mild array), default ", values[A2]);
    PRINT_OPT("", "--a3=A3_SIZE", "Size of Array3 (Cold array), default ", values[A3]);
    PRINT_OPT("-l,", "--loops=LOOPS", "number of loops, default ", values[LOOPS]);
    PRINT_OPT_NO_DEF("-p,", "--persistent=[y|n]","repeat after abort, default n");
    PRINT_OPT("","--lct=LCT","Probability of address repetition, default ", values[LCT]);
    PRINT_OPT("","--r1=R1","Reads/tx of Hot array, default ", values[R1]);
    PRINT_OPT("","--w1=W1","Writes/tx of Hot array, default ", values[W1]);
    PRINT_OPT("","--r2=R2","Reads/tx of Mild array, default ", values[R2]);
    PRINT_OPT("","--w2=W2","Writes/tx of Mild array, default ", values[W2]);
    PRINT_OPT("","--r3i=R3I","Reads/tx of Cold array, default ", values[R3I]);
    PRINT_OPT("","--w3i=W3I","Writes/tx of Cold array, default ", values[W3I]);
    PRINT_OPT("","--nopi=NOPI","No-ops between TM accesses, default ", values[NOPI]);
    PRINT_OPT("","--ki=KI","Scaler for in-TX local ops, default ", values[KI]);
    PRINT_OPT("","--r3o=R3O","Reads/non-tx of Cold array, default ", values[R3O]);
    PRINT_OPT("","--w3o=W3O","Writes/non-tx of Cold array, default ", values[W3O]);
    PRINT_OPT("","--nopo=NOPO","No-ops outside TX, default ", values[NOPO]);
    PRINT_OPT("","--ko=KO","Scaler for out-TX local ops, default ", values[KO]);
    printf("Other options:\n");
    PRINT_OPT("-t","  NO_THREADS","Number of Threads, default ", values[THREADS]);
    PRINT_OPT_NO_DEF("-T","","Time execution using clock()");
    PRINT_OPT_NO_DEF("-v","","Print parameters' values");
    PRINT_OPT_NO_DEF("-h","","Displays this message");
}
void print_help_and_exit(char *name){
    print_help(name);
    exit(-1);
}

void print_data(data_t *data){
    printf("%-13s%4d\n", "(t)hreads:", data->no_threads);
    printf("%-10s%7d\t%-10s%7d\t%-10s%7d\n", "a1:", data->A1, "a2:", data->A2, "a3:", data->A3);
    printf("%-10s%7d\t%-13s%4s\t%-10s%7.3f\n", "(l)oops:", data->loops, "(p)ersistent:", (data->persistent) ? "y" : "n","lct:",data->lct);
    printf("%-10s%7d\t%-10s%7d\n", "r1:", data->R1, "w1:", data->W1);
    printf("%-10s%7d\t%-10s%7d\n", "r2:", data->R2, "w2:", data->W2);
    printf("%-10s%7d\t%-10s%7d\t%-10s%7d	%-10s%7d\n", "r3i:", data->R3_i, "w3i:", data->W3_i, "nopi:", data->Nop_i, "ki:", data->k_i);
    printf("%-10s%7d\t%-10s%7d\t%-10s%7d	%-10s%7d\n", "r3o:", data->R3_o, "w3o:", data->W3_o, "nopo:", data->Nop_o, "ko:", data->k_o);
}



void parse_args(int argc, char **argv, data_t* data){
    char *name = argv[0];
    data->time = values[TIME];
    data->A1 = values[A1]; data->A2 = values[A2]; data->A3 = values[A3]; data->no_threads = values[THREADS];
    data->loops = values[LOOPS]; data->persistent = values[PERSIST]; data->lct = (float) values[LCT];
    data->R1 = values[R1]; data->W1 = values[W1]; data->R2 = values[R2]; data->W2 = values[W2];
    data->R3_i = values[R3I]; data->W3_i = values[W3I]; data->Nop_i = values[NOPI]; data->k_i = values[KI];
    data->R3_o = values[R3O]; data->W3_o = values[W3O]; data->Nop_o = values[NOPO]; data->k_o = values[KO];

    long opt;
    char *subopts = NULL;
    int option_index = 0;
    bool print_data_bool = false;

#define CASE_DATA(x, y) case x: \
    data->y = (int) strtol(optarg, &subopts, 10); \
    if(strcmp(subopts,optarg)==0) print_help_and_exit(name); \
    break;

    while ((opt = getopt_long(argc, argv, "t:p:l:vTh", long_options, &option_index)) != -1) {
        switch (opt) {
            CASE_DATA(A1, A1)
            CASE_DATA(A2, A2)
            CASE_DATA(A3, A3)
            case 'l':
                if((data->loops = (int) strtol(optarg, &subopts, 10)) == 0) print_help_and_exit(name);
                break;
            case 'p':
                if(!(strcmp(optarg, "n") == 0 || strcmp(optarg, "no") == 0 ||
                    strcmp(optarg, "y") == 0 || strcmp(optarg, "yes") == 0 )) print_help_and_exit(name);
                data->persistent = (strcmp(optarg, "n") == 0 || strcmp(optarg, "no") == 0 )? false : true;
                break;
            case LCT:
                data->lct = strtof(optarg, &subopts);
                if(optarg == subopts) print_help_and_exit(name);
                break;
            CASE_DATA(R1, R1)
            CASE_DATA(W1, W1)
            CASE_DATA(R2, R2)
            CASE_DATA(W2, W2)
            CASE_DATA(R3I, R3_i)
            CASE_DATA(W3I, W3_i)
            CASE_DATA(NOPI, Nop_i)
            CASE_DATA(KI, k_i)
            CASE_DATA(R3O, R3_o)
            CASE_DATA(W3O, W3_o)
            CASE_DATA(NOPO, Nop_o)
            CASE_DATA(KO, k_o)
            case 't':
                if((data->no_threads = (int) strtol(optarg, &subopts, 10)) == 0) print_help_and_exit(name);
                break;
            case 'v':
                print_data_bool = true;
                break;
            case 'T':
                data->time = true;
                break;
            case 'h':
            default:
                print_help_and_exit(name);
        }
    }
#undef CASE_DATA
    if(print_data_bool)
        print_data(data);
}

void *x_malloc(size_t size){
    void * p = malloc(size);
    if(!p){
        fprintf(stderr, "Out of memory --- malloc failed\n");
        exit(-1);
    }
    return p;
}
