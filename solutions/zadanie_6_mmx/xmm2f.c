#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#define TEST_ITERS 512
#define VSZ 4 * 1024 * 1024
#define ALIGNMENT 16

void calculate_time(struct timeval *start, struct timeval *end, time_t *seconds, suseconds_t *micros);

struct output{
char c;
__attribute__((aligned(ALIGNMENT))) float out[4];
}out;

int main(void) {
  // time
  struct timeval start0, end0, start1, end1;
  suseconds_t micros;
  time_t seconds;

  float *v1 = aligned_alloc(ALIGNMENT, VSZ * sizeof(float));

  for (int i = 0; i < VSZ; ++i) {
    v1[i] = 1. / (i + 1) / (i + 1);
  }

  gettimeofday(&start0, NULL);

  for (int j = 0; j < TEST_ITERS; ++j) {
    out.out[0] = out.out[1] = out.out[2] = out.out[3] = 0.;
    asm("pxor xmm2, xmm2" ::: "xmm2");
    for (int i = 0; i < VSZ / 4; ++i) {
      asm("movaps xmm0, XMMWORD PTR %0\n\t"
          "movaps xmm1, XMMWORD PTR %1\n\t"
          "mulps xmm0, xmm1\n\t"
          "addps xmm2, xmm0" ::"m"(v1[4 * i]), "m"(v1[4 * i])
          : "xmm0", "xmm1", "xmm2");
    }
    asm("movntps %0, xmm2" : "=m"(out.out)::"xmm2");
  }

  gettimeofday(&end0, NULL);

  float prod = out.out[0] + out.out[1] + out.out[2] + out.out[3];
  printf("xmm  %.10f\n", sqrt(prod));

  gettimeofday(&start1, NULL);
  float chk = 0.;
  for (int j = 0; j < TEST_ITERS; ++j) {
    chk = 0.;
    for (int i = 0; i < VSZ; ++i) {
      chk += v1[i] * v1[i];
    }
  }
  gettimeofday(&end1, NULL);

  printf("loop %.10f\n", sqrt(chk));
  calculate_time(&start0, &end0, &seconds, &micros);
  calculate_time(&start1, &end1, &seconds, &micros);

  free(v1);
  return 0;
}


void calculate_time(struct timeval *start, struct timeval *end, time_t *seconds,
                    suseconds_t *micros) {
  *micros = end->tv_usec - start->tv_usec;
  *seconds = end->tv_sec - start->tv_sec - (*micros < 0 ? 1 : 0);
  *micros = *micros < 0 ? 1000000 + *micros : *micros;
  printf("It took: %d sec %d usec\n", *seconds, *micros);
}

