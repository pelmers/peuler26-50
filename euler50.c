#include "euler.h"

int main(int argc, char** argv);

int main(int argc, char** argv) {
    int plen;
    int current;
    int max_num;
    int max_count = 0;
    int* primes = find_primes(1000000, &plen);
    printf("%d primes found\n", plen);
    for (int i = 0; i < plen && (plen - i) > max_count; ++i) {
        current = primes[i];
        for (int j = i + 1; j < plen; ++j) {
            current += primes[j];
            if (current > 1000000)
                break;
            if (binary_search(current, primes, plen) != -1) {
                if ((j-i) > max_count) {
                    max_count = j-i;
                    max_num = current;
                }
            }
        }
    }
    ++max_count;
    printf("%d is the sum of %d consecutive primes.\n", max_num, max_count);
    return 0;
}
