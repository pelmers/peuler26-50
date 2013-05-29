#include "euler.h"

int rotate_number(int num);
int* find_rotations(int num, int* len);
int check_for_evens(int* nums, int len);
int is_circular_prime(int num, int* primes, int prime_count);
int main(int argc, char **argv);

int rotate_number(int num) {
    int len;
    int res;
    int* num_arr = split_number(num, &len);
    int* num_rot = malloc(sizeof(int)*len);
    int last = num_arr[len-1];
    for (int i = 1; i < len; ++i)
        num_rot[i] = num_arr[i-1];
    num_rot[0] = last;
    res = join_number(num_rot, len);
    free(num_arr);
    free(num_rot);
    return res;
}

int* find_rotations(int num, int* len) {
    int i = 1;
    int* rotations = malloc(sizeof(int)*100);
    rotations[0] = num;
    while (1) {
        rotations[i] = rotate_number(rotations[i-1]);
        ++i;
        if (rotations[i-1] == num)
            break;
    }
    *len = i - 1;
    rotations = realloc(rotations, sizeof(int) * (i-1));
    return rotations;
}

int check_for_evens(int* numbers, int len) {
    /* Return the index of first even digit if found in numbers, else -1
     * Begins search from the start of the array
     */
    int i;
    for (i = 0; i < len; ++i)
        if (0 == numbers[i] || 2 == numbers[i] || 4 == numbers[i] ||
                6 == numbers[i] || 8 == numbers[i])
            return i;
    return -1;
}

int is_circular_prime(int num, int* primes, int prime_count) {
    int len;
    int* num_s = split_number(num, &len);
    if (len > 1 && check_for_evens(num_s, len) != -1) {
        free(num_s);
        return 0;
    }
    free(num_s);
    int* rotations = find_rotations(num, &len);
    for (int i = 0; i < len; ++i) {
        if (binary_search(rotations[i], primes, prime_count) == -1) {
            free(rotations);
            return 0;
        }
    }
    free(rotations);
    return 1;
}

int main(int argc, char **argv) {
    int prime_len;
    int count = 0;
    int* primes = find_primes(1000000, &prime_len);
    for (int i = 1; i < 1000000; ++i) {
        if (is_circular_prime(i, primes, prime_len)) {
            ++count;
            printf("%d is circular\n", i);
        }
    }
    printf("%d circular primes found.\n", count);
    free(primes);
    return 0;
}

