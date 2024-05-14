#include<iostream>
#include<CL/sycl.hpp>

using std::cout;
using std::endl;
using namespace sycl;

#define N 10

int main(){
    int *dataA, *dataB, *dataC, i;
    queue Q;

    dataA = new int[N];
    dataB = new int[N];
    dataC = new int[N];

    for(i = 0; i < N; i++){
        dataA[i] = 90;
        dataB[i] = 10;
    }

    buffer<int, 1> buff_a(dataA, range(N));
    buffer<int, 1> buff_b(dataB, range(N));
    buffer<int, 1> buff_c(dataC, range(N));

    Q.submit([&](handler &cgh){
        auto acc_A = buff_a.get_access<access::mode::read>(cgh);
        auto acc_B = buff_b.get_access<access::mode::read>(cgh);
        auto acc_C = buff_c.get_access<access::mode::read_write>(cgh);

        cgh.parallel_for(range<1>(N), [=](id<1> indx){
            acc_C[indx] = acc_A[indx] + acc_B[indx];
        });
    });

    auto C = buff_c.get_access<access::mode::read>();

    for(i=0; i<N; i++){
        cout << C[i] << " ";
    }

    cout << std::endl;

    delete[] dataA;
    delete[] dataB;
    delete[] dataC;

    return 0;
}
