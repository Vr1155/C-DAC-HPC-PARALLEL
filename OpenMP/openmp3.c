#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
        int cores, nthreads, tid, procs, maxt, inpar, dynamic, nested;

        #pragma omp parallel
        {
                tid = omp_get_thread_num();

		// this wont run if your cpu has less than 7 cores:
                if(tid == 6){
                        printf("Thread %d getting Info..\n", tid);
                        cores = omp_get_num_procs();
                        nthreads = omp_get_num_threads();
                        maxt = omp_get_max_threads();
                        inpar = omp_in_parallel();

                        printf("Number of cores = %d\n", cores);
                        printf("Number of threads = %d\n", nthreads);
                        printf("Max threads = %d\n", maxt);
                        printf("In parallel? = %d\n", inpar);
                }
        }
}

