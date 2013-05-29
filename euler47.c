#include "euler.h"

int count_prime_factors(int num, int* primes, int prime_len);
int main(int argc, char** argv);

int count_prime_factors(int num, int* primes, int prime_len) {
    int count = 0;
    int last_i = -1;
    while (num != 1) {
        // start i at last_i if last_i has been set
        for (int i = (last_i < 0)?0:last_i; i < prime_len; ++i) {
            if (num % primes[i] == 0) {
                if (i != last_i) {
                    last_i = i;
                    ++count;
                }
                num /= primes[i];
                break;
            }
        }
    }
    return count;
}

int main(int argc, char** argv) {
    int p_len;
    int *primes = find_primes(150000, &p_len);
    for (int i = 11; i < 150000-4; ++i) {
        if (count_prime_factors(i, primes, p_len) == 4 &&
                count_prime_factors(i+1, primes, p_len) == 4 &&
                count_prime_factors(i+2, primes, p_len) == 4 &&
                count_prime_factors(i+3, primes, p_len) == 4)
            printf("%d  %d  %d %d\n", i, i+1, i+2, i+3);
    }
    return 0;
}

