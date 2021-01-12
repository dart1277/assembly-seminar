#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define SZ 1024*24

typedef int num_t;

void calculate_time(struct timeval *start, struct timeval *end, time_t *seconds,
                    suseconds_t *micros);

num_t tab[SZ][SZ];

void branches(){
	for(int i=0; i<SZ; ++i){
		for(int j=0; j<SZ; ++j){			
			if(__builtin_expect(!!(i),1)){
				tab[i][j]=2*j;
				asm volatile(".align 128 \n\t""nop \n\t");
			}		
			else {

			tab[i][j]=i+j;

			}
			
		}

	}
}

int main(void){
  struct timeval start0, end0;
  suseconds_t micros;
  time_t seconds;

gettimeofday(&start0, NULL);

branches();

gettimeofday(&end0, NULL);
calculate_time(&start0, &end0, &seconds, &micros);

return 0;
}

void calculate_time(struct timeval *start, struct timeval *end, time_t *seconds,
                    suseconds_t *micros) {
  *micros = end->tv_usec - start->tv_usec;
  *seconds = end->tv_sec - start->tv_sec - (*micros < 0 ? 1 : 0);
  *micros = *micros < 0 ? 1000000 + *micros : *micros;
  printf("It took: %d sec %d usec\n", *seconds, *micros);
}
