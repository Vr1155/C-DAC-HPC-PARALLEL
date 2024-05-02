#include <stdio.h>
#include <omp.h>
#include <sys/time.h>
#define SIZE 4000
int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
int main() {
    int i, j, k;
    struct timeval tv1, tv2;
    struct timezone tz;
        double elapsed;
       for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            A[i][j] = 1;
            B[i][j] = 1;
            C[i][j] = 0;
        }
    }

    gettimeofday(&tv1, &tz);
    #pragma omp parallel for private(i, j, k)
    for(i = 0; i < SIZE; i++) {
        for(k = 0; k < SIZE; k++) {
            for(j = 0; j < SIZE; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    gettimeofday(&tv2, &tz);
    elapsed = (double) (tv2.tv_sec-tv1.tv_sec) + (double) (tv2.tv_usec-tv1.tv_usec) * 1.e-6;
    printf("elapsed time = %f seconds.\n", elapsed);
    return 0;
}

