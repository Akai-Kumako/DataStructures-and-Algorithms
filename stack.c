// e1433 藤本恭子 「構造体とポインタによるスタック」

#include <stdio.h>
#include <stdlib.h>

typedef struct cell{ //cell_t(= struct cell)構造体
  int item;
  struct cell *next;
} cell_t;

cell_t *listhead; //stackの先頭を表すcell_tのポインタ

cell_t *lalloc(void){ //メモリを確保する関数 構造体のポインタを返す
  return((cell_t *)malloc(sizeof(cell_t)));
}

cell_t *initlist(void){ //stackを初期化する関数
  cell_t *p;
  p = lalloc();
  p->next = NULL;
  return(p);
}

cell_t *top = NULL; //stackの最上層を表すcell_tのポインタ

cell_t *push(int x, cell_t *top){ //push関数
  cell_t *p;
  p = lalloc();
  p->item = x;
  p->next = top;
  return(p); //最新の最上層のデータを返す
}

cell_t *pop(cell_t *top){ //pop関数
  int x;
  if(top != NULL){
    x = top->item;
    top = top->next;
    printf("データ%dを取り出しました。\n", x);
  }else
    printf("スタックは空です。\n");
  return(top); //最新の最上層のデータを返す
}

int main(void){ //メイン関数
  listhead = initlist();
  
  top = push(2, top);  
  top = pop(top);
  top = pop(top);

  return(0);
}
