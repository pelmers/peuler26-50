#include "euler.h"

int main(int argc, char **argv);

int main(int argc, char **argv) {
    int s3, s3_squared;
    int perimeters[1001];
    int max = 0;
    memset(perimeters, 0, sizeof(int)*1001);
    for (int s1 = 1; s1 < 500; ++s1) {
        for (int s2 = 1; s2 < 500; ++s2) {
            s3_squared = s1*s1 + s2*s2;
            s3 = sqrt(s3_squared);
            if (s3*s3 == s3_squared)
                if (s3+s2+s1 < 1000)
                    ++perimeters[s3+s2+s1];
        }
    }
    for (int i = 1; i < 1001; ++i)
        if (perimeters[i] > perimeters[max])
            max = i;
    printf("Max perimeter: %d\n", max);
    return 0;
}
