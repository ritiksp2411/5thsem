#include <stdio.h>
#include <omp.h>
int index=-1;
void binarySearchseq(int arr[], int l, int r, int x) {
    while (l <= r){ 
        int m = l + (r - l) / 2;
        if (arr[m] == x){
            printf("Found\n\n");
        }
        if (arr[m] < x) l = m + 1; 
        else r = m - 1; 
    }
    return ; 
}
int binarySearchpar(int arr[],int l,int r,int x){
    if(l>=r) return -1;
    int ind=l+r;
    ind=ind/2;
    if(arr[ind]==x){
        return ind;
    }
    int left,right;
    #pragma omp task
    right=binarySearchpar(arr,ind+1,r,x);
    #pragma omp task
    left=binarySearchpar(arr,l,ind-1,x);
    #pragma omp taskwait
    if(right>left) return right;
    return left;
}
int main(){
    int n;
    double t1,t2;
    printf("Enter the value of N\n");
    scanf("%d", &n);
	int array[n];
    int i;
    int ele;
    int flag=0;
    array[0]=5;
    #pragma omp for schedule(static,8)
    for(int i=1;i<n;i++){
            array[i]=array[i-1] + rand()%10;
    }
    ele=array[n/7];
    t1=omp_get_wtime();
    binarySearchseq(array,0,n-1,ele);
    t2=omp_get_wtime();
    printf("Time taken for sequential : %f s\n\n", t2-t1);
    t1=omp_get_wtime();
    index=binarySearchpar(array,0,n-1, ele);   
    t2=omp_get_wtime();
    if(index!=-1) printf("Found at %d\n\n",index);
    else printf("Not Found");
    printf("Time taken for parallal: %f s", t2-t1);
    return 0;
}