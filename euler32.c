#include "euler.h"

int are_pandigital3(int num1, int num2, int num3);
int main(int argc, char** argv);

int are_pandigital3(int num1, int num2, int num3) {
    int c1, c2, c3, res;
    int* num1_arr = split_number(num1, &c1);
    int* num2_arr = split_number(num2, &c2);
    int* num3_arr = split_number(num3, &c3);
    int* all_nums = malloc(sizeof(int) * (c1+c2+c3));
    memcpy(all_nums, num1_arr, c1*sizeof(int));
    memcpy(all_nums+c1, num2_arr, c2*sizeof(int));
    memcpy(all_nums+c1+c2, num3_arr, c3*sizeof(int));
    if ((c1+c2+c3) == 9)
        res = is_pandigital(all_nums, 9);
    else
        res = 0;
    free(all_nums);
    free(num1_arr);
    free(num2_arr);
    free(num3_arr);
    return res;
}

int main(int argc, char** argv) {
    for (int i = 3; i < 99; ++i)
        for (int j = 100; j < 3333; ++j)
            if (are_pandigital3(i,j,i*j))
                printf("Pandigital 1-9: %d * %d = %d\n", i, j, i*j);
    return 0;
}

