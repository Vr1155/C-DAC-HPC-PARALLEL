#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

        int nthreads, tid;

        // Fork a team of threads by giving them their own copies of variables
        #pragma omp parallel private(nthreads, tid) num_threads(4)
        {       // Notice that you cannot put { in same line
                // because # represents a pre-processor directive.

                // Obtain thread number and print it
                tid = omp_get_thread_num();
                printf("Hello World from thread = %d\n", tid);

                // Only master thread does this:
                if(tid == 0){
                        nthreads = omp_get_num_threads();
                        printf("Number of threads = %d\n", nthreads);
                }
        }       // All threads join master thread
} 
