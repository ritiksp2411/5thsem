#include <stdio.h>
#include <omp.h>
int main(){
	int array[]={12,15,8,3,24,56,65,1,67,44},i,cur_max;
	cur_max=0;
    #pragma omp parallel for
    for(i=0; i<10; i++){
        if(array[i]>cur_max)
            #pragma omp critical
                if(array[i]>cur_max)
                    cur_max=array[i];
    }
	printf("The largest number in given array is %d\n",cur_max);
    return 0;
}