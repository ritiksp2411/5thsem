#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main (void) {
   int i,j,k;
   #pragma omp parallel
   {
       #pragma omp for schedule(static,3) private(i,j) collapse(3)
       for(i=0;i<2;i++)
           for(j=0;j<3;j++)
           {
               for(k=0; k<2; k++){
                   int tid2=omp_get_thread_num();
          printf("tid=%d, i=%d, j=%d, k=%d\n",omp_get_thread_num(),i,j,k);
               }
           }
   }
   return 0;
}
