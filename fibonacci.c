//e1433 藤本恭子「フィボナッチ数」

#include<stdio.h>
#include<math.h>

#define SQRT sqrt(5)

int main(void){
  int n;
  int ans;
  scanf("%d", &n);
  ans = pow((1 + SQRT) / 2, n) / SQRT - pow((1 - SQRT) / 2, n) / SQRT;
  printf("%d\n", ans);
}
