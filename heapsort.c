// e1433 藤本 恭子 「ヒープソート」
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 1000000

int n = 0;
int h[HEAP_SIZE];
int A[HEAP_SIZE];

void init(int seed){
  srand((unsigned int)seed);
  for(int i = 1; i <= HEAP_SIZE; i++){
    A[i] = rand();
  } 
}

void down(int k){
  int r = n;
  int i = 2 * k;
  int v = h[k];
  while(i <= r){
    if(i < r && h[i] < h[i+1]) i++;
    if(h[i] <= v) break;
    h[k] = h[i];
    k = i; i = 2 * k;
  }
  h[k] = v;
}

void get(){
  int temp = h[1];
  h[1] = h[n];
  h[n] = h[1];
  n = n - 1;
  down(1);
}

void up(){
  int k = n;
  int i = k / 2;
  int v = h[k];
  while(i >= 1){
    if(h[i] >= v) break;
    h[k] = h[i];
    k = i;
    i = k / 2;
  }
  h[k] = v;
}

void put(int x){
  h[++n] = x;
  up();
}

int main(void){
  int getSeed = 0;
  printf("Please enter seed : ");
  scanf("%d", &getSeed);
  init(getSeed);
  for(int i = 1; i <= HEAP_SIZE; i++){
    put(A[i]);
  }
  for(int i = 1; i <= HEAP_SIZE; i++){
    get();
  }
  printf("%d\n", h[500000]);
}
