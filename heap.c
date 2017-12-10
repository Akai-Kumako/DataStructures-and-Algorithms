// e1433 藤本 恭子 「ヒープ」
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 10

int n = 0;
int h[HEAP_SIZE];

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

int get(){
  int x = h[1];
  h[1] = h[n];
  n = n - 1;
  down(1);
  return x;
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
  char com;
  int a;
  while(1){
    printf("Please enter the command : ");
    scanf("%1s", &com);
    if(com == 'i'){
      if(n > HEAP_SIZE - 1) printf(" - Heap is full\n");
      else{
        printf(" - Please enter the data : ");
        scanf("%d", &a);
        put(a);
      }
    }else if(com == 'd'){
      if(n < 1) printf(" - Heap is empty\n");
      else get();
    }else if(com == 'p'){
      for(int i = 1; i < n; ++i){
        printf(" - %d [%d]\n", h[i], i);
      }
    }else if(com == 'q'){
      break;
    }else{
      printf(" - Please enter i, d, m, p, q or q\n");
    }
  }
}
