#include "euler.h"

int goldbach_search(int num, int* primes, int prime_len);
int main(int argc, char** argv);

int goldbach_search(int num, int* primes, int prime_len) {
    int test, root;
    // don't include 2 because odd subtracted by 2 is still odd
    for (int i = prime_len - 1; i > 0; --i) {
        test = num - primes[i];
        if (test >= 0) {
            test /= 2;
            root = sqrt(test);
            if (root*root == test)
                return 1;
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    int prime_len;
    int* primes = find_primes(6000, &prime_len);
    for (int i = 9; i < 10000; i+=2) {
        if (!(goldbach_search(i, primes, prime_len))) {
            printf("%d failed.\n", i);
            break;
        }
    }
    return 0;
}

