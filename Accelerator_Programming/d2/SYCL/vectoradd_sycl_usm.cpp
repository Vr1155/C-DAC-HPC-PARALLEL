#include<iostream>
#include<CL/sycl.hpp>

using std::cout;
using std::endl;
using namespace sycl;

#define N 10

int main(){
	int i;
	queue Q(cpu_selector_v);
		
	int *dataA = (int*)malloc_shared(sizeof(int)*N, Q);
	int *dataB = (int*)malloc_shared(sizeof(int)*N, Q);
	int *dataC = (int*)malloc_shared(sizeof(int)*N, Q);

	for(i = 0; i < N; i++){
		dataA[i] = 90;
		dataB[i] = 10;
	}

	Q.parallel_for(range<1>(N), [=](id<1> indx){
		dataC[indx] = dataA[indx] + dataB[indx];
	}).wait();

	for(i = 0; i < N; i++){
		cout << dataC[i] << " ";
	}
	cout << std::endl;

	return 0;
}
