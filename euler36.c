#include "euler.h"

char* to_binary(int num, int* len);
int main(int argc, char** argv);

char* to_binary(int num, int* len) {
    int i = 0;
    char* b = malloc(sizeof(char)*sizeof(int)*8);
    while (num != 0) {
        b[i] = '0' + (num & 1);
        num >>= 1;
        ++i;
    }
    *len = i;
    b = realloc(b, sizeof(char)*i);
    reverse_carray(b, i);
    return b;
}

int main(int argc, char** argv) {
    char *b;
    int *n;
    int clen;
    int ilen;
    int sum = 0;
    for (int i = 1; i < 1000000; i+=2) {
        n = split_number(i, &ilen);
        if (is_palindrome_i(n, ilen)) {
            b = to_binary(i, &clen);
            if (is_palindrome(b, clen)) {
                printf("%d\n", i);
                sum += i;
                free(b);
            }
        }
        free(n);
    }
    printf("Sum: %d\n", sum);
    return 0;
}
