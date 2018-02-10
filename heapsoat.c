//e1433 ヒープソート

#include <stdio.h>
#include <stdlib.h>

#define N 1000000

int seed = 100;

void init(int A[]){
  int i;

  srand((unsigned int) seed);

  for(i = 1; i <= N; i++){
    A[i] = rand();
  }

  printf("%d\n", A[500000]);
}

int main(void){
  int A[1000000];
  init(A);

}
