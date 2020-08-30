#include <stdio.h>
#include <sys/time.h>
#include <omp.h>
#include <stdlib.h>
int main(){
    struct timeval TimeValue_Start;
    struct timezone TimeZone_Start;
    struct timeval TimeValue_Final;
    struct timezone TimeZone_Final;
    long time_start, time_end;
    double time_overhead;
    int n=50000;
	int array[n],i;
    for(int i=0; i<n; i++){
        array[i]=rand();
    }
	int cur_min=array[0];
    gettimeofday(&TimeValue_Start, &TimeZone_Start);
    #pragma omp parallel for schedule(dynamic,8) num_thread(2)
    for(i=0; i<n; i++){
        if(array[i]<cur_min)
            #pragma omp critical
                if(array[i]<cur_min)
                    cur_min=array[i];
    }
    gettimeofday(&TimeValue_Final, &TimeZone_Final);
    time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
    time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
    time_overhead = (time_end - time_start)/1000000.0;
    printf("\n\n\tTime in Seconds (T) : %lf\n",time_overhead);
	printf("The smallest number in given array is %d\n",cur_min);
    return 0;
}
