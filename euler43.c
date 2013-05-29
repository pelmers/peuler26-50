#include "euler.h"

int substring_divisible(int* num_arr, int len);
int main(int argc, char** argv);

int substring_divisible(int *num_arr, int len) {
    int subnum[3];
    subnum[0] = num_arr[1];
    subnum[1] = num_arr[2];
    subnum[2] = num_arr[3];
    if (join_number(subnum, 3) % 2 != 0)
        return 0;
    subnum[0] = num_arr[2];
    subnum[1] = num_arr[3];
    subnum[2] = num_arr[4];
    if (join_number(subnum, 3) % 3 != 0)
        return 0;
    subnum[0] = num_arr[3];
    subnum[1] = num_arr[4];
    subnum[2] = num_arr[5];
    if (join_number(subnum, 3) % 5 != 0)
        return 0;
    subnum[0] = num_arr[4];
    subnum[1] = num_arr[5];
    subnum[2] = num_arr[6];
    if (join_number(subnum, 3) % 7 != 0)
        return 0;
    subnum[0] = num_arr[5];
    subnum[1] = num_arr[6];
    subnum[2] = num_arr[7];
    if (join_number(subnum, 3) % 11 != 0)
        return 0;
    subnum[0] = num_arr[6];
    subnum[1] = num_arr[7];
    subnum[2] = num_arr[8];
    if (join_number(subnum, 3) % 13 != 0)
        return 0;
    subnum[0] = num_arr[7];
    subnum[1] = num_arr[8];
    subnum[2] = num_arr[9];
    if (join_number(subnum, 3) % 17 != 0)
        return 0;
    return 1;
}

int main(int argc, char** argv) {
    long int sum = 0;
    int num_arr[10];
    int num_len = 10;
    long int i;
    for (num_arr[0] = 0; num_arr[0] < 10; num_arr[0]++) {
    for (num_arr[1] = 0; num_arr[1] < 10; num_arr[1]++) {
    for (num_arr[2] = 0; num_arr[2] < 10; num_arr[2]++) {
    for (num_arr[3] = 0; num_arr[3] < 10; num_arr[3] += 2) {
    for (num_arr[4] = 0; num_arr[4] < 10; num_arr[4]++) {
    for (num_arr[5] = 0; num_arr[5] < 10; num_arr[5]+=5) {
    for (num_arr[6] = 0; num_arr[6] < 10; num_arr[6]++) {
    for (num_arr[7] = 0; num_arr[7] < 10; num_arr[7]++) {
    for (num_arr[8] = 0; num_arr[8] < 10; num_arr[8]++) {
    for (num_arr[9] = 0; num_arr[9] < 10; num_arr[9]++) {
        if (is_pandigital_with_0(num_arr, num_len)) {
            if (substring_divisible(num_arr, num_len)) {
                i = join_number(num_arr, num_len);
                printf("%ld works.\n", i);
                sum += i;
            }
        }
    }}}}}}}}}}
    printf("Total sum: %ld\n", sum);
    return 0;
}
