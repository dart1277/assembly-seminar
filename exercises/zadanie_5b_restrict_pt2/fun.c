#include <assert.h>
#include "fun.h"

void __attribute__ ((noinline)) fun(num_t*  out,
 num_t* src, num_t*  coeff, int n)
{
  int i,j,k;
  assert(n % coeff_sz == 0);
  n = n/coeff_sz;
  for(i=0; i<coeff_sz; i++)out[i]=0.; 
   src  += coeff_sz;
   out += coeff_sz;

  for (i=1; i<n; i++)
  {
    
    out[0] = src[-4] * coeff[0] + src[-3] * coeff[1] + src[-2] * coeff[2] + src[-1] * coeff[3];

    out[1] = src[-3] * coeff[0] + src[-2] * coeff[1] + src[-1] * coeff[2] + src[0] * coeff[3];

    out[2] = src[-2] * coeff[0] + src[-1] * coeff[1] + src[0] * coeff[2] + src[1] * coeff[3];

    out[3] = src[-1] * coeff[0] + src[0] * coeff[1] + src[1] * coeff[2] + src[2] * coeff[3];

    src  += coeff_sz;
    out += coeff_sz;
  }
}
