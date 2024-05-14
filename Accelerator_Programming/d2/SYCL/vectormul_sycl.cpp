#include<iostream>
#include<CL/sycl.hpp>


using std::cout;
using std::endl;
using namespace sycl;

#define N 10


int main(){

	int i, j, k;
	
    	// Declare queue object here:
    	queue Q(cpu_selector_v);

    	int A[N][N], B[N][N], C[N][N];

        // int *A = (int*)malloc_shared(sizeof(int)*N*N, Q);
    	// int *B = (int*)malloc_shared(sizeof(int)*N*N, Q);
    	// int *C = (int*)malloc_shared(sizeof(int)*N*N, Q);
 
        // Initializing the matrix's
        for(i=0; i<N; i++){
    		for(j=0; j<N; j++){
                	A[i][j] = (j%10)+1;
                }
        }
    
        for(i=0; i<N; i++){                                  
		for(j=0; j<N; j++){
			B[i][j] = (j%10)+1;                                   }
        }

	// Create SYCL buffers for matrix A, B and C here:

    	buffer<int, 2> buff_A((int*)A, range<2>(N,N));
	buffer<int, 2> buff_B((int*)B, range<2>(N,N));
    	buffer<int, 2> buff_C((int*)C, range<2>(N,N));
    	Q.submit([&](handler &cgh){
		// Create SYCL accessors for buffers buff_a, buff_b, buff_c here:
		auto accessorA = buff_A.get_access<access::mode::read>(cgh);
		auto accessorB = buff_B.get_access<access::mode::read>(cgh);
    		auto result = buff_C.get_access<access::mode::write>(cgh);
		cgh.parallel_for<class MatrixMultiply>(range<2>(N,N), [=](item<2> item){
   			// Define iterator using items here:
   			int i = item.get_id(0);
    			int j = item.get_id(1);
    			int k;
    			int sum = 0;
			for(k=0; k<N; k++){
				sum += accessorA[i][k] * accessorB[k][j];
			}
    			result[item] = sum;
    		});
    	}).wait();

	cout << "\n\nFirst matrix :"<<std::endl;
	for(i=0; i<N; i++){
		cout << "\t\t\t" << std::endl;
		for(j=0; j<N; j++)
			cout << A[i][j] << " ";
	}
	cout << "\n\nSecond matrix :" << std::endl;
	for(i=0; i<N; i++){
		cout << "\t\t\t" << std::endl;
		for(j=0; j<N; j++)
			cout << B[i][j] << " ";
	} 
	cout << "\n\nResultant matrix :" << std::endl;
	for(i=0; i<N; i++){
		cout << "\t\t\t" << std::endl;
		for(j=0; j<N; j++)
			cout << C[i][j] << " ";
	} cout << "\n\n";
	return 0;
}
