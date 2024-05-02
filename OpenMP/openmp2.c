#include<stdio.h>
#include<omp.h>

int main(){
        #pragma omp parallel num_threads(8)
        printf("Welcome to CDAC Bangalore\n");
}

