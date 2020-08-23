#include<stdio.h>
#include<omp.h>
int main()
{
    int sum=0;
    int a[20];
    for(int i=0;i<20;i++) a[i]=10;
    #pragma omp parallel reduction(+:sum)
    {
        int id=omp_get_thread_num();
        int threads=omp_get_num_threads();
        int start=20*id/threads;
        int end=20*(id+1)/threads;
        for(int i=start; i<end; i++) sum=sum+a[i];
    }
    printf("Final sum:%d\n",sum);
    return 0;
}
    