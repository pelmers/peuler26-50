#include "euler.h"

int truncate_prime_r(int* digits, int len, int* primes, int prime_len);
int truncate_prime_l(int* digits, int len ,int* primes, int prime_len);
int main(int argc, char **argv);

int truncate_prime_r(int* digits, int len, int* primes, int prime_len) {
    if (len == 0)
        return 1;
    if (binary_search(join_number(digits, len), primes, prime_len) != -1) {
        int *new_digits = malloc(sizeof(int)*(len-1));
        for (int i = 1; i < len; ++i)
            new_digits[i-1] = digits[i];
        int r = truncate_prime_r(new_digits, len-1, primes, prime_len);
        free(new_digits);
        return r;
    }
    else
        return 0;
}

int truncate_prime_l(int *digits, int len, int* primes, int prime_len) {
    if (len == 0)
        return 1;
    if (binary_search(join_number(digits, len), primes, prime_len) != -1)
        return truncate_prime_l(digits, len - 1, primes, prime_len);
    return 0;
}

int main(int argc, char **argv) {
    int prime_len, len, c = 0, sum = 0;
    int* i_arr;
    int *primes = find_primes(1000000, &prime_len);
    for (int i = 11; i < prime_len && c < 11; ++i) {
        i_arr = split_number(primes[i], &len);
        if (truncate_prime_r(i_arr, len, primes, prime_len) &&
                truncate_prime_l(i_arr, len, primes, prime_len)) {
            printf("%d\n", primes[i]);
            ++c;
            sum += primes[i];
        }
        free(i_arr);
    }
    printf("Sum: %d\n", sum);
    return 0;
}
