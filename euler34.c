#include "euler.h"

int factorialize(int num);
int main(int argc, char **argv);

int factorialize(int num) {
    int len;
    int fact_sum = 0;
    int* num_arr = split_number(num, &len);
    for (int i = 0; i < len; ++i)
        fact_sum += factorial(num_arr[i]);
    free(num_arr);
    return fact_sum;
}


int main(int argc, char **argv) {
    for (int i = 11; i < 100000; ++i)
        if (i == factorialize(i))
            printf("%d\n", i);
}
