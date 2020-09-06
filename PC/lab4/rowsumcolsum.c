#include<stdio.h>
#include<omp.h>
int main()
{
    int sum=0;
    int n;
    double t1,t2;    
    printf("Enter the value of the n: ");
    scanf("%d",&n);
    int a[n][n];
    #pragma omp for schedule(static,8) collapse(2)
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            a[i][j]=rand()%1000;
        }
    }
    // n=3;
    // int a[3][3]={
    //     1,2,3,
    //     4,5,6,
    //     7,8,9
    // };
    t1=omp_get_wtime();
    // printf("Row sum is : ");
    for(int i=0; i<n; i++){
        sum=0;
        #pragma omp parallel for schedule(static,8) reduction(+:sum)
        for(int j=0; j<n; j++) sum=sum+a[i][j];
        // printf("%d ",sum);
    }
    // printf("\n\nCol sum is : ");
    for(int i=0; i<n; i++){
        sum=0;
        #pragma omp parallel for schedule(static,8) reduction(+:sum)
        for(int j=0; j<n; j++) sum=sum+a[j][i];
        // printf("%d ",sum);
    }
    t2=omp_get_wtime();
    printf("\n\ntime required in parallal :%f s",t2-t1);
    t1=omp_get_wtime();
    // printf("\n\nRow sum is : ");
    for(int i=0; i<n; i++){
        sum=0;
        for(int j=0; j<n; j++) sum=sum+a[i][j];
        // printf("%d ",sum);
    }
    // printf("\n\nCol sum is : ");
    for(int i=0; i<n; i++){
        sum=0;
        for(int j=0; j<n; j++) sum=sum+a[j][i];
        // printf("%d ",sum);
    }
    t2=omp_get_wtime();
    printf("\n\ntime required in sequential :%f s\n",t2-t1);
    return 0;
}
