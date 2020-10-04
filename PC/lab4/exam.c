#include<stdio.h>
#include<omp.h>
int main()
{
    int sum[1000];
    int sum2=0;
    int n=1000;
    double t1,t2;
    int a[1000][24];
    #pragma omp parallel for
    for(int i=0; i<n; i++){
        sum[i]=0;
        #pragma omp parallel for schedule(static,8) reduction(+:sum[i])
        for(int j=0; j<24; j++) sum[i]=sum[i]+a[i][j];
    }
    #pragma omp parallel for schedule(static,8) reduction(+:sum2)    
    for(int j=0; j<n; j++) sum2=sum2+sum[j];
    printf("The avg. of the each sensor");
    for(int i=0; i<n; i++){
        print("%f ", (float)sum[i]/24);
    }
    printf("\nThe avg. of the all sensors\n");
    print("%f ", (float)sum2/1000);
    return 0;
}
