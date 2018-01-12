//e1433 藤本恭子「フィボナッチ数」

#include<stdio.h>
#include<math.h>

int main(void){
  int i = 1, j = 0;
  int n = 0;
  scanf("%d", &n);
  
  for(int k = 0; k < n; k++){
    j = j + i;
    i = j - i;
  }
  printf("%d\n", j);
  return 0;
}
