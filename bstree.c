// e1433 藤本 恭子 「2分探索木」
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1

typedef struct node{
  char str[128];
  struct node *left;
  struct node *right;
}
