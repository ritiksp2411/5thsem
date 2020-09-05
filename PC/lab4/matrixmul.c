#include <stdio.h>
#include <omp.h>
int main() 
{
    int n;
    double t1,t2;    
    printf("Enter the value of the n: ");
    scanf("%d",&n);
    int a[n][n],b[n][n];
    int c[n][n];
    #pragma omp for schedule(static,8) collapse(2)
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            a[i][j]=rand()%1000;
            b[i][j]=rand()%1000;
        }
    }
    t1=omp_get_wtime();
    #pragma omp parallel for schedule(static,12) num_threads(12)
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    t2=omp_get_wtime();
    printf("\n\nTime for parallal : %f s\n\n\n\n", t2-t1);
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<n; j++) printf("%d ",c[i][j]);
    //     printf("\n");
    // }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) c[i][j]=0;
    }
    t1=omp_get_wtime();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    t2=omp_get_wtime();
    printf("\n\nTime for sequential : %f s\n\n\n\n", t2-t1);
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<n; j++) printf("%d ",c[i][j]);
    //     printf("\n");
    // }
}
 