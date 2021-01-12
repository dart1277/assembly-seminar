#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

typedef int num_t;

#define inner_loop inner_loop0
#ifdef A 
  #define insertion_sort insertion_sort1

#endif

#ifdef B 
  #define insertion_sort insertion_sort2
#endif

#ifdef C 
  #define insertion_sort insertion_sort2
  #undef inner_loop
  #define inner_loop inner_loop1
#endif

#ifdef D 
  #define insertion_sort insertion_sort3
#endif

#ifdef IL 
  void  inner_loop0(num_t* t, int sz){}
#endif



void  inner_loop0(num_t*, int);
void  inner_loop1(num_t*, int);
void  insertion_sort3(num_t*, int);
void  init_tab(num_t **tabp, size_t sz, int);
void  is_sorted(num_t *tab, const size_t sz);
void  is_sorted_rev(num_t *tab, const size_t sz);
void  calculate_time(struct timeval *start, struct timeval *end, time_t *seconds,
                    suseconds_t *micros);


void insertion_sort1(num_t *tab, const size_t sz) {
  for (int i = 1; i < sz; ++i) {
    num_t current = tab[i];
    int j = i - 1;
    for (; j >= 0; --j) {
      if (tab[j] > current)
        tab[j + 1] = tab[j];
      else
        break;
    }
    tab[j + 1] = current;
  }
}

void insertion_sort2(num_t *tab, const size_t sz) {
  for (int i = 1; i < sz; ++i) {
  	inner_loop(tab,i);
  }
}


int main(void) {
  const size_t TEST_SZ = 1024*32; //* 128;
  num_t *test_table = 0;
  // time
  struct timeval start, end;
  suseconds_t micros;
  time_t seconds;

  // init
  init_tab(&test_table, TEST_SZ, 0);

  // check
  is_sorted_rev(test_table, TEST_SZ);

  is_sorted(test_table, TEST_SZ);

  printf("Sort start\n");

  gettimeofday(&start, NULL);

  // sort
  insertion_sort(test_table, TEST_SZ);

  gettimeofday(&end, NULL);

  is_sorted(test_table, TEST_SZ);

  calculate_time(&start, &end, &seconds, &micros);

  free(test_table);
  return 0;
}

void is_sorted_rev(num_t *tab, const size_t sz) {
  int sorted = 1;
  for (int i = 0; i < sz - 1; ++i)
    if (tab[i + 1] > tab[i]) {
      sorted = 0;
      break;
    }
  printf("Table is %ssorted in descending order\n", sorted ? "" : "not ");
}

void is_sorted(num_t *tab, const size_t sz) {
  int sorted = 1;
  for (int i = 0; i < sz - 1; ++i)
    if (tab[i + 1] < tab[i]) {
      sorted = 0;
      break;
    }
  printf("Table is %ssorted in ascending order\n", sorted ? "" : "not ");
}

void init_tab(num_t **tabp, size_t sz, int rnd ) {
  (*tabp) = malloc(sz * sizeof(**tabp));
  srand(time(0));
  for (int i = 0; i < sz; ++i) {
	if(!rnd)
	    (*tabp)[i] = sz - i - 1;
	else
	(*tabp)[i] = rand() % 1024;
  }

}

void calculate_time(struct timeval *start, struct timeval *end, time_t *seconds,
                    suseconds_t *micros) {
  *micros = end->tv_usec - start->tv_usec;
  *seconds = end->tv_sec - start->tv_sec - (*micros < 0 ? 1 : 0);
  *micros = *micros < 0 ? 1000000 + *micros : *micros;
  printf("It took: %d sec %d usec\n", *seconds, *micros);
}

