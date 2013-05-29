#include "euler.h"

int cancelled_but_equal(int numer, int denom);
int main(int argc, char **argv);

int cancelled_but_equal(int numer, int denom) {
    if (numer % 10 == 0 || denom % 10 == 0)
        return 0;
    int _;
    int* numer_arr = split_number(numer, &_);
    int* denom_arr = split_number(denom, &_);
    int new_numer;
    int new_denom;
    if (numer_arr[0] == denom_arr[0]) {
        new_numer = numer_arr[1];
        new_denom = denom_arr[1];
    }
    else if (numer_arr[0] == denom_arr[1]) {
        new_numer = numer_arr[1];
        new_denom = denom_arr[0];
    }
    
    else if (numer_arr[1] == denom_arr[0]) {
        new_numer = numer_arr[0];
        new_denom = denom_arr[1];
    }
    
    else if (numer_arr[1] == denom_arr[1]) {
        new_numer = numer_arr[0];
        new_denom = denom_arr[0];
    }
    else {
        new_numer = 1;
        new_denom = 1;
    }
    free(numer_arr);
    free(denom_arr);
    return ((numer % new_numer == 0) && (numer / new_numer) * new_denom == denom);
}

int main(int argc, char **argv) {
    printf("%d/%d is cancellable\n", 49,98);
    for (int numer = 10; numer < 98; ++numer)
        for (int denom = numer+1; denom < 99; ++denom)
            if (cancelled_but_equal(numer, denom))
                printf("%d/%d is cancellable\n", numer,denom);
    return 0;
}
