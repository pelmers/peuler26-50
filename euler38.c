#include "euler.h"

void pandigital_products(int num);
int main(int argc, char** argv);

void pandigital_products(int num) {
    int len, len_total;
    int i = 2;
    int *numbers = split_number(num, &len);
    int *all_numbers = malloc(sizeof(int) * 16);
    memcpy(all_numbers, numbers, sizeof(int)*len);
    len_total = len;
    while (len_total < 9) {
        numbers = split_number(num*i, &len);
        memcpy(all_numbers+len_total, numbers,sizeof(int)*len);
        len_total += len;
        ++i;
    }
    if (len_total == 9)
        if (is_pandigital(all_numbers, 9))
            printf("Product of %d: %ld\n", num, join_number(all_numbers,9));
}

int main(int argc, char** argv) {
    for (int i = 2; i < 9999; ++i)
        pandigital_products(i);
    return 0;
}
