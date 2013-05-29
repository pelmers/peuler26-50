#include "euler.h"

int unit_fraction(int divisor, int show);
int main(int argc, char** argv);

int unit_fraction(int divisor, int show) {
    // show determines if we should print it or not
    int* remainders = malloc(sizeof(int)); // track remainders
    int rem_count = 0; // count number of divisions made
    int dividend = 1;
    if (show)
        printf("\n0.");
    // while remainder's not 0 and we haven't seen this remainder before
    while (dividend != 0 &&
            linear_search(dividend, remainders, rem_count-1)==-1) {
        if (dividend < divisor)
            // equivalent to carrying down a 0 in manual long-division
            dividend *= 10;
        if (show)
            printf("%i", dividend/divisor);
        // new dividend is the remainder of this one
        dividend %= divisor;
        remainders = realloc(remainders, sizeof(int)*(rem_count+1));
        // add this remainder to the list
        remainders[rem_count++] = dividend;
    }
    if (show)
        printf("\n");
    // distance from this point to last time we saw this remainder
    return rem_count - linear_search(dividend, remainders, rem_count) - 1;
}

int main(int argc, char** argv) {
    int r;
    int s = 1;
    int t = 0;
    for (int i = 1; i < 1000; ++i) {
        r = unit_fraction(i, 0);
        if (r > t) {
            t = r;
            s = i;
        }
    }
    printf("%d, repeating term is %d digits\n", s, t);
    unit_fraction(s, 1);
    return 0;
}
