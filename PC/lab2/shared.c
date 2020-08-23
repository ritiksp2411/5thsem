#include<omp.h>
#include<stdio.h>
int main(){
    int x=0;
    #pragma omp parallel shared(x)
    {
        int tid=omp_get_thread_num();
        x=x+1;
        printf("Thread [%d] value of x is %d \n",tid,x);
    }
}
//gcc prog1.c -fopenmp