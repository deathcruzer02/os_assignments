#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int chunk=100;

void* getSum(void* range)
{
  int sum=0;
  int end=(int)range;
  int start=(end-100)+1;
  for(start;start<=end;start++)
  {
    sum=sum+start;
  }
  return ((void*)sum);
}

int main()
{
  int totalSum=0;
  int sums[10];
  pthread_t threads[10];

  int start=1;
  int end=10;
  int i=0;
  for(start;start<=end;start++)
  {
    pthread_create(&threads[i],NULL,getSum,start*chunk);
    i++;
  }

  start=1;i=0;
  for(start;start<=end;start++)
  {
    pthread_join(threads[i],(void**)&sums[i]);
    i++;
  }

  start=0;
  for(start;start<end;start++)
  {
    totalSum=totalSum+sums[start];
  }

  printf("sum of first 1000 natural numbers using 10 threads: %d\n",totalSum);
  return 0;
}
