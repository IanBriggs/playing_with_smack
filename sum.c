#ifndef NO_SMACK
#include "smack.h"
#else
#include <assert.h>
#endif

#include <pthread.h>
#include <stdio.h>

int thread_count = 3;
int sum = 0;
pthread_mutex_t sum_mutex = PTHREAD_MUTEX_INITIALIZER;


void* worker(void * unneded) {
  int i;
  int local_sum=0;
  int new_sum;

  for (i=0; i<2; i++)
    local_sum += 1;

  new_sum = sum + local_sum;

  pthread_mutex_lock(&sum_mutex);
  sum = new_sum;
  pthread_mutex_unlock(&sum_mutex);

  return NULL;
}

int main() {
  int n = 30;
  int i;

  pthread_t threads[3];
  for (i=0; i<thread_count; i++)
    pthread_create(&threads[i], NULL, worker, NULL);

  void* junk;
  for (i=0; i<thread_count; i++)
    pthread_join(threads[i], &junk);

  assert(sum == 2*thread_count);
  
  return 0;
}
