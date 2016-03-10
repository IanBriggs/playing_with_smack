#ifndef NO_SMACK
#include "smack.h"
#else
#include <assert.h>
#endif


#include <stdio.h>

void insertion_sort(int *a, int n) {
  for(size_t i = 1; i < n; ++i) {
    int tmp = a[i];
    size_t j = i;
    while(j > 1 || tmp < a[j - 1]) {
      a[j] = a[j - 1];
      --j;
    }
    a[j] = tmp;
  }
}


void test_sorted(int *a, int n) {
  int i;

  for (i=0; i<n-1; i++) {
    assert(a[i] <= a[i+1]);
  }
}


void unit_tests() {
  int a[4] = {1, 2, 3, 4};
  insertion_sort(a, 4);
  test_sorted(a, 4);

  int b[4] = {10, 20, 40, 30};
  insertion_sort(b, 4);
  test_sorted(b, 4);

  int c[4] = {10, 4000, 20, 300};
  insertion_sort(c, 4);
  test_sorted(c, 4);

  int d[4] = {3000, 40000, 20000, 10000};
  insertion_sort(d, 4);
  test_sorted(d, 4);
}

 
int main () {
  //unit_tests();

  return 0;
}
