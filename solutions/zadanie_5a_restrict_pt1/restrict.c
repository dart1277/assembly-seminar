#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "fun.h"
#define sz 64*1024

void calculate_time(struct timeval *start, struct timeval *end, time_t *seconds,
                    suseconds_t *micros);
void save(num_t* tab, const char* name, const int n);


num_t src_tab[sz];
num_t out_tab[sz];

int main (int argc, char**args)
{
srand(time(NULL));
struct timeval start, end;
  suseconds_t micros;
  time_t seconds;

  int i,j;

  num_t coeff[coeff_sz];
  for (i=0; i<coeff_sz; i++)   coeff[i] = 1./coeff_sz;
  for (i=0; i<sz; i++) src_tab[i] = i % 64 + 5*( 1.*rand()/RAND_MAX -.5);


gettimeofday(&start, NULL);
  for (j=0; j<50000; j++)
    fun(out_tab, src_tab, coeff, sz);
gettimeofday(&end, NULL);

save(src_tab,"source.dat",sz);
save(out_tab,"destination.dat",sz);
calculate_time(&start, &end, &seconds, &micros);

}

void save(num_t* t, const char* name, const int n){
FILE* fp = fopen(name,"w");
for(int i=0; i < n; ++i)fprintf(fp,"%.4f\n",t[i]);
fclose(fp);
}

void calculate_time(struct timeval *start, struct timeval *end, time_t *seconds,
                    suseconds_t *micros) {
  *micros = end->tv_usec - start->tv_usec;
  *seconds = end->tv_sec - start->tv_sec - (*micros < 0 ? 1 : 0);
  *micros = *micros < 0 ? 1000000 + *micros : *micros;
  printf("It took: %d sec %d usec\n", *seconds, *micros);
}
