#include "euler.h"

int summer(int n);
int main(int argc, char** argv);

int summer(int n) {
    int len;
    int* n_digits = split_number(n, &len);
    int sum = 0;
    for (int i = 0; i < len; ++i)
        sum += pow(n_digits[i], 5);
    free(n_digits);
    return sum;
}

int main(int argc, char** argv) {
    int sum = 0;
    for (int i = 2; i < pow(9,5)*6; ++i) {
        if (i == summer(i)) {
            printf("%d\n", i);
            sum += i;
        }
    }
    printf("Sum: %d\n", sum);
    return 0;
}
