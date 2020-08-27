#include<omp.h>
#include<stdio.h>
int main(){
    int x=10;
    #pragma omp parallel private(x) num_threads(4)
    {
        x=x+1;
        printf("%d\n",x);
        int tid=omp_get_thread_num();
        printf("Hello world from thread=%d\n",tid);
    }
}