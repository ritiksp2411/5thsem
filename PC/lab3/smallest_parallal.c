#include <stdio.h>
#include <sys/time.h>
#include <omp.h>
#include <stdlib.h>
int main(){
    struct timeval TimeValue_Start;
    struct timezone TimeZone_Start;
    struct timeval TimeValue_Final;
    struct timezone TimeZone_Final;
    long time_start1, time_end1;
    double time_overhead1;
    int n=1000000;
	int array[n],i;
    for(int i=0; i<n; i++){
        array[i]=rand();
    }
    long time_start2, time_end2;
    double time_overhead2;
	int cur_min2=array[0];
    gettimeofday(&TimeValue_Start, &TimeZone_Start);
    #pragma omp parallel for schedule(runtime) num_threads(21)
    for(i=0; i<n; i++){
        if(array[i]<cur_min2)
            #pragma omp critical
                if(array[i]<cur_min2)
                    cur_min2=array[i];
    }
    gettimeofday(&TimeValue_Final, &TimeZone_Final);
    time_start2 = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
    time_end2 = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
    time_overhead2 = (time_end2 - time_start2)/1000000.0;
    printf("\n\n\tTime in Parallal Seconds (T) : %lf\n",time_overhead2);
	printf("The smallest number in given array is %d\n",cur_min2);
	int cur_min1=array[0];
    gettimeofday(&TimeValue_Start, &TimeZone_Start);
    for(int i=1; i<n; i++){
        if(cur_min1 > array[i]) cur_min1=array[i];
    }
    gettimeofday(&TimeValue_Final, &TimeZone_Final);
    time_start1 = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
    time_end1 = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
    time_overhead1 = (time_end1 - time_start1)/1000000.0;
    printf("\n\n\tTime in Sequential Seconds (T) : %lf\n",time_overhead1);
	printf("The smallest number in given array is %d\n",cur_min1);
    return 0;
}
