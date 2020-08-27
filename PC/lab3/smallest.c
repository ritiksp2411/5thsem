#include <stdio.h>
#include <omp.h>
int main(){
	int array[]={12,15,8,3,24,56,65,67,1},i;
	int cur_min=10000;
    #pragma omp parallel for
    for(i=0; i<9; i++){
        if(array[i]<cur_min)
            #pragma omp critical
                if(array[i]<cur_min)
                    cur_min=array[i];
    }
	printf("The smallest number in given array is %d\n",cur_min);
    return 0;
}