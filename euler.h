#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void swap_i(int* x, int* y);
int linear_search(int target, int* numbers, int len);
int rlinear_search(int target, int* numbers, int len);
int binary_search(int num, int* nums, int len);
int reverse_iarray(int* nums, int len);
int reverse_carray(char* str, int len);
void print_iarray(int* nums, int num_count);
int is_prime(int* primes, int prime_count, int n);
int* find_primes(int upto, int* count);
int is_palindrome(char* n, int len);
int is_palindrome_i(int* digits, int len);
char* getSubstring(char *word, int start, int end);
int is_pandigital(int* num_arr, int len);
int is_pandigital_with_0(int* num_arr, int len);
int* split_number(int num, int *len);
long join_number(int *split, int len);
long factorial(int n);
inline long triangular_number(int term);
inline int is_triangular(long num);
inline long pentagonal_number(int term);
inline int is_pentagonal(long num);
inline long hexagonal_number(int term);
inline int is_hexagonal(long term);

void swap_i(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int linear_search(int target, int* numbers, int len) {
    /* Return the index of target if found in numbers, else -1
     * Begins search from the start of the array
     */
    int i;
    for (i = 0; i < len; ++i)
        if (target == numbers[i])
            return i;
    return -1;
}

int rlinear_search(int target, int* numbers, int len) {
    /* Return the index of target if found in numbers, else -1
     * Begins search from the end of the array
     */
    int i;
    for (i = len - 1; i >= 0 ; --i)
        if (target == numbers[i])
            return i;
    return -1;
}

int binary_search(int num, int* nums, int len) {
    /* Return the index of target if found in array nums, else -1
     * Nums must be sorted
     */
    int start = 0;
    int end = len - 1;
    int mid;
    while (end >= start) {
        mid = (end-start)/2 + start;
        if (nums[mid] < num)
            start = mid + 1;
        else if (nums[mid] > num)
            end = mid - 1;
        else
            return mid;
    }
    return -1;
}

int reverse_iarray(int* nums, int len) {
    /* Reverse the order of the elements of array nums in place
     * Return the length of the array, len
     */
    int tmp;
    for (int i = 0, j = len-1; i < j; ++i) {
        tmp = nums[i];
        nums[i] = nums[j];
        nums[j--] = tmp;
    }
    return len;
}

int reverse_carray(char* str, int len) {
    /* Reverse the order of the elements of array str in place
     * Return the length of the array, len
     */
    int tmp;
    for (int i = 0, j = len-1; i < j; ++i) {
        tmp = str[i];
        str[i] = str[j];
        str[j--] = tmp;
    }
    return len;
}

void print_iarray(int* nums, int num_count) {
    /* Print the array nums in brackets, each element separated by commas
     * Ex: [0, 1, 2, 3]
     */
    int i;
    //emulates java's Arrays.toString
    printf("[");
    for (i = 0; i < num_count - 1; ++i)
        printf("%d, ", nums[i]);
    printf("%d]\n", nums[num_count-1]);
}

int is_prime(int* primes, int prime_count, int n) {
    /* Return 1 if n is prime, 0 if composite
     * Primes must be an array of prime numbers up to the square root of n
     */
    int i;
    int root = sqrt(n) + 1;
    for (i = 0; i < prime_count && primes[i] < root; i++)
        // only check already-found prime factors
        if (!(n % primes[i]))
            return 0;
    return 1;
}

int* find_primes(int upto, int* count) {
    /* Return an array of all prime numbers less than or equal to upto
     * Update *count to the number of primes found
     */
    int n = 1;
    int c = 2;
    int* primes = malloc(2*sizeof(int));
    primes[0] = 2;
    primes[1] = 3;
    upto -= 6;
    while (n <= upto) {
        n += 4;
        if (is_prime(primes, c, n)) {
            ++c;
            primes = realloc(primes, c*sizeof(int));
            primes[c-1] = n;
        }
        n += 2;
        if (is_prime(primes, c, n)) {
            ++c;
            primes = realloc(primes, c*sizeof(int));
            primes[c-1] = n;
        }
    }
    *count = c;
    return primes;
}

int is_palindrome(char* n, int len) {
    /* Return 1 if string n is palindrome, else 0
     */
    int i;
    for (i = 0; i < len/2; i++)
        if (n[i] != n[len-i-1])
            return 0;
    return 1;
}

int is_palindrome_i(int* digits, int len) {
    /* Return 1 if int array digits is palindrome, else 0
     */
    int i;
    for (i = 0; i < len/2; i++)
        if (digits[i] != digits[len-i-1])
            return 0;
    return 1;
}

char* getSubstring(char* word, int start, int end) {
    /* Return substring of word on range [start, end)
     */
    int i, c;
    char* sub = (char*)malloc(sizeof(char) * (end - start + 1));
    for (i = start, c = 0; i < end; ++i)
        sub[c++] = word[i];
    // remember to mark end of string
    sub[c] = '\0';
    return sub;
}

int is_pandigital(int* num_arr, int len) {
    /* Return 1 if num_arr is pandigital:
     * contains every digit in range [1,len] exactly once
     * else return 0
     */
    for (int i = 1; i <= len; ++i)
        if (linear_search(i, num_arr, len) == -1)
            return 0;
    return 1;
}

int is_pandigital_with_0(int *num_arr, int len) {
    /* Return 1 if num_arr is pandigital, including 0:
     * contains every digit in range [0,len) exactly once
     * else return 0
     */
    for (int i = 0; i < len; ++i)
        if (linear_search(i, num_arr, len) == -1) 
            return 0;
    return 1;
}

int *split_number(int num, int* len) {
    /* Return an array whose elements are each digit of num
     * Update len with the length of the array
     */
    int c;
    int* num_arr = malloc(sizeof(int) * 100);
    for (c = 0; num > 0; num /= 10)
        num_arr[c++] = num % 10;
    num_arr = realloc(num_arr, sizeof(int) * c);
    *len = c;
    reverse_iarray(num_arr, c);
    return num_arr;
}

long join_number(int *split, int len) {
    long int joined = 0;
    for (int i = 0; i < len; ++i)
        joined += split[i] * pow(10, (len - i - 1));
    return joined;
}

long int factorial(int n) {
    /* Return n!
     */
    if (n == 0 || n == 1)
        return 1;
    int fact = 1;
    for (; n > 1; --n)
        fact *= n;
    return fact;
}

long triangular_number(int term) {
    return (term*(term+1)) / 2;
}

int is_triangular(long num) {
    int n = sqrt(2*num+0.25) - 0.5;
    return (num == n*(n+1)/2);
}

long pentagonal_number(int term) {
    // make sure that divide by 2 happens at the end
    return (term*(3*term-1))/2;
}

int is_pentagonal(long num) {
    int n = (sqrt(24*num+1) + 1) / 6;
    return ((n*(3*n-1))/2 == num);
}

long hexagonal_number(int term) {
    return (term * (2*term - 1));
}

int is_hexagonal(long num) {
    int n = (sqrt(8*num+1)+1) / 4;
    return (n * (2*n - 1) == num);
}

