#include <stdio.h>
#include <omp.h>
int index=-1;
void binarySearchseq(int arr[], int l, int r, int x) {
    while (l <= r){ 
        int m = l + (r - l) / 2;
        if (arr[m] == x) printf("Found\n\n");
        if (arr[m] < x) l = m + 1; 
        else r = m - 1; 
    }
    return ; 
}
int main(){
    int n;
    double t1,t2;
    printf("Enter the value of N\n");
    scanf("%d", &n);
	int array[n];
    int i;
    int ele;
    printf("Element to search\n");
    scanf("%d",&ele);
    int flag=0;
    #pragma omp for schedule(static,8)
    for(int i=0;i<n;i++){
            array[i]=rand()%1000;
    }
    t1=omp_get_wtime();
    for(i=0; i<n; i++){
        if(array[i]==ele){
            flag=1;
            index=i;
        }
    }
    t2=omp_get_wtime();
    printf("Time taken for sequential linear : %f s\n\n", t2-t1);
    t1=omp_get_wtime();
    binarySearchseq(array,0,n-1,ele);
    t2=omp_get_wtime();
    printf("Time taken for sequential binary : %f s\n\n", t2-t1);
    t1=omp_get_wtime();
    #pragma omp parallel for schedule(static,12)
    for(i=0; i<n; i++){
        if(array[i]==ele){
            flag=1;
        }
    }
    t2=omp_get_wtime();
    if(index==-1) printf("Not Found\n\n");
    else printf("Found at %d\n\n",index);
    printf("Time taken for parallal: %f s", t2-t1);
    return 0;
}