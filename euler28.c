#include "euler.h"

int main(int argc, char** argv);

int main(int argc, char** argv) {
    const int Dimensions = 1001;
    long int sum = 1;
    for (int i = 3; i <= Dimensions; i+=2) {
        sum += 4*i*i - 6*(i-1);
    }
    printf("Sum: %ld\n", sum);
    return 0;
}
