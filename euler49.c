#include "euler.h"

int are_perms49(int* a, int* b);
int main(int argc, char** argv);

int are_perms49(int* a, int* b) {
    for (int i = 0; i < 4; ++i)
        if (linear_search(a[i], b, 4) == -1 ||
                linear_search(b[i], a, 4) == -1)
            return 0;
    return 1;
}

int main(int argc, char** argv) {
    int plen, diff, k, i_l, j_l, k_l;
    int* i_s;
    int* j_s;
    int* k_s;
    int* primes = find_primes(10000, &plen);
    for (int i = 0; i < plen; ++i) {
        for (int j = i + 1; j < (plen-1); ++j) {
            if (primes[i] < 1000 || primes[j] < 1000 ||
                    primes[i] == 1487)
                continue;
            // primes[j] > primes[i]
            diff = primes[j] - primes[i];
            k = primes[j] + diff;
            if (k < 10000 && is_prime(primes, plen, k)) {
                i_s = split_number(primes[i], &i_l);
                j_s = split_number(primes[j], &j_l);
                if (are_perms49(i_s, j_s)) {
                    k_s = split_number(k, &k_l);
                    if (are_perms49(j_s, k_s)) {
                        printf("%d %d %d\n", primes[i], primes[j], k);
                        free(k_s);
                        free(j_s);
                        free(i_s);
                        return 0;
                    }
                    free(k_s);
                }
                free(j_s);
                free(i_s);
            }
        }
    }
    return 0;
}


