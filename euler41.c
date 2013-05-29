#include "euler.h"

int main(int argc, char** argv);

int main(int argc, char** argv) {
    int p_len, a_len;
    int* primes = find_primes(sqrt(7654321)+1, &p_len);
    int* prime_arr;
    for (int i = 1234567; i <= 7654321; i+=2) {
        if (is_prime(primes, p_len, i)) {
            //printf("Testing %d...\n", i);
            prime_arr = split_number(i, &a_len);
            if (is_pandigital(prime_arr, a_len))
                printf("%d is pandigital prime\n", i);
            free(prime_arr);
        }
    }
    free(primes);
    return 0;
}
