#include <assert.h>
#include "fun.h"

void __attribute__ ((noinline)) fun(num_t* __restrict  out,
 num_t* __restrict src, num_t* __restrict  coeff, int n)
{
  int i,j,k;
  assert(n % coeff_sz == 0);
  n = n/coeff_sz;
  for(i=0; i<coeff_sz; i++)out[i]=0.; 
   src  += coeff_sz;
   out += coeff_sz;

  for (i=1; i<n; i++)
  {
    for(j=0;j<coeff_sz;++j){
	out[j]=0;
	for(k=0;k<coeff_sz;++k)
    		out[j] += src[k-coeff_sz+j] * coeff[k] ;
	}

    src  += coeff_sz;
    out += coeff_sz;
  }
}
