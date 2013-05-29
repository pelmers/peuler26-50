#include "euler.h"

int main(int argc, char** argv);


int main(int argc, char** argv) {
    int pj, pk;
    int min_diff = -1;
    for (int j = 1; j < 3000; ++j) {
        pj = pentagonal_number(j);
        for (int k = j+1; k < 3000; ++k) {
            pk = pentagonal_number(k);
            if (is_pentagonal(pk+pj) && is_pentagonal(pk-pj)) {
                printf("p(%d) = %d and p(%d) = %d\n", j, pj, k, pk);
                if (pk-pj < min_diff || min_diff < 0)
                    min_diff = pk - pj;
            }
        }
    }
    printf("Minimum difference: %d\n", min_diff);
    return 0;
}
