#include<omp.h>
#include<stdio.h>
int main(){
    int i,n=40;
    int a[40],b[40],c[40];
    for(i=0;i<n;i++){ 
        b[i]=i*4;
        c[i]=i*6;
    }
    #pragma omp parallel for schedule(static,4)
    for(i=0;i<n;i++)
    {
        a[i]=b[i]+c[i];
        printf("Thread id= %d i=%d,a[%d]=%d\n", omp_get_thread_num(),i,i,a[i]);
    }
}