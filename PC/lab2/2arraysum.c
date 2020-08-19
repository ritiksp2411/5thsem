#include<omp.h>
#include<stdio.h>
int main(){
    int i,n=20;
    int a[20],b[20],c[20];
    for(i=0;i<n;i++){ 
        b[i]=i*4;
        c[i]=i*6;
    }
    #pragma omp parallel for schedule(static,2)
    for(i=0;i<n;i++)
    {
        a[i]=b[i]+c[i];
        printf("Thread id= %d i=%d,a[%d]=%d\n", omp_get_thread_num(),i,i,a[i]);
    }
}